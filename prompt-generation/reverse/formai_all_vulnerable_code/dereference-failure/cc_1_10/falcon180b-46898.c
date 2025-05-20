//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000

int main() {
    char *sequence = (char *)malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    char *reads[NUM_READS];
    int read_lengths[NUM_READS];
    int i, j, k;
    FILE *fp;

    // Generate a random DNA sequence
    srand(time(NULL));
    for (i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[MAX_SEQUENCE_LENGTH - 1] = '\0';

    // Create the reads
    for (i = 0; i < NUM_READS; i++) {
        reads[i] = (char *)malloc(MAX_READ_LENGTH * sizeof(char));
        read_lengths[i] = rand() % MAX_READ_LENGTH + 1;
        for (j = 0; j < read_lengths[i]; j++) {
            reads[i][j] = sequence[rand() % MAX_SEQUENCE_LENGTH];
        }
        reads[i][read_lengths[i]] = '\0';
    }

    // Print the reads
    printf("Reads:\n");
    for (i = 0; i < NUM_READS; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }

    // Save the reads to a file
    fp = fopen("reads.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    for (i = 0; i < NUM_READS; i++) {
        fprintf(fp, ">Read %d\n%s\n", i + 1, reads[i]);
    }
    fclose(fp);

    // Clean up
    for (i = 0; i < NUM_READS; i++) {
        free(reads[i]);
    }
    free(sequence);

    return 0;
}