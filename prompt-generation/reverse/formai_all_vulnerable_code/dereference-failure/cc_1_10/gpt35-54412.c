//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _nucleotide {
    char symbol;
    struct _nucleotide* next;
} Nucleotide;

void printSequence(Nucleotide* seq) {
    while(seq != NULL) {
        printf("%c", seq->symbol);
        seq = seq->next;
    }
    printf("\n");
}

Nucleotide* addNucleotide(Nucleotide* seq, char symbol) {
    if(seq == NULL) {
        seq = (Nucleotide*)malloc(sizeof(Nucleotide));
        seq->symbol = symbol;
        seq->next = NULL;
    } else {
        Nucleotide* curr = seq;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = (Nucleotide*)malloc(sizeof(Nucleotide));
        curr->next->symbol = symbol;
        curr->next->next = NULL;
    }
    return seq;
}

Nucleotide* generateSequence(int length) {
    Nucleotide* seq = NULL;
    for(int i=0; i<length; i++) {
        int randNum = rand() % 4;
        switch(randNum) {
            case 0:
                seq = addNucleotide(seq, 'A');
                break;
            case 1:
                seq = addNucleotide(seq, 'G');
                break;
            case 2:
                seq = addNucleotide(seq, 'C');
                break;
            case 3:
                seq = addNucleotide(seq, 'T');
                break;
        }
    }
    return seq;
}

void freeSequence(Nucleotide* seq) {
    Nucleotide* curr = seq;
    while(curr != NULL) {
        Nucleotide* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL)); // initialize random number generator
    int seqLength = 50;
    Nucleotide* sequence = generateSequence(seqLength);
    printf("Generated sequence: ");
    printSequence(sequence);
    freeSequence(sequence);
    return 0;
}