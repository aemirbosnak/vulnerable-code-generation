//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 20

typedef struct Room {
    int x, y;
    char name[20];
    struct Room* north, *south, *east, *west;
} Room;

Room** create_map(int size) {
    Room** map = malloc(size * sizeof(Room*));
    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(Room));
        map[i]->x = -1;
        map[i]->y = -1;
        map[i]->name[0] = '\0';
        map[i]->north = NULL;
        map[i]->south = NULL;
        map[i]->east = NULL;
        map[i]->west = NULL;
    }
    return map;
}

void generate_map(Room** map, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        map[i]->x = rand() % size;
        map[i]->y = rand() % size;
        sprintf(map[i]->name, "Room %d", i + 1);
    }
}

void connect_rooms(Room** map, int size) {
    for (int i = 0; i < size; i++) {
        int num_connections = rand() % 3;
        switch (num_connections) {
            case 0:
                break;
            case 1:
                map[i]->north = map[rand() % size];
                break;
            case 2:
                map[i]->north = map[rand() % size];
                map[i]->east = map[rand() % size];
                break;
            case 3:
                map[i]->north = map[rand() % size];
                map[i]->east = map[rand() % size];
                map[i]->south = map[rand() % size];
                break;
        }
    }
}

int main() {
    int map_size = 10;
    Room** map = create_map(map_size);
    generate_map(map, map_size);
    connect_rooms(map, map_size);

    // Print the map
    for (int i = 0; i < map_size; i++) {
        printf("Room %d: (%d, %d) - %s\n", i + 1, map[i]->x, map[i]->y, map[i]->name);
    }

    return 0;
}