#include "insertionSort/insertionSort.h"
#include "mergeSort/mergeSort.h"
#include "radixSort/radixSort.h"

#define TAM 100000000

int main(){
    int* vet = (int*) malloc(sizeof(int) * TAM);;
    int count = 1;

    for (int i = TAM-1; i >= 0; i--){
        vet[i] = count++;
    }

    printf("Antes:\n");
    // for (int i = 0; i < TAM; i++){
    //     printf("%d ", vet[i]);
    // }
    // printf("\n");

    printf("RadixSort\n");
    mergeSort(vet, TAM);

    printf("Depois:\n");
    // for (int i = 0; i < TAM; i++){
    //     printf("%d ", vet[i]);
    // }
    // printf("\n");

    free(vet);
    return 0;
}