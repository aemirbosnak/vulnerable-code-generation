//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 10000
#define MIN_TERM 1
#define MAX_TERM 1000000

int main() {
    int i, j, n, a, b, c, terms;
    int *fib_seq;
    char *filename;
    FILE *file;
    struct tm *tm;
    time_t now;

    srand(time(NULL));
    n = rand() % (MAX_TERM - MIN_TERM + 1) + MIN_TERM;
    terms = rand() % (MAX_TERMS - 2) + 2;
    fib_seq = (int *) malloc(sizeof(int) * terms);

    for (i = 0; i < terms; i++) {
        fib_seq[i] = 0;
    }

    fib_seq[0] = 0;
    fib_seq[1] = 1;

    for (i = 2; i < terms; i++) {
        a = fib_seq[i - 1];
        b = fib_seq[i - 2];
        c = a + b;
        fib_seq[i] = c;
    }

    filename = (char *) malloc(sizeof(char) * 20);
    sprintf(filename, "fib_%d_%d.txt", n, terms);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to create file.\n");
        exit(1);
    }

    tm = localtime(&now);
    fprintf(file, "Fibonacci sequence generated on %s", asctime(tm));
    fprintf(file, "\nNumber of terms: %d\n", terms);
    fprintf(file, "Initial values: 0, 1\n");

    for (i = 0; i < terms; i++) {
        fprintf(file, "%d ", fib_seq[i]);
    }

    fprintf(file, "\n");
    fclose(file);

    printf("Fibonacci sequence saved to file: %s\n", filename);

    free(filename);
    free(fib_seq);

    return 0;
}