//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define MAX_WATER 10

typedef struct WaterDrop {
    int x;
    int y;
    struct WaterDrop* next;
} WaterDrop;

WaterDrop* createWaterDrop() {
    WaterDrop* drop = malloc(sizeof(WaterDrop));
    drop->x = -1;
    drop->y = -1;
    drop->next = NULL;
    return drop;
}

void addWaterDrop(WaterDrop* head, int x, int y) {
    WaterDrop* newDrop = createWaterDrop();
    newDrop->x = x;
    newDrop->y = y;
    newDrop->next = head;
    head = newDrop;
}

void simulatePercolation(WaterDrop* head) {
    srand(time(NULL));
    for (int i = 0; i < MAX_WATER; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        addWaterDrop(head, x, y);
    }

    for (WaterDrop* drop = head; drop; drop = drop->next) {
        int x = drop->x;
        int y = drop->y;
        int neighbors = 0;
        if (x > 0) neighbors++;
        if (x < WIDTH - 1) neighbors++;
        if (y > 0) neighbors++;
        if (y < HEIGHT - 1) neighbors++;

        if (neighbors > 0) {
            drop->x = -1;
            drop->y = -1;
        }
    }

    for (WaterDrop* drop = head; drop; drop = drop->next) {
        if (drop->x != -1 && drop->y != -1) {
            printf("(%d, %d)\n", drop->x, drop->y);
        }
    }
}

int main() {
    WaterDrop* head = createWaterDrop();
    simulatePercolation(head);
    return 0;
}