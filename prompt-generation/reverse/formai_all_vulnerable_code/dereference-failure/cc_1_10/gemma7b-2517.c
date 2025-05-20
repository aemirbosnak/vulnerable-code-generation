//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 3
#define MAX_DISCS 10

typedef struct Disk {
    int number;
    struct Disk* next;
} Disk;

void Hanoi(int n, Disk* source, Disk* destination, Disk* auxiliary)
{
    if (n == 0) {
        return;
    }

    Hanoi(n - 1, source, auxiliary, destination);

    printf("Move disk %d from %s to %s\n", n, source->number, destination->number);

    Disk* tmp = source;
    source = destination;
    destination = tmp;
    Hanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    Disk* pile1 = NULL;
    Disk* pile2 = NULL;
    Disk* pile3 = NULL;

    for (int i = MAX_DISCS - 1; i >= 0; i--) {
        Disk* newDisk = (Disk*)malloc(sizeof(Disk));
        newDisk->number = i + 1;
        newDisk->next = NULL;

        if (pile1 == NULL) {
            pile1 = newDisk;
        } else if (pile2 == NULL) {
            pile2 = newDisk;
        } else if (pile3 == NULL) {
            pile3 = newDisk;
        }
    }

    Hanoi(MAX_DISCS, pile1, pile2, pile3);

    return 0;
}