#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "insertionSort/insertionSort.h"
#include "mergeSort/mergeSort.h"
#include "radixSort/radixSort.h"

int main(int argc, char** argv) {
    int* valores;
    double tempo[20];
    FILE* instancia;
    char caminho[100];

    clock_t start, end;

    int TAM = atoi(argv[1]);
    char algoritmo[14];
    strcpy(algoritmo, argv[2]);

    bool isMerge = (strcmp("MergeSort", algoritmo) == 0) ? true : false;
    bool isInsertion = (strcmp("InsertionSort", algoritmo) == 0) ? true : false;
    bool isRadix = (strcmp("RadixSort", algoritmo) == 0) ? true : false;

    if (!(isMerge || isInsertion || isRadix)) {
        printf("Algoritmo selecionado invalido. Os algoritmos sao:\n");
        printf("- MergeSort\n");
        printf("- InsertionSort\n");
        printf("- RadixSort\n");
        printf("Algoritmo selecionado: %s\n", algoritmo);

        exit(0);
    }

    printf("%s\n\n", algoritmo);

    valores = (int*)malloc(TAM * sizeof(int));

    for (int i = 1; i <= 20; i++) {
        sprintf(caminho, "../data/input/n%d/instance-n%d-%d.in", TAM, TAM, i);
        instancia = fopen(caminho, "r");

        for (int j = 0; j < TAM; j++) {
            fscanf(instancia, "%d", &valores[j]);
        }

        if (isMerge) {
            start = clock();
            mergeSort(valores, TAM);
            end = clock();

        } else if (isInsertion) {
            start = clock();
            insertionSort(valores, TAM);
            end = clock();

        } else if (isRadix) {
            start = clock();
            radixSort(valores, TAM);
            end = clock();
        }

        tempo[i] = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%.8lf\n", tempo[i]);

        fclose(instancia);
    }

    double media = 0.0;
    for (int i = 1; i <= 20; i++) {
        printf("Instancia %d: %lf\n", i, tempo[i - 1]);
        media += tempo[i - 1];
    }
    printf("\nTempo medio: %lf\n", media / 20.0);

    free(valores);
    return 0;
}