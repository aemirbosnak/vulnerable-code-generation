//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIMENSION 10
#define MAX_SAMPLES 1000

typedef struct {
    int dimension;
    int samples;
    int* data;
} dataset;

dataset generate_dataset(int dimension) {
    dataset d;
    d.dimension = dimension;
    d.samples = rand() % 100 + 1;
    d.data = malloc(d.samples * dimension * sizeof(int));
    for (int i = 0; i < d.samples; i++) {
        for (int j = 0; j < dimension; j++) {
            d.data[i * dimension + j] = rand() % 10 + 1;
        }
    }
    return d;
}

void print_dataset(dataset d) {
    printf("Dimension: %d\n", d.dimension);
    for (int i = 0; i < d.samples; i++) {
        for (int j = 0; j < d.dimension; j++) {
            printf("%d ", d.data[i * d.dimension + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    dataset d1 = generate_dataset(3);
    print_dataset(d1);

    dataset d2 = generate_dataset(4);
    print_dataset(d2);

    dataset d3 = generate_dataset(5);
    print_dataset(d3);

    return 0;
}