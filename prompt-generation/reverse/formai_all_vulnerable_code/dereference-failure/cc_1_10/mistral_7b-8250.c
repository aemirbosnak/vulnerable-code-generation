//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    char name[20];
    int size;
} Rod;

typedef struct {
    Rod* rods;
    int num_rods;
    int num_disks;
} Tower;

void init_tower(Tower* tower, int num_rods, int num_disks) {
    tower->rods = (Rod*) calloc(num_rods, sizeof(Rod));
    tower->num_rods = num_rods;
    tower->num_disks = num_disks;
    for (int i = 0; i < num_rods; i++) {
        sprintf(tower->rods[i].name, "Rod %d", i + 1);
        tower->rods[i].size = num_disks;
    }
}

void print_tower(const Tower* tower) {
    for (int i = 0; i < tower->num_rods; i++) {
        printf("%s: ", tower->rods[i].name);
        for (int j = 0; j < tower->num_disks; j++) {
            if (tower->rods[i].size > j) {
                printf("Disk %d ", j + 1);
            }
        }
        printf("\n");
    }
}

void hanoi(Rod src, Rod dest, Rod aux, int num_disks) {
    if (num_disks <= 0) {
        return;
    }

    hanoi(src, aux, dest, num_disks - 1);
    printf("Move disk %d from rod %s to rod %s.\n", num_disks, src.name, dest.name);
    hanoi(aux, dest, src, num_disks - 1);
}

void play_game(Tower* tower) {
    printf("Initial configuration:\n");
    print_tower(tower);

    hanoi(tower->rods[0], tower->rods[2], tower->rods[1], tower->num_disks);

    printf("\nFinal configuration:\n");
    print_tower(tower);
}

int main(void) {
    srand(time(NULL));

    int num_rods = 3;
    int num_disks = rand() % 10 + 1;

    Tower tower;
    init_tower(&tower, num_rods, num_disks);

    play_game(&tower);

    free(tower.rods);

    return EXIT_SUCCESS;
}