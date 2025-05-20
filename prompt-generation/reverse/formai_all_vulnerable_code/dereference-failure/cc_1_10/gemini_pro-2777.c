//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 25

#define PLAYER_CHAR '@'
#define WALL_CHAR '#'
#define FLOOR_CHAR '.'

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char** tiles;
    Position player_pos;
} Map;

void init_map(Map* map) {
    srand(time(NULL));

    map->tiles = malloc(sizeof(char*) * MAP_HEIGHT);
    for (int i = 0; i < MAP_HEIGHT; i++) {
        map->tiles[i] = malloc(sizeof(char) * MAP_WIDTH);
        for (int j = 0; j < MAP_WIDTH; j++) {
            map->tiles[i][j] = (rand() % 2 == 0) ? FLOOR_CHAR : WALL_CHAR;
        }
    }

    int x, y;
    do {
        x = rand() % MAP_WIDTH;
        y = rand() % MAP_HEIGHT;
    } while (map->tiles[y][x] != FLOOR_CHAR);

    map->player_pos.x = x;
    map->player_pos.y = y;
}

void free_map(Map* map) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
}

void print_map(Map* map) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (map->player_pos.x == j && map->player_pos.y == i) {
                printf("%c", PLAYER_CHAR);
            } else {
                printf("%c", map->tiles[i][j]);
            }
        }
        printf("\n");
    }
}

void move_player(Map* map, int dx, int dy) {
    int new_x = map->player_pos.x + dx;
    int new_y = map->player_pos.y + dy;

    if (map->tiles[new_y][new_x] != WALL_CHAR) {
        map->player_pos.x = new_x;
        map->player_pos.y = new_y;
    }
}

int main() {
    Map map;
    init_map(&map);

    print_map(&map);

    char input;
    while ((input = getchar()) != 'q') {
        switch (input) {
            case 'w':
                move_player(&map, 0, -1);
                break;
            case 's':
                move_player(&map, 0, 1);
                break;
            case 'a':
                move_player(&map, -1, 0);
                break;
            case 'd':
                move_player(&map, 1, 0);
                break;
        }

        print_map(&map);
    }

    free_map(&map);

    return 0;
}