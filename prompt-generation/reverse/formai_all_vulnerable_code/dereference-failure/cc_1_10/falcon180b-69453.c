//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n, max, min, range, *arr;
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;
    printf("Range: %d\n", range);

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < range; j++) {
            if (arr[i] == j + min) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nBucket Sort completed in %lf seconds.\n", cpu_time_used);

    return 0;
}