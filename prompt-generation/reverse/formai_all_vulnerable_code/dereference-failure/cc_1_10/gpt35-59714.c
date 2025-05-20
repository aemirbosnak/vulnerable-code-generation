//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_X 50
#define MAP_SIZE_Y 20
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 6

typedef struct {
    int x, y, w, h;
} room_t;

typedef struct {
    char tile;
    int x, y;
} map_t;

void generate_map(map_t *map, room_t *rooms, int num_rooms) {
    // Set all tiles to wall
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            map[y * MAP_SIZE_X + x].tile = '#';
            map[y * MAP_SIZE_X + x].x = x;
            map[y * MAP_SIZE_X + x].y = y;
        }
    }
    // Generate rooms
    for (int r = 0; r < num_rooms; r++) {
        int w = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int h = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int x = rand() % (MAP_SIZE_X - w - 1) + 1;
        int y = rand() % (MAP_SIZE_Y - h - 1) + 1;
        rooms[r].x = x;
        rooms[r].y = y;
        rooms[r].w = w;
        rooms[r].h = h;
        // Set room tiles to floor
        for (int j = y; j < y + h; j++) {
            for (int i = x; i < x + w; i++) {
                map[j * MAP_SIZE_X + i].tile = '.';
            }
        }
    }
    // Generate corridors
    for (int r = 0; r < num_rooms - 1; r++) {
        int x1 = rooms[r].x + rooms[r].w / 2;
        int y1 = rooms[r].y + rooms[r].h / 2;
        int x2 = rooms[r + 1].x + rooms[r + 1].w / 2;
        int y2 = rooms[r + 1].y + rooms[r + 1].h / 2;
        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
            } else if (x1 > x2) {
                x1--;
            }
            if (y1 < y2) {
                y1++;
            } else if (y1 > y2) {
                y1--;
            }
            // Set corridor tiles to floor
            map[y1 * MAP_SIZE_X + x1].tile = '.';
        }
    }
}

void print_map(map_t *map) {
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            printf("%c", map[y * MAP_SIZE_X + x].tile);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    map_t *map = malloc(sizeof(map_t) * MAP_SIZE_X * MAP_SIZE_Y);
    room_t rooms[MAX_ROOMS];
    const int num_rooms = rand() % (MAX_ROOMS - 2 + 1) + 2; // Generate random number of rooms (at least 2)
    generate_map(map, rooms, num_rooms);
    print_map(map);
    free(map);
    return 0;
}