//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random base
char random_base() {
    int rand_num = rand() % 4;
    char base;
    switch(rand_num) {
        case 0:
            base = 'A';
            break;
        case 1:
            base = 'C';
            break;
        case 2:
            base = 'G';
            break;
        case 3:
            base = 'T';
            break;
    }
    return base;
}

int main() {
    // Set seed for random number generator
    srand(time(NULL));
    
    // Declare variables
    int num_bases;
    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("How many bases would you like to generate?\n");
    scanf("%d", &num_bases);
    
    // Generate random sequence of bases
    printf("Generating random base sequence...\n");
    char *seq = malloc(num_bases * sizeof(char));
    int i;
    for(i = 0; i < num_bases; i++) {
        seq[i] = random_base();
    }
    
    // Output sequence
    printf("Generated sequence: ");
    for(i = 0; i < num_bases; i++) {
        printf("%c", seq[i]);
    }
    printf("\n");
    
    // Free memory
    free(seq);
    
    // End program
    printf("Thank you for using the Genome Sequencing Simulator!\n");
    return 0;
}