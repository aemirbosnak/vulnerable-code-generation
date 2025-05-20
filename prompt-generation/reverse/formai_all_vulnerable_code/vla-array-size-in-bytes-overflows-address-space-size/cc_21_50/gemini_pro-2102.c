//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create the towers.
    int tower1[n], tower2[n], tower3[n];
    for (int i = 0; i < n; i++) {
        tower1[i] = n - i;
    }

    // Print the initial state of the towers.
    printf("Initial state of the towers:\n");
    printf("Tower 1: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower1[i]);
    }
    printf("\n");
    printf("Tower 2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower2[i]);
    }
    printf("\n");
    printf("Tower 3: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower3[i]);
    }
    printf("\n");

    // Solve the Tower of Hanoi problem.
    int num_moves = pow(2, n) - 1;
    for (int i = 0; i < num_moves; i++) {
        // Find the smallest disk that can be moved.
        int smallest_disk = n;
        for (int j = 0; j < n; j++) {
            if (tower1[j] != 0 && tower1[j] < smallest_disk) {
                smallest_disk = tower1[j];
            }
            if (tower2[j] != 0 && tower2[j] < smallest_disk) {
                smallest_disk = tower2[j];
            }
            if (tower3[j] != 0 && tower3[j] < smallest_disk) {
                smallest_disk = tower3[j];
            }
        }

        // Move the smallest disk from one tower to another.
        int source_tower = -1;
        int destination_tower = -1;
        for (int j = 0; j < n; j++) {
            if (tower1[j] == smallest_disk) {
                source_tower = 1;
                if (tower2[j] == 0) {
                    destination_tower = 2;
                } else if (tower3[j] == 0) {
                    destination_tower = 3;
                }
                break;
            }
            if (tower2[j] == smallest_disk) {
                source_tower = 2;
                if (tower1[j] == 0) {
                    destination_tower = 1;
                } else if (tower3[j] == 0) {
                    destination_tower = 3;
                }
                break;
            }
            if (tower3[j] == smallest_disk) {
                source_tower = 3;
                if (tower1[j] == 0) {
                    destination_tower = 1;
                } else if (tower2[j] == 0) {
                    destination_tower = 2;
                }
                break;
            }
        }

        switch (source_tower) {
            case 1:
                tower1[smallest_disk - 1] = 0;
                break;
            case 2:
                tower2[smallest_disk - 1] = 0;
                break;
            case 3:
                tower3[smallest_disk - 1] = 0;
                break;
        }

        switch (destination_tower) {
            case 1:
                tower1[n - smallest_disk] = smallest_disk;
                break;
            case 2:
                tower2[n - smallest_disk] = smallest_disk;
                break;
            case 3:
                tower3[n - smallest_disk] = smallest_disk;
                break;
        }

        // Print the current state of the towers.
        printf("Current state of the towers:\n");
        printf("Tower 1: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", tower1[j]);
        }
        printf("\n");
        printf("Tower 2: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", tower2[j]);
        }
        printf("\n");
        printf("Tower 3: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", tower3[j]);
        }
        printf("\n");
    }

    return 0;
}