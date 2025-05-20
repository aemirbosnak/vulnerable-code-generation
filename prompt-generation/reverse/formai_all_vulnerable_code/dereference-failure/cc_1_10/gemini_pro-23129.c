//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAP_SIZE 100
#define NUM_ROOMS 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int size;
} Room;

typedef struct {
    Room *rooms;
    int num_rooms;
} Map;

Map *generate_map() {
    Map *map = malloc(sizeof(Map));
    map->rooms = malloc(sizeof(Room) * NUM_ROOMS);
    map->num_rooms = NUM_ROOMS;

    for (int i = 0; i < NUM_ROOMS; i++) {
        map->rooms[i].pos.x = rand() % MAP_SIZE;
        map->rooms[i].pos.y = rand() % MAP_SIZE;
        map->rooms[i].size = rand() % 10 + 1;
    }

    return map;
}

void print_map(Map *map) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            char c = '.';
            for (int k = 0; k < map->num_rooms; k++) {
                Room *room = &map->rooms[k];
                if (i >= room->pos.x && i < room->pos.x + room->size &&
                    j >= room->pos.y && j < room->pos.y + room->size) {
                    c = '#';
                }
            }
            printf("%c", c);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Map *map = generate_map();

    print_map(map);

    return 0;
}