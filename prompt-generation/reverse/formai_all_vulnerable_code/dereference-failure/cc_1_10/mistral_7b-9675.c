//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 50000
#define LEN 100

typedef struct genome {
    char base[LEN];
    struct genome *next;
} genome_t;

void create_genome(genome_t **head, int num) {
    genome_t *genome, *current = *head;

    for (int i = 0; i < num; i++) {
        genome = (genome_t *) malloc(sizeof(genome_t));
        strncpy(genome->base, "ACGT", LEN);
        genome->next = NULL;

        if (*head == NULL) {
            *head = genome;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = genome;
        }
    }
}

void mutate_genome(genome_t *genome) {
    int index = rand() % LEN;
    genome->base[index] = (genome->base[index] == 'A' ? 'T' : 'A');
}

void print_genome(genome_t *genome) {
    printf("%s\n", genome->base);
}

void simulate_sequencing(genome_t *genome) {
    char reads[N][LEN];
    genome_t *current = genome;
    int errors = 0;

    for (int i = 0; i < N; i++) {
        strncpy(reads[i], current->base, LEN);
        current = current->next;

        for (int j = 0; j < LEN; j++) {
            if (reads[i][j] != current->base[j]) {
                errors++;
            }
            mutate_genome(current);
        }
    }

    printf("Total Errors: %d\n", errors);
}

int main() {
    srand(time(NULL));
    genome_t *genome_head = NULL;

    create_genome(&genome_head, 5);
    simulate_sequencing(genome_head);

    genome_t *current = genome_head;
    while (current != NULL) {
        genome_t *temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}