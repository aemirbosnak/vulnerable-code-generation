//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCS 10
#define NUM_PILES 3

typedef struct Disk
{
    int number;
    struct Disk* next;
} Disk;

void Hanoi(int n, Disk* source, Disk* auxiliary, Disk* destination)
{
    if (n == 0)
    {
        return;
    }

    Hanoi(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %s to %s\n", n, source->number, destination->number);

    Disk* temp = source->next;
    source->next = destination;
    destination->next = temp;
    destination->number = n;

    Hanoi(1, auxiliary, source, destination);
}

int main()
{
    Disk* disks = NULL;
    for (int i = 0; i < MAX_DISCS; i++)
    {
        disks = malloc(sizeof(Disk));
        disks->number = i + 1;
        disks->next = NULL;

        if (disks != NULL)
        {
            if (disks->next == NULL)
            {
                disks = disks;
            }
            else
            {
                disks->next = disks;
            }
        }
    }

    Hanoi(MAX_DISCS, disks, disks->next, disks->next->next);

    return 0;
}