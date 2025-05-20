//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *createSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    sequence->length = length;
    return sequence;
}

void destroySequence(Sequence *sequence) {
    free(sequence->sequence);
    free(sequence);
}

void generateRandomSequence(Sequence *sequence) {
    srand(time(NULL));
    for (int i = 0; i < sequence->length; i++) {
        switch (rand() % 4) {
            case 0:
                sequence->sequence[i] = 'A';
                break;
            case 1:
                sequence->sequence[i] = 'C';
                break;
            case 2:
                sequence->sequence[i] = 'G';
                break;
            case 3:
                sequence->sequence[i] = 'T';
                break;
        }
    }
    sequence->sequence[sequence->length] = '\0';
}

void printSequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    int length = 100;
    Sequence *sequence = createSequence(length);
    generateRandomSequence(sequence);
    printSequence(sequence);
    destroySequence(sequence);
    return 0;
}