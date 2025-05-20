//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 20
#define PLAYER_SIZE 5

typedef struct Player {
    int x, y;
    char symbol;
} Player;

typedef struct Map {
    int **grid;
    Player player;
} Map;

void initializeMap(Map *map) {
    map->grid = malloc(MAP_SIZE * sizeof(int *));
    for (int i = 0; i < MAP_SIZE; i++) {
        map->grid[i] = malloc(MAP_SIZE * sizeof(int));
    }

    map->player.x = MAP_SIZE / 2;
    map->player.y = MAP_SIZE / 2;
    map->player.symbol = 'P';

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map->grid[i][j] = 0;
        }
    }

    map->grid[map->player.x][map->player.y] = map->player.symbol;
}

void drawMap(Map *map) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map->grid[i][j]);
        }

        printf("\n");
    }

    printf("Player position: (%d, %d)\n", map->player.x, map->player.y);
}

int main() {
    Map map;
    initializeMap(&map);

    drawMap(&map);

    return 0;
}