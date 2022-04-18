#include "radixSort.h"

void countingSort(int* content, int length) {

    int maximum = _findMaximum(content);
    int* countingArray = calloc(maximum + 1, sizeof(int));
    int* sortedArray = malloc(length + 1 * sizeof(int));

    for (int i = 0; i < length; i++) {
        countingArray[i] += 1;
    }

    for (int i = 1; i <= maximum; i++) {
        countingArray[i] += countingArray[i - 1];
    }

    for (int i = maximum - 1; i >= 0; i--) {
        int value = content[i];
        int pos = countingArray[value];

        sortedArray[pos - 1] = value;
        countingArray[value] -= 1;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < length; i++) {
        content[i] = sortedArray[i];
    }

}