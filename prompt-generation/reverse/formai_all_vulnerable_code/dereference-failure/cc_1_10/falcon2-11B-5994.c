//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Genome {
    int size;
    char* sequence;
} Genome;

Genome* create_genome(int size) {
    Genome* genome = (Genome*)malloc(sizeof(Genome));
    genome->size = size;
    genome->sequence = (char*)malloc(size * sizeof(char));
    return genome;
}

void print_genome(Genome* genome) {
    for (int i = 0; i < genome->size; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

void shuffle_genome(Genome* genome) {
    for (int i = 0; i < genome->size - 1; i++) {
        int r = rand() % (i + 1);
        char temp = genome->sequence[i];
        genome->sequence[i] = genome->sequence[r];
        genome->sequence[r] = temp;
    }
}

void print_shuffled_genome(Genome* genome) {
    for (int i = 0; i < genome->size; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

void free_genome(Genome* genome) {
    free(genome->sequence);
    free(genome);
}

int main() {
    int size = 100;
    Genome* genome = create_genome(size);
    char* sequence = genome->sequence;
    for (int i = 0; i < size; i++) {
        sequence[i] = 'A' + (rand() % 4);
    }
    print_genome(genome);
    printf("\nShuffling the genome...\n");
    shuffle_genome(genome);
    print_shuffled_genome(genome);
    printf("\nFreeing the genome...\n");
    free_genome(genome);
    return 0;
}