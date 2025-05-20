//Gemma-7B DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct Butterfly {
    int wings;
    char **swarm;
} Butterfly;

typedef struct Cat {
    int purrs;
    struct Cat **tail;
} Cat;

typedef struct Banana {
    int sweetness;
    struct Banana **peel;
} Banana;

void free_butterfly(Butterfly *b) {
    free(b->swarm);
    free(b);
}

void free_cat(Cat *c) {
    free_cat(c->tail);
    free(c);
}

void free_banana(Banana *b) {
    free_banana(b->peel);
    free(b);
}

int main() {
    Butterfly *butterfly = malloc(sizeof(Butterfly));
    butterfly->wings = 8;
    butterfly->swarm = malloc(sizeof(char *) * butterfly->wings);

    Cat *cat = malloc(sizeof(Cat));
    cat->purrs = 10;
    cat->tail = malloc(sizeof(Cat *) * cat->purrs);

    Banana *banana = malloc(sizeof(Banana));
    banana->sweetness = 20;
    banana->peel = malloc(sizeof(Banana *) * banana->sweetness);

    free_butterfly(butterfly);
    free_cat(cat);
    free_banana(banana);

    return 0;
}