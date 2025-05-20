//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a Tower
typedef struct Tower {
    int *disks;
    int top;
    int capacity;
} Tower;

// Function to create a Tower
Tower* createTower(int capacity) {
    Tower* tower = (Tower*) malloc(sizeof(Tower));
    tower->capacity = capacity;
    tower->top = -1;
    tower->disks = (int*) malloc(sizeof(int) * capacity);
    return tower;
}

// Function to check if the tower is full
bool isFull(Tower* tower) {
    return (tower->top == tower->capacity - 1);
}

// Function to check if the tower is empty
bool isEmpty(Tower* tower) {
    return (tower->top == -1);
}

// Function to add a disk to the tower
void push(Tower* tower, int disk) {
    if (isFull(tower)) {
        printf("Error: Tower is full\n");
        return;
    }
    tower->disks[++tower->top] = disk;
}

// Function to remove a disk from the tower
int pop(Tower* tower) {
    if (isEmpty(tower)) {
        printf("Error: Tower is empty\n");
        return -1;
    }
    return tower->disks[tower->top--];
}

// Function to display the Tower
void displayTower(Tower* tower) {
    printf("Tower: ");
    for (int i = tower->top; i >= 0; i--) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

// Recursive function to solve the Tower of Hanoi
void solveHanoi(int n, Tower* source, Tower* target, Tower* auxiliary) {
    if (n == 1) {
        int disk = pop(source);
        push(target, disk);
        printf("Move disk %d from Source to Target\n", disk);
        return;
    }
    solveHanoi(n - 1, source, auxiliary, target);
    int disk = pop(source);
    push(target, disk);
    printf("Move disk %d from Source to Target\n", disk);
    solveHanoi(n - 1, auxiliary, target, source);
}

// Function to cleanup and free memory for a Tower
void cleanupTower(Tower* tower) {
    free(tower->disks);
    free(tower);
}

int main() {
    int numDisks;

    printf("Welcome to the Tower of Hanoi Problem Solver!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Create towers
    Tower* source = createTower(numDisks);
    Tower* target = createTower(numDisks);
    Tower* auxiliary = createTower(numDisks);

    // Initialize the source tower with disks
    for (int i = numDisks; i >= 1; i--) {
        push(source, i);
    }

    printf("Initial state of towers:\n");
    displayTower(source);
    displayTower(target);
    displayTower(auxiliary);
    
    // Solve the Tower of Hanoi
    printf("Solving Tower of Hanoi...\n");
    solveHanoi(numDisks, source, target, auxiliary);
    
    printf("Final state of towers after solving:\n");
    displayTower(source);
    displayTower(target);
    displayTower(auxiliary);

    // Free allocated memory
    cleanupTower(source);
    cleanupTower(target);
    cleanupTower(auxiliary);

    printf("Tower of Hanoi solution completed!\n");
    return 0;
}