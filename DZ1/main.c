#include <stdio.h>

int decToBin(int n) {
    int bin = 0;
    int rem, i = 1;
    while (n!=0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

int main() {
    int i = 0, quan; 
    scanf("%d", &quan);
    int decArray[quan], binArray[quan];
    for (int i = 0; i < quan; i++) {
      scanf("%d", &decArray[i]);
    }
    for (int i = 0; i < quan; i++) {
        binArray[i] = decToBin(decArray[i]);
    }
    printf("decimal array:\t");
    for (int i = 0; i < quan; i++) {
        printf("%d\t", decArray[i]);
    }
    printf("\nbinary array:\t");

    for (int i = 0; i < quan; i++) {
        printf("%d\t", binArray[i]);
    }
}
