//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
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
    Sequence *sequences;
    int count;
} Sequences;

char *generate_random_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
    return sequence;
}

Sequence *generate_random_sequences(int count, int max_length) {
    Sequence *sequences = malloc(count * sizeof(Sequence));
    for (int i = 0; i < count; i++) {
        int length = rand() % max_length + 1;
        sequences[i].sequence = generate_random_sequence(length);
        sequences[i].length = length;
    }
    return sequences;
}

void print_sequences(Sequence *sequences, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", sequences[i].sequence);
    }
}

int main() {
    srand(time(NULL));

    int count = 10;
    int max_length = 100;

    Sequence *sequences = generate_random_sequences(count, max_length);
    print_sequences(sequences, count);

    free(sequences);
    return 0;
}