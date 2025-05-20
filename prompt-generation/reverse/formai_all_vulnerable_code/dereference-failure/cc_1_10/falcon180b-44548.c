//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    char *sequence;
    int length;
    Genome *genome;
} Read;

Genome *generate_genome(int length) {
    Genome *genome = (Genome *)malloc(sizeof(Genome));
    genome->sequence = (char *)malloc((length + 1) * sizeof(char));
    genome->length = length;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = (char)(rand() % 4 + 'A');
    }
    genome->sequence[length] = '\0';

    return genome;
}

Read *generate_read(Genome *genome, int length) {
    Read *read = (Read *)malloc(sizeof(Read));
    read->sequence = (char *)malloc((length + 1) * sizeof(char));
    read->length = length;
    read->genome = genome;

    for (int i = 0; i < length; i++) {
        read->sequence[i] = genome->sequence[rand() % genome->length];
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
    printf("Read: %s\n", read->sequence);
}

int main() {
    srand(time(0));

    Genome *genome = generate_genome(MAX_SEQUENCE_LENGTH);
    Read *read = generate_read(genome, MAX_READ_LENGTH);

    print_genome(genome);
    print_read(read);

    free(genome->sequence);
    free(genome);
    free(read->sequence);
    free(read);

    return 0;
}