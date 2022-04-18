#include "mergeSort.h"

void merge_sort(int* vet, int esq, int dir){
	if(esq >= dir){
		return;
	}

	int meio = (dir + esq) / 2;
	merge_sort(vet,  esq, meio);
	merge_sort(vet,  meio + 1, dir);
	merge_sort_intercala(vet, esq, meio, dir);
}

void merge_sort_intercala(int* vet, int esq, int meio, int dir){
	int i, j, k;
	int tam_a = meio - esq + 1;
	int tam_b = dir - meio;
	int* a = malloc(tam_a * sizeof(int));
	int* b = malloc(tam_b * sizeof(int));

	for(i = 0; i < tam_a; i++){
		a[i] = vet[esq + i];
	}
	for(i = 0; i < tam_a; i++){
		b[i] = vet[i + meio + 1];
	}

	for(i = 0, j = 0, k = esq; k <= dir; k++){
		if(i == tam_a){
			vet[k] = b[j++];
		}
		else if(j == tam_b){
			vet[k] = a[i++];
		}
		else if(a[i] < b[j]){
			vet[k] = a[i++];
		}
		else if(a[i] >= b[j]){
			vet[k] = b[j++];
		}
	}

	free(a);
	free(b);
}