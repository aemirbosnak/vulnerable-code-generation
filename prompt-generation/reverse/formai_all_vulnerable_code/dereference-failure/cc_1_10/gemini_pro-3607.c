//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's ship
typedef struct {
    int x, y;         // Coordinates
    int fuel;         // Remaining fuel
    int shields;      // Shield strength
    int weapons;      // Weapon power
} Ship;

// Define the game world
typedef struct {
    int width, height;  // Dimensions
    char **map;        // Map of the world
} World;

// Create a new ship
Ship *create_ship() {
    Ship *ship = malloc(sizeof(Ship));
    ship->x = rand() % 100;
    ship->y = rand() % 100;
    ship->fuel = 100;
    ship->shields = 100;
    ship->weapons = 100;
    return ship;
}

// Create a new world
World *create_world() {
    World *world = malloc(sizeof(World));
    world->width = 100;
    world->height = 100;
    world->map = malloc(world->width * sizeof(char *));
    for (int i = 0; i < world->width; i++) {
        world->map[i] = malloc(world->height * sizeof(char));
    }
    for (int i = 0; i < world->width; i++) {
        for (int j = 0; j < world->height; j++) {
            world->map[i][j] = '.';
        }
    }
    return world;
}

// Print the game world
void print_world(World *world, Ship *ship) {
    for (int i = 0; i < world->width; i++) {
        for (int j = 0; j < world->height; j++) {
            if (i == ship->x && j == ship->y) {
                printf("S");
            } else {
                printf("%c", world->map[i][j]);
            }
        }
        printf("\n");
    }
}

// Move the ship around the world
void move_ship(World *world, Ship *ship, int dx, int dy) {
    if (ship->x + dx >= 0 && ship->x + dx < world->width
        && ship->y + dy >= 0 && ship->y + dy < world->height) {
        ship->x += dx;
        ship->y += dy;
    }
}

// Check for collisions between the ship and the world
int check_collisions(World *world, Ship *ship) {
    if (world->map[ship->x][ship->y] == '#') {
        return 1;
    }
    return 0;
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game world and the player's ship
    World *world = create_world();
    Ship *ship = create_ship();

    // Game loop
    while (1) {
        // Print the game world
        print_world(world, ship);

        // Get the player's input
        char input;
        printf("Enter a command (w, a, s, d, q): ");
        scanf(" %c", &input);

        // Move the ship
        switch (input) {
            case 'w':
                move_ship(world, ship, 0, -1);
                break;
            case 'a':
                move_ship(world, ship, -1, 0);
                break;
            case 's':
                move_ship(world, ship, 0, 1);
                break;
            case 'd':
                move_ship(world, ship, 1, 0);
                break;
            case 'q':
                return 0;
        }

        // Check for collisions
        if (check_collisions(world, ship)) {
            printf("You have crashed!\n");
            return 0;
        }
    }

    return 0;
}