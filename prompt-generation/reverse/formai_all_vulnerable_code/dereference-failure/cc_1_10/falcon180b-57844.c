//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define PI 3.14159265358979323846

int main() {
    int i, j, k;
    double x, y, z;
    time_t start_time, end_time;
    double elapsed_time;

    int *array = (int *)malloc(MAX_SIZE * sizeof(int));

    for (i = 0; i < MAX_SIZE; i++) {
        array[i] = i;
    }

    // Sorting algorithm
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = i + 1; j < MAX_SIZE; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Performance-critical component
    start_time = time(NULL);
    for (k = 0; k < 100000; k++) {
        for (i = 0; i < MAX_SIZE; i++) {
            x = array[i];
            y = array[i + 1];
            z = array[i + 2];
            array[i] = x + y + z;
        }
    }
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    free(array);

    return 0;
}