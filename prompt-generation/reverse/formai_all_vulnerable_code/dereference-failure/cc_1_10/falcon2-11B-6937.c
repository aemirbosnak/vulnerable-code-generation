//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *source;
    int *destination;
    int *auxiliary;
} Tower;

void moveDisk(Tower *tower, int disk);

int main() {
    Tower tower = {3, (int *)malloc(sizeof(int) * 3), (int *)malloc(sizeof(int) * 3), (int *)malloc(sizeof(int) * 3)};
    int n = tower.n;

    tower.source[0] = 1;
    tower.source[1] = 2;
    tower.source[2] = 3;

    printf("Original tower: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower.source[i]);
    }
    printf("\n");

    moveDisk(&tower, 0);
    printf("After move 1: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower.source[i]);
    }
    printf("\n");

    moveDisk(&tower, 1);
    printf("After move 2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower.source[i]);
    }
    printf("\n");

    moveDisk(&tower, 2);
    printf("After move 3: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower.source[i]);
    }
    printf("\n");

    free(tower.source);
    free(tower.destination);
    free(tower.auxiliary);

    return 0;
}

void moveDisk(Tower *tower, int disk) {
    int n = tower->n;
    int source = tower->source[disk];
    int destination = tower->destination[disk];
    int auxiliary = tower->auxiliary[disk];

    tower->source[disk] = auxiliary;
    tower->destination[disk] = source;
    tower->auxiliary[disk] = destination;

    if (disk > 0) {
        moveDisk(tower, disk - 1);
    }
    if (disk < n - 1) {
        moveDisk(tower, disk + 1);
    }
}