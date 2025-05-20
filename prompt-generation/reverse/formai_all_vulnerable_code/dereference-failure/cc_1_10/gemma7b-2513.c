//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ_LENGTH 20

typedef struct Nucleotide {
    char nucleotide;
    struct Nucleotide* next;
} Nucleotide;

void insertNucleotides(Nucleotide* head, char nucleotide) {
    Nucleotide* newNode = malloc(sizeof(Nucleotide));
    newNode->nucleotide = nucleotide;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

int main() {
    Nucleotide* head = NULL;
    char read[MAX_READ_LENGTH];
    int i;

    printf("Welcome to the C Genome Sequencing Simulator!\n");

    // Read a sequence of nucleotides
    printf("Enter a sequence of nucleotides (maximum %d characters): ", MAX_READ_LENGTH);
    fgets(read, MAX_READ_LENGTH, stdin);

    // Insert the nucleotides into a linked list
    for (i = 0; read[i] != '\0'; i++) {
        insertNucleotides(head, read[i]);
    }

    // Print the sequence of nucleotides
    printf("Your sequence of nucleotides: ");
    Nucleotide* current = head;
    while (current) {
        printf("%c ", current->nucleotide);
        current = current->next;
    }

    printf("\n");

    return 0;
}