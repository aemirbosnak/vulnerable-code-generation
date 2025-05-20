//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

enum direction {UP, DOWN, LEFT, RIGHT};

typedef struct {
    int x, y, dx, dy;
} coord;

typedef struct {
    coord position;
    enum direction direction;
} game_state;

game_state* initialize_game(int width, int height) {
    game_state* game = (game_state*)malloc(sizeof(game_state));
    game->position.x = (rand() % (width - 1)) + 1;
    game->position.y = (rand() % (height - 1)) + 1;
    game->direction = UP;
    return game;
}

void print_game_state(game_state* game) {
    printf("(x=%d, y=%d) %s\n", game->position.x, game->position.y,
           (game->direction == UP)? "UP" :
           (game->direction == DOWN)? "DOWN" :
           (game->direction == LEFT)? "LEFT" : "RIGHT");
}

int main() {
    int width = 10, height = 10;
    game_state* game = initialize_game(width, height);

    while (1) {
        print_game_state(game);

        switch (game->direction) {
            case UP:
                if (game->position.y == 1) {
                    game->position.y = height - 1;
                    game->direction = DOWN;
                } else {
                    game->position.y--;
                }
                break;
            case DOWN:
                if (game->position.y == height) {
                    game->position.y = 1;
                    game->direction = UP;
                } else {
                    game->position.y++;
                }
                break;
            case LEFT:
                if (game->position.x == 1) {
                    game->position.x = width - 1;
                    game->direction = RIGHT;
                } else {
                    game->position.x--;
                }
                break;
            case RIGHT:
                if (game->position.x == width) {
                    game->position.x = 1;
                    game->direction = LEFT;
                } else {
                    game->position.x++;
                }
                break;
        }
    }

    free(game);
    return 0;
}