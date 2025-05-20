//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_DISKS 3

typedef struct Disk {
    int size;
    struct Disk* next;
} Disk;

typedef struct Tower {
    Disk* top;
    char name;
} Tower;

// Function prototypes
void initTower(Tower* tower, char name);
void push(Disk** top, int size);
int pop(Disk** top);
void printTower(Tower tower);
void moveDisks(int n, Tower* source, Tower* target, Tower* auxiliary);
void sleepForAWhile(int seconds);

int main() {
    Tower source, target, auxiliary;
    initTower(&source, 'A');
    initTower(&target, 'B');
    initTower(&auxiliary, 'C');

    // Pushing disks onto the source tower, in descending order
    for (int i = NUM_DISKS; i > 0; i--) {
        push(&source.top, i);
    }

    printf("Starting the surreal dance of the towers...\n");
    moveDisks(NUM_DISKS, &source, &target, &auxiliary);
    printf("The dance is now complete, a new order is born!\n");

    return 0;
}

// Initialize a tower
void initTower(Tower* tower, char name) {
    tower->top = NULL;
    tower->name = name;
}

// Push a disk onto the tower
void push(Disk** top, int size) {
    Disk* newDisk = (Disk*)malloc(sizeof(Disk));
    newDisk->size = size;
    newDisk->next = *top;
    *top = newDisk;
}

// Pop a disk from the tower
int pop(Disk** top) {
    if (*top == NULL) {
        printf("Attempted to pop from an empty tower!\n");
        exit(EXIT_FAILURE);
    }
    int diskSize = (*top)->size;
    Disk* temp = *top;
    *top = (*top)->next;
    free(temp);
    return diskSize;
}

// Print the tower's state
void printTower(Tower tower) {
    printf("Tower %c: ", tower.name);
    Disk* disk = tower.top;
    while (disk) {
        printf("%d ", disk->size);
        disk = disk->next;
    }
    printf("\n");
}

// Move disks according to the Tower of Hanoi rules
void moveDisks(int n, Tower* source, Tower* target, Tower* auxiliary) {
    if (n == 1) {
        int disk = pop(&source->top);
        push(&target->top, disk);
        printf("Moved disk %d from %c to %c\n", disk, source->name, target->name);
        printTower(*source);
        printTower(*target);
        printTower(*auxiliary);
        sleepForAWhile(1);
        return;
    }
    moveDisks(n - 1, source, auxiliary, target);
    moveDisks(1, source, target, auxiliary);
    moveDisks(n - 1, auxiliary, target, source);
}

// Sleep for a surreal amount of time
void sleepForAWhile(int seconds) {
    for (int i = 0; i < seconds; i++) {
        printf("In a dream-like pause… %d\n", i + 1);
        sleep(1);
    }
}