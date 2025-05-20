//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Shape {
    char symbol;
    int length;
    struct Shape *next;
} Shape;

typedef struct Genome {
    Shape *sequence;
    int length;
} Genome;

Shape *create_shape(char symbol, int length) {
    Shape *new_shape = (Shape *)malloc(sizeof(Shape));
    new_shape->symbol = symbol;
    new_shape->length = length;
    new_shape->next = NULL;
    return new_shape;
}

Genome *create_genome(int length) {
    Genome *new_genome = (Genome *)malloc(sizeof(Genome));
    new_genome->length = length;
    new_genome->sequence = NULL;

    for (int i = 0; i < length; i++) {
        int random_shape = rand() % 3; // A, C, G
        Shape *new_shape = create_shape((random_shape == 0) ? 'A' :
                                        (random_shape == 1) ? 'C' : 'G', 1);
        new_genome->sequence = (Shape *)realloc(new_genome->sequence, sizeof(Shape) * (new_genome->length + 1));
        new_genome->sequence[new_genome->length - 1] = *new_shape;
        new_shape->next = new_genome->sequence;
    }

    return new_genome;
}

void print_genome(Genome *genome) {
    Shape *current = genome->sequence;
    for (int i = 0; i < genome->length; i++) {
        for (int j = 0; j < current->length; j++) {
            printf("%c", current->symbol);
        }
        current = current->next;
    }
    printf("\n");
}

void free_genome(Genome *genome) {
    Shape *current = genome->sequence;
    Shape *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(genome);
}

int main() {
    srand(time(NULL));

    int genome_length = 25;
    Genome *genome = create_genome(genome_length);
    print_genome(genome);

    free_genome(genome);

    return 0;
}