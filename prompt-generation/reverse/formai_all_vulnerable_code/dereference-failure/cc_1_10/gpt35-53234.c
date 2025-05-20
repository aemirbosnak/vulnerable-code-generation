//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define READ_LENGTH 100
#define DNA_LENGTH 1000

char nucleotides[] = {'A', 'C', 'G', 'T'};

char generate_random_nucleotide() {
    return nucleotides[rand() % 4];
}

char * generate_random_dna_sequence() {
    char * sequence = malloc(DNA_LENGTH + 1);
    for (int i = 0; i < DNA_LENGTH; i++) {
        sequence[i] = generate_random_nucleotide();
    }
    sequence[DNA_LENGTH] = '\0';
    return sequence;
}

char ** simulate_reads(char * sequence, int num_reads) {
    char ** reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        int start_index = rand() % (DNA_LENGTH - READ_LENGTH + 1);
        reads[i] = malloc(READ_LENGTH + 1);
        strncpy(reads[i], sequence + start_index, READ_LENGTH);
        reads[i][READ_LENGTH] = '\0';
    }
    return reads;
}

int main() {
    srand(time(NULL));
    char * sequence = generate_random_dna_sequence();
    printf("Generated DNA sequence: %s\n\n", sequence);
    
    int num_reads;
    printf("Enter the number of reads to simulate: ");
    scanf("%d", &num_reads);
    
    char ** reads = simulate_reads(sequence, num_reads);
    printf("\nSimulated reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("%d. %s\n", i + 1, reads[i]);
    }
    
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
    free(sequence);
    
    return 0;
}