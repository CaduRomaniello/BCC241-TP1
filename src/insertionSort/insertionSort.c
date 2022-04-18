#include "insertionSort.h"

void insertionSort(int* vet, int n){
 	int aux ;
 	int i, j;

 	for (i = 1; i < n; i ++) {
 		aux = vet[i];
 		j = i - 1;
 		while (j >= 0 && aux < vet[j]) {
 			vet[j + 1] = vet[j];
 			j--;
 		}
 		vet[j + 1] = aux;
 	}
}