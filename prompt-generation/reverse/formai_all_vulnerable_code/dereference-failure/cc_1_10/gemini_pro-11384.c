//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Procedural space adventure game
// Creates a random universe of stars and planets, and allows the player to explore it

// Universe struct
typedef struct {
    int width;
    int height;
    char** grid;
} Universe;

// Player struct
typedef struct {
    int x;
    int y;
} Player;

// Create a new universe
Universe* create_universe(int width, int height) {
    Universe* universe = malloc(sizeof(Universe));
    universe->width = width;
    universe->height = height;
    universe->grid = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        universe->grid[i] = malloc(sizeof(char) * width);
    }
    // Initialize the universe with random stars and planets
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (rand() % 100 < 10) {
                universe->grid[i][j] = '*'; // Star
            } else if (rand() % 100 < 20) {
                universe->grid[i][j] = 'o'; // Planet
            } else {
                universe->grid[i][j] = ' '; // Empty space
            }
        }
    }
    return universe;
}

// Free the universe
void free_universe(Universe* universe) {
    for (int i = 0; i < universe->height; i++) {
        free(universe->grid[i]);
    }
    free(universe->grid);
    free(universe);
}

// Create a new player
Player* create_player(int x, int y) {
    Player* player = malloc(sizeof(Player));
    player->x = x;
    player->y = y;
    return player;
}

// Free the player
void free_player(Player* player) {
    free(player);
}

// Move the player
void move_player(Player* player, int dx, int dy) {
    player->x += dx;
    player->y += dy;
}

// Draw the universe
void draw_universe(Universe* universe) {
    for (int i = 0; i < universe->height; i++) {
        for (int j = 0; j < universe->width; j++) {
            printf("%c", universe->grid[i][j]);
        }
        printf("\n");
    }
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the universe
    Universe* universe = create_universe(80, 25);

    // Create the player
    Player* player = create_player(universe->width / 2, universe->height / 2);

    // Game loop
    while (1) {
        // Draw the universe
        draw_universe(universe);

        // Get the player's input
        char input = getchar();

        // Move the player
        switch (input) {
            case 'w':
                move_player(player, 0, -1);
                break;
            case 's':
                move_player(player, 0, 1);
                break;
            case 'a':
                move_player(player, -1, 0);
                break;
            case 'd':
                move_player(player, 1, 0);
                break;
            case 'q':
                exit(0);
        }

        // Check if the player has collided with anything
        if (universe->grid[player->y][player->x] == '*') {
            printf("You collided with a star!\n");
            exit(0);
        } else if (universe->grid[player->y][player->x] == 'o') {
            printf("You landed on a planet!\n");
            exit(0);
        }
    }

    // Free the universe and the player
    free_universe(universe);
    free_player(player);

    return 0;
}