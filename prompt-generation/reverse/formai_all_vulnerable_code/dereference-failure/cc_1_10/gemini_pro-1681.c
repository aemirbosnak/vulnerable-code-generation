//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000

typedef struct {
    char *sequence;
    int length;
} Read;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random DNA sequence
    char *sequence = malloc(MAX_READ_LENGTH * sizeof(char));
    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        int base = rand() % 4;
        switch (base) {
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

    // Generate a list of reads from the sequence
    Read *reads = malloc(MAX_NUM_READS * sizeof(Read));
    for (int i = 0; i < MAX_NUM_READS; i++) {
        // Generate a random read length
        int read_length = rand() % MAX_READ_LENGTH + 1;

        // Generate a random start position for the read
        int start_position = rand() % (MAX_READ_LENGTH - read_length + 1);

        // Create a new read
        Read read;
        read.sequence = malloc(read_length * sizeof(char));
        memcpy(read.sequence, sequence + start_position, read_length);
        read.length = read_length;

        // Add the read to the list of reads
        reads[i] = read;
    }

    // Print the reads to a file
    FILE *fp = fopen("reads.txt", "w");
    for (int i = 0; i < MAX_NUM_READS; i++) {
        fprintf(fp, "%s\n", reads[i].sequence);
    }
    fclose(fp);

    // Free the memory allocated for the sequence and reads
    free(sequence);
    for (int i = 0; i < MAX_NUM_READS; i++) {
        free(reads[i].sequence);
    }
    free(reads);

    return 0;
}