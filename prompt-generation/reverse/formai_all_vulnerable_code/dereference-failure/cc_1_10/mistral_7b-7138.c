//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define DRAGON_SIZE 10

typedef struct {
    int fib;
    int* dragon;
} fib_dragon;

void generate_dragon(fib_dragon* fd, int size) {
    int i, j;
    fd->dragon = (int*) malloc(size * sizeof(int));
    fd->dragon[0] = 0;
    fd->dragon[1] = 1;

    for (i = 2; i < size; i++) {
        fd->dragon[i] = fd->dragon[i - 1] + fd->dragon[i - 2];
    }
}

void print_dragon(fib_dragon* fd, int size) {
    int i;
    printf("Fibonacci Dragon of size %d:\n", size);

    for (i = 0; i < size; i++) {
        printf("%d ", fd->dragon[i]);
    }

    printf("\n");
}

void fibonacci(int n, fib_dragon* fd) {
    int i;
    fd->fib = 0;
    fd->fib = fd->dragon[n];
}

int main(void) {
    fib_dragon fd;
    int n, i, j;
    clock_t start, end;

    srand(time(NULL));

    n = rand() % (MAX + 1);

    generate_dragon(&fd, DRAGON_SIZE);

    printf("Fibonacci number of index %d: %d\n", n, fd.fib);

    start = clock();

    for (i = 0; i <= n; i++) {
        fibonacci(i, &fd);
    }

    end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    print_dragon(&fd, DRAGON_SIZE);

    free(fd.dragon);

    return 0;
}