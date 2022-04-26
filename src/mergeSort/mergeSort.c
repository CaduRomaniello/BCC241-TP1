#include "mergeSort.h"

void mergeSort(int* vet, int n) { mergeSort_ordena(vet, 0, n - 1); }

void mergeSort_ordena(int* vet, int esq, int dir) {
    if (esq >= dir) {
        return;
    }

    int meio = (esq + dir) / 2;
    mergeSort_ordena(vet, esq, meio);
    mergeSort_ordena(vet, meio + 1, dir);
    mergeSort_intercala(vet, esq, meio, dir);
}

void mergeSort_intercala(int* vet, int esq, int meio, int dir) {
    int i, j, k;
    int a_tam = meio - esq + 1;
    int b_tam = dir - meio;
    int* a = (int*)malloc(sizeof(int) * a_tam);
    int* b = (int*)malloc(sizeof(int) * b_tam);

    for (i = 0; i < a_tam; i++) {
        a[i] = vet[i + esq];
    }
    for (i = 0; i < b_tam; i++) {
        b[i] = vet[i + meio + 1];
    }

    for (i = 0, j = 0, k = esq; k <= dir; k++) {
        if (i == a_tam) {
            vet[k] = b[j++];
        } else if (j == b_tam) {
            vet[k] = a[i++];
        } else if (a[i] < b[j]) {
            vet[k] = a[i++];
        } else {
            vet[k] = b[j++];
        }
    }

    free(a);
    free(b);
}

/**
 * Função de complexidade de mergeSort
 * - Função mergeSort_intercala - Custo Local O(n)
 * - Função mergeSort_ordena - T(n) = 2 * T(n/2) + O(n)
 *
 * - Pelo Teorema Mestre simplificado temos que
 * - log a na base b = 1, onde a = 2, b = 2
 * - como temos o expoente do custo local como sendo 1 (O(n^1))
 * - temos que a complexidade é Θ(n * log n).
 */