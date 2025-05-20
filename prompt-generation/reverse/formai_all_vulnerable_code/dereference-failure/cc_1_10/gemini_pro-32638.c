//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

typedef struct {
    int a;
    int b;
    int c;
} data_t;

data_t *data;

void fill_data() {
    for (int i = 0; i < N; i++) {
        data[i].a = rand() % 100;
        data[i].b = rand() % 100;
        data[i].c = rand() % 100;
    }
}

void test_1() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += data[i].a + data[i].b + data[i].c;
    }
    printf("Sum: %d\n", sum);
}

void test_2() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += data[i].a;
        sum += data[i].b;
        sum += data[i].c;
    }
    printf("Sum: %d\n", sum);
}

int main() {
    data = malloc(N * sizeof(data_t));
    fill_data();

    clock_t start, end;

    printf("Test 1:\n");
    start = clock();
    test_1();
    end = clock();
    printf("Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\nTest 2:\n");
    start = clock();
    test_2();
    end = clock();
    printf("Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(data);
    return 0;
}