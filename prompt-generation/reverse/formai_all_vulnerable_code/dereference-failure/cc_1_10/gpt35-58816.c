//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_LENGTH 100

/* Function to generate a random genome */
char* generateGenome() {
    char* genome = (char*)malloc(sizeof(char)*GENOME_LENGTH);
    int i;
    for(i=0; i<GENOME_LENGTH; i++) {
        int base = rand() % 4;
        switch(base) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
        }
    }
    return genome;
}

/* Function to print a genome */
void printGenome(char* genome) {
    int i;
    for(i=0; i<GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

/* Function to simulate sequencing */
void simulateSequencing(char* genome) {
    int i;
    for(i=0; i<GENOME_LENGTH; i++) {
        /* Introduce errors randomly */
        int error = rand() % 10;
        if(error == 0) {
            switch(genome[i]) {
                case 'A':
                    genome[i] = 'T';
                    break;
                case 'T':
                    genome[i] = 'A';
                    break;
                case 'C':
                    genome[i] = 'G';
                    break;
                case 'G':
                    genome[i] = 'C';
                    break;
            }
        }
    }
}

/* Main function */
int main() {
    srand(time(NULL));
    
    /* Generate a random genome */
    char* genome = generateGenome();
    printf("Original genome:\n");
    printGenome(genome);
    
    /* Simulate sequencing */
    simulateSequencing(genome);
    printf("Simulated sequencing:\n");
    printGenome(genome);
    
    return 0;
}