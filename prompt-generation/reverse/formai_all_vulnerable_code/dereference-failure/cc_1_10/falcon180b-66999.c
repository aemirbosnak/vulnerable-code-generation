//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_ROOM_SIZE 10
#define MAX_ROOM_ITEMS 5

struct room {
    int x, y;
    char symbol;
    int items[MAX_ROOM_ITEMS];
};

struct dungeon {
    int num_rooms;
    struct room rooms[MAX_ROOMS];
};

void generate_dungeon(struct dungeon *dungeon) {
    int num_rooms = rand() % (MAX_ROOMS - 2) + 2;
    int room_size = rand() % MAX_ROOM_SIZE + 1;
    int x, y;

    for (int i = 0; i < num_rooms; i++) {
        do {
            x = rand() % room_size;
            y = rand() % room_size;
        } while (x == 0 || y == 0 || x == room_size - 1 || y == room_size - 1);

        dungeon->rooms[i].x = x;
        dungeon->rooms[i].y = y;
        dungeon->rooms[i].symbol = rand() % 26 + 'A';
    }
}

void generate_items(struct dungeon *dungeon) {
    int num_items = rand() % MAX_ROOM_ITEMS + 1;

    for (int i = 0; i < num_items; i++) {
        dungeon->rooms[rand() % dungeon->num_rooms].items[i] = rand() % 10 + 1;
    }
}

void print_dungeon(struct dungeon *dungeon) {
    for (int i = 0; i < dungeon->num_rooms; i++) {
        printf("%c ", dungeon->rooms[i].symbol);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    struct dungeon dungeon;
    generate_dungeon(&dungeon);
    generate_items(&dungeon);

    print_dungeon(&dungeon);

    return 0;
}