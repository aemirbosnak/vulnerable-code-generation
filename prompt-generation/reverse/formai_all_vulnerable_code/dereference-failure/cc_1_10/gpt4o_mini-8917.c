//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define MAX_GENOMES 100
#define MUTATION_RATE 0.01
#define NUM_BASES 4

const char bases[NUM_BASES] = {'A', 'C', 'G', 'T'};

typedef struct {
    char id[50];
    char sequence[SEQUENCE_LENGTH + 1]; // +1 for null terminator
} Genome;

void generate_random_genome(Genome *genome, const char *id) {
    strcpy(genome->id, id);
    
    for(int i = 0; i < SEQUENCE_LENGTH; i++) {
        genome->sequence[i] = bases[rand() % NUM_BASES];
    }
    genome->sequence[SEQUENCE_LENGTH] = '\0'; // Null terminate string
}

void mutate_genome(Genome *genome) {
    for(int i = 0; i < SEQUENCE_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            genome->sequence[i] = bases[rand() % NUM_BASES]; // Change to a random base
        }
    }
}

void print_genome(const Genome *genome) {
    printf("Genome ID: %s\n", genome->id);
    printf("Sequence: %s\n", genome->sequence);
}

void save_genome_to_file(const Genome *genome, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Genome ID: %s\n", genome->id);
        fprintf(file, "Sequence: %s\n", genome->sequence);
        fclose(file);
    } else {
        perror("Error opening file");
    }
}

void load_genome_from_file(Genome *genome, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fscanf(file, "Genome ID: %s\n", genome->id);
        fscanf(file, "Sequence: %s\n", genome->sequence);
        fclose(file);
    } else {
        perror("Error opening file");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Genome genomes[MAX_GENOMES];
    int genome_count = 0;

    // Generate genomes
    for(int i = 0; i < MAX_GENOMES; i++) {
        char id[50];
        snprintf(id, sizeof(id), "Genome_%d", i + 1);
        generate_random_genome(&genomes[genome_count], id);
        mutate_genome(&genomes[genome_count]);
        genome_count++;
    }

    // Print genomes
    for(int i = 0; i < genome_count; i++) {
        print_genome(&genomes[i]);
    }

    // Save first genome to a file
    save_genome_to_file(&genomes[0], "genome_1.txt");

    // Load genome from file
    Genome loaded_genome;
    load_genome_from_file(&loaded_genome, "genome_1.txt");
    printf("\nLoaded Genome:\n");
    print_genome(&loaded_genome);

    return 0;
}