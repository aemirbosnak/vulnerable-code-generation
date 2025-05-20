//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_SEQUENCE_NUMBER 10

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

void generateSequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
}

int main() {
    srand(time(NULL));

    Sequence *sequences[MAX_SEQUENCE_NUMBER];
    int sequenceCount = 0;

    while (sequenceCount < MAX_SEQUENCE_NUMBER) {
        Sequence *newSequence = (Sequence *)malloc(sizeof(Sequence));
        generateSequence(newSequence);
        int isDuplicate = 0;

        for (int i = 0; i < sequenceCount; i++) {
            if (strcmp(sequences[i]->sequence, newSequence->sequence) == 0) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            sequences[sequenceCount] = newSequence;
            sequenceCount++;
        } else {
            free(newSequence);
        }
    }

    printf("Sequencing complete!\n");

    for (int i = 0; i < sequenceCount; i++) {
        printf("Sequence %d:\n%s\n", i + 1, sequences[i]->sequence);
    }

    for (int i = 0; i < sequenceCount; i++) {
        free(sequences[i]);
    }

    return 0;
}