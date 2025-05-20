//GEMINI-pro DATASET v1.0 Category: Pac-Man Game Clone ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define MAP_WIDTH 28
#define MAP_HEIGHT 31
#define PACMAN_START_X 14
#define PACMAN_START_Y 23

// Enumerations
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

// Structs
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    Direction direction;
    bool alive;
} Pacman;

typedef struct {
    char **map;
    Pacman pacman;
} Game;

// Functions
void initMap(Game *game);
void printMap(Game *game);
void movePacman(Game *game, Direction direction);
bool isWall(Game *game, Position position);

// Main function
int main() {
    // Initialize game
    Game game;
    initMap(&game);
    game.pacman.position.x = PACMAN_START_X;
    game.pacman.position.y = PACMAN_START_Y;
    game.pacman.direction = RIGHT;
    game.pacman.alive = true;

    // Main game loop
    while (game.pacman.alive) {
        // Get input
        char input;
        printf("Enter direction (u/d/l/r): ");
        scanf(" %c", &input);

        // Move pacman
        switch (input) {
            case 'u':
                movePacman(&game, UP);
                break;
            case 'd':
                movePacman(&game, DOWN);
                break;
            case 'l':
                movePacman(&game, LEFT);
                break;
            case 'r':
                movePacman(&game, RIGHT);
                break;
        }

        // Print map
        printMap(&game);
    }

    // Game over
    printf("Game over!\n");

    return 0;
}

// Function definitions
void initMap(Game *game) {
    // Allocate memory for map
    game->map = malloc(MAP_HEIGHT * sizeof(char *));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        game->map[i] = malloc(MAP_WIDTH * sizeof(char));
    }

    // Initialize map
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                game->map[i][j] = '#';
            } else if ((i == 7 || i == 11 || i == 15) && (j == 1 || j == 7 || j == 13 || j == 19 || j == 25)) {
                game->map[i][j] = '#';
            } else {
                game->map[i][j] = ' ';
            }
        }
    }
}

void printMap(Game *game) {
    // Print top border
    printf("+");
    for (int i = 0; i < MAP_WIDTH; i++) {
        printf("-");
    }
    printf("+\n");

    // Print map
    for (int i = 0; i < MAP_HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (game->pacman.position.x == j && game->pacman.position.y == i) {
                printf("O");
            } else {
                printf("%c", game->map[i][j]);
            }
        }
        printf("|\n");
    }

    // Print bottom border
    printf("+");
    for (int i = 0; i < MAP_WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
}

void movePacman(Game *game, Direction direction) {
    // Get new position
    Position newPosition;
    newPosition.x = game->pacman.position.x;
    newPosition.y = game->pacman.position.y;

    switch (direction) {
        case UP:
            newPosition.y--;
            break;
        case DOWN:
            newPosition.y++;
            break;
        case LEFT:
            newPosition.x--;
            break;
        case RIGHT:
            newPosition.x++;
            break;
    }

    // Check if new position is valid
    if (!isWall(game, newPosition)) {
        // Move pacman
        game->pacman.position = newPosition;
    }
}

bool isWall(Game *game, Position position) {
    return game->map[position.y][position.x] == '#';
}