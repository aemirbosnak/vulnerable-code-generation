//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>

// Function to print the state of the towers
void printTowers(int n, char from_rod, char to_rod, char aux_rod, int towers[][3]) {
    printf("Current state of the towers:\n");
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (towers[i - 1][j] != 0) {
                printf("%d ", towers[i - 1][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("From: %c, To: %c, Aux: %c\n", from_rod, to_rod, aux_rod);
    printf("=======================\n");
}

// Function to move disks from one rod to another
void moveDisk(int towers[][3], char from_rod, char to_rod, int n) {
    if (!towers[n - 1][from_rod - 'A']) {
        printf("No disk to move from %c\n", from_rod);
        return;
    }

    int disk = towers[n - 1][from_rod - 'A'];
    towers[n - 1][from_rod - 'A'] = 0;
    towers[n][to_rod - 'A'] = disk;

    printf("Moved disk %d from %c to %c\n", disk, from_rod, to_rod);
    printTowers(n, from_rod, to_rod, 'C', towers);
}

// Recursive function to implement Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int towers[][3]) {
    if (n == 1) {
        moveDisk(towers, from_rod, to_rod, n);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, towers);
    moveDisk(towers, from_rod, to_rod, n);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, towers);
}

// Function to initialize towers
void initializeTowers(int towers[][3], int n) {
    for (int i = 0; i < n; i++) {
        towers[i][0] = n - i; // Starting all disks on Rod A
        towers[i][1] = 0;
        towers[i][2] = 0;
    }
}

int main() {
    int n = 3; // Number of disks
    int towers[3][3] = {0}; // 3 rods A, B, C initialized to 0

    printf("Welcome to the Tower of Hanoi Problem\n");
    printf("With %d disks:\n", n);
    
    // Initialize the towers
    initializeTowers(towers, n);
    
    // Print initial state
    printTowers(n, 'A', 'C', 'B', towers);
    
    // Start the recursive process
    towerOfHanoi(n, 'A', 'C', 'B', towers);
    
    printf("All disks have been moved from rod A to rod C!\n");
    return 0;
}