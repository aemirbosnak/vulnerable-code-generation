//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random DNA sequences */
char* generate_sequence(int length) {
    char* sequence = malloc(length * sizeof(char));
    srand(time(NULL));
    int i;
    for(i = 0; i < length; i++) {
        int random_num = rand() % 4;
        switch(random_num) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'T';
                break;
            case 2:
                sequence[i] = 'C';
                break;
            case 3:
                sequence[i] = 'G';
                break;
        }
    }
    return sequence;
}

/* Function to simulate the sequencing process */
char* simulate_sequencing(char* sequence, int seq_length, float error_rate) {
    char* results = malloc(seq_length * sizeof(char));
    srand(time(NULL));
    int i;
    for(i = 0; i < seq_length; i++) {
        float random_num = rand() / (float)RAND_MAX;
        if(random_num <= error_rate) {
            int random_base = rand() % 3;
            if(sequence[i] == 'A') {
                switch(random_base) {
                    case 0:
                        results[i] = 'T';
                        break;
                    case 1:
                        results[i] = 'C';
                        break;
                    case 2:
                        results[i] = 'G';
                        break;
                }
            } else if(sequence[i] == 'T') {
                switch(random_base) {
                    case 0:
                        results[i] = 'A';
                        break;
                    case 1:
                        results[i] = 'C';
                        break;
                    case 2:
                        results[i] = 'G';
                        break;
                }
            } else if(sequence[i] == 'C') {
                switch(random_base) {
                    case 0:
                        results[i] = 'A';
                        break;
                    case 1:
                        results[i] = 'T';
                        break;
                    case 2:
                        results[i] = 'G';
                        break;
                }
            } else {
                switch(random_base) {
                    case 0:
                        results[i] = 'A';
                        break;
                    case 1:
                        results[i] = 'T';
                        break;
                    case 2:
                        results[i] = 'C';
                        break;
                }
            }
        } else {
            results[i] = sequence[i];
        }
    }
    return results;
}

/* Main function */
int main() {
    int sequence_length = 100;
    char* dna_sequence = generate_sequence(sequence_length);
    float error_probability = 0.1;
    char* sequenced_dna = simulate_sequencing(dna_sequence, sequence_length, error_probability);
    printf("Original DNA Sequence: %s \n", dna_sequence);
    printf("Sequenced DNA Sequence: %s \n", sequenced_dna);
    free(dna_sequence);
    free(sequenced_dna);
    return 0;
}