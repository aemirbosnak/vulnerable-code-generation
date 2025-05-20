//GEMINI-pro DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int x, y;
} Vec2i;

typedef enum {
    NORTH, EAST, SOUTH, WEST
} Direction;

typedef struct {
    Vec2i pos;
    Direction dir;
} Player;

typedef struct {
    int width, height;
    char** tiles;
} Level;

Level* level_create(int width, int height) {
    Level* level = malloc(sizeof(Level));
    level->width = width;
    level->height = height;
    level->tiles = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        level->tiles[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            level->tiles[i][j] = '.';
        }
    }
    return level;
}

void level_destroy(Level* level) {
    for (int i = 0; i < level->height; i++) {
        free(level->tiles[i]);
    }
    free(level->tiles);
    free(level);
}

void level_print(Level* level) {
    for (int i = 0; i < level->height; i++) {
        for (int j = 0; j < level->width; j++) {
            printf("%c", level->tiles[i][j]);
        }
        printf("\n");
    }
}

Player* player_create(int x, int y, Direction dir) {
    Player* player = malloc(sizeof(Player));
    player->pos.x = x;
    player->pos.y = y;
    player->dir = dir;
    return player;
}

void player_destroy(Player* player) {
    free(player);
}

void player_move(Player* player, Level* level) {
    switch (player->dir) {
        case NORTH:
            if (player->pos.y > 0) {
                player->pos.y--;
            }
            break;
        case EAST:
            if (player->pos.x < level->width - 1) {
                player->pos.x++;
            }
            break;
        case SOUTH:
            if (player->pos.y < level->height - 1) {
                player->pos.y++;
            }
            break;
        case WEST:
            if (player->pos.x > 0) {
                player->pos.x--;
            }
            break;
    }
}

void player_turn(Player* player, Direction dir) {
    player->dir = dir;
}

int main() {
    Level* level = level_create(80, 25);
    Player* player = player_create(40, 12, NORTH);

    while (1) {
        level_print(level);
        printf("\n");

        char input;
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                player_move(player, level);
                break;
            case 'd':
                player_turn(player, EAST);
                break;
            case 's':
                player_turn(player, SOUTH);
                break;
            case 'a':
                player_turn(player, WEST);
                break;
            case 'q':
                exit(0);
        }
    }

    level_destroy(level);
    player_destroy(player);

    return 0;
}