//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Shape shifting DNA sequence
    printf("Welcome to the Shape Shifting Genome Simulator\n\n");
    
    // Initialize the DNA sequence
    char *dna_sequence;
    dna_sequence = (char*) malloc(sizeof(char)*10);
    dna_sequence = "ATCGAAAAGC";
    int length = 10;

    printf("Original DNA sequence: %s\n", dna_sequence);
    printf("Length of sequence: %d\n\n", length);

    // Mutation probability
    float mutation_prob = 0.2;
    printf("Mutation Probability: %f\n\n", mutation_prob);

    // Generate random mutations
    int num_mutations = 0;
    for(int i=0; i<length; i++){
        float r = (float) rand() / (float) RAND_MAX;
        if(r < mutation_prob){
            num_mutations++;
            dna_sequence[i] = rand() % 4 + 'A';
        }
    }

    // Print mutated DNA sequence
    printf("Mutated DNA sequence: %s\n", dna_sequence);
    printf("Number of mutations: %d\n\n", num_mutations);

    // Reverse the DNA sequence
    char *reverse_seq;
    reverse_seq = (char*) malloc(sizeof(char)*10);
    for(int i=0; i<length; i++){
        reverse_seq[length-i-1] = dna_sequence[i];
    }

    // Print reverse DNA sequence
    printf("Reverse DNA sequence: %s\n\n", reverse_seq);

    // Complement the DNA sequence
    char *complement_seq;
    complement_seq = (char*) malloc(sizeof(char)*10);
    for(int i=0; i<length; i++){
        if(dna_sequence[i] == 'A')
            complement_seq[i] = 'T';
        else if(dna_sequence[i] == 'T')
            complement_seq[i] = 'A';
        else if(dna_sequence[i] == 'C')
            complement_seq[i] = 'G';
        else if(dna_sequence[i] == 'G')
            complement_seq[i] = 'C';
    }

    // Print complement DNA sequence
    printf("Complement DNA sequence: %s\n\n", complement_seq);

    // Exit program
    free(dna_sequence);
    free(reverse_seq);
    free(complement_seq);
    return 0;
}