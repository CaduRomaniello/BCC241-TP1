#include "radixSort.h"

countingSort(int[] content) {

        int maximum = _findMaximum(content);
        int[] countingArray = new int[maximum + 1];
        int[] sortedArray = new int[content.length + 1];
        Arrays.fill(countingArray, 0);

        for (int i : content) {
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
        for (int i = 0; i < content.length; i++) {
            content[i] = sortedArray[i];
        }

    }