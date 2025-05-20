//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 25

typedef struct {
    int x;
    int y;
    char symbol;
} Entity;

typedef struct {
    char **map;
    Entity player;
    Entity monster;
} Game;

void initializeGame(Game *game) {
    // Allocate memory for the map
    game->map = malloc(sizeof(char *) * MAP_HEIGHT);
    for (int i = 0; i < MAP_HEIGHT; i++) {
        game->map[i] = malloc(sizeof(char) * MAP_WIDTH);
    }

    // Initialize the map
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                game->map[i][j] = '#';
            } else {
                game->map[i][j] = ' ';
            }
        }
    }

    // Initialize the player
    game->player.x = MAP_WIDTH / 2;
    game->player.y = MAP_HEIGHT / 2;
    game->player.symbol = '@';

    // Initialize the monster
    game->monster.x = rand() % (MAP_WIDTH - 2) + 1;
    game->monster.y = rand() % (MAP_HEIGHT - 2) + 1;
    game->monster.symbol = 'M';
}

void drawGame(Game *game) {
    // Clear the screen
    system("clear");

    // Draw the map
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", game->map[i][j]);
        }
        printf("\n");
    }

    // Draw the player
    game->map[game->player.y][game->player.x] = game->player.symbol;

    // Draw the monster
    game->map[game->monster.y][game->monster.x] = game->monster.symbol;
}

void movePlayer(Game *game, int dx, int dy) {
    // Check if the player is moving into a wall
    if (game->map[game->player.y + dy][game->player.x + dx] == '#') {
        return;
    }

    // Check if the player is moving into the monster
    if (game->monster.x == game->player.x + dx && game->monster.y == game->player.y + dy) {
        printf("You lose!\n");
        exit(0);
    }

    // Move the player
    game->player.x += dx;
    game->player.y += dy;
}

void moveMonster(Game *game) {
    // Get the player's position
    int playerX = game->player.x;
    int playerY = game->player.y;

    // Calculate the distance between the player and the monster
    int dx = playerX - game->monster.x;
    int dy = playerY - game->monster.y;

    // Move the monster towards the player
    if (abs(dx) > abs(dy)) {
        if (dx > 0) {
            game->monster.x--;
        } else {
            game->monster.x++;
        }
    } else {
        if (dy > 0) {
            game->monster.y--;
        } else {
            game->monster.y++;
        }
    }

    // Check if the monster has caught the player
    if (game->monster.x == playerX && game->monster.y == playerY) {
        printf("You lose!\n");
        exit(0);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game
    Game game;
    initializeGame(&game);

    // Draw the game
    drawGame(&game);

    // Main game loop
    while (1) {
        // Get the player's input
        char input = getchar();

        // Move the player
        switch (input) {
            case 'w':
                movePlayer(&game, 0, -1);
                break;
            case 'a':
                movePlayer(&game, -1, 0);
                break;
            case 's':
                movePlayer(&game, 0, 1);
                break;
            case 'd':
                movePlayer(&game, 1, 0);
                break;
            case 'q':
                exit(0);
                break;
        }

        // Move the monster
        moveMonster(&game);

        // Draw the game
        drawGame(&game);

        // Check if the player has won
        if (game.player.x == game.monster.x && game.player.y == game.monster.y) {
            printf("You win!\n");
            exit(0);
        }
    }

    return 0;
}