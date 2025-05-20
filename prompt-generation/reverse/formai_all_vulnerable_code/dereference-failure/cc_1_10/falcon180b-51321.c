//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main(int argc, char *argv[]) {
    int i, j, k, n;
    int *arr1, *arr2;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    arr1 = (int *) malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    arr2 = (int *) malloc(n * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = n - i;
    }

    start = clock();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            k = arr1[i] + arr2[j];
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    free(arr1);
    free(arr2);

    return 0;
}