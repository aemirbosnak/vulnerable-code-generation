//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000

// Function to generate a random DNA sequence
void generate_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

// Function to generate a random DNA read
void generate_read(char* read, int length) {
    for (int i = 0; i < length; i++) {
        read[i] = 'A' + rand() % 4;
    }
    read[length] = '\0';
}

// Function to print a DNA sequence
void print_sequence(char* sequence) {
    printf("%s\n", sequence);
}

// Function to print a DNA read
void print_read(char* read) {
    printf("%s\n", read);
}

// Function to compare two DNA sequences
int compare_sequences(char* seq1, char* seq2) {
    int length = strlen(seq1);
    int matches = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            matches++;
        }
    }
    return matches;
}

// Function to simulate genome sequencing
int main() {
    srand(time(NULL));

    char* genome_sequence = (char*) malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    generate_sequence(genome_sequence, MAX_SEQUENCE_LENGTH);

    int num_reads = rand() % MAX_NUM_READS + 1;
    char** read_sequences = (char**) malloc(num_reads * sizeof(char*));
    for (int i = 0; i < num_reads; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        char* read_sequence = (char*) malloc(read_length * sizeof(char));
        generate_read(read_sequence, read_length);
        read_sequences[i] = read_sequence;
    }

    for (int i = 0; i < num_reads; i++) {
        int matches = 0;
        for (int j = 0; j < MAX_SEQUENCE_LENGTH - read_sequences[i][0] + 1; j++) {
            matches += compare_sequences(genome_sequence + j, read_sequences[i]);
        }
        printf("Read %d matches the genome sequence %d times.\n", i + 1, matches);
    }

    free(genome_sequence);
    for (int i = 0; i < num_reads; i++) {
        free(read_sequences[i]);
    }
    free(read_sequences);

    return 0;
}