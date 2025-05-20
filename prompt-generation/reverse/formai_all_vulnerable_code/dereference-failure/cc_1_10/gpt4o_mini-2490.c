//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 100
#define MAX_GENOMES 10

char* generate_random_sequence(int length) {
    char* sequence = (char*)malloc(length + 1);
    const char nucleotides[] = "ACGT";
    
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    
    sequence[length] = '\0'; // Null-terminate the string
    return sequence;
}

void mutate_sequence(char* sequence, int mutations) {
    const char nucleotides[] = "ACGT";
    int length = strlen(sequence);
    
    for (int i = 0; i < mutations; i++) {
        int position = rand() % length; // Random position to mutate
        char new_nucleotide;
        
        // Ensure the new nucleotide isn't the same as the current nucleotide
        do {
            new_nucleotide = nucleotides[rand() % 4];
        } while (new_nucleotide == sequence[position]);
        
        sequence[position] = new_nucleotide; // Mutate the sequence
    }
}

int compare_sequences(const char* seq1, const char* seq2) {
    int differences = 0;
    int length = strlen(seq1);
    
    for (int i = 0; i < length; i++) {
        if (seq1[i] != seq2[i]) {
            differences++;
        }
    }
    
    return differences;
}

void print_genome_analysis(const char* original, const char* mutated) {
    int differences = compare_sequences(original, mutated);
    printf("Original sequence: %s\n", original);
    printf("Mutated sequence: %s\n", mutated);
    printf("Number of mutations: %d\n", differences);
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    char* genomes[MAX_GENOMES];
    
    // Generate random genomes
    for (int i = 0; i < MAX_GENOMES; i++) {
        genomes[i] = generate_random_sequence(SEQUENCE_LENGTH);
        printf("Genome %d: %s\n", i + 1, genomes[i]);
    }
    
    // Mutate genomes and analyze the first genome
    int mutations = 5; // Number of mutations to introduce
    char* mutated_genome = strdup(genomes[0]); // Copy original genome for mutation
    mutate_sequence(mutated_genome, mutations);
    
    // Perform analysis
    print_genome_analysis(genomes[0], mutated_genome);
    
    // Free allocated memory
    for (int i = 0; i < MAX_GENOMES; i++) {
        free(genomes[i]);
    }
    free(mutated_genome);
    
    return 0;
}