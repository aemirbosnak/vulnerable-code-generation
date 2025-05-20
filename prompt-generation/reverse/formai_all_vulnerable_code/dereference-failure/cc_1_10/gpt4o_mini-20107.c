//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
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

void push(Tower *tower, Disk *disk) {
    if (tower->top != NULL && tower->top->size <= disk->size) {
        printf("Error: Cannot place disk of size %d on top of disk size %d on tower %c\n", disk->size, tower->top->size, tower->name);
        return;
    }
    disk->next = tower->top;
    tower->top = disk;
    printf("Disk %d pushed to tower %c\n", disk->size, tower->name);
}

Disk *pop(Tower *tower) {
    if (tower->top == NULL) {
        printf("Error: Tower %c is empty\n", tower->name);
        return NULL;
    }
    Disk *disk = tower->top;
    tower->top = tower->top->next;
    printf("Disk %d popped from tower %c\n", disk->size, tower->name);
    return disk;
}

void moveDisk(Tower *source, Tower *destination) {
    Disk *disk = pop(source);
    if (disk != NULL) {
        push(destination, disk);
    }
}

void moveTower(int n, Tower *source, Tower *destination, Tower *auxiliary) {
    if (n == 1) {
        moveDisk(source, destination);
        return;
    }
    moveTower(n - 1, source, auxiliary, destination);
    moveDisk(source, destination);
    moveTower(n - 1, auxiliary, destination, source);
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

void clearTower(Tower *tower) {
    while (tower->top != NULL) {
        Disk *disk = pop(tower);
        free(disk);
    }
    free(tower);
}

int main() {
    int numDisks = 3; // Number of disks
    Tower *towerA = createTower('A');
    Tower *towerB = createTower('B');
    Tower *towerC = createTower('C');

    // Initialize the tower with disks
    for (int i = numDisks; i >= 1; i--) {
        Disk *disk = createDisk(i);
        push(towerA, disk);
    }

    printf("Initial state:\n");
    printTower(towerA);
    printTower(towerB);
    printTower(towerC);
    
    printf("\nMoving disks...\n");

    moveTower(numDisks, towerA, towerC, towerB);

    printf("\nFinal state:\n");
    printTower(towerA);
    printTower(towerB);
    printTower(towerC);

    // Cleanup
    clearTower(towerA);
    clearTower(towerB);
    clearTower(towerC);

    return 0;
}