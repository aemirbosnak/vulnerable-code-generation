//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GENOME_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

Genome *generate_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % 4;
    }
    genome->sequence[length] = '\0';

    return genome;
}

Read *generate_read(Genome *genome, int length) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(length + 1);
    read->length = length;
    read->position = rand() % genome->length;

    for (int i = 0; i < length; i++) {
        read->sequence[i] = genome->sequence[read->position + i];
    }
    read->sequence[length] = '\0';

    return read;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Genome *genome = generate_genome(MAX_GENOME_LENGTH);
    Read *read = generate_read(genome, MAX_READ_LENGTH);

    printf("Genome:\n");
    print_genome(genome);
    printf("Read:\n");
    print_read(read);

    free(genome->sequence);
    free(genome);
    free(read->sequence);
    free(read);

    return 0;
}