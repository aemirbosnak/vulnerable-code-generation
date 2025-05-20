//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to display the rods
void displayRods(int n, char src, char dest, char aux, int *srcRod, int *destRod, int *auxRod) {
    printf("\nCurrent State of Rods:\n");
    for (int i = n; i >= 1; i--) {
        if (srcRod[i] > 0) {
            printf("Rod %c: Disk-%d ", src, srcRod[i]);
        } else {
            printf("Rod %c: Empty ", src);
        }

        if (destRod[i] > 0) {
            printf("Rod %c: Disk-%d ", dest, destRod[i]);
        } else {
            printf("Rod %c: Empty ", dest);
        }

        if (auxRod[i] > 0) {
            printf("Rod %c: Disk-%d ", aux, auxRod[i]);
        } else {
            printf("Rod %c: Empty ", aux);
        }

        printf("\n");
    }
    usleep(500000); // pause for half a second for aesthetics
}

// Function to move a disk from one rod to another
void moveDisk(char fromRod, char toRod, int *from, int *to) {
    int disk = from[0];
    from[0]--;
    to[++(to[0])] = disk;
    printf("Moving Disk-%d from Rod %c to Rod %c...\n", disk, fromRod, toRod);
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char src, char dest, char aux, int *srcRod, int *destRod, int *auxRod) {
    if (n == 1) {
        moveDisk(src, dest, srcRod, destRod);
        displayRods(5, src, dest, aux, srcRod, destRod, auxRod);
        return;
    }
    
    towerOfHanoi(n - 1, src, aux, dest, srcRod, auxRod, destRod);
    moveDisk(src, dest, srcRod, destRod);
    displayRods(5, src, dest, aux, srcRod, destRod, auxRod);
    towerOfHanoi(n - 1, aux, dest, src, auxRod, destRod, srcRod);
}

// Function to initialize rods and start the process
void initializeRods(int n, char src, char dest, char aux) {
    int *srcRod = (int *)malloc((n + 1) * sizeof(int));
    int *destRod = (int *)malloc((n + 1) * sizeof(int));
    int *auxRod = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        srcRod[i] = 0;
        destRod[i] = 0;
        auxRod[i] = 0;
    }

    for (int i = n; i >= 1; i--) {
        srcRod[++(srcRod[0])] = i; // Init source rod
    }

    printf("Initialized Tower of Hanoi with %d disks.\n\n", n);
    displayRods(n, src, dest, aux, srcRod, destRod, auxRod);
    
    towerOfHanoi(n, src, dest, aux, srcRod, destRod, auxRod);

    free(srcRod);
    free(destRod);
    free(auxRod);
    printf("\nAll disks successfully moved to Rod %c!\n", dest);
}

int main() {
    // Set the number of disks
    int numDisks = 5;
    char source = 'A', destination = 'C', auxiliary = 'B';

    printf("Welcome to the Futuristic Tower of Hanoi!\n");
    printf("This program simulates the movement of disks.\n");
    initializeRods(numDisks, source, destination, auxiliary);

    return 0;
}