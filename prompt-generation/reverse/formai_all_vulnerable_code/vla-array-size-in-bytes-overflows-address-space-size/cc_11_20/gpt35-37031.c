//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LEN 1000 // maximum length of each genome sequence
#define MUTATION_RATE 0.1 // probability of a mutation occurring in each position of the genome sequence

int main() {
    // initialize random number generator
    srand(time(NULL));
    
    // obtain number of genome sequences to simulate
    int num_sequences;
    printf("Enter the number of genome sequences to simulate: ");
    scanf("%d", &num_sequences);
    
    // obtain length of each genome sequence
    int sequence_length;
    printf("Enter the length of each genome sequence: ");
    scanf("%d", &sequence_length);
    
    // generate genome sequences
    char sequences[num_sequences][MAX_SEQ_LEN];
    for (int i = 0; i < num_sequences; i++) {
        for (int j = 0; j < sequence_length; j++) {
            float random = ((float) rand() / (float) RAND_MAX);
            if (random < MUTATION_RATE) {
                // randomly select a mutation
                int mutation = rand() % 4;
                switch (mutation) {
                    case 0:
                        sequences[i][j] = 'A';
                        break;
                    case 1:
                        sequences[i][j] = 'C';
                        break;
                    case 2:
                        sequences[i][j] = 'G';
                        break;
                    case 3:
                        sequences[i][j] = 'T';
                        break;
                }
            } else {
                // randomly select a base
                int base = rand() % 4;
                switch (base) {
                    case 0:
                        sequences[i][j] = 'A';
                        break;
                    case 1:
                        sequences[i][j] = 'C';
                        break;
                    case 2:
                        sequences[i][j] = 'G';
                        break;
                    case 3:
                        sequences[i][j] = 'T';
                        break;
                }
            }
        }
    }
    
    // print genome sequences
    printf("Genome Sequences:\n");
    for (int i = 0; i < num_sequences; i++) {
        printf("%d: ", i+1);
        for (int j = 0; j < sequence_length; j++) {
            printf("%c", sequences[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}