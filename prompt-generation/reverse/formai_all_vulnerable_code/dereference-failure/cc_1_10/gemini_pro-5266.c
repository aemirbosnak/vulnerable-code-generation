//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Genome;

Genome *create_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        switch (rand() % 4) {
            case 0:
                genome->sequence[i] = 'A';
                break;
            case 1:
                genome->sequence[i] = 'C';
                break;
            case 2:
                genome->sequence[i] = 'G';
                break;
            case 3:
                genome->sequence[i] = 'T';
                break;
        }
    }

    genome->sequence[length] = '\0';

    return genome;
}

void destroy_genome(Genome *genome) {
    free(genome->sequence);
    free(genome);
}

void print_genome(Genome *genome) {
    printf("%s\n", genome->sequence);
}

int main() {
    srand(time(NULL));

    int length = 100;
    Genome *genome = create_genome(length);

    printf("Generated genome:\n");
    print_genome(genome);

    destroy_genome(genome);

    return 0;
}