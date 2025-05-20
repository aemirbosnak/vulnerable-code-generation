//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_DISCS 10
#define NUMBER_OF_PILES 3

typedef struct Disc {
    int number;
    struct Disc* next;
} Disc;

typedef struct Pile {
    Disc* top;
    struct Pile* next;
} Pile;

void move_disc(Pile* source, Pile* destination)
{
    Disc* disc = source->top;
    source->top = disc->next;
    destination->top = disc;
    destination->top->next = NULL;
}

void hanoi(int number_of_discs, Pile* pile_a, Pile* pile_b, Pile* pile_c)
{
    if (number_of_discs > 0)
    {
        hanoi(number_of_discs - 1, pile_a, pile_c, pile_b);
        move_disc(pile_a, pile_c);
        hanoi(1, pile_b, pile_a, pile_c);
    }
}

int main()
{
    Pile* pile_a = malloc(sizeof(Pile));
    pile_a->top = NULL;
    pile_a->next = NULL;

    Pile* pile_b = malloc(sizeof(Pile));
    pile_b->top = NULL;
    pile_b->next = NULL;

    Pile* pile_c = malloc(sizeof(Pile));
    pile_c->top = NULL;
    pile_c->next = NULL;

    hanoi(MAX_NUMBER_OF_DISCS, pile_a, pile_b, pile_c);

    return 0;
}