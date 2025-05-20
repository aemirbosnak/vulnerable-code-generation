//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define N 1000
#define P 10

typedef struct {
    unsigned int *a;
    unsigned int n;
} seq;

seq *new_seq(unsigned int n) {
    seq *s = malloc(sizeof(seq));
    s->n = n;
    s->a = malloc(n * sizeof(unsigned int));
    return s;
}

void free_seq(seq *s) {
    free(s->a);
    free(s);
}

void fill_seq(seq *s, unsigned int *a, unsigned int n) {
    memcpy(s->a, a, n * sizeof(unsigned int));
    s->n = n;
}

void print_seq(seq *s) {
    for (unsigned int i = 0; i < s->n; i++) {
        printf("%u ", s->a[i]);
    }
    printf("\n");
}

seq *fib(unsigned int n) {
    seq *s = new_seq(n);
    s->a[0] = 0;
    s->a[1] = 1;
    for (unsigned int i = 2; i < n; i++) {
        s->a[i] = s->a[i - 1] + s->a[i - 2];
    }
    return s;
}

seq *lucas(unsigned int n) {
    seq *s = new_seq(n);
    s->a[0] = 2;
    s->a[1] = 1;
    for (unsigned int i = 2; i < n; i++) {
        s->a[i] = s->a[i - 1] + s->a[i - 2];
    }
    return s;
}

seq *pell(unsigned int n) {
    seq *s = new_seq(n);
    s->a[0] = 0;
    s->a[1] = 1;
    for (unsigned int i = 2; i < n; i++) {
        s->a[i] = 2 * s->a[i - 1] + s->a[i - 2];
    }
    return s;
}

seq *tri(unsigned int n) {
    seq *s = new_seq(n);
    s->a[0] = 0;
    s->a[1] = 1;
    s->a[2] = 1;
    for (unsigned int i = 3; i < n; i++) {
        s->a[i] = s->a[i - 1] + s->a[i - 2] + s->a[i - 3];
    }
    return s;
}

int main(int argc, char **argv) {
    unsigned int n = N;
    unsigned int p = P;
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    if (argc > 2) {
        p = atoi(argv[2]);
    }

    srand(time(NULL));

    seq *s = NULL;
    switch (rand() % 4) {
        case 0:
            s = fib(n);
            printf("Fibonacci sequence of length %u:\n", n);
            break;
        case 1:
            s = lucas(n);
            printf("Lucas sequence of length %u:\n", n);
            break;
        case 2:
            s = pell(n);
            printf("Pell sequence of length %u:\n", n);
            break;
        case 3:
            s = tri(n);
            printf("Triangular sequence of length %u:\n", n);
            break;
    }

    print_seq(s);

    free_seq(s);

    return 0;
}