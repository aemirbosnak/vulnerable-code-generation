//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: invasive
#include <stdlib.h>
#include <stdio.h>

#define MAX_ROOM_SIZE 10
#define MAX_MONSTER_COUNT 5

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
    char** map;
    int monsters_spawned;
} Room;

Room* generate_room(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->map = malloc(MAX_ROOM_SIZE * MAX_ROOM_SIZE * sizeof(char));
    for (int i = 0; i < MAX_ROOM_SIZE; i++) {
        for (int j = 0; j < MAX_ROOM_SIZE; j++) {
            room->map[i][j] = '#';
        }
    }
    room->map[x][y] = 'O';
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    room->monsters_spawned = 0;
    return room;
}

void spawn_monsters(Room* room) {
    for (int i = 0; i < room->monsters_spawned; i++) {
        // Spawn monster
    }
}

void print_room(Room* room) {
    for (int i = 0; i < MAX_ROOM_SIZE; i++) {
        for (int j = 0; j < MAX_ROOM_SIZE; j++) {
            printf("%c ", room->map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Room* room = generate_room(5, 5);
    spawn_monsters(room);
    print_room(room);

    return 0;
}