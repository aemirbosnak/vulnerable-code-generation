//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define RANGE 1000000

int *generate_random_data(int n) {
    int *data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        data[i] = rand() % RANGE;
    }
    return data;
}

void print_data(int *data, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void bucket_sort(int *data, int n) {
    int *buckets = (int*) malloc(MAX_SIZE * sizeof(int));
    memset(buckets, 0, MAX_SIZE * sizeof(int));

    for (int i = 0; i < n; ++i) {
        ++buckets[data[i] / RANGE];
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        while (buckets[i] > 0) {
            data[index++] = i * RANGE;
            --buckets[i];
        }
    }

    free(buckets);
}

int main() {
    int n = MAX_SIZE;
    int *data = generate_random_data(n);

    printf("Before sorting:\n");
    print_data(data, n);

    clock_t start_time = clock();
    bucket_sort(data, n);
    clock_t end_time = clock();

    double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("After sorting:\n");
    print_data(data, n);
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    free(data);
    return 0;
}