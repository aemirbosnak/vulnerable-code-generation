//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nucleotide
{
    char base;
    struct Nucleotide* next;
} Nucleotide;

Nucleotide* createNucleotide(char base)
{
    Nucleotide* nucleotide = malloc(sizeof(Nucleotide));
    nucleotide->base = base;
    nucleotide->next = NULL;
    return nucleotide;
}

void insertNucleotide(Nucleotide* nucleotide, char base)
{
    Nucleotide* newNucleotide = createNucleotide(base);
    if (nucleotide)
    {
        nucleotide->next = newNucleotide;
    }
    else
    {
        nucleotide = newNucleotide;
    }
}

void simulateGenomeSequencing(int length)
{
    Nucleotide* head = NULL;
    for (int i = 0; i < length; i++)
    {
        insertNucleotide(head, rand() % 4 + 1);
    }

    printf("Sequencing results:\n");
    for (Nucleotide* current = head; current; current = current->next)
    {
        printf("%c ", current->base);
    }

    printf("\n");
}

int main()
{
    simulateGenomeSequencing(1000);
    return 0;
}