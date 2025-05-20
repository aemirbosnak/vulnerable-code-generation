//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define NUM_SEQUENCES 10
#define SEQUENCE_LENGTH 100

typedef struct {
    char *sequence;
} Genome;

Genome *create_genomes(int num_genomes) {
    Genome *genomes = (Genome *)malloc(sizeof(Genome) * num_genomes);
    for (int i = 0; i < num_genomes; i++) {
        genomes[i].sequence = (char *)malloc(sizeof(char) * (MAX_GENOME_LENGTH + 1));
    }
    return genomes;
}

void free_genomes(Genome *genomes, int num_genomes) {
    for (int i = 0; i < num_genomes; i++) {
        free(genomes[i].sequence);
    }
    free(genomes);
}

void generate_random_sequence(char *sequence, int length) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null terminate the string
}

void simulate_genome_sequencing(Genome *genomes, int num_genomes, int sequence_length) {
    for (int i = 0; i < num_genomes; i++) {
        generate_random_sequence(genomes[i].sequence, sequence_length);
    }
}

void print_genomes(Genome *genomes, int num_genomes) {
    for (int i = 0; i < num_genomes; i++) {
        printf("Genome %d: %s\n", i + 1, genomes[i].sequence);
    }
}

void write_genomes_to_file(Genome *genomes, int num_genomes, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < num_genomes; i++) {
        fprintf(file, ">Genome_%d\n%s\n", i + 1, genomes[i].sequence);
    }
    fclose(file);
}

void mutate_genome(Genome *genome, int mutation_rate) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (rand() % 100 < mutation_rate) {
            // Randomly mutate the nucleotide
            const char *nucleotides = "ACGT";
            genome->sequence[i] = nucleotides[rand() % 4];
        }
    }
}

void simulate_mutation(Genome *genomes, int num_genomes, int mutation_rate) {
    for (int i = 0; i < num_genomes; i++) {
        mutate_genome(&genomes[i], mutation_rate);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    
    int num_genomes = NUM_SEQUENCES;
    Genome *genomes = create_genomes(num_genomes);

    // Simulate genome sequencing
    simulate_genome_sequencing(genomes, num_genomes, SEQUENCE_LENGTH);
    printf("Original Genomes:\n");
    print_genomes(genomes, num_genomes);

    // Simulate mutations
    int mutation_rate = 10; // 10% mutation rate
    simulate_mutation(genomes, num_genomes, mutation_rate);
    printf("\nGenomes After Mutation:\n");
    print_genomes(genomes, num_genomes);

    // Write to file
    write_genomes_to_file(genomes, num_genomes, "genomes.txt");

    // Free allocated memory
    free_genomes(genomes, num_genomes);

    return 0;
}