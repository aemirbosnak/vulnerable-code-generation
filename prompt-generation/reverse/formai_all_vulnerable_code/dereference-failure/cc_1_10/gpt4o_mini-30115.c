//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define NUM_OF_SEQUENCES 5
#define BASES "ACGT"

char *generate_genome(int length) {
    char *genome = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        genome[i] = BASES[rand() % 4];
    }
    genome[length] = '\0';
    return genome;
}

void surrealistic_sequencer() {
    int states = 10; // Abstract sequences of the mind
    char *sequences[NUM_OF_SEQUENCES];
    int lengths[NUM_OF_SEQUENCES];

    for (int i = 0; i < NUM_OF_SEQUENCES; i++) {
        lengths[i] = rand() % (MAX_GENOME_LENGTH + 1); // Random length
        sequences[i] = generate_genome(lengths[i]);
        printf("Genome Fragment %d: %s (Length: %d)\n", i + 1, sequences[i], lengths[i]);
    }

    // Shuffling the bases of the first genome as a surreal touch
    printf("\nShuffling the very essence of the first genome:\n");
    char *shuffled_genome = strdup(sequences[0]); // Duplicate to shuffle
    for (int i = 0; i < lengths[0]; i++) {
        int j = rand() % lengths[0];
        char temp = shuffled_genome[i];
        shuffled_genome[i] = shuffled_genome[j];
        shuffled_genome[j] = temp;
    }
    printf("Shuffled Genome Fragment 1: %s\n", shuffled_genome);

    // Compare sequences in a Cubist vision
    printf("\nComparing the inner dimensions of the sequences:\n");
    for (int i = 0; i < NUM_OF_SEQUENCES; i++) {
        for (int j = i + 1; j < NUM_OF_SEQUENCES; j++) {
            int diff_count = 0;
            int min_length = lengths[i] < lengths[j] ? lengths[i] : lengths[j];
            for (int k = 0; k < min_length; k++) {
                if (sequences[i][k] != sequences[j][k]) {
                    diff_count++;
                }
            }
            printf("Difference between Fragment %d and %d: %d\n", i + 1, j + 1, diff_count);
        }
    }

    // Surreal mutation - random mutation of the last genome
    printf("\nEmbracing the chaos with mutations:\n");
    for (int i = 0; i < lengths[NUM_OF_SEQUENCES - 1]; i++) {
        if (rand() % 5 == 0) { // Mutate 1 in 5 bases
            sequences[NUM_OF_SEQUENCES - 1][i] = BASES[rand() % 4];
        }
    }
    printf("Mutated Genome Fragment %d: %s\n", NUM_OF_SEQUENCES, sequences[NUM_OF_SEQUENCES - 1]);

    // Free up the generated memories
    for (int i = 0; i < NUM_OF_SEQUENCES; i++) {
        free(sequences[i]);
    }
    free(shuffled_genome);
}

int main() {
    srand(time(NULL)); // Seeding the randomness from the universe
    printf("Welcome to the Surrealist Genome Sequencer!\n");
    printf("Unfolding sequences from the dreams of DNA...\n");
    
    surrealistic_sequencer();

    printf("Thank you for exploring the surreal realms of genetic sequences.\n");
    return 0;
}