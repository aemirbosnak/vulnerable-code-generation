//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 100
#define NUM_GENOMES 5

typedef struct {
    char *sequence;
    size_t length;
} Genome;

void create_genome(Genome *genome) {
    static const char *nucleotides = "ACGT";
    genome->length = rand() % (MAX_GENOME_LENGTH - 1) + 1; // Length between [1, MAX_GENOME_LENGTH]
    genome->sequence = malloc(genome->length + 1); // +1 for null terminator
    
    for (size_t i = 0; i < genome->length; i++) {
        genome->sequence[i] = nucleotides[rand() % 4]; // Selecting a random nucleotide
    }
    genome->sequence[genome->length] = '\0'; // Null-terminate the string
}

void destroy_genome(Genome *genome) {
    free(genome->sequence);
    genome->sequence = NULL;
    genome->length = 0;
}

void print_genome(const Genome *genome) {
    printf("Genome Sequence: %s\n", genome->sequence);
    printf("Length of Genome: %zu\n", genome->length);
}

void simulate_genome_sequencing(Genome *genomes, size_t num_genomes) {
    printf("Hear ye, hear ye! Let the sequencing of the genomes commence!\n");

    for (size_t i = 0; i < num_genomes; i++) {
        printf("\nSequencing Genome %zu...\n", i + 1);
        create_genome(&genomes[i]);
        print_genome(&genomes[i]);
    }
    printf("\nAll genomes have been sequenced in due time!\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    Genome genomes[NUM_GENOMES]; // Array to hold our genomes

    simulate_genome_sequencing(genomes, NUM_GENOMES);

    for (size_t i = 0; i < NUM_GENOMES; i++) {
        destroy_genome(&genomes[i]); // Clean up memory after use
    }

    printf("The noble genomes have now returned to the ether!\n");
    return 0;
}