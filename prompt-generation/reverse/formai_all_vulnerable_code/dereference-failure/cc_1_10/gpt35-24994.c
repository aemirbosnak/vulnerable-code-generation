//FormAI DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
/* "Programs for testing performance alone do not deserve publication, because they 
    have no importance in themselves," says Prof. Knuth. In line with his thinking, 
    I present a benchmarking example program that aims to be both useful and elegant. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main() {
    clock_t start, end;
    double time_used;

    int *array = malloc(SIZE * sizeof(int));

    /* Filling array with random values between 1 and 1000 */
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000 + 1;
    }

    printf("Array before sorting: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    /* Bubble Sort algorithm */
    start = clock();
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n\nArray after sorting: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nBubble Sort took %f seconds to execute.\n", time_used);

    free(array);

    return 0;
}