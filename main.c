#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <locale.h>

void InsertSort(int n, int schetchik[], int yacheyki[])
{
    int newElement, location, newYacheyka;

    for (int i = 1; i < n; i++){
        newElement = schetchik[i];
        newYacheyka = yacheyki[i];
        location = i - 1;
        while(location >= 0 && schetchik[location] > newElement){
            schetchik[location+1] = schetchik[location];
            yacheyki[location+1]=yacheyki[location];
            location = location - 1;
        }
        schetchik[location+1] = newElement;
        yacheyki[location+1]=newYacheyka;
    }
}

void graphviz(int edges, int arr[edges][edges]){
        int i,j;
        FILE *graph;
        graph=fopen("graph.dot", "w");
        fprintf(graph, "%s", "graph whatsthis{\n");
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
            int schetchik[edges];
            for(int n=0;n<edges;n++){
                schetchik[n]=0;
            }
            printf("Ячейки:\n");

            for(i=0;i<edges;i++){
                for(j=0;j<edges;j++){
                    if(arr[i][j]==1){
                        if(i==j){
                            schetchik[i]++;
                        }
                        schetchik[i]++;
                    }
                }
                printf("ячейка %d - степень %d\n",i+1,schetchik[i]);
            }

            int yacheyki[edges];
            for(i=1;i<=edges;i++){
                yacheyki[i-1]=i;
            }

            InsertSort(edges, schetchik, yacheyki);
            printf("Cортировка ячеек с четными вершинами...\n");

            for(i=0;i<edges;i++){
                if(schetchik[i]%2==0&&schetchik[i]!=0){
                    printf("ячейка %d - степень%d\n",yacheyki[i],schetchik[i]);
                }
            }
        }
    }
}

