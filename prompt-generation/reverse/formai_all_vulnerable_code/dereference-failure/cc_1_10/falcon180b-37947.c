//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // number of sites
#define T 100 // number of trials

// Function prototypes
void init(int *s);
int check(int *s, int i, int j);
int count_neighbors(int *s, int i, int j);
void percolate(int *s);

int main() {
    int *s;
    int i, j, k, l;
    int trials, percolations;
    double p;

    s = (int *) malloc(N * sizeof(int));
    init(s);

    for (trials = 0; trials < T; trials++) {
        percolate(s);
        percolations = 0;
        for (i = 0; i < N; i++) {
            if (s[i] == 1) {
                percolations++;
            }
        }
        p = (double) percolations / N;
        printf("Trial %d: Percolation probability = %.4f\n", trials + 1, p);
    }

    free(s);
    return 0;
}

void init(int *s) {
    int i;

    for (i = 0; i < N; i++) {
        s[i] = 0;
    }
}

int check(int *s, int i, int j) {
    if ((i < 0) || (i >= N) || (j < 0) || (j >= N)) {
        return 0;
    }
    return 1;
}

int count_neighbors(int *s, int i, int j) {
    int count = 0;
    int k, l;

    for (k = -1; k <= 1; k++) {
        for (l = -1; l <= 1; l++) {
            if ((k!= 0) || (l!= 0)) {
                if (check(s, i + k, j + l) && (s[i + k] == 1)) {
                    count++;
                }
            }
        }
    }

    return count;
}

void percolate(int *s) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((rand() % 2) == 0) {
                s[i] = 1;
            }
        }
    }
}