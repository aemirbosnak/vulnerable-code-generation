//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct Disk {
    int size;
    struct Disk *next;
} Disk;

typedef struct Tower {
    Disk *top;
    char name;
} Tower;

Tower *createTower(char name) {
    Tower *tower = (Tower *)malloc(sizeof(Tower));
    tower->top = NULL;
    tower->name = name;
    return tower;
}

Disk *createDisk(int size) {
    Disk *disk = (Disk *)malloc(sizeof(Disk));
    disk->size = size;
    disk->next = NULL;
    return disk;
}

void pushDisk(Tower *tower, Disk *disk) {
    disk->next = tower->top;
    tower->top = disk;
}

Disk *popDisk(Tower *tower) {
    if (tower->top == NULL) {
        return NULL;
    }
    Disk *removedDisk = tower->top;
    tower->top = tower->top->next;
    return removedDisk;
}

void printTower(Tower *tower) {
    printf("Tower %c: ", tower->name);
    Disk *current = tower->top;
    while (current != NULL) {
        printf("%d ", current->size);
        current = current->next;
    }
    printf("\n");
}

void moveDisk(Tower *from, Tower *to) {
    Disk *disk = popDisk(from);
    if (disk == NULL) {
        printf("Cannot move disk, tower %c is empty!\n", from->name);
        return;
    }
    pushDisk(to, disk);
    printf("Moved disk of size %d from tower %c to tower %c\n", disk->size, from->name, to->name);
}

void hanoi(int n, Tower *source, Tower *target, Tower *auxiliary) {
    if (n == 1) {
        moveDisk(source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    moveDisk(source, target);
    hanoi(n - 1, auxiliary, target, source);
}

void freeDisks(Disk *disk) {
    while (disk != NULL) {
        Disk *temp = disk;
        disk = disk->next;
        free(temp);
    }
}

void cleanupTowers(Tower *tower) {
    freeDisks(tower->top);
    free(tower);
}

int main() {
    printf("In the ruins of civilization, where hope clings like vines to a crumbling wall...\n");
    printf("You have three towers amidst the debris of forgotten times:\n");
    printf("Towers A, B, and C, where remnants of the past wait for resurrection.\n");

    Tower *towerA = createTower('A');
    Tower *towerB = createTower('B');
    Tower *towerC = createTower('C');

    // Initialize the first tower with disks
    for (int i = 5; i >= 1; i--) {
        pushDisk(towerA, createDisk(i)); // larger disk at the bottom
    }

    printf("Initial State:\n");
    printTower(towerA);
    printTower(towerB);
    printTower(towerC);
    printf("\n");

    // Solving the Tower of Hanoi problem
    printf("Moving the disks to Tower C...\n");
    hanoi(5, towerA, towerC, towerB);

    printf("\nFinal State:\n");
    printTower(towerA);
    printTower(towerB);
    printTower(towerC);

    cleanupTowers(towerA);
    cleanupTowers(towerB);
    cleanupTowers(towerC);
    
    printf("\nThe task is complete. In the ashes of the old world, a new order has emerged.\n");

    return 0;
}