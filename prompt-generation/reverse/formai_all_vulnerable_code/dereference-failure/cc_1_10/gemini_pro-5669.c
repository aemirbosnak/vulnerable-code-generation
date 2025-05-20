//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's ship
typedef struct ship {
    int x;
    int y;
    int health;
    int fuel;
} ship;

// Define the game world
typedef struct world {
    int width;
    int height;
    char **map;
} world;

// Create a new ship
ship *create_ship(int x, int y) {
    ship *new_ship = (ship *)malloc(sizeof(ship));
    new_ship->x = x;
    new_ship->y = y;
    new_ship->health = 100;
    new_ship->fuel = 100;
    return new_ship;
}

// Create a new world
world *create_world(int width, int height) {
    world *new_world = (world *)malloc(sizeof(world));
    new_world->width = width;
    new_world->height = height;
    new_world->map = (char **)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        new_world->map[i] = (char *)malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            new_world->map[i][j] = '.';
        }
    }
    return new_world;
}

// Draw the game world
void draw_world(world *world) {
    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            printf("%c", world->map[i][j]);
        }
        printf("\n");
    }
}

// Move the ship
void move_ship(ship *ship, world *world, char direction) {
    switch (direction) {
        case 'w':
            if (ship->y > 0) {
                ship->y--;
            }
            break;
        case 'a':
            if (ship->x > 0) {
                ship->x--;
            }
            break;
        case 's':
            if (ship->y < world->height - 1) {
                ship->y++;
            }
            break;
        case 'd':
            if (ship->x < world->width - 1) {
                ship->x++;
            }
            break;
    }
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game world
    world *world = create_world(100, 100);

    // Create the player's ship
    ship *player_ship = create_ship(50, 50);

    // Draw the initial game state
    draw_world(world);

    // Game loop
    while (1) {
        // Get the player's input
        char input = getchar();

        // Move the ship
        move_ship(player_ship, world, input);

        // Draw the updated game state
        draw_world(world);
    }

    return 0;
}