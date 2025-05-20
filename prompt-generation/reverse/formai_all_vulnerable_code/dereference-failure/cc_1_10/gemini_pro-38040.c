//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024
#define MAX_READ_LENGTH 150
#define MAX_NUM_READS 100000

// Generate a random base between A, C, G, and T
char generate_base() {
    int rand_num = rand() % 4;
    switch (rand_num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N';
    }
}

// Generate a random read of length between 50 and 150 bases
char *generate_read() {
    int read_length = 50 + (rand() % 101);
    char *read = malloc(read_length + 1);
    for (int i = 0; i < read_length; i++) {
        read[i] = generate_base();
    }
    read[read_length] = '\0';
    return read;
}

// Generate a FASTA file containing simulated reads
void generate_fasta(char *filename, int num_reads) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < num_reads; i++) {
        char *read = generate_read();
        fprintf(fp, ">read%d\n%s\n", i, read);
        free(read);
    }

    fclose(fp);
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Generate a FASTA file containing 100,000 simulated reads
    generate_fasta("simulated_reads.fasta", MAX_NUM_READS);

    return 0;
}