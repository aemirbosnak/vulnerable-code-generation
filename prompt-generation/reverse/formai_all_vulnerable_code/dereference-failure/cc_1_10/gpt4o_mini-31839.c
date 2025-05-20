//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define MAX_SEQUENCES 10

void generate_random_sequence(char *sequence, int length) {
    const char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0';  // Null-terminate the string
}

void generate_genome_sequence(char *genome, int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        int length = rand() % MAX_GENOME_LENGTH + 1;  // random length between 1 and MAX_GENOME_LENGTH
        generate_random_sequence(genome + i * (MAX_GENOME_LENGTH + 1), length);  
    }
}

void mutate_sequence(char *sequence, int length, float mutation_rate) {
    for (int i = 0; i < length; i++) {
        float random_value = (float)rand() / RAND_MAX;
        if (random_value < mutation_rate) {
            const char nucleotides[] = "ACGT";
            // Mutation: replace with a random nucleotide
            sequence[i] = nucleotides[rand() % 4];
        }
    }
}

void save_genome_to_file(char *genome, int num_sequences, const char *filename) {
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_sequences; i++) {
        fprintf(file, ">Sequence %d\n%s\n", i + 1, genome + i * (MAX_GENOME_LENGTH + 1));
    }

    fclose(file);
}

void print_genome(char *genome, int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        printf(">Sequence %d\n%s\n", i + 1, genome + i * (MAX_GENOME_LENGTH + 1));
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <num_sequences> <mutation_rate> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_sequences = atoi(argv[1]);
    float mutation_rate = atof(argv[2]);
    const char *output_file = argv[3];

    if (num_sequences <= 0 || num_sequences > MAX_SEQUENCES) {
        fprintf(stderr, "Number of sequences must be between 1 and %d\n", MAX_SEQUENCES);
        return EXIT_FAILURE;
    }

    if (mutation_rate < 0.0 || mutation_rate > 1.0) {
        fprintf(stderr, "Mutation rate must be between 0.0 and 1.0\n");
        return EXIT_FAILURE;
    }

    char *genome = malloc(num_sequences * (MAX_GENOME_LENGTH + 1));
    if (genome == NULL) {
        perror("Memory allocation for genome sequence failed");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    generate_genome_sequence(genome, num_sequences);
    print_genome(genome, num_sequences);

    for (int i = 0; i < num_sequences; i++) {
        int length = strlen(genome + i * (MAX_GENOME_LENGTH + 1));
        mutate_sequence(genome + i * (MAX_GENOME_LENGTH + 1), length, mutation_rate);
    }

    printf("\nMutated Genome:\n");
    print_genome(genome, num_sequences);

    save_genome_to_file(genome, num_sequences, output_file);
    printf("Genome sequences saved to %s\n", output_file);

    free(genome);
    
    return EXIT_SUCCESS;
}