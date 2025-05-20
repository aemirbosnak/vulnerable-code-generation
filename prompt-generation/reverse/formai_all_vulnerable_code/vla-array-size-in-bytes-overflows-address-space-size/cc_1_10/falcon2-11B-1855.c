//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks == 1) {
        printf("Move disk 1 from rod A to rod C.\n");
        return 0;
    }

    int disks[num_disks];
    int moves[num_disks][3];
    int num_moves;

    for (int i = 0; i < num_disks; i++) {
        disks[i] = i + 1;
    }

    printf("Initial configuration:\n");
    for (int i = 0; i < num_disks; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");

    num_moves = num_disks * (num_disks - 1) / 2;
    moves[0][0] = num_moves;
    moves[0][1] = 0;
    moves[0][2] = 0;

    for (int i = 1; i < num_disks - 1; i++) {
        moves[i][0] = moves[i - 1][1];
        moves[i][1] = moves[i - 1][0];
        moves[i][2] = moves[i - 1][2];

        moves[i][0] += disks[i];
        moves[i][2] += disks[i];
    }

    moves[num_disks - 1][0] = moves[num_disks - 2][1];
    moves[num_disks - 1][1] = moves[num_disks - 2][0];
    moves[num_disks - 1][2] = moves[num_disks - 2][2];

    printf("\nSolution:\n");
    for (int i = 0; i < num_disks; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");

    printf("Total number of moves: %d\n", moves[num_disks - 1][0]);

    return 0;
}