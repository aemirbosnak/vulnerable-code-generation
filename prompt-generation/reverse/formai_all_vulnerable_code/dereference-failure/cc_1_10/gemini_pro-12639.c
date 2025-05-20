//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
// In the desolate wasteland, where rust and ruin reign supreme,
// a solitary tower stands as a testament to a bygone era.
// Its once-gleaming disks, now coated in grime and decay, await their fateful journey.

#include <stdio.h>
#include <stdlib.h>

// A scarred veteran in a shattered world
typedef struct disk {
    int size;
    struct disk *next;
} Disk;

// The dilapidated tower that holds the secrets of the past
typedef struct tower {
    char name;
    Disk *top;
} Tower;

// The enigmatic guide, leading us through this treacherous path
void move(Tower *src, Tower *dest, Tower *aux) {
    // If only one disk remains, move it to the destination
    if (src->top->next == NULL) {
        dest->top = src->top;
        src->top = NULL;
        return;
    }

    // Recursive descent into the depths of the tower
    move(src, aux, dest);
    move(src, dest, aux);
    move(aux, dest, src);
}

// The weathered traveler, bearing the burden of knowledge
int main() {
    // The three forsaken towers, standing in silence
    Tower A = {'A', NULL}, B = {'B', NULL}, C = {'C', NULL};

    // The age-old puzzle, etched into the fabric of time
    Disk *d1 = malloc(sizeof(Disk)), *d2 = malloc(sizeof(Disk)), *d3 = malloc(sizeof(Disk));
    d1->size = 3;
    d2->size = 2;
    d3->size = 1;
    d1->next = d2;
    d2->next = d3;
    d3->next = NULL;
    A.top = d1;

    // The guiding light through the maze of despair
    move(&A, &C, &B);

    // The triumphant cry of a weary soul
    printf("The Tower of Hanoi has been solved in this forsaken wasteland.\n");
    return 0;
}