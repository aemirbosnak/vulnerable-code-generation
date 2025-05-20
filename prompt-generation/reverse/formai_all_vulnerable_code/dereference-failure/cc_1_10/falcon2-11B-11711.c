//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ROOM_X 40
#define MAX_ROOM_Y 30
#define MAX_ROOM_NUM 200

// Map data structure
typedef struct {
    char** room;
    int room_num;
    int x_size;
    int y_size;
} map_t;

// Create a new room
map_t* create_map() {
    map_t* map = malloc(sizeof(map_t));
    map->room = (char**)malloc(MAX_ROOM_NUM * sizeof(char*));
    map->room_num = MAX_ROOM_NUM;
    map->x_size = MAX_ROOM_X;
    map->y_size = MAX_ROOM_Y;

    for (int i = 0; i < MAX_ROOM_NUM; i++) {
        map->room[i] = (char*)malloc(MAX_ROOM_X * MAX_ROOM_Y * sizeof(char));
    }

    return map;
}

// Print the map
void print_map(map_t* map) {
    for (int y = 0; y < map->y_size; y++) {
        for (int x = 0; x < map->x_size; x++) {
            printf("%c", map->room[y][x]);
        }
        printf("\n");
    }
}

// Generate a map
map_t* generate_map() {
    srand(time(0));
    map_t* map = create_map();

    for (int i = 0; i < MAX_ROOM_NUM; i++) {
        int x_start = rand() % MAX_ROOM_X + 1;
        int y_start = rand() % MAX_ROOM_Y + 1;
        int x_size = rand() % (MAX_ROOM_X / 2) + 1;
        int y_size = rand() % (MAX_ROOM_Y / 2) + 1;

        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                map->room[y][x] = '#';
            }
        }

        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                if (rand() % 100 < 50) {
                    map->room[y + y_start][x + x_start] = '.';
                }
            }
        }
    }

    return map;
}

// Main program
int main() {
    map_t* map = generate_map();
    print_map(map);

    free(map->room);
    free(map);

    return 0;
}