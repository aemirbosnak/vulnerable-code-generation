//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE_LEN 4
#define READ_LEN 50

// Function to generate a random sequence
char* generateSequence(int len) {
    char* sequence = (char*) malloc(len * sizeof(char));
    const char bases[] = {'A', 'C', 'G', 'T'};
    int i;
    for (i = 0; i < len; i++) {
        sequence[i] = bases[rand() % BASE_LEN];
    }
    return sequence;
}

// Function to generate a read from a sequence
char* generateRead(char* sequence, int len, int read_pos) {
    char* read = (char*) malloc(READ_LEN * sizeof(char));
    int i;
    for (i = 0; i < READ_LEN; i++) {
        if (read_pos + i < len) {
            read[i] = sequence[read_pos + i];
        } else {
            read[i] = 'N';
        }
    }
    return read;
}

int main() {
    srand((unsigned int) time(NULL));
    
    // Generate a random sequence of length 100
    char* sequence = generateSequence(100);
    
    // Print the sequence
    printf("Sequence: %s\n", sequence);
    
    // Generate and print 10 reads of length 50 from the sequence
    int i;
    for (i = 0; i < 10; i++) {
        int read_pos = rand() % 51;
        char* read = generateRead(sequence, 100, read_pos);
        printf("Read %d: %s\n", i + 1, read);
        free(read);
    }
    
    free(sequence);
    return 0;
}