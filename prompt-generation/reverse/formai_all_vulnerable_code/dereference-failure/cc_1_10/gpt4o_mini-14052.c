//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printTower(int n, char source, char target, char auxiliary) {
    printf("   Tower of Hanoi State: \n");
    printf("A | B | C\n");
    printf("---------\n");
    for (int i = n; i > 0; i--) {
        printf("%c | %c | %c\n", (i <= n ? source : ' '), (i <= n ? target : ' '), (i <= n ? auxiliary : ' '));
        printf("---------\n");
    }
}

void moveDisk(int disk, char source, char target) {
    printf("Move disk %d from %c to %c\n", disk, source, target);
}

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        moveDisk(n, source, target);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    moveDisk(n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}

void displayRules() {
    printf("Welcome to the Mysterious Tower of Hanoi!\n");
    printf("Rules of the Game:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.\n");
    printf("3. No larger disk may be placed on top of a smaller disk.\n");
    printf("Get ready to embark on a journey through the tower of colors and numbers!\n\n");
}

void clearScreen() {
    printf("\033[H\033[J");
}

int main(int argc, char *argv[]) {
    int numberOfDisks = 3;

    if (argc > 1) {
        numberOfDisks = atoi(argv[1]);
    }

    if (numberOfDisks <= 0) {
        printf("The number of disks should be a positive integer.\n");
        return 1;
    }

    clearScreen();
    displayRules();
    printf("Let's begin with %d disks!\n\n", numberOfDisks);
    
    sleep(2);
    clearScreen();

    printf("Initial Tower Configuration (empty):\n");
    printTower(numberOfDisks, 'A', 'B', 'C');
    sleep(2);
    
    printf("Now we shall perform the magical moves...\n\n");
    sleep(2);
    
    towerOfHanoi(numberOfDisks, 'A', 'C', 'B');
    
    printf("\nCongratulations! You've solved the Tower of Hanoi with %d disks!\n", numberOfDisks);
    return 0;
}