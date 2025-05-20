//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for defining the game world
#define WIDTH 80
#define HEIGHT 25
#define NUM_ROOMS 10

// Constants for defining the player
#define PLAYER_CHAR '@'
#define PLAYER_HEALTH 100

// Constants for defining the enemies
#define ENEMY_CHAR 'E'
#define ENEMY_HEALTH 20

// Constants for defining the items
#define ITEM_CHAR '+'
#define ITEM_HEALTH 10

// Structure for defining a single tile in the game world
typedef struct Tile {
    char chr;
    int health;
} Tile;

// Structure for defining a room in the game world
typedef struct Room {
    int x;
    int y;
    int width;
    int height;
    Tile tiles[WIDTH][HEIGHT];
} Room;

// Function to create a new tile
Tile new_tile(char chr, int health) {
    Tile tile;
    tile.chr = chr;
    tile.health = health;
    return tile;
}

// Function to create a new room
Room new_room(int x, int y, int width, int height) {
    Room room;
    room.x = x;
    room.y = y;
    room.width = width;
    room.height = height;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            room.tiles[i][j] = new_tile(' ', 0);
        }
    }
    return room;
}

// Function to generate a random room
Room random_room() {
    int x = rand() % (WIDTH - 10);
    int y = rand() % (HEIGHT - 10);
    int width = rand() % 10 + 5;
    int height = rand() % 10 + 5;
    return new_room(x, y, width, height);
}

// Function to generate the game world
Room* generate_world() {
    srand(time(NULL));
    Room* world = malloc(sizeof(Room) * NUM_ROOMS);
    for (int i = 0; i < NUM_ROOMS; i++) {
        world[i] = random_room();
    }
    return world;
}

// Function to print the game world
void print_world(Room* world) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < world[i].width; j++) {
            for (int k = 0; k < world[i].height; k++) {
                printf("%c", world[i].tiles[j][k].chr);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Generate the game world
    Room* world = generate_world();

    // Print the game world
    print_world(world);

    return 0;
}