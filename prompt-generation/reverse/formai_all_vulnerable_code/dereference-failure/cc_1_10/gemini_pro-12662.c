//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdlib.h>
#include <stdio.h>

#define N 3

typedef struct {
    int n;
    int *T;
} Tower;

void init_tower(Tower *tower, int n) {
    tower->n = n;
    tower->T = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        tower->T[i] = n - i;
    }
}

void print_tower(Tower *tower) {
    for (int i = tower->n - 1; i >= 0; i--) {
        printf("%d ", tower->T[i]);
    }
    printf("\n");
}

void move_disk(Tower *from, Tower *to) {
    int disk = from->T[from->n - 1];
    from->n--;
    to->T[to->n++] = disk;
}

int main() {
    Tower towers[3];
    init_tower(&towers[0], N);
    init_tower(&towers[1], 0);
    init_tower(&towers[2], 0);

    print_tower(&towers[0]);
    print_tower(&towers[1]);
    print_tower(&towers[2]);

    for (int i = 0; i < N; i++) {
        move_disk(&towers[0], &towers[1]);
        print_tower(&towers[0]);
        print_tower(&towers[1]);
        print_tower(&towers[2]);

        move_disk(&towers[1], &towers[2]);
        print_tower(&towers[0]);
        print_tower(&towers[1]);
        print_tower(&towers[2]);

        move_disk(&towers[0], &towers[2]);
        print_tower(&towers[0]);
        print_tower(&towers[1]);
        print_tower(&towers[2]);
    }

    return 0;
}