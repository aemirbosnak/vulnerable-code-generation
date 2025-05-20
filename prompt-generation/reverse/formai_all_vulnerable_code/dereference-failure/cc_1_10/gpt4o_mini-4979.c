//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int numDisks, int* source, int* destination, int* auxiliary) {
    printf("Current State of Towers:\n");
    printf("Source: ");
    for (int i = numDisks - 1; i >= 0; i--) {
        if (source[i] != 0) {
            printf("%d ", source[i]);
        }
    }
    printf("\nDestination: ");
    for (int i = numDisks - 1; i >= 0; i--) {
        if (destination[i] != 0) {
            printf("%d ", destination[i]);
        }
    }
    printf("\nAuxiliary: ");
    for (int i = numDisks - 1; i >= 0; i--) {
        if (auxiliary[i] != 0) {
            printf("%d ", auxiliary[i]);
        }
    }
    printf("\n\n");
}

// Function to move the disks
void moveDisk(int* source, int* destination, int disk, int numDisks) {
    int sourceIndex = numDisks - 1, destinationIndex = numDisks - 1;

    // Find the top disk on the source
    while (sourceIndex >= 0 && source[sourceIndex] != disk) {
        sourceIndex--;
    }

    // Find the position to place the disk on the destination
    while (destinationIndex >= 0 && destination[destinationIndex] != 0) {
        destinationIndex--;
    }

    // Move the disk from source to destination
    if (sourceIndex >= 0 && destinationIndex >= 0) {
        destination[destinationIndex] = source[sourceIndex];
        source[sourceIndex] = 0;
    }
}

// Recursive function to solve the Tower of Hanoi
void towerOfHanoi(int numDisks, int* source, int* destination, int* auxiliary) {
    if (numDisks == 0) return;

    // Move top n-1 disks from source to auxiliary
    towerOfHanoi(numDisks - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    moveDisk(source, destination, numDisks, numDisks);
    printTowers(numDisks, source, destination, auxiliary);

    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(numDisks - 1, auxiliary, destination, source);
}

// Main function to initiate the Tower of Hanoi problem
int main() {
    int numDisks = 4; // Number of disks for this example
    int* source = (int*) calloc(numDisks, sizeof(int));
    int* destination = (int*) calloc(numDisks, sizeof(int));
    int* auxiliary = (int*) calloc(numDisks, sizeof(int));

    // Initialize the source tower with disks
    for (int i = 0; i < numDisks; i++) {
        source[i] = i + 1; // Assign disks numbered 1 to numDisks
    }

    printf("Starting the Tower of Hanoi with %d disks...\n", numDisks);
    printTowers(numDisks, source, destination, auxiliary);

    // Solve the Tower of Hanoi
    towerOfHanoi(numDisks, source, destination, auxiliary);

    // Free the allocated memory
    free(source);
    free(destination);
    free(auxiliary);

    printf("Tower of Hanoi has been successfully solved!\n");
    return 0;
}