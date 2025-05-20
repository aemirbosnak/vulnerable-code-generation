//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_BASE_TYPES 4
#define MAX_NUM_SEQUENCES 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
    int base_types;
} Genome;

void generate_sequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = rand() % MAX_BASE_TYPES + 1;
    }
}

void generate_genome(Genome *genome) {
    int i;
    genome->sequences = malloc(genome->num_sequences * sizeof(Sequence));
    for (i = 0; i < genome->num_sequences; i++) {
        genome->sequences[i].sequence = malloc(genome->sequences[i].length * sizeof(char));
        genome->sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        generate_sequence(&genome->sequences[i]);
    }
}

void print_sequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i] + 'A' - 1);
    }
    printf("\n");
}

void print_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->num_sequences; i++) {
        printf("Sequence %d:\n", i + 1);
        print_sequence(&genome->sequences[i]);
    }
}

int main() {
    srand(time(NULL));
    Genome genome;
    int i;
    printf("Enter the number of sequences: ");
    scanf("%d", &genome.num_sequences);
    printf("Enter the maximum length of each sequence: ");
    scanf("%d", &genome.sequences[0].length);
    printf("Enter the number of base types (1-4): ");
    scanf("%d", &genome.base_types);
    genome.sequences = malloc(genome.num_sequences * sizeof(Sequence));
    for (i = 0; i < genome.num_sequences; i++) {
        genome.sequences[i].sequence = malloc(genome.sequences[i].length * sizeof(char));
        genome.sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        generate_sequence(&genome.sequences[i]);
    }
    printf("Generated genome:\n");
    print_genome(&genome);
    return 0;
}