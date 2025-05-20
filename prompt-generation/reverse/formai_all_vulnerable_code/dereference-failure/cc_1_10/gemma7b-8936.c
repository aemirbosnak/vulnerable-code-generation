//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISKS 5

typedef struct Disk {
    int size;
    char color;
    struct Disk* next;
} Disk;

void Hanoi(int n, Disk* top, Disk* middle, Disk* bottom) {
    if (n == 0) {
        return;
    }

    Hanoi(n - 1, top, middle, bottom);

    printf("Move disk %d from %c to %c.\n", n, top->color, bottom->color);

    Disk* newTop = middle->next;
    middle->next = top;
    top = newTop;

    Hanoi(n - 1, top, middle, bottom);
}

int main() {
    Disk* top = NULL;
    Disk* middle = NULL;
    Disk* bottom = NULL;

    for (int i = 0; i < MAX_DISKS; i++) {
        Disk* newDisk = (Disk*)malloc(sizeof(Disk));
        newDisk->size = i + 1;
        newDisk->color = 'A' + i;
        newDisk->next = NULL;

        if (top == NULL) {
            top = newDisk;
        } else {
            middle->next = newDisk;
            middle = newDisk;
        }
    }

    Hanoi(MAX_DISKS, top, middle, bottom);

    return 0;
}