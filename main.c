#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const short ARRAY_SIZE = 1024;
const short STRING_SIZE = 20;

int main() {
    FILE * FILE_INPUT, * FILE_OUTPUT;
    char arr[ARRAY_SIZE][ARRAY_SIZE], s;
    int i = 0, j = 0, d = 0;
    FILE_INPUT = fopen("matrix_of_incendence.txt", "r");
    while (!feof(FILE_INPUT)) {
        s = fgetc(FILE_INPUT);
        if (s == '\n') {
            d++;
        }
        if (s != ' ' && s != '\n') {
            arr[i][j] = s;
            j++;
            if (j == STRING_SIZE) {
                i++;
                j = 0;
            }
        }
    }
    while (!feof(FILE_INPUT)) {
        s = fgetc(FILE_INPUT);
        if (s == '\n') {
            d++;
    
        }
            }
    d++;
    bool FLAG;
    FILE_OUTPUT = fopen("graf.gv", "w");
    fputs("graph grath {\n", FILE_OUTPUT);
    for (int i = 0; i < d; i++) {
        fprintf(FILE_OUTPUT, "%d\n", d + 1);
    }
    for (int a = 0; a < STRING_SIZE; a++) {
        FLAG = true;
        for (int y = 0; y < d; y++) {
            if (arr[y][a] != '0') {
                if (FLAG) {
                    fprintf(FILE_OUTPUT, "%d", y + 1);
                    printf("%d", y + 1);
                    FLAG = false;
                } else {
                    printf(" -- %d", y + 1);
                    fprintf(FILE_OUTPUT, " -- %d [label = ""%d""]", y + 1, a + 1);
                }
            }
        }
        fputs("\n", FILE_OUTPUT);
        puts("\n");
    }
    fputs("}", FILE_OUTPUT);
    fclose(FILE_OUTPUT);
    system("dot graf.gv -Tpng -o image.png");
    system("nsxiv -z 200 image.png");
    return 0;
}
