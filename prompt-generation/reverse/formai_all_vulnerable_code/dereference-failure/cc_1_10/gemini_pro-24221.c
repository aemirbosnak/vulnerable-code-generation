//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Our brave explorer!
typedef struct {
    int x, y; // Current coordinates
    int heading; // 0-3: North, East, South, West
    int fuel; // How much juice we have left
    int destination_x, destination_y; // Where we're trying to go
} Explorer;

// The world they're exploring
typedef struct {
    int width, height; // Dimensions
    char **map; // Array of characters representing terrain types (e.g. '.' for open space)
} World;

// Initialize the explorer and world
void init(Explorer *explorer, World *world) {
    srand(time(NULL)); // Seed the random number generator
    explorer->x = rand() % world->width;
    explorer->y = rand() % world->height;
    explorer->heading = rand() % 4;
    explorer->fuel = 100; // Starting with a full tank

    world->width = 100;
    world->height = 100;

    world->map = malloc(sizeof(char *) * world->height);
    for (int i = 0; i < world->height; i++) {
        world->map[i] = malloc(sizeof(char) * world->width);
        for (int j = 0; j < world->width; j++) {
            world->map[i][j] = rand() % 2 == 0 ? '.' : '#'; // Randomly generate terrain
        }
    }

    // Randomly choose the destination
    do {
        explorer->destination_x = rand() % world->width;
        explorer->destination_y = rand() % world->height;
    } while (world->map[explorer->destination_y][explorer->destination_x] == '#');
}

// Display the world
void display(Explorer *explorer, World *world) {
    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            if (explorer->x == j && explorer->y == i) {
                printf("E");
            } else {
                printf("%c", world->map[i][j]);
            }
        }
        printf("\n");
    }
}

// Move the explorer
void move(Explorer *explorer, World *world) {
    // Check for valid move
    int new_x = explorer->x + (explorer->heading % 2 == 0 ? explorer->heading - 1 : explorer->heading);
    int new_y = explorer->y + (explorer->heading % 2 == 1 ? explorer->heading % 2 : !(explorer->heading % 2));
    if (new_x >= 0 && new_x < world->width && new_y >= 0 && new_y < world->height && world->map[new_y][new_x] != '#') {
        explorer->x = new_x;
        explorer->y = new_y;
        explorer->fuel--;
    }
}

// Rotate the explorer
void rotate(Explorer *explorer, int direction) {
    explorer->heading = (explorer->heading + direction + 4) % 4; // Adjust for negative rotations
}

// Check if the explorer has reached the destination
int reached_destination(Explorer *explorer) {
    return explorer->x == explorer->destination_x && explorer->y == explorer->destination_y;
}

int main() {
    Explorer explorer;
    World world;

    init(&explorer, &world);
    display(&explorer, &world);

    while (!reached_destination(&explorer) && explorer.fuel > 0) {
        char command;
        printf("Enter command (m: move, l: left, r: right, q: quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'm':
                move(&explorer, &world);
                break;
            case 'l':
                rotate(&explorer, -1);
                break;
            case 'r':
                rotate(&explorer, 1);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid command\n");
        }

        display(&explorer, &world);
    }

    if (reached_destination(&explorer)) {
        printf("Congratulations! You reached your destination.\n");
    } else {
        printf("Sorry, you ran out of fuel.\n");
    }

    for (int i = 0; i < world.height; i++) {
        free(world.map[i]);
    }
    free(world.map);
    return 0;
}