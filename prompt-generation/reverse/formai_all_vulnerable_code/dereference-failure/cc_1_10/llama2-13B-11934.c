//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANTS 50
#define GRID_SIZE 10
#define FOOD_PROB 0.1
#define MAX_STEPS 1000

typedef struct {
    int x;
    int y;
} ant_t;

ant_t *ants;

void init_ants() {
    int i;
    for (i = 0; i < ANTS; i++) {
        ants[i].x = rand() % GRID_SIZE;
        ants[i].y = rand() % GRID_SIZE;
    }
}

void move_ants() {
    int i;
    for (i = 0; i < ANTS; i++) {
        if (rand() % 10 < FOOD_PROB) {
            ants[i].x += rand() % 2 - 1;
            ants[i].y += rand() % 2 - 1;
        } else {
            ants[i].x += (rand() % 2 - 1) * 2;
            ants[i].y += (rand() % 2 - 1) * 2;
        }
    }
}

void print_ants() {
    int i;
    for (i = 0; i < ANTS; i++) {
        printf("Ant %d is at (%d, %d)\n", i, ants[i].x, ants[i].y);
    }
}

int main() {
    srand(time(NULL));
    init_ants();
    for (int i = 0; i < MAX_STEPS; i++) {
        move_ants();
        print_ants();
    }
    return 0;
}