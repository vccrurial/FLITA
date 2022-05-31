#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void InsertSort(int n, int counter[], int cells[])
{
    int newElement, location, newCell;

    for (int i = 1; i < n; i++){
        newElement = counter[i];
        newCell = cells[i];
        location = i - 1;
        while(location >= 0 && counter[location] > newElement){
            counter[location+1] = counter[location];
            cells[location+1]=cells[location];
            location = location - 1;
        }
        counter[location+1] = newElement;
        cells[location+1]=newCell;
    }
}

void graphviz(int edges, int arr[edges][edges]){
        int i,j;
        FILE *graph;
        graph=fopen("graph.dot", "w");
        fprintf(graph, "%s", "graph awesomegraph{\n");
            for(i=0; i<edges; i++){
                fprintf(graph, "\t%d;\n", i+1);
            }
            for(i=0; i<edges; i++){
                for(j=0; j<edges; j++){
                    if(arr[i][j]==1){
                        fprintf(graph, "\t%d--%d;\n", i+1,j+1);
                    }
                }
            }
            fprintf(graph, "%s", "}");
            fclose(graph);
        printf("\nМатрица смежности:\n");
        for(i=0; i<edges; i++){
            for(j=0; j<edges; j++){
                printf("%2d ", arr[i][j]);
            }
            printf("\n");
        }
}

int main()
{
    setlocale(0, "rus");
    int val,rib,i,j,edges;
    printf("Введите количество ячеек:\n");
        scanf("%d", &edges);
        int arr[edges][edges];
        printf("\n1: есть ребро\n0: нет ребра\n\n");
        for(int i=0; i<edges; i++){
            for(int j=0; j<edges; j++){
                if(j>=i){
                    printf("%d ячейка связана с %d ячейкой? ", i+1,j+1);
                    scanf("%d", &val);
                    if(val==1||val==0){
                        arr[i][j]=val;
                    }else{
                        printf("Некорректный ответ\n");
                        j--;
                    }
                }else{
                    arr[i][j]=arr[j][i];
                }
            }
        }
        graphviz(edges,arr);
        int ans=-1;
        while(ans!=0&&ans!=1){
        printf("Найти и отсортировать четные вершины?\n1 - Да\n0 - Нет\n");
        scanf("%d",&ans);
        if(ans!=0&&ans!=1){
            printf("Некорректный ответ\n");
        }
        if(ans==1){
            int counter[edges];
            for(int n=0;n<edges;n++){
                counter[n]=0;
            }
            printf("Ячейки:\n");

            for(i=0;i<edges;i++){
                for(j=0;j<edges;j++){
                    if(arr[i][j]==1){
                        if(i==j){
                            counter[i]++;
                        }
                        counter[i]++;
                    }
                }
                printf("ячейка %d - степень %d\n",i+1,counter[i]);
            }

            int cells[edges];
            for(i=1;i<=edges;i++){
                cells[i-1]=i;
            }

            InsertSort(edges, counter, cells);
            printf("Cортировка ячеек с четными вершинами...\n");

            for(i=0;i<edges;i++){
                if(counter[i]%2==0&&counter[i]!=0){
                    printf("ячейка %d - степень%d\n",cells[i],counter[i]);
                }
            }
        }
    }
}

