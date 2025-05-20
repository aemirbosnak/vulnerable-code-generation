//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void moveDisks(int n, char from_peg, char to_peg, char aux_peg);
void validateInput(int argc, char *argv[]);
void printUsage(char *programName);

int main(int argc, char *argv[]) {
    // Validate the input
    validateInput(argc, argv);

    // Get number of disks from command line argument
    int n = atoi(argv[1]);
    
    // Perform the Tower of Hanoi algorithm
    printf("Solving Tower of Hanoi for %d disks:\n", n);
    moveDisks(n, 'A', 'C', 'B');  // A, B and C are the names of the rods

    return 0;
}

// Function to perform the Tower of Hanoi algorithm
void moveDisks(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
    moveDisks(n - 1, from_peg, aux_peg, to_peg);
    printf("Move disk %d from peg %c to peg %c\n", n, from_peg, to_peg);
    moveDisks(n - 1, aux_peg, to_peg, from_peg);
}

// Function to validate user input
void validateInput(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Error: Number of disks must be a positive integer.\n");
        printUsage(argv[0]);
        exit(EXIT_FAILURE);
    }
}

// Function to print the usage of the program
void printUsage(char *programName) {
    printf("Usage: %s <number_of_disks>\n", programName);
    printf("Example: %s 3\n", programName);
}