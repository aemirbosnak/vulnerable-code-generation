//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define TOWERS_COUNT     3
#define DISKS_COUNT      6
#define START_TOWER     1
#define DEST_TOWER      3
#define AUX_TOWER       2

typedef struct {
    int numDisks;
    int tower;
} towerState_t;

void hanoi(int numDisks, int startTower, int destTower, int auxTower) {
    if (numDisks > 0) {
        hanoi(numDisks - 1, startTower, auxTower, destTower);
        printf("Move disk %d from tower %d to tower %d\n", numDisks, startTower, destTower);
        hanoi(numDisks - 1, auxTower, destTower, startTower);
    }
}

towerState_t getInitialTowerStates() {
    int i;
    towerState_t initialStates[TOWERS_COUNT];

    for (i = 0; i < TOWERS_COUNT; i++) {
        initialStates[i].numDisks = 0;
        initialStates[i].tower = i + 1;
    }

    initialStates[START_TOWER - 1].numDisks = DISKS_COUNT;

    return initialStates[0];
}

void printTowerStates(towerState_t states[]) {
    int i;

    printf("\nCurrent tower states:\n");

    for (i = 0; i < TOWERS_COUNT; i++) {
        printf("Tower %d: %d disks\n", states[i].tower, states[i].numDisks);
    }
}

int main() {
    int numDisks = DISKS_COUNT;
    towerState_t initialStates, finalStates;

    initialStates = getInitialTowerStates();

    hanoi(numDisks, START_TOWER, DEST_TOWER, AUX_TOWER);

    printTowerStates(initialStates.numDisks > 0 ? &initialStates : &finalStates);
    printTowerStates(finalStates.numDisks > 0 ? &finalStates : &initialStates);

    return 0;
}