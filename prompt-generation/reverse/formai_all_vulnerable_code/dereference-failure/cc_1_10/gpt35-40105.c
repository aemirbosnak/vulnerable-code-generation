//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Genome {
    char nucleotide;
    struct Genome* next;
};

struct Genome* createGenome(char nucleotide) {
    struct Genome* newGenome = (struct Genome*) malloc(sizeof(struct Genome));
    newGenome -> nucleotide = nucleotide;
    newGenome -> next = NULL;
    return newGenome;
}

void printGenome(struct Genome* head) {
    struct Genome* current = head;
    while(current != NULL) {
        printf("%c", current -> nucleotide);
        current = current -> next;
    }
    printf("\n");
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    // Create the DNA sequences for Romeo and Juliet
    struct Genome* romeoDNA = createGenome('A');
    struct Genome* current = romeoDNA;
    int i;
    for(i = 0; i < 49; i++) {
        char nucleotide;
        int randomNum = rand() % 4; // Generate a random number from 0 to 3
        // Assign nucleotide based on the random number
        switch(randomNum) {
            case 0: nucleotide = 'A'; break;
            case 1: nucleotide = 'C'; break;
            case 2: nucleotide = 'G'; break;
            case 3: nucleotide = 'T'; break;
        }
        struct Genome* newGenome = createGenome(nucleotide);
        current -> next = newGenome;
        current = current -> next;
    }

    struct Genome* julietDNA = createGenome('A');
    current = julietDNA;
    for(i = 0; i < 49; i++) {
        char nucleotide;
        int randomNum = rand() % 4;
        switch(randomNum) {
            case 0: nucleotide = 'A'; break;
            case 1: nucleotide = 'C'; break;
            case 2: nucleotide = 'G'; break;
            case 3: nucleotide = 'T'; break;
        }
        struct Genome* newGenome = createGenome(nucleotide);
        current -> next = newGenome;
        current = current -> next;
    }

    // Print the DNA sequences for Romeo and Juliet
    printf("Romeo's DNA sequence:\n");
    printGenome(romeoDNA);
    printf("Juliet's DNA sequence:\n");
    printGenome(julietDNA);

    // Compare the DNA sequences
    int similarityCount = 0;
    current = romeoDNA;
    struct Genome* julietCurrent = julietDNA;
    while(current != NULL) {
        if(current -> nucleotide == julietCurrent -> nucleotide) {
            similarityCount++;
        }
        current = current -> next;
        julietCurrent = julietCurrent -> next;
    }

    // Print the similarity count
    printf("Number of matching nucleotides between Romeo and Juliet's DNA sequence: %d\n", similarityCount);

    return 0;
}