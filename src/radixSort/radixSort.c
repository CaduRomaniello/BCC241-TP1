#include "radixSort.h"

int findMaximum(int *v, int tam){
    int max = v[0];

    for (int i = 1; i < tam; i++){
        if (v[i] > max){
            max = v[i];
        }
    }
    
    return max;
}

void countingSort(int* content, int length, int expo) {
    int maximum = findMaximum(content, length);
    int* countingArray = calloc(maximum + 1, sizeof(int));
    int* sortedArray = calloc(length + 1,  sizeof(int));

    for (int i = 0; i < length; i++) {
        int idx = (content[i] / expo) % 10;
        countingArray[idx] += 1;
    }

    for (int i = 1; i <= maximum; i++) {
        countingArray[i] += countingArray[i - 1];
    }

    for (int i = maximum - 1; i >= 0; i--) {
        int idx = (content[i] / expo) % 10;
        int pos = countingArray[idx];

        sortedArray[pos - 1] = content[i];
        countingArray[idx] -= 1;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < length; i++) {
        content[i] = sortedArray[i];
    }

    free(countingArray);
    free(sortedArray);
}

void radixSort(int *v, int length){
    int max = findMaximum(v, length);

    for (int expo = 1; (max / expo) > 0; expo *= 10){
        countingSort(v, length, expo);
    }
}