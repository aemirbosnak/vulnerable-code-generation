//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DISKS 10

typedef struct {
    int id;
    int num_disks;
    int towers[3][MAX_DISKS];
} TowerOfHanoi;

void initializeHanoi(TowerOfHanoi *hanoi, int num_disks) {
    hanoi->id = rand() % 1000; // Unique ID for the Tower of Hanoi instance
    hanoi->num_disks = num_disks;

    // Initialize tower 0 with disks
    for (int i = 0; i < num_disks; i++) {
        hanoi->towers[0][i] = num_disks - i; // Larger disks are at the bottom
        hanoi->towers[1][i] = 0; // Empty tower 1
        hanoi->towers[2][i] = 0; // Empty tower 2
    }
}

void printTowers(TowerOfHanoi *hanoi) {
    printf("=== Tower of Hanoi ID: %d ===\n", hanoi->id);
    for (int i = 0; i < hanoi->num_disks; i++) {
        printf("Disk %d: [%d | %d | %d]\n", i + 1, hanoi->towers[0][i], hanoi->towers[1][i], hanoi->towers[2][i]);
    }
    printf("=============================\n");
}

void moveDisk(TowerOfHanoi *hanoi, int from, int to) {
    for (int i = 0; i < hanoi->num_disks; i++) {
        if (hanoi->towers[from][i] != 0) {
            // Move the top disk from 'from' tower to 'to' tower
            for (int j = 0; j < hanoi->num_disks; j++) {
                if (hanoi->towers[to][j] == 0) {
                    hanoi->towers[to][j] = hanoi->towers[from][i];
                    hanoi->towers[from][i] = 0;
                    return;
                }
            }
        }
    }
}

void solveHanoi(TowerOfHanoi *hanoi, int n, int from, int to, int aux) {
    if (n == 1) {
        moveDisk(hanoi, from, to);
        printTowers(hanoi);
        usleep(500000); // Wait for 0.5 seconds
    } else {
        solveHanoi(hanoi, n - 1, from, aux, to);
        moveDisk(hanoi, from, to);
        printTowers(hanoi);
        usleep(500000);
        solveHanoi(hanoi, n - 1, aux, to, from);
    }
}

int main() {
    srand(time(NULL)); // Seed for randomness
    
    int num_disks = 3; // Change this to increase the complexity
    if (num_disks > MAX_DISKS) {
        fprintf(stderr, "Error: Maximum number of disks is %d\n", MAX_DISKS);
        return EXIT_FAILURE;
    }

    TowerOfHanoi *hanoi = (TowerOfHanoi *)malloc(sizeof(TowerOfHanoi));
    initializeHanoi(hanoi, num_disks);
    
    printf("Starting the Cyberpunk Tower of Hanoi...\n");
    printTowers(hanoi);
    
    solveHanoi(hanoi, num_disks, 0, 2, 1);
    
    printf("Cyberpunk Tower of Hanoi completed successfully!\n");
    free(hanoi);
    return EXIT_SUCCESS;
}