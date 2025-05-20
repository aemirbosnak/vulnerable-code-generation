//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

typedef enum {
    EMPTY,
    WALL,
    FLOOR
} Tile;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Tile map[MAP_HEIGHT][MAP_WIDTH];
    Position player_pos;
} Map;

Map* create_map() {
    Map* map = malloc(sizeof(Map));
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1)
                map->map[i][j] = WALL;
            else
                map->map[i][j] = FLOOR;
        }
    }
    map->player_pos.x = MAP_WIDTH / 2;
    map->player_pos.y = MAP_HEIGHT / 2;
    return map;
}

void print_map(Map* map) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == map->player_pos.y && j == map->player_pos.x)
                printf("@");
            else if (map->map[i][j] == WALL)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

void generate_map(Map* map) {
    srand(time(NULL));
    int i, j;
    for (i = 1; i < MAP_HEIGHT - 1; i++) {
        for (j = 1; j < MAP_WIDTH - 1; j++) {
            if (rand() % 100 < 45)
                map->map[i][j] = WALL;
        }
    }
}

int main() {
    Map* map = create_map();
    generate_map(map);
    print_map(map);
    free(map);
    return 0;
}