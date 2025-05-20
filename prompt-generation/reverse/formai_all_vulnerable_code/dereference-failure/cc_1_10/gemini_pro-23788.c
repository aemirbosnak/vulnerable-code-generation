//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nucleotide sequence
char *sequence;

// Read sequence from file
void read_sequence(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    sequence = malloc(size + 1);
    fread(sequence, 1, size, fp);
    sequence[size] = '\0';
    fclose(fp);
}

// Generate random sequence
void generate_random_sequence(int length) {
    sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int rand_num = rand() % 4;
        switch (rand_num) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
    sequence[length] = '\0';
}

// Print sequence
void print_sequence() {
    printf("%s\n", sequence);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Read sequence from file
    read_sequence(argv[1]);

    // Print sequence
    print_sequence();

    // Free memory
    free(sequence);

    return 0;
}