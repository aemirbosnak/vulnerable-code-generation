//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define NUM_PILES 3
#define MAX_DISCS 10

typedef struct Disc {
    int number;
    struct Disc* next;
} Disc;

void moveDisc(Disc* from, Disc* to) {
    if (from && to) {
        int discNumber = from->number;
        from->number = from->next->number;
        from->next = from->next->next;
        to->number = discNumber;
        to->next = NULL;
    }
}

void hanoi(int n, Disc* top, Disc* second, Disc* third) {
    if (n > 0) {
        hanoi(n - 1, top, third, second);
        moveDisc(top, second);
        hanoi(1, second, top, third);
    }
}

int main() {
    Disc* top = NULL;
    Disc* second = NULL;
    Disc* third = NULL;

    for (int i = 0; i < MAX_DISCS; i++) {
        Disc* newDisc = (Disc*)malloc(sizeof(Disc));
        newDisc->number = i + 1;
        newDisc->next = NULL;

        if (top) {
            newDisc->next = top;
        }
        top = newDisc;
    }

    hanoi(MAX_DISCS, top, second, third);

    printf("Discs have been moved to the third pile.\n");

    return 0;
}