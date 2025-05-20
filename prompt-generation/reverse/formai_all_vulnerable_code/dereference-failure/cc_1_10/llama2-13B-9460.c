//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define BENCHMARK_LOOP_SIZE 100000
#define BENCHMARK_ITERATIONS 5

void benchmark_function(void (*function)(void), char *name) {
    clock_t start, end;
    double elapsed_time;

    srand(time(NULL));

    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        start = clock();
        function();
        end = clock();
        elapsed_time = (end - start) / CLOCKS_PER_SEC;

        printf("%s: %f seconds\n", name, elapsed_time);
    }
}

int main() {
    char *functions[] = {"memset", "memcpy", "strlen"};
    int i;

    for (i = 0; i < sizeof(functions) / sizeof(functions[0]); i++) {
        benchmark_function(functions[i], functions[i]);
    }

    return 0;
}

void memset_benchmark(void) {
    char buffer[100];
    memset(buffer, 'a', 100);
}

void memcpy_benchmark(void) {
    char buffer[100];
    char *src = "Hello, world!";
    char *dst = buffer;
    memcpy(dst, src, strlen(src));
}

void strlen_benchmark(void) {
    char buffer[100];
    char *src = "Hello, world!";
    int len = strlen(src);
    printf("%d\n", len);
}