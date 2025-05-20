//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void tower_of_hanoi(int num_disks, int num_pegs, char** pegs) {
    if (num_disks == 0) {
        return;
    }
    if (num_pegs == 3) {
        tower_of_hanoi(num_disks - 1, num_pegs, pegs);
        printf("Move disk %d from peg %s to peg %s\n", num_disks, pegs[0], pegs[1]);
        tower_of_hanoi(num_disks - 1, num_pegs, pegs);
    } else if (num_pegs == 4) {
        tower_of_hanoi(num_disks - 1, num_pegs, pegs);
        printf("Move disk %d from peg %s to peg %s\n", num_disks, pegs[0], pegs[1]);
        tower_of_hanoi(num_disks - 1, num_pegs - 1, pegs + 1);
        printf("Move disk %d from peg %s to peg %s\n", num_disks, pegs[1], pegs[2]);
        tower_of_hanoi(num_disks - 1, num_pegs - 1, pegs + 1);
    } else if (num_pegs == 5) {
        tower_of_hanoi(num_disks - 1, num_pegs, pegs);
        printf("Move disk %d from peg %s to peg %s\n", num_disks, pegs[0], pegs[1]);
        tower_of_hanoi(num_disks - 1, num_pegs - 2, pegs + 1);
        printf("Move disk %d from peg %s to peg %s\n", num_disks, pegs[num_pegs - 2], pegs[num_pegs - 1]);
        tower_of_hanoi(num_disks - 1, num_pegs - 2, pegs + 1);
        printf("Move disk %d from peg %s to peg %s\n", num_disks, pegs[1], pegs[num_pegs - 1]);
        tower_of_hanoi(num_disks - 1, num_pegs - 2, pegs + 1);
    }
}

int main(void) {
    int num_disks, num_pegs;
    char** pegs;
    char shape;
    
    printf("Welcome to the shape shifting Tower of Hanoi program!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    printf("Enter the number of pegs (3, 4, or 5): ");
    scanf("%d", &num_pegs);
    printf("Enter the shape of the pegs (A, B, or C): ");
    scanf(" %c", &shape);
    
    pegs = (char**) malloc(sizeof(char*) * num_pegs);
    for (int i = 0; i < num_pegs; i++) {
        pegs[i] = (char*) malloc(sizeof(char) * 2);
        pegs[i][0] = shape;
        pegs[i][1] = i + 49;
    }
    
    printf("The initial state of the pegs:\n");
    for (int i = 0; i < num_pegs; i++) {
        for (int j = 0; j < num_disks; j++) {
            if (j < num_disks - 1) {
                printf(" ");
            } else {
                printf("%s\n", pegs[i]);
            }
        }
    }
    
    tower_of_hanoi(num_disks, num_pegs, pegs);
    
    printf("The final state of the pegs:\n");
    for (int i = 0; i < num_pegs; i++) {
        for (int j = 0; j < num_disks; j++) {
            if (j < num_disks - 1) {
                printf(" ");
            } else {
                printf("%s\n", pegs[i]);
            }
        }
    }
    
    for (int i = 0; i < num_pegs; i++) {
        free(pegs[i]);
    }
    free(pegs);
    
    return 0;
}