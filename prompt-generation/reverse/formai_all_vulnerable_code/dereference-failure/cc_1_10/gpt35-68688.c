//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define READ_LENGTH 50     // length of sequence read

// Function to generate random nucleotides
char generate_nucleotide() {
    int random_num = rand() % 4;
    switch(random_num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

// Function to generate random DNA sequence
char* generate_sequence(int length) {
    char* sequence = (char*) calloc(length, sizeof(char));
    for(int i=0; i<length; i++) {
        sequence[i] = generate_nucleotide();
    }
    return sequence;
}

// Function for simulating sequencing
char* simulate_seq(char* dna_seq, int num_reads) {
    int seq_len = strlen(dna_seq);
    char* sequence_reads = (char*) calloc(num_reads*READ_LENGTH, sizeof(char));
    for(int i=0; i<num_reads; i++) {
        int start_index = rand() % (seq_len - READ_LENGTH);
        for(int j=0; j<READ_LENGTH; j++) {
            sequence_reads[i*READ_LENGTH+j] = dna_seq[start_index+j];
        }
    }
    return sequence_reads;
}

int main() {
    srand(time(NULL));
    char* dna_sequence = generate_sequence(500);
    char* sequence_reads = simulate_seq(dna_sequence, 10);
    printf("Original DNA sequence: %s\n", dna_sequence);
    printf("Simulated sequence reads: \n");
    for(int i=0; i<10; i++) {
        for(int j=0; j<READ_LENGTH; j++) {
            printf("%c", sequence_reads[i*READ_LENGTH+j]);
        }
        printf("\n");
    }
    free(dna_sequence);
    free(sequence_reads);
    return 0;
}