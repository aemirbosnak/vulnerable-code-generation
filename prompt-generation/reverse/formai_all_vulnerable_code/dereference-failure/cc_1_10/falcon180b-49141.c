//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *alphabet;
    int size;
} Alphabet;

void generate_random_sequence(Sequence *sequence, Alphabet *alphabet) {
    for (int i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = alphabet->alphabet[rand() % alphabet->size];
    }
    sequence->sequence[sequence->length] = '\0';
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    Alphabet alphabet;
    alphabet.size = MAX_ALPHABET_SIZE;
    alphabet.alphabet = malloc(alphabet.size * sizeof(char));
    for (int i = 0; i < alphabet.size; i++) {
        alphabet.alphabet[i] = 'A' + i;
    }

    Sequence sequence;
    sequence.length = MAX_SEQUENCE_LENGTH;
    sequence.sequence = malloc(sequence.length * sizeof(char));

    generate_random_sequence(&sequence, &alphabet);
    print_sequence(&sequence);

    free(sequence.sequence);
    free(alphabet.alphabet);

    return 0;
}