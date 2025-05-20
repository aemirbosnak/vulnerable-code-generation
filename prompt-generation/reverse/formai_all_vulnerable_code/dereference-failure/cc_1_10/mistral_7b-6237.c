//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_GENome_SIZE 100000
#define ALPHABET_SIZE 4
#define PROTECTED_SECTION __attribute__((section(".protected")))

typedef struct genome {
    char base;
    struct genome *next;
} genome_t;

PROTECTED_SECTION genome_t *head = NULL;

void genome_push(char base) {
    genome_t *new_node = (genome_t *)malloc(sizeof(genome_t));
    new_node->base = base;
    new_node->next = head;
    head = new_node;
}

void genome_sequence(char *dna_sequence) {
    for (int i = 0; i < strlen(dna_sequence); i++) {
        if (isalpha(dna_sequence[i])) {
            putchar(toupper(dna_sequence[i]));
            genome_push(dna_sequence[i]);
        } else {
            putchar('N');
        }
    }

    printf("\nGenome Sequence: ");
    genome_t *current = head;
    while (current != NULL) {
        putchar(current->base);
        current = current->next;
    }

    putchar('\n');

    genome_t *temp = head;
    while (temp != NULL) {
        genome_t *to_delete = temp;
        temp = temp->next;
        free(to_delete);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <DNA Sequence>\n", argv[0]);
        return 1;
    }

    genome_sequence(argv[1]);

    return 0;
}