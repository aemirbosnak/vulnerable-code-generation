//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a, b) do { __typeof__(a) t = (a); (a) = (b); (b) = t; } while (0)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define RANDOM(min, max) (rand() % ((max) - (min) + 1) + (min))

typedef struct {
    int *array;
    size_t size;
} Array;

void knuthSort(Array *a) {
    int i, j, k;
    int sentinel = a->array[0];

    for (i = 1; i < a->size; ++i) {
        int element = a->array[i];
        int position = i;

        if (element < sentinel) {
            sentinel = element;
            position = i;
        }

        for (j = i - 1; j >= 0 && a->array[j] > element; --j) {
            a->array[j + 1] = a->array[j];
        }

        SWAP(a->array[j + 1], a->array[position]);
    }
}

void printArray(const Array *a) {
    for (size_t i = 0; i < a->size; ++i) {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

void generateRandomArray(Array *a) {
    a->size = ARRAY_SIZE(a->array);
    a->array = malloc(sizeof(int) * a->size);

    for (size_t i = 0; i < a->size; ++i) {
        a->array[i] = RANDOM(0, 100);
    }
}

void benchmarkSort(const char *name, Array *a) {
    clock_t start = clock();
    knuthSort(a);
    clock_t end = clock();

    printf("%s sorting took %f ms\n", name, 1000.0 * (end - start) / CLOCKS_PER_SEC);
}

int main() {
    srand(time(NULL));

    Array a;
    generateRandomArray(&a);

    printf("Randomly generated array:\n");
    printArray(&a);

    benchmarkSort("Knuth Sort", &a);

    free(a.array);

    return 0;
}