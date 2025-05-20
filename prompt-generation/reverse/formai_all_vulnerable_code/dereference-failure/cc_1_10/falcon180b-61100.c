//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DNA_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *dna;
    int length;
} DNA;

typedef struct {
    char *read;
    int start;
    int end;
} Read;

DNA *generate_dna(int length) {
    DNA *dna = malloc(sizeof(DNA));
    dna->dna = calloc(length + 1, sizeof(char));
    dna->length = length;

    for (int i = 0; i < length; i++) {
        dna->dna[i] = 'A' + rand() % 4;
    }

    return dna;
}

Read *generate_read(DNA *dna, int read_length) {
    Read *read = malloc(sizeof(Read));
    read->read = calloc(read_length + 1, sizeof(char));
    read->start = rand() % dna->length;
    read->end = read->start + read_length - 1;

    for (int i = 0; i < read_length; i++) {
        read->read[i] = dna->dna[read->start + i];
    }

    return read;
}

int main() {
    srand(time(NULL));

    DNA *dna = generate_dna(MAX_DNA_LENGTH);
    Read *read = generate_read(dna, MAX_READ_LENGTH);

    printf("DNA sequence:\n%s\n", dna->dna);
    printf("Read sequence:\n%s\n", read->read);

    free(dna->dna);
    free(dna);
    free(read->read);
    free(read);

    return 0;
}