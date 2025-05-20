//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int *disks;
} Tower;

void print_tower(Tower *tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

void move_disk(Tower *from, Tower *to) {
    int disk = from->disks[from->num_disks - 1];
    from->num_disks--;
    to->disks[to->num_disks++] = disk;
}

int solve_tower_of_hanoi(Tower *from, Tower *to, Tower *aux, int num_disks) {
    if (num_disks == 1) {
        move_disk(from, to);
        return 1;
    } else {
        int moves = solve_tower_of_hanoi(from, aux, to, num_disks - 1);
        moves += solve_tower_of_hanoi(from, to, aux, 1);
        moves += solve_tower_of_hanoi(aux, to, from, num_disks - 1);
        return moves;
    }
}

int main() {
    srand(time(NULL));

    int num_disks = rand() % MAX_DISKS + 1;
    Tower from, to, aux;
    from.num_disks = num_disks;
    from.disks = malloc(sizeof(int) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        from.disks[i] = i + 1;
    }
    to.num_disks = 0;
    to.disks = malloc(sizeof(int) * num_disks);
    aux.num_disks = 0;
    aux.disks = malloc(sizeof(int) * num_disks);

    printf("Initial state:\n");
    print_tower(&from);
    print_tower(&to);
    print_tower(&aux);
    printf("\n");

    int moves = solve_tower_of_hanoi(&from, &to, &aux, num_disks);

    printf("Final state:\n");
    print_tower(&from);
    print_tower(&to);
    print_tower(&aux);
    printf("\n");

    printf("Number of moves: %d\n", moves);

    free(from.disks);
    free(to.disks);
    free(aux.disks);

    return 0;
}