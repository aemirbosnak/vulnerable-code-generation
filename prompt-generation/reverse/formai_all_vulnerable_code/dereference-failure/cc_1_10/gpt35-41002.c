//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 1000
#define MAX_LENGTH 10000
#define MAX_BASES 4

typedef struct Genome {
    char *bases;
    int length;
} Genome;

void create_genome(Genome *genome) {
    genome->length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
    genome->bases = malloc(genome->length * sizeof(char));
    for (int i = 0; i < genome->length; i++) {
        int base = rand() % MAX_BASES;
        switch(base) {
            case 0:
                genome->bases[i] = 'A';
                break;
            case 1:
                genome->bases[i] = 'T';
                break;
            case 2:
                genome->bases[i] = 'C';
                break;
            case 3:
                genome->bases[i] = 'G';
                break;
            default:
                genome->bases[i] = 'N'; // error character
        }
    }
}

void print_genome(Genome genome) {
    printf("Length: %d\nSequence: ", genome.length);
    for (int i = 0; i < genome.length; i++) {
        printf("%c", genome.bases[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator
    Genome genome;
    create_genome(&genome);
    print_genome(genome);
    free(genome.bases);
    return 0;
}