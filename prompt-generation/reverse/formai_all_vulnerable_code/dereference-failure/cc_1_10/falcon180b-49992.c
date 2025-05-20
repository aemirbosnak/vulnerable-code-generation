//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
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

Alphabet *create_alphabet(int size) {
    Alphabet *alphabet = (Alphabet *)malloc(sizeof(Alphabet));
    alphabet->alphabet = (char *)malloc((size + 1) * sizeof(char));
    alphabet->size = size;
    for (int i = 0; i < size; i++) {
        alphabet->alphabet[i] = 'A' + i;
    }
    alphabet->alphabet[size] = '\0';
    return alphabet;
}

Sequence *create_sequence(int length) {
    Sequence *sequence = (Sequence *)malloc(sizeof(Sequence));
    sequence->sequence = (char *)malloc((length + 1) * sizeof(char));
    sequence->length = length;
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 26;
    }
    sequence->sequence[length] = '\0';
    return sequence;
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    Alphabet *alphabet = create_alphabet(MAX_ALPHABET_SIZE);
    Sequence *sequence = create_sequence(MAX_SEQUENCE_LENGTH);

    print_sequence(sequence);

    free(sequence->sequence);
    free(sequence);
    free(alphabet->alphabet);
    free(alphabet);

    return 0;
}