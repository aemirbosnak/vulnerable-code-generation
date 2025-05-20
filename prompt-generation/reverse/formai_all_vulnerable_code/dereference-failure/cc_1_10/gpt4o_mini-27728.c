//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int top;
    int max_size;
} Tower;

// Function to create a tower of given size
Tower* createTower(int size) {
    Tower* tower = (Tower*)malloc(sizeof(Tower));
    tower->max_size = size;
    tower->top = -1;
    tower->stack = (int*)malloc(size * sizeof(int));
    return tower;
}

// Function to push a disk onto the tower
void push(Tower* tower, int disk) {
    if (tower->top >= tower->max_size - 1) {
        printf("Error: Tower is full!\n");
        return;
    }
    tower->stack[++(tower->top)] = disk;
}

// Function to pop a disk from the tower
int pop(Tower* tower) {
    if (tower->top < 0) {
        printf("Error: Tower is empty!\n");
        return -1;
    }
    return tower->stack[(tower->top)--];
}

// Function to get the top disk of the tower
int peek(Tower* tower) {
    if (tower->top < 0) {
        return -1;  // Indicate that the tower is empty
    }
    return tower->stack[tower->top];
}

// Function to perform the Tower of Hanoi operation
void towerOfHanoi(int n, Tower* source, Tower* auxiliary, Tower* destination) {
    if (n == 1) {
        int disk = pop(source);
        printf("Move disk %d from Tower %d to Tower %d\n", disk, source->max_size, destination->max_size);
        push(destination, disk);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    int disk = pop(source);
    printf("Move disk %d from Tower %d to Tower %d\n", disk, source->max_size, destination->max_size);
    push(destination, disk);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Function to display the contents of a tower
void displayTower(Tower* tower) {
    if (tower->top == -1) {
        printf("Tower is empty\n");
        return;
    }
    printf("Tower contents: ");
    for (int i = tower->top; i >= 0; i--) {
        printf("%d ", tower->stack[i]);
    }
    printf("\n");
}

int main() {
    int num_disks = 3;
    Tower* source = createTower(num_disks);
    Tower* auxiliary = createTower(num_disks);
    Tower* destination = createTower(num_disks);

    // Initialize the source tower with disks
    for (int i = num_disks; i >= 1; i--) {
        push(source, i);
    }

    printf("Initial state of Towers:\n");
    displayTower(source);
    displayTower(auxiliary);
    displayTower(destination);

    // Solve the Tower of Hanoi problem
    printf("\nSolving Tower of Hanoi problem:\n");
    towerOfHanoi(num_disks, source, auxiliary, destination);

    // Display final state of Towers
    printf("\nFinal state of Towers:\n");
    displayTower(source);
    displayTower(auxiliary);
    displayTower(destination);

    // Free allocated memory
    free(source->stack);
    free(auxiliary->stack);
    free(destination->stack);
    free(source);
    free(auxiliary);
    free(destination);

    return 0;
}