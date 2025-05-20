//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 6

typedef struct room {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct map {
    char tiles[MAP_HEIGHT][MAP_WIDTH];
} Map;

void print_map(Map *map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map->tiles[y][x]);
        }
        printf("\n");
    }
}

void fill_map(Map *map, char tile) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map->tiles[y][x] = tile;
        }
    }
}

Room *generate_room() {
    Room *room = malloc(sizeof(Room));
    room->width = rand() % 6 + 4;
    room->height = rand() % 4 + 3;
    room->x = rand() % (MAP_WIDTH - room->width - 1) + 1;
    room->y = rand() % (MAP_HEIGHT - room->height - 1) + 1;
    return room;
}

void generate_rooms(Room *rooms[MAX_ROOMS]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room *room = generate_room();
        rooms[i] = room;
    }
}

void connect_rooms(Room *room1, Room *room2, Map *map) {
    int x = room1->x + room1->width / 2;
    int y = room1->y + room1->height / 2;
    while (x != room2->x + room2->width / 2) {
        if (map->tiles[y][x] != '.') map->tiles[y][x] = '#';
        x += (x < room2->x + room2->width / 2) ? 1 : -1;
    }
    while (y != room2->y + room2->height / 2) {
        if (map->tiles[y][x] != '.') map->tiles[y][x] = '#';
        y += (y < room2->y + room2->height / 2) ? 1 : -1;
    }
}

void generate_map(Map *map) {
    Room *rooms[MAX_ROOMS];
    generate_rooms(rooms);
    fill_map(map, ' ');
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room *room = rooms[i];
        for (int y = room->y; y < room->y + room->height; y++) {
            for (int x = room->x; x < room->x + room->width; x++) {
                if ((x == room->x) || (x == room->x + room->width - 1) || 
                    (y == room->y) || (y == room->y + room->height - 1)) {
                    map->tiles[y][x] = '#';
                } else {
                    map->tiles[y][x] = '.';
                }
            }
        }
    }
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        Room *room1 = rooms[i];
        Room *room2 = rooms[i+1];
        connect_rooms(room1, room2, map);
    }
}

int main() {
    srand(time(NULL));
    Map map;
    generate_map(&map);
    print_map(&map);
    return 0;
}