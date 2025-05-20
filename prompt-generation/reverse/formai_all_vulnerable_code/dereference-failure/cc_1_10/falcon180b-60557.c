//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
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
    char *alphabet;
    int size;
} Alphabet;

Sequence *generateRandomSequence(Alphabet *alphabet, int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    sequence->length = length;

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = alphabet->alphabet[rand() % alphabet->size];
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

void printSequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    Alphabet *alphabet = malloc(sizeof(Alphabet));
    alphabet->alphabet = "ACGT";
    alphabet->size = strlen(alphabet->alphabet);

    Sequence *sequence = generateRandomSequence(alphabet, MAX_SEQUENCE_LENGTH);
    printSequence(sequence);

    free(sequence->sequence);
    free(sequence);
    free(alphabet->alphabet);
    free(alphabet);

    return 0;
}