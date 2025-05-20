//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 10000000

typedef struct {
    int *data;
    int size;
} vector;

void vector_init(vector *v, int size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void vector_destroy(vector *v) {
    free(v->data);
}

void vector_print(vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int main() {
    int size = MAX_SIZE;
    vector v1, v2;
    int *data1, *data2;
    clock_t start, end;
    double cpu_time_used;

    vector_init(&v1, size);
    vector_init(&v2, size);

    data1 = v1.data;
    data2 = v2.data;

    for (int i = 0; i < size; i++) {
        data1[i] = i;
        data2[i] = i * 2;
    }

    start = clock();
    for (int i = 0; i < size; i++) {
        data2[i] = data1[i] + data2[i];
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU Time used: %lf seconds\n", cpu_time_used);

    vector_destroy(&v1);
    vector_destroy(&v2);

    return 0;
}