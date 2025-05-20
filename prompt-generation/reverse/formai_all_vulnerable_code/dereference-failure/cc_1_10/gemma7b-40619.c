//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCS 10

typedef struct Disc {
    int number;
    struct Disc* next;
} Disc;

void moveDiscs(Disc* source, Disc* destination)
{
    if (source && destination)
    {
        Disc* currentDisc = source->next;
        while (currentDisc)
        {
            if (currentDisc->number > destination->number)
            {
                Disc* previousDisc = source;
                while (previousDisc->next && previousDisc->next->number < currentDisc->number)
                {
                    previousDisc = previousDisc->next;
                }

                moveDiscs(previousDisc->next, destination);
                moveDiscs(source, previousDisc->next);
                destination->next = currentDisc;
                currentDisc->next = NULL;
            }
            else
            {
                destination->next = currentDisc;
                currentDisc->next = NULL;
            }
        }
    }
}

int main()
{
    Disc* discs = NULL;
    for (int i = 0; i < MAX_DISCS; i++)
    {
        discs = malloc(sizeof(Disc));
        discs->number = i + 1;
        discs->next = discs;
    }

    moveDiscs(discs, discs->next);

    return 0;
}