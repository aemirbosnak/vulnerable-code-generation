//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_DISKS 4

// Defining the tower structure
struct Tower {
    int numDisks;
    int *diskSizes;
};

// Function to create and initialize the towers
struct Tower* initializeTower(int numDisks) {
    struct Tower *t = (struct Tower*) malloc(sizeof(struct Tower)); 
    t->numDisks = numDisks;
    t->diskSizes = (int*) malloc(sizeof(int)*numDisks);

    for(int i = 0; i<numDisks; i++) {
        t->diskSizes[i] = numDisks - i;
    }

    return t;
}

// Function to print the towers
void printTowers(struct Tower *t1, struct Tower *t2, struct Tower *t3) {
    printf("\n\n");

    for(int i = 0; i < NUM_DISKS; i++) {
        // Printing the disks in Tower 1
        if(i < t1->numDisks) {
            printf("|");

            for(int j = t1->diskSizes[i]; j>0; j--) {
                printf(" ");
            }

            for(int j = t1->diskSizes[i]; j<NUM_DISKS; j++) {
                printf("-");
            }

            for(int j = t1->diskSizes[i]; j>0; j--) {
                printf(" ");
            }

            printf("|");
        }
        else {
            for(int j = 0; j<NUM_DISKS+2; j++) {
                printf(" ");
            }
        }

        // Printing the disks in Tower 2
        if(i < t2->numDisks) {
            printf("|");

            for(int j = t2->diskSizes[i]; j>0; j--) {
                printf(" ");
            }

            for(int j = t2->diskSizes[i]; j<NUM_DISKS; j++) {
                printf("-");
            }

            for(int j = t2->diskSizes[i]; j>0; j--) {
                printf(" ");
            }

            printf("|");
        }
        else {
            for(int j = 0; j<NUM_DISKS+2; j++) {
                printf(" ");
            }
        }

        // Printing the disks in Tower 3
        if(i < t3->numDisks) {
            printf("|");

            for(int j = t3->diskSizes[i]; j>0; j--) {
                printf(" ");
            }

            for(int j = t3->diskSizes[i]; j<NUM_DISKS; j++) {
                printf("-");
            }

            for(int j = t3->diskSizes[i]; j>0; j--) {
                printf(" ");
            }

            printf("|");
        }
        else {
            for(int j = 0; j<NUM_DISKS+2; j++) {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n1");

    for(int j = 0; j<NUM_DISKS+1; j++) {
        printf(" ");
    }

    printf("2");

    for(int j = 0; j<NUM_DISKS+1; j++) {
        printf(" ");
    }

    printf("3\n\n");
}

// Function to move the disks
void moveDisk(struct Tower *from, struct Tower *to) {
    int topFrom = from->diskSizes[from->numDisks-1];
    int topTo;

    if(to->numDisks == 0) {
        topTo = NUM_DISKS+1;
    }
    else {
        topTo = to->diskSizes[to->numDisks-1];
    }

    if(topFrom < topTo) {
        to->diskSizes[to->numDisks] = from->diskSizes[from->numDisks-1];
        to->numDisks++;
        from->numDisks--;
    }
}

// Function to recursively solve the Tower of Hanoi problem
void solveHanoi(int numDisks, struct Tower *source, struct Tower *destination, struct Tower *auxiliary) {
    if(numDisks == 1) {
        moveDisk(source, destination);
        printTowers(source, destination, auxiliary);
    }
    else {
        solveHanoi(numDisks-1, source, auxiliary, destination);
        moveDisk(source, destination);
        printTowers(source, destination, auxiliary);
        solveHanoi(numDisks-1, auxiliary, destination, source);
    }
}

int main() {
    struct Tower *tower1 = initializeTower(NUM_DISKS);
    struct Tower *tower2 = (struct Tower*) malloc(sizeof(struct Tower));
    tower2->numDisks = 0;
    tower2->diskSizes = (int*) malloc(sizeof(int)*NUM_DISKS);

    struct Tower *tower3 = (struct Tower*) malloc(sizeof(struct Tower));
    tower3->numDisks = 0;
    tower3->diskSizes = (int*) malloc(sizeof(int)*NUM_DISKS);

    printf("\n\nInitial Configuration:\n");
    printTowers(tower1, tower2, tower3);

    solveHanoi(NUM_DISKS, tower1, tower3, tower2);

    printf("Tower of Hanoi solved.\n");

    return 0;
}