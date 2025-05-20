//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int n;
    int *towers;
    int *visited;
} hanoi;

hanoi *hanoi_new(int n) {
    hanoi *h = malloc(sizeof(hanoi));
    h->n = n;
    h->towers = malloc(sizeof(int) * n);
    h->visited = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        h->towers[i] = 0;
        h->visited[i] = 0;
    }
    return h;
}

void hanoi_free(hanoi *h) {
    free(h->towers);
    free(h->visited);
    free(h);
}

void hanoi_print(hanoi *h) {
    for (int i = 0; i < h->n; i++) {
        for (int j = 0; j < h->n; j++) {
            if (h->towers[j] == i) {
                printf("|%d", j + 1);
            } else {
                printf("| ");
            }
        }
        printf("|\n");
    }
    printf("-------------------------------\n");
}

int hanoi_solve(hanoi *h, int n, int from, int to, int via) {
    if (n == 1) {
        h->towers[to] = h->towers[from];
        h->towers[from] = 0;
        hanoi_print(h);
        return 1;
    } else {
        int moves = 0;
        moves += hanoi_solve(h, n - 1, from, via, to);
        h->towers[to] = h->towers[from];
        h->towers[from] = 0;
        hanoi_print(h);
        moves += hanoi_solve(h, n - 1, via, to, from);
        return moves;
    }
}

int main() {
    hanoi *h = hanoi_new(N);
    for (int i = 0; i < N; i++) {
        h->towers[i] = i;
    }
    hanoi_print(h);
    int moves = hanoi_solve(h, N, 0, 2, 1);
    printf("Number of moves: %d\n", moves);
    hanoi_free(h);
    return 0;
}