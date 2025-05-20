//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define N 50 // Sequence length
#define A 0
#define C 1
#define G 2
#define T 3

typedef struct {
    int base;
    int next;
} Sequence;

void ReadSequence(Sequence *seq) {
    char input[N + 1];
    int i, base;

    printf("Enter the sequence:\n");
    fgets(input, N + 1, stdin);
    input[strcspn(input, "\n")] = '\0';

    seq->next = 0;
    for (i = 0; i < N; i++) {
        base = (input[i] == 'A') ? A :
               (input[i] == 'C') ? C :
               (input[i] == 'G') ? G : T;
        seq->base = base;
        if (i < N - 1) {
            Sequence *next = (Sequence *)malloc(sizeof(Sequence));
            next->base = base;
            next->next = 0;
            seq->next = next;
            seq = next;
        }
    }
}

void SequencePrint(Sequence *seq) {
    Sequence *current = seq;
    while (current != NULL) {
        printf("%c", (current->base == A) ? 'A' :
               (current->base == C) ? 'C' :
               (current->base == G) ? 'G' : 'T');
        current = current->next;
    }
}

void SequenceCompare(Sequence *seq1, Sequence *seq2) {
    Sequence *current1 = seq1;
    Sequence *current2 = seq2;
    int mismatch = 0;

    while (current1 != NULL && current2 != NULL) {
        if (current1->base != current2->base) {
            mismatch++;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 != NULL || current2 != NULL) {
        mismatch = 1;
    }

    printf("Number of mismatches: %d\n", mismatch);
}

int main() {
    Sequence *seq1 = NULL;
    Sequence *seq2 = NULL;

    ReadSequence(seq1);
    printf("Sequence 1: ");
    SequencePrint(seq1);

    ReadSequence(seq2);
    printf("\nSequence 2: ");
    SequencePrint(seq2);

    SequenceCompare(seq1, seq2);

    Sequence *temp = seq1;
    while (temp != NULL) {
        Sequence *next = temp->next;
        free(temp);
        temp = next;
    }

    Sequence *temp2 = seq2;
    while (temp2 != NULL) {
        Sequence *next = temp2->next;
        free(temp2);
        temp2 = next;
    }

    return 0;
}