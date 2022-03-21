#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        FILE *FNUM1, *FNUM2;
        int NUM = 0;
        char c[2048];

        for (int i = 0; i < 1024; i ++) {
                c[i] = '/0';
        }

        FNUM1 = fopen(argv[1], "r");
        fgets(c, 1024, FNUM1);
        for (int i = 0; i < 1024; i ++) {
                if (c[i] == ' ')
                        NUM++;
        }
        fclose(FNUM1);
        FNUM1 = fopen(argv[1], "r");
        FNUM2 = fopen(argv[2], "w");
        fprintf(FNUM2, "graph G {\n");

        for (int i = 0; i < NUM; i++) {
                for (int k = 0; k < NUM; k++) {
                        fscanf(FNUM1, "%s ", &c);
                        if (c[0] != '0' && k >= i)
                                fprintf(FNUM2, "\t%c -- %c [label = %s];\n", 'A' + i, 'A' + k, c);
                }
        }
        fprintf(FNUM2, "}");
        fclose(FNUM1);
        fclose(FNUM2);
        system("dot -Tpng output.txt > image.png");
        return 0;
}
