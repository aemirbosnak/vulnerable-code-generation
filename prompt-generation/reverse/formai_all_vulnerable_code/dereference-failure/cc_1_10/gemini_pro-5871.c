//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct {
    int x, y;
    char type;
} Tile;

Tile **map;
int map_width, map_height;

void init_map() {
    srand(time(NULL));
    map_width = 100;
    map_height = 100;
    map = malloc(sizeof(Tile *) * map_height);
    for (int i = 0; i < map_height; i++) {
        map[i] = malloc(sizeof(Tile) * map_width);
    }
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            map[i][j].x = j;
            map[i][j].y = i;
            map[i][j].type = rand() % 2 == 0 ? '.' : '#';
        }
    }
}

void free_map() {
    for (int i = 0; i < map_height; i++) {
        free(map[i]);
    }
    free(map);
}

void print_map() {
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            printf("%c", map[i][j].type);
        }
        printf("\n");
    }
}

int main() {
    init_map();
    print_map();
    free_map();
    return 0;
}