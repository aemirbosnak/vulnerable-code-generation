//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_BASE_PAIRS 500000

typedef struct {
    char base;
    int quality;
} BasePair;

typedef struct {
    BasePair *pairs;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = (Sequence *)malloc(sizeof(Sequence));
    seq->pairs = (BasePair *)malloc(sizeof(BasePair) * length);
    seq->length = length;

    for (int i = 0; i < length; i++) {
        BasePair pair = {(char)(rand() % 4 + 65), rand() % 41};
        seq->pairs[i] = pair;
    }

    return seq;
}

void printSequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c (%d)\n", seq->pairs[i].base, seq->pairs[i].quality);
    }
}

void freeSequence(Sequence *seq) {
    free(seq->pairs);
    free(seq);
}

int main() {
    srand(time(NULL));

    Sequence *seq = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printSequence(seq);
    freeSequence(seq);

    return 0;
}