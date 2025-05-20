//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's ship
typedef struct {
    int x, y; // Coordinates
    int fuel; // Remaining fuel
} Ship;

// Define the universe
typedef struct {
    int width, height; // Dimensions
    char **grid; // Grid of characters
} Universe;

// Initialize the player's ship
Ship *init_ship(int x, int y, int fuel) {
    Ship *ship = malloc(sizeof(Ship));
    ship->x = x;
    ship->y = y;
    ship->fuel = fuel;
    return ship;
}

// Initialize the universe
Universe *init_universe(int width, int height) {
    Universe *universe = malloc(sizeof(Universe));
    universe->width = width;
    universe->height = height;
    universe->grid = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        universe->grid[i] = malloc(sizeof(char) * width);
    }
    return universe;
}

// Generate a random universe
void generate_universe(Universe *universe) {
    for (int i = 0; i < universe->height; i++) {
        for (int j = 0; j < universe->width; j++) {
            universe->grid[i][j] = rand() % 26 + 'a';
        }
    }
}

// Print the universe
void print_universe(Universe *universe) {
    for (int i = 0; i < universe->height; i++) {
        for (int j = 0; j < universe->width; j++) {
            printf("%c", universe->grid[i][j]);
        }
        printf("\n");
    }
}

// Move the player's ship
void move_ship(Ship *ship, Universe *universe, char direction) {
    switch (direction) {
        case 'w':
            ship->y--;
            break;
        case 's':
            ship->y++;
            break;
        case 'a':
            ship->x--;
            break;
        case 'd':
            ship->x++;
            break;
    }

    // Wrap the ship around the universe if it goes out of bounds
    if (ship->x < 0) {
        ship->x = universe->width - 1;
    } else if (ship->x >= universe->width) {
        ship->x = 0;
    }
    if (ship->y < 0) {
        ship->y = universe->height - 1;
    } else if (ship->y >= universe->height) {
        ship->y = 0;
    }
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the universe
    Universe *universe = init_universe(80, 25);
    generate_universe(universe);

    // Initialize the player's ship
    Ship *ship = init_ship(universe->width / 2, universe->height / 2, 100);

    // Game loop
    while (ship->fuel > 0) {
        // Print the universe
        print_universe(universe);

        // Get the player's input
        char direction;
        printf("Enter a direction (w, s, a, d): ");
        scanf(" %c", &direction);

        // Move the player's ship
        move_ship(ship, universe, direction);

        // Decrement the player's fuel
        ship->fuel--;
    }

    // Game over
    printf("Game over! You ran out of fuel.\n");

    // Free the memory allocated for the universe and the player's ship
    free(universe->grid);
    free(universe);
    free(ship);

    return 0;
}