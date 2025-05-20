//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    char *alphabet;
    int size;
} Alphabet;

Alphabet *createAlphabet(int size) {
    Alphabet *alphabet = (Alphabet *)malloc(sizeof(Alphabet));
    alphabet->size = size;
    alphabet->alphabet = (char *)malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++) {
        alphabet->alphabet[i] = 'a' + i;
    }
    alphabet->alphabet[size] = '\0';
    return alphabet;
}

Genome *createGenome(Alphabet *alphabet, int length) {
    Genome *genome = (Genome *)malloc(sizeof(Genome));
    genome->sequence = (char *)malloc((length + 1) * sizeof(char));
    genome->length = length;
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = alphabet->alphabet[rand() % alphabet->size];
    }
    genome->sequence[length] = '\0';
    return genome;
}

void printGenome(Genome *genome) {
    printf("Sequence: %s\n", genome->sequence);
    printf("Length: %d\n", genome->length);
}

int main() {
    srand(time(NULL));
    Alphabet *alphabet = createAlphabet(MAX_ALPHABET_SIZE);
    Genome *genome = createGenome(alphabet, rand() % MAX_SEQUENCE_LENGTH + 1);
    printGenome(genome);
    free(genome->sequence);
    free(genome);
    free(alphabet->alphabet);
    free(alphabet);
    return 0;
}