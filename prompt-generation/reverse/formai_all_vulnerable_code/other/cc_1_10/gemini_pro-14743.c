//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_TOWERS 3
#define NUM_DISKS 7

typedef struct _disk {
    int size;
    struct _disk *next;
} disk;

typedef struct _tower {
    disk *top;
} tower;

void init_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        towers[i].top = NULL;
    }
}

void init_disks(disk *disks) {
    for (int i = 0; i < NUM_DISKS; i++) {
        disks[i].size = NUM_DISKS - i;
        disks[i].next = &disks[i + 1];
    }
    disks[NUM_DISKS - 1].next = NULL;
}

void move_disk(tower *from, tower *to) {
    assert(from->top != NULL);
    assert(to->top == NULL || from->top->size < to->top->size);

    disk *disk = from->top;
    from->top = from->top->next;
    disk->next = to->top;
    to->top = disk;
}

void move_disks(int n, tower *from, tower *to, tower *aux) {
    if (n == 1) {
        move_disk(from, to);
        return;
    }

    move_disks(n - 1, from, aux, to);
    move_disk(from, to);
    move_disks(n - 1, aux, to, from);
}

void print_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        disk *d = towers[i].top;
        printf("Tower %d: ", i + 1);
        while (d != NULL) {
            printf("%d ", d->size);
            d = d->next;
        }
        printf("\n");
    }
}

int main() {
    tower towers[NUM_TOWERS];
    disk disks[NUM_DISKS];

    init_towers(towers);
    init_disks(disks);

    move_disks(NUM_DISKS, &towers[0], &towers[2], &towers[1]);
    print_towers(towers);

    return 0;
}