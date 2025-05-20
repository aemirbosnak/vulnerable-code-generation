//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *alphabet;
    int size;
} Alphabet;

Sequence *generate_random_sequence(Alphabet *alphabet, int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = alphabet->alphabet[rand() % alphabet->size];
    }

    return sequence;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

int main() {
    Alphabet *alphabet = malloc(sizeof(Alphabet));
    alphabet->alphabet = "ACGT";
    alphabet->size = strlen(alphabet->alphabet);

    Sequence *sequence1 = generate_random_sequence(alphabet, 10);
    Sequence *sequence2 = generate_random_sequence(alphabet, 20);

    print_sequence(sequence1);
    print_sequence(sequence2);

    free(sequence1->sequence);
    free(sequence1);
    free(sequence2->sequence);
    free(sequence2);
    free(alphabet->alphabet);
    free(alphabet);

    return 0;
}