//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_SEQ_PER_FILE 100
#define NUM_FILES 10

// Function to generate a random DNA sequence of specified length
char* generateSequence(int length) {
    char* sequence = (char*) malloc(length + 1);
    for(int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to write a sequence to a file
void writeSequenceToFile(FILE* file, char* sequence) {
    fprintf(file, ">Sequence %d\n%s\n", rand() % 1000000, sequence);
}

// Function to generate a fasta file with specified number of sequences
void generateFastaFile(char* filename, int numSequences, int maxSequenceLength) {
    FILE* file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    srand(time(NULL));

    for(int i = 0; i < numSequences; i++) {
        char* sequence = generateSequence(rand() % maxSequenceLength + 1);
        writeSequenceToFile(file, sequence);
    }

    fclose(file);
}

int main() {
    for(int i = 0; i < NUM_FILES; i++) {
        char filename[20];
        sprintf(filename, "file_%d.fasta", i);
        generateFastaFile(filename, rand() % 50 + 1, rand() % 1000 + 1);
    }

    return 0;
}