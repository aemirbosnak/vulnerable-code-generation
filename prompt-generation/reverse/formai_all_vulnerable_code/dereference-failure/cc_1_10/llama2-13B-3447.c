//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 1000
#define M 100000

struct bit_array {
    int size;
    int *bits;
};

void init_bit_array(struct bit_array *ba) {
    ba->size = N;
    ba->bits = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        ba->bits[i] = 0;
    }
}

void set_bit(struct bit_array *ba, int index) {
    ba->bits[index] = 1;
}

int get_bit(struct bit_array *ba, int index) {
    return ba->bits[index];
}

void print_bit_array(struct bit_array *ba) {
    for (int i = 0; i < N; i++) {
        printf("%d ", ba->bits[i]);
    }
    printf("\n");
}

int main() {
    struct bit_array ba;
    init_bit_array(&ba);

    // Benchmarking loop
    for (int i = 0; i < M; i++) {
        set_bit(&ba, i % N);
    }

    // Timing loop
    for (int j = 0; j < 10; j++) {
        clock_t start = clock();
        for (int i = 0; i < N; i++) {
            get_bit(&ba, i);
        }
        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Loop %d took %f seconds\n", j, time);
    }

    print_bit_array(&ba);

    return 0;
}