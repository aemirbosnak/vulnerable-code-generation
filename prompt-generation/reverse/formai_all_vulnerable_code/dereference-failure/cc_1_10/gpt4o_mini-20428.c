//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to hold the Tower of Hanoi information
typedef struct Tower {
    int id;             // Identifier of the tower
    int *disks;        // Array to hold disks on the tower
    int top;           // Index of the top disk
} Tower;

// Function to create a new tower with a given capacity
Tower createTower(int id, int n) {
    Tower t;
    t.id = id;
    t.disks = (int *)malloc(n * sizeof(int));
    t.top = -1;
    return t;
}

// Function to place a disk on the tower
void pushDisk(Tower *t, int disk) {
    t->disks[++(t->top)] = disk;
    printf("    A disk of size %d has been placed on Tower %d.\n", disk, t->id);
}

// Function to remove a disk from the tower
int popDisk(Tower *t) {
    if (t->top == -1) {
        printf("    Tower %d is empty, no disk to remove!\n", t->id);
        return -1;
    }
    int disk = t->disks[(t->top)--];
    printf("    A disk of size %d has been removed from Tower %d.\n", disk, t->id);
    return disk;
}

// Recursive function to solve the Tower of Hanoi problem
void solveHanoi(int n, Tower *source, Tower *target, Tower *auxiliary) {
    if (n == 1) {
        int disk = popDisk(source);
        pushDisk(target, disk);
        return;
    }
    
    // Move n-1 disks from source to auxiliary using target as auxiliary
    solveHanoi(n - 1, source, auxiliary, target);
    
    // Move the nth disk from source to target
    int disk = popDisk(source);
    pushDisk(target, disk);
    
    // Move the n-1 disks from auxiliary to target using source as auxiliary
    solveHanoi(n - 1, auxiliary, target, source);
}

// Function to print the state of the towers
void printTowers(Tower *towers, int num_towers) {
    printf("\nThe state of the towers is as follows:\n");
    for (int i = 0; i < num_towers; i++) {
        printf("  Tower %d: ", towers[i].id);
        if (towers[i].top == -1) {
            printf("empty\n");
        } else {
            for (int j = 0; j <= towers[i].top; j++) {
                printf("%d ", towers[i].disks[j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

// The main function to orchestrate the creation and solving of the problem
int main() {
    int num_disks;
    printf("Enter the number of disks for the grand task of the Tower of Hanoi: ");
    scanf("%d", &num_disks);

    // Create towers
    Tower towers[3];
    towers[0] = createTower(1, num_disks);
    towers[1] = createTower(2, num_disks);
    towers[2] = createTower(3, num_disks);

    // Initially place disks on the first tower
    for (int i = num_disks; i >= 1; i--) {
        pushDisk(&towers[0], i);
    }

    // Print initial state
    printTowers(towers, 3);

    // Begin the legendary move of disks
    printf("Commencing the ancient and noble task of moving the disks!\n");
    solveHanoi(num_disks, &towers[0], &towers[2], &towers[1]);

    // Print final state
    printTowers(towers, 3);

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(towers[i].disks);
    }

    return 0;
}