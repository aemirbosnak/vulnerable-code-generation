//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* disks;
    int numDisks;
    int numPegs;
} TowerOfHanoi;

TowerOfHanoi* createTower(int numDisks, int numPegs) {
    TowerOfHanoi* tower = (TowerOfHanoi*)malloc(sizeof(TowerOfHanoi));
    tower->numDisks = numDisks;
    tower->numPegs = numPegs;
    tower->disks = (int*)malloc(sizeof(int) * numDisks);
    for (int i = 0; i < numDisks; i++) {
        tower->disks[i] = i;
    }
    return tower;
}

void printTower(TowerOfHanoi* tower) {
    for (int i = 0; i < tower->numDisks; i++) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

bool isLegalMove(TowerOfHanoi* tower, int fromPeg, int toPeg) {
    for (int i = 0; i < tower->numDisks; i++) {
        if (tower->disks[i] == fromPeg) {
            return false;
        }
    }
    return true;
}

void moveDisk(TowerOfHanoi* tower, int fromPeg, int toPeg) {
    int temp = tower->disks[fromPeg];
    tower->disks[fromPeg] = tower->disks[toPeg];
    tower->disks[toPeg] = temp;
}

void hanoi(TowerOfHanoi* tower, int fromPeg, int toPeg, int tempPeg) {
    if (tower->numDisks == 1) {
        moveDisk(tower, fromPeg, toPeg);
        return;
    }
    hanoi(tower, fromPeg, tempPeg, toPeg);
    moveDisk(tower, fromPeg, toPeg);
    hanoi(tower, tempPeg, toPeg, fromPeg);
}

int main() {
    int numDisks = 3;
    int numPegs = 3;
    TowerOfHanoi* tower = createTower(numDisks, numPegs);
    printTower(tower);
    hanoi(tower, 0, 1, 2);
    printTower(tower);
    return 0;
}