//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

void fibonacci(int n, int *fib) {
    int i, a = 0, b = 1;
    for (i = 0; i < n; i++) {
        fib[i] = a;
        a = b;
        b += a;
    }
    fib[n] = -1;
}

void save_to_file(const char *filename, int *fib, int n) {
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i <= n; i++) {
        fprintf(fp, "%d ", fib[i]);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    int n, *fib;

    if (argc != 3) {
        printf("Usage: %s <number> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);

    if (n < 0 || n > MAX_SIZE) {
        printf("Error: Invalid number.\n");
        return EXIT_FAILURE;
    }

    fib = (int *) calloc(n + 1, sizeof(int));
    if (fib == NULL) {
        perror("Error allocating memory.");
        return EXIT_FAILURE;
    }

    fibonacci(n, fib);

    printf("Fibonacci sequence up to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    save_to_file(argv[2], fib, n);

    free(fib);

    return EXIT_SUCCESS;
}