//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int *counts;
    int alphabet_size;
} Alphabet;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = (Sequence *) malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = (char *) malloc(sizeof(char) * length);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }

    return sequence;
}

Alphabet *count_alphabet(Sequence *sequence) {
    Alphabet *alphabet = (Alphabet *) malloc(sizeof(Alphabet));
    alphabet->alphabet_size = MAX_ALPHABET_SIZE;
    alphabet->counts = (int *) malloc(sizeof(int) * alphabet->alphabet_size);

    for (int i = 0; i < alphabet->alphabet_size; i++) {
        alphabet->counts[i] = 0;
    }

    for (int i = 0; i < sequence->length; i++) {
        alphabet->counts[(int) sequence->sequence[i] - 'A']++;
    }

    return alphabet;
}

void print_alphabet_counts(Alphabet *alphabet) {
    for (int i = 0; i < alphabet->alphabet_size; i++) {
        printf("%c: %d\n", 'A' + i, alphabet->counts[i]);
    }
}

int main() {
    int sequence_length = 1000;
    Sequence *sequence = generate_random_sequence(sequence_length);
    Alphabet *alphabet = count_alphabet(sequence);

    printf("Random sequence of length %d:\n%s\n", sequence_length, sequence->sequence);
    printf("Alphabet counts:\n");
    print_alphabet_counts(alphabet);

    free(sequence->sequence);
    free(sequence);
    free(alphabet->counts);
    free(alphabet);

    return 0;
}