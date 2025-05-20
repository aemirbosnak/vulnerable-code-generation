//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define NUM_ROOMS 10

typedef struct {
    int x, y;
    char symbol;
} Cell;

typedef struct {
    int num_rooms;
    Cell *rooms[NUM_ROOMS];
} Dungeon;

void generate_dungeon(Dungeon *dungeon) {
    int i;
    srand(time(NULL));

    for (i = 0; i < NUM_ROOMS; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        Cell *room = &dungeon->rooms[i];

        room->x = x;
        room->y = y;
        room->symbol = '.';

        if (i % 2 == 0) {
            room->symbol = '|';
        } else if (i % 2 == 1) {
            room->symbol = '-';
        }
    }
}

void print_dungeon(Dungeon *dungeon) {
    int i;

    for (i = 0; i < HEIGHT; ++i) {
        printf("\n");
    }

    for (i = 0; i < NUM_ROOMS; ++i) {
        Cell *room = &dungeon->rooms[i];

        printf("%c ", room->symbol);
    }
}

int main() {
    Dungeon dungeon;
    generate_dungeon(&dungeon);
    print_dungeon(&dungeon);

    return 0;
}