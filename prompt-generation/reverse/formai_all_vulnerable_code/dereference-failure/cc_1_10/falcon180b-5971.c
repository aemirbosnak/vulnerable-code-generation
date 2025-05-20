//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int *counts;
    int alphabet_size;
} Alphabet;

Alphabet create_alphabet(int size) {
    Alphabet alphabet = {0};
    alphabet.alphabet_size = size;
    alphabet.counts = calloc(size, sizeof(int));
    return alphabet;
}

void destroy_alphabet(Alphabet *alphabet) {
    free(alphabet->counts);
}

Sequence create_sequence(int length) {
    Sequence sequence = {0};
    sequence.sequence = calloc(length + 1, sizeof(char));
    sequence.length = length;
    for (int i = 0; i < length; i++) {
        sequence.sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    return sequence;
}

void destroy_sequence(Sequence *sequence) {
    free(sequence->sequence);
}

void print_sequence(Sequence sequence) {
    printf("%s\n", sequence.sequence);
}

int main() {
    srand(time(NULL));

    Alphabet alphabet = create_alphabet(MAX_ALPHABET_SIZE);
    Sequence sequence = create_sequence(MAX_SEQUENCE_LENGTH);

    printf("Original sequence:\n");
    print_sequence(sequence);

    int *counts = alphabet.counts;
    for (int i = 0; i < MAX_ALPHABET_SIZE; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < sequence.length; i++) {
        counts[(int) sequence.sequence[i] - 'A']++;
    }

    printf("Alphabet counts:\n");
    for (int i = 0; i < MAX_ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'A' + i, counts[i]);
    }

    destroy_alphabet(&alphabet);
    destroy_sequence(&sequence);

    return 0;
}