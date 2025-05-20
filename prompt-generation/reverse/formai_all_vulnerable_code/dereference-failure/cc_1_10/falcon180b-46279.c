//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000000
#define MAX_ALPHABET_SIZE 26
#define MIN_ALPHABET_SIZE 4

typedef struct {
    char *sequence;
    int length;
} Genome;

void generate_random_genome(Genome *genome, int alphabet_size) {
    genome->length = rand() % MAX_LENGTH + 1;
    genome->sequence = malloc(genome->length * sizeof(char));

    for (int i = 0; i < genome->length; i++) {
        int random_index = rand() % alphabet_size;
        genome->sequence[i] = 'a' + random_index;
    }
}

int main() {
    srand(time(NULL));

    int alphabet_size = rand() % (MAX_ALPHABET_SIZE - MIN_ALPHABET_SIZE + 1) + MIN_ALPHABET_SIZE;
    Genome genome1, genome2;

    generate_random_genome(&genome1, alphabet_size);
    generate_random_genome(&genome2, alphabet_size);

    printf("Genome 1:\n");
    for (int i = 0; i < genome1.length; i++) {
        printf("%c", genome1.sequence[i]);
    }
    printf("\n");

    printf("Genome 2:\n");
    for (int i = 0; i < genome2.length; i++) {
        printf("%c", genome2.sequence[i]);
    }
    printf("\n");

    int edit_distance = 0;
    int i = 0, j = 0;

    while (i < genome1.length && j < genome2.length) {
        if (genome1.sequence[i] == genome2.sequence[j]) {
            i++;
            j++;
        } else {
            edit_distance++;
            if (genome1.length < genome2.length) {
                i++;
            } else {
                j++;
            }
        }
    }

    while (i < genome1.length) {
        edit_distance++;
        i++;
    }

    while (j < genome2.length) {
        edit_distance++;
        j++;
    }

    printf("Edit distance: %d\n", edit_distance);

    free(genome1.sequence);
    free(genome2.sequence);

    return 0;
}