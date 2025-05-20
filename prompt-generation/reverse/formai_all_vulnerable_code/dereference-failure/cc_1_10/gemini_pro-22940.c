//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

#define PLAYER 'O'
#define WALL 'X'
#define GOAL 'G'

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char **map;
    Point player;
} Game;

// Create a new game
Game *new_game() {
    Game *game = malloc(sizeof(Game));

    // Create the map
    game->map = malloc(sizeof(char *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        game->map[i] = malloc(sizeof(char) * WIDTH);
    }

    // Initialize the map
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            game->map[i][j] = ' ';
        }
    }

    // Place the player
    game->player.x = WIDTH / 2;
    game->player.y = HEIGHT / 2;

    // Place the goal
    game->map[HEIGHT - 1][WIDTH - 1] = GOAL;

    return game;
}

// Free the game
void free_game(Game *game) {
    // Free the map
    for (int i = 0; i < HEIGHT; i++) {
        free(game->map[i]);
    }
    free(game->map);

    // Free the game
    free(game);
}

// Draw the game
void draw_game(Game *game) {
    // Clear the screen
    printf("\033[2J");

    // Draw the map
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (game->map[i][j] == PLAYER) {
                printf("\033[41;30m%c\033[0m", game->map[i][j]);
            } else {
                printf("%c", game->map[i][j]);
            }
        }
        printf("\n");
    }
}

// Update the game
void update_game(Game *game, char key) {
    switch (key) {
        case UP:
            if (game->player.y > 0 && game->map[game->player.y - 1][game->player.x] != WALL) {
                game->player.y--;
            }
            break;
        case DOWN:
            if (game->player.y < HEIGHT - 1 && game->map[game->player.y + 1][game->player.x] != WALL) {
                game->player.y++;
            }
            break;
        case LEFT:
            if (game->player.x > 0 && game->map[game->player.y][game->player.x - 1] != WALL) {
                game->player.x--;
            }
            break;
        case RIGHT:
            if (game->player.x < WIDTH - 1 && game->map[game->player.y][game->player.x + 1] != WALL) {
                game->player.x++;
            }
            break;
    }
}

// Check if the player has won
int has_won(Game *game) {
    return game->player.x == WIDTH - 1 && game->player.y == HEIGHT - 1;
}

int main() {
    // Create a new game
    Game *game = new_game();

    // Draw the game
    draw_game(game);

    // Get input from the player
    char key;
    while ((key = getchar()) != 'q') {
        // Update the game
        update_game(game, key);

        // Draw the game
        draw_game(game);

        // Check if the player has won
        if (has_won(game)) {
            printf("You win!\n");
            break;
        }
    }

    // Free the game
    free_game(game);

    return 0;
}