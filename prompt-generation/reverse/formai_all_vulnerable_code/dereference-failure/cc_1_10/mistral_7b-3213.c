//MISTRAL-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 10
#define ROOM_MIN 3
#define ROOM_MAX 7

typedef struct {
    int x, y;
} position;

typedef struct {
    int type;
    int value;
} item;

typedef struct {
    int hp;
    int max_hp;
    int xp;
    int level;
} player;

typedef struct {
    int width, height;
    int **map;
    int room_count;
    position room_pos[ROOM_MAX];
} game;

void generate_room(game *game, int room_x, int room_y, int room_width, int room_height) {
    int i, j;
    game->map[room_y + room_height][room_x + room_width] = 1;
    for (i = room_y; i < room_y + room_height; i++) {
        for (j = room_x; j < room_x + room_width; j++) {
            if (i == room_y || i == room_y + room_height - 1 || j == room_x || j == room_x + room_width - 1) {
                game->map[i][j] = 2;
            } else {
                game->map[i][j] = 0;
            }
        }
    }
    game->room_pos[game->room_count++] = (position){room_x, room_y};
}

void generate_map(game *game) {
    int i, j, x, y, room_width, room_height;
    srand(time(NULL));

    game->map = malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++) {
        game->map[i] = calloc(WIDTH, sizeof(int));
    }

    game->map[0] = calloc(WIDTH, sizeof(int) + 1);
    game->map[HEIGHT - 1] = calloc(WIDTH, sizeof(int) + 1);

    for (i = 0; i < HEIGHT && game->room_count < ROOM_MAX; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (game->map[i][j] == 0) {
                x = j;
                y = i;
                room_width = rand() % (WIDTH / 2 + 1) + 1;
                room_height = rand() % (HEIGHT / 2 + 1) + 1;

                if (x + room_width > WIDTH) {
                    x -= room_width;
                }
                if (y + room_height > HEIGHT) {
                    y -= room_height;
                }

                generate_room(game, x, y, room_width, room_height);
            }
        }
    }
}

int main() {
    game game;
    generate_map(&game);

    // Add player and enemy classes, game loop, input handling, etc.

    return 0;
}