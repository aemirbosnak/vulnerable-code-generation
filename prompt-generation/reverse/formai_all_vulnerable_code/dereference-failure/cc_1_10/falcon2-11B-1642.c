//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n;
    srand(time(NULL));

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *array = (int*) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int *swapped;
    swapped = (int*) calloc(n, sizeof(int));
    if (swapped == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int j;
        for (j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                swapped[i] = array[i];
                swapped[j] = array[j];
                array[i] = array[j];
                array[j] = swapped[i];
                array[j] = swapped[j];
            }
        }
    }

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(swapped);
    free(array);

    return 0;
}