//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Genome;

void generate_random_genome(Genome *genome) {
    genome->sequence = malloc(MAX_LENGTH * sizeof(char));
    genome->length = rand() % MAX_LENGTH + 1;

    for (int i = 0; i < genome->length; i++) {
        genome->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }

    genome->sequence[genome->length] = '\0';
}

void print_genome(const Genome *genome) {
    printf("Genome sequence: %s\n", genome->sequence);
    printf("Genome length: %d\n", genome->length);
}

int main() {
    srand(time(NULL));

    Genome genome1, genome2;
    generate_random_genome(&genome1);
    generate_random_genome(&genome2);

    printf("Genome 1:\n");
    print_genome(&genome1);

    printf("Genome 2:\n");
    print_genome(&genome2);

    int alignment_score = 0;
    int gap_penalty = -1;

    int i = 0, j = 0;
    while (i < genome1.length && j < genome2.length) {
        if (genome1.sequence[i] == genome2.sequence[j]) {
            alignment_score++;
            i++;
            j++;
        } else if (genome1.sequence[i]!= '-' && genome2.sequence[j]!= '-') {
            gap_penalty--;
            if (genome1.sequence[i] == '-') {
                i++;
            } else {
                j++;
            }
        } else {
            gap_penalty--;
            if (genome1.sequence[i] == '-') {
                i++;
            } else {
                j++;
            }
        }
    }

    printf("Alignment score: %d\n", alignment_score);
    printf("Gap penalty: %d\n", gap_penalty);

    return 0;
}