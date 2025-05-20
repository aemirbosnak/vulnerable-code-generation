//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000000
#define MAX_M 1000000

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main(int argc, char **argv) {
    int n, m, i, j;
    int *arr1, *arr2, *result;
    double start_time, end_time;

    srand(time(NULL));

    printf("Enter the size of first array: ");
    scanf("%d", &n);

    printf("Enter the size of second array: ");
    scanf("%d", &m);

    arr1 = (int *) malloc(n * sizeof(int));
    arr2 = (int *) malloc(m * sizeof(int));
    result = (int *) malloc(n * sizeof(int));

    printf("Enter elements of first array: ");
    for (i = 0; i < n; i++) {
        arr1[i] = rand_int(1, 1000000);
    }

    printf("Enter elements of second array: ");
    for (i = 0; i < m; i++) {
        arr2[i] = rand_int(1, 1000000);
    }

    start_time = clock();
    for (i = 0; i < n; i++) {
        result[i] = 0;
        for (j = 0; j < m; j++) {
            if (arr1[i] == arr2[j]) {
                result[i] = 1;
                break;
            }
        }
    }
    end_time = clock();

    printf("Time taken: %f seconds\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}