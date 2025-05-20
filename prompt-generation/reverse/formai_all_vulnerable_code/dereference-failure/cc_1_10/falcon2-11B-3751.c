//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numDisks;
    int numPoles;
    int* disks;
    int* poles;
} Tower;

void print_tower(Tower* tower) {
    for (int i = 0; i < tower->numPoles; i++) {
        for (int j = 0; j < tower->numDisks; j++) {
            printf("%d ", tower->disks[i*tower->numDisks + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_disks(Tower* tower, int start, int target, int auxiliary) {
    int numDisks = tower->numDisks;
    int numPoles = tower->numPoles;
    int* disks = tower->disks;
    int* poles = tower->poles;

    for (int i = 0; i < numDisks; i++) {
        disks[i] = disks[start*numDisks + i];
    }

    for (int i = 0; i < numDisks; i++) {
        disks[i*numPoles + target] = disks[i*numPoles + start];
    }

    for (int i = 0; i < numDisks; i++) {
        disks[i*numPoles + auxiliary] = disks[i*numPoles + start];
    }
}

void tower_of_hanoi(Tower* tower, int start, int target, int auxiliary) {
    if (tower->numDisks == 1) {
        printf("Move disk 1 from pole %d to pole %d\n", start, target);
        return;
    }

    tower_of_hanoi(tower, start, auxiliary, target);
    move_disks(tower, start, target, auxiliary);
    tower_of_hanoi(tower, auxiliary, target, start);
}

int main() {
    int numDisks = 3;
    int numPoles = 3;

    Tower* tower = (Tower*) malloc(sizeof(Tower));
    tower->numDisks = numDisks;
    tower->numPoles = numPoles;
    tower->disks = (int*) malloc(numPoles*numPoles*numDisks*sizeof(int));
    tower->poles = (int*) malloc(numPoles*sizeof(int));

    for (int i = 0; i < numPoles; i++) {
        for (int j = 0; j < numPoles; j++) {
            tower->poles[i] = j;
        }
    }

    for (int i = 0; i < numPoles*numPoles*numDisks; i++) {
        tower->disks[i] = i;
    }

    tower_of_hanoi(tower, 0, 2, 1);
    print_tower(tower);
    free(tower->disks);
    free(tower->poles);
    free(tower);

    return 0;
}