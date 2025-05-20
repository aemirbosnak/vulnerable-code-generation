//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BENCHMARK_ITERATIONS 10000
#define BENCHMARK_FUNCTIONS \
    bench_function_1, \
    bench_function_2, \
    bench_function_3, \
    bench_function_4, \
    bench_function_5

void bench_function_1(void) {
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        printf("Hello, world! %d\n", i);
    }
}

void bench_function_2(void) {
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        printf("Hello, brave world! %d\n", i);
    }
}

void bench_function_3(void) {
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        printf("Hello, %s! %d\n", "world", i);
    }
}

void bench_function_4(void) {
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        printf("Hello, %s! %d\n", "brave", i);
    }
}

void bench_function_5(void) {
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        printf("Hello, %s! %d\n", "world", i);
    }
}

int main(void) {
    clock_t start, end;
    double time_taken;

    for (int i = 0; i < BENCHMARK_FUNCTIONS; i++) {
        start = clock();
        bench_function_1();
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Function %d took %f seconds to execute\n", i, time_taken);
    }

    return 0;
}