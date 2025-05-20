//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define READ_SIZE 1000
#define DEFAULT_LENGTH 1000

// Sample DNA letters
char dna_letters[] = {'A', 'C', 'G', 'T'};

// Function to generate a random DNA sequence of a given length
char* generate_sequence(int length) {
    char* sequence = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++) {
        int index = rand() % 4;
        sequence[i] = dna_letters[index];
    }
    return sequence;
}

// Function to simulate the sequencing process
void simulate_sequencing(char* sequence, int length) {
    char* read = malloc(sizeof(char) * READ_SIZE);
    int position = 0;

    while (position < length) {
        // Read a chunk of the sequence
        int chunk_size = rand() % READ_SIZE + 1;
        if (position + chunk_size > length) {
            chunk_size = length - position;
        }
        for (int i = 0; i < chunk_size; i++) {
            read[i] = sequence[position + i];
        }
        read[chunk_size] = '\0';
        
        // Print out the read and its position
        printf("Read from position %d:\n", position);
        printf("%s\n\n", read);
        
        // Move on to the next chunk
        position += chunk_size;
    }
    free(read);
}

int main() {
    srand(time(NULL));
    int length = DEFAULT_LENGTH;

    // Generate a random DNA sequence
    char* sequence = generate_sequence(length);
    printf("Generated sequence:\n%s\n\n", sequence);

    // Simulate the sequencing process
    simulate_sequencing(sequence, length);
    free(sequence);

    return 0;
}