//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's ship
typedef struct {
    int health;
    int energy;
    int fuel;
    int x;
    int y;
} ship;

// Define the game world
typedef struct {
    int width;
    int height;
    char **map;
} world;

// Define the game state
typedef struct {
    ship player;
    world world;
} game;

// Create a new game
game *new_game() {
    game *g = malloc(sizeof(game));
    g->player.health = 100;
    g->player.energy = 100;
    g->player.fuel = 100;
    g->player.x = 0;
    g->player.y = 0;
    g->world.width = 100;
    g->world.height = 100;
    g->world.map = malloc(sizeof(char *) * g->world.height);
    for (int i = 0; i < g->world.height; i++) {
        g->world.map[i] = malloc(sizeof(char) * g->world.width);
        for (int j = 0; j < g->world.width; j++) {
            g->world.map[i][j] = '.';
        }
    }
    return g;
}

// Free the game
void free_game(game *g) {
    for (int i = 0; i < g->world.height; i++) {
        free(g->world.map[i]);
    }
    free(g->world.map);
    free(g);
}

// Draw the game world
void draw_world(game *g) {
    for (int i = 0; i < g->world.height; i++) {
        for (int j = 0; j < g->world.width; j++) {
            printf("%c", g->world.map[i][j]);
        }
        printf("\n");
    }
}

// Update the game state
void update_game(game *g) {
    // Get the player's input
    char input = getchar();

    // Move the player's ship
    switch (input) {
        case 'w':
            g->player.y--;
            break;
        case 'a':
            g->player.x--;
            break;
        case 's':
            g->player.y++;
            break;
        case 'd':
            g->player.x++;
            break;
    }

    // Check if the player's ship has collided with anything
    if (g->world.map[g->player.y][g->player.x] != '.') {
        g->player.health--;
    }

    // Update the player's energy and fuel
    g->player.energy--;
    g->player.fuel--;
}

// Check if the game is over
int game_over(game *g) {
    return g->player.health <= 0 || g->player.energy <= 0 || g->player.fuel <= 0;
}

// Main game loop
int main() {
    // Create a new game
    game *g = new_game();

    // Draw the game world
    draw_world(g);

    // Update the game state
    while (!game_over(g)) {
        update_game(g);
        draw_world(g);
    }

    // Free the game
    free_game(g);

    return 0;
}