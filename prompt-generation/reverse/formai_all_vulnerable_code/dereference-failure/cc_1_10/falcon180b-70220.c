//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *name;
    Sequence *sequence;
} Genome;

void generate_random_sequence(Sequence *sequence, int length) {
    sequence->length = length;
    sequence->sequence = (char *)malloc(length * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }

    sequence->sequence[length] = '\0';
}

Genome *create_genome(char *name, int sequence_length) {
    Genome *genome = (Genome *)malloc(sizeof(Genome));

    genome->name = strdup(name);
    Sequence *sequence = (Sequence *)malloc(sizeof(Sequence));
    generate_random_sequence(sequence, sequence_length);
    genome->sequence = sequence;

    return genome;
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

void print_genome(Genome *genome) {
    printf("Name: %s\n", genome->name);
    print_sequence(genome->sequence);
}

int main() {
    Genome *genome1 = create_genome("Neo", 100);
    Genome *genome2 = create_genome("Trinity", 200);

    print_genome(genome1);
    print_genome(genome2);

    free(genome1->name);
    free(genome1->sequence);
    free(genome1);

    free(genome2->name);
    free(genome2->sequence);
    free(genome2);

    return 0;
}