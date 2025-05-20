//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct DNA {
    char nucleotide;
    struct DNA *next;
} DNA;

void addNucleotide(DNA **head, char nucleotide) {
    DNA *newNucleotide = (DNA*) malloc(sizeof(DNA));
    newNucleotide->nucleotide = nucleotide;
    if(*head == NULL) {
        *head = newNucleotide;
        (*head)->next = NULL;
    }
    else {
        DNA *curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNucleotide;
        newNucleotide->next = NULL;
    }
}

void printSequence(DNA *head) {
    while(head != NULL) {
        printf("%c", head->nucleotide);
        head = head->next;
    }
    printf("\n");
}

void freeSequence(DNA *head) {
    DNA *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    srand(time(0));
    printf("Welcome to the Genome Sequencing Simulator!\n");
    int length;
    printf("Enter the desired length of the sequence: ");
    scanf("%d", &length);
    DNA *sequence = NULL;
    printf("Generating sequence...\n");
    int i;
    for(i=0; i<length; i++) {
        int nucleotideType = rand() % 4;
        if(nucleotideType == 0) {
            addNucleotide(&sequence, 'A');
        }
        else if(nucleotideType == 1) {
            addNucleotide(&sequence, 'C');
        }
        else if(nucleotideType == 2) {
            addNucleotide(&sequence, 'G');
        }
        else {
            addNucleotide(&sequence, 'T');
        }
    }
    printf("Generated sequence: ");
    printSequence(sequence);
    freeSequence(sequence);
    printf("Sequence destroyed. Simulation complete.\n");
    return 0;
}