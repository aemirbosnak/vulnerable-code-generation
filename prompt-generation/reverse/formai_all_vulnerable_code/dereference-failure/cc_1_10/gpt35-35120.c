//FormAI DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int* bubble_sort(int array[], int length);

int main(void) {
    int listSize, i;
    int *unsortedList, *sortedList;
    char input[MAX_INPUT_LENGTH + 1];

    printf("Enter the size of the list to sort: ");
    fgets(input, MAX_INPUT_LENGTH + 1, stdin);
    listSize = atoi(input);

    unsortedList = (int*)malloc(listSize * sizeof(int));
    sortedList = (int*)malloc(listSize * sizeof(int));

    printf("Enter the numbers to sort:\n");
    for (i = 0; i < listSize; i++) {
        fgets(input, MAX_INPUT_LENGTH + 1, stdin);
        unsortedList[i] = atoi(input);
    }

    sortedList = bubble_sort(unsortedList, listSize);

    printf("Sorted List:\n");
    for (i = 0; i < listSize; i++) {
        printf("%d\n", sortedList[i]);
    }

    free(unsortedList);
    free(sortedList);

    return 0;
}

int* bubble_sort(int array[], int length) {
    int i, j, temp;
    int *sorted = malloc(length * sizeof(int));

    memcpy(sorted, array, length * sizeof(int));

    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    return sorted;
}