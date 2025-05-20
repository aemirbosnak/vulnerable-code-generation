//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_SIZE 1000000

typedef struct {
    char *genome;
    int size;
} Genome;

Genome *generate_random_genome(int size) {
    char *genome = (char *) malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        genome[i] = rand() % 4;
    }
    Genome *result = (Genome *) malloc(sizeof(Genome));
    result->genome = genome;
    result->size = size;
    return result;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->size; i++) {
        printf("%c", genome->genome[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Genome *genome = generate_random_genome(MAX_GENOME_SIZE);
    print_genome(genome);
    char *sequence = (char *) malloc(MAX_GENOME_SIZE * sizeof(char));
    int sequence_length = 0;
    int current_position = 0;
    while (sequence_length < MAX_GENOME_SIZE) {
        int read_length = rand() % 100 + 1;
        if (read_length + current_position > MAX_GENOME_SIZE) {
            read_length = MAX_GENOME_SIZE - current_position;
        }
        for (int i = 0; i < read_length; i++) {
            sequence[sequence_length] = genome->genome[current_position + i];
            current_position++;
        }
        sequence_length += read_length;
    }
    printf("Sequence:\n");
    for (int i = 0; i < sequence_length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
    free(genome->genome);
    free(genome);
    free(sequence);
    return 0;
}