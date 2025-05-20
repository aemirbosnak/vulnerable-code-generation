//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOWER_HEIGHT 10

// Structure to represent a tower
typedef struct Tower {
    int height;
    int *disks;
} Tower;

// Function to create a new tower
Tower *createTower(int height) {
    Tower *tower = (Tower *)malloc(sizeof(Tower));
    tower->height = height;
    tower->disks = (int *)malloc(sizeof(int) * height);
    for (int i = 0; i < height; i++) {
        tower->disks[i] = 0;
    }
    return tower;
}

// Function to move a disk from one tower to another
void moveDisk(Tower *fromTower, Tower *toTower) {
    int disk = fromTower->disks[fromTower->height - 1];
    fromTower->height--;
    toTower->disks[toTower->height++] = disk;
}

// Function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(Tower *fromTower, Tower *toTower, Tower *auxTower, int height) {
    if (height == 1) {
        moveDisk(fromTower, toTower);
        return;
    }

    // Move the top height - 1 disks from the fromTower to the auxTower
    solveTowerOfHanoi(fromTower, auxTower, toTower, height - 1);

    // Move the remaining disk from the fromTower to the toTower
    moveDisk(fromTower, toTower);

    // Move the height - 1 disks from the auxTower to the toTower
    solveTowerOfHanoi(auxTower, toTower, fromTower, height - 1);
}

// Function to print the towers
void printTowers(Tower *tower1, Tower *tower2, Tower *tower3) {
    for (int i = MAX_TOWER_HEIGHT - 1; i >= 0; i--) {
        printf("%d %d %d\n", tower1->disks[i], tower2->disks[i], tower3->disks[i]);
    }
}

int main() {
    // Create the three towers
    Tower *tower1 = createTower(MAX_TOWER_HEIGHT);
    Tower *tower2 = createTower(MAX_TOWER_HEIGHT);
    Tower *tower3 = createTower(MAX_TOWER_HEIGHT);

    // Initialize the first tower with disks
    for (int i = MAX_TOWER_HEIGHT - 1; i >= 0; i--) {
        tower1->disks[i] = i + 1;
    }

    // Solve the Tower of Hanoi problem
    solveTowerOfHanoi(tower1, tower3, tower2, MAX_TOWER_HEIGHT);

    // Print the towers
    printTowers(tower1, tower2, tower3);

    return 0;
}