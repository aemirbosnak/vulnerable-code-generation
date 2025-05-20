//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void towerOfHanoi(int n, char source, char destination, char auxiliary);
int validateInput(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    int numDiscs;

    // Validate the command line input
    numDiscs = validateInput(argc, argv);
    if (numDiscs < 1) {
        fprintf(stderr, "Please provide a positive integer number of discs.\n");
        return EXIT_FAILURE;
    }

    // Solve the Tower of Hanoi
    printf("Solving Tower of Hanoi for %d discs:\n", numDiscs);
    towerOfHanoi(numDiscs, 'A', 'C', 'B'); // A, B and C are names of rods
    return EXIT_SUCCESS;
}

// Function to validate input command line arguments
int validateInput(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_discs>\n", argv[0]);
        return -1;
    }
    int num = atoi(argv[1]);
    if (num <= 0) {
        return -1; // Should be a positive integer
    }
    return num;
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If only one disc remains
    if (n == 1) {
        printf("Move disc 1 from rod %c to rod %c\n", source, destination);
        return;
    }
  
    // Move top n-1 discs from source to auxiliary, using destination as a temporary rod
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disc from source to destination
    printf("Move disc %d from rod %c to rod %c\n", n, source, destination);
  
    // Move the n-1 discs from auxiliary to destination, using source as a temporary rod
    towerOfHanoi(n - 1, auxiliary, destination, source);
}