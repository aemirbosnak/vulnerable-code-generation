//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A brave adventurer seeking the fastest path through treacherous terrain.
typedef struct adventurer {
    int id;                 // A unique identifier for the adventurer.
    int x, y;               // The adventurer's current coordinates.
    int speed;              // The adventurer's speed (tiles per second).
    int direction;          // The adventurer's current direction of travel.
    int distance_traveled;   // The total distance traveled by the adventurer.
} adventurer_t;

// The treacherous terrain through which the adventurers must navigate.
typedef struct terrain {
    int width;             // The width of the terrain (in tiles).
    int height;            // The height of the terrain (in tiles).
    int** tiles;           // A 2D array representing the terrain, with each element representing the type of tile at that location.
} terrain_t;

// Initialize the terrain.
terrain_t* create_terrain(int width, int height) {
    terrain_t* terrain = malloc(sizeof(terrain_t));
    terrain->width = width;
    terrain->height = height;
    terrain->tiles = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        terrain->tiles[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            terrain->tiles[i][j] = rand() % 10;
        }
    }
    return terrain;
}

// Free the memory allocated for the terrain.
void destroy_terrain(terrain_t* terrain) {
    for (int i = 0; i < terrain->height; i++) {
        free(terrain->tiles[i]);
    }
    free(terrain->tiles);
    free(terrain);
}

// Initialize the adventurer.
adventurer_t* create_adventurer(int id, int x, int y, int speed, int direction) {
    adventurer_t* adventurer = malloc(sizeof(adventurer_t));
    adventurer->id = id;
    adventurer->x = x;
    adventurer->y = y;
    adventurer->speed = speed;
    adventurer->direction = direction;
    adventurer->distance_traveled = 0;
    return adventurer;
}

// Free the memory allocated for the adventurer.
void destroy_adventurer(adventurer_t* adventurer) {
    free(adventurer);
}

// Move the adventurer in the specified direction.
void move_adventurer(adventurer_t* adventurer, terrain_t* terrain) {
    switch (adventurer->direction) {
        case 0:  // Up
            adventurer->y -= adventurer->speed;
            break;
        case 1:  // Right
            adventurer->x += adventurer->speed;
            break;
        case 2:  // Down
            adventurer->y += adventurer->speed;
            break;
        case 3:  // Left
            adventurer->x -= adventurer->speed;
            break;
    }

    // Check if the adventurer has moved out of bounds.
    if (adventurer->x < 0 || adventurer->x >= terrain->width || adventurer->y < 0 || adventurer->y >= terrain->height) {
        // The adventurer has fallen off the edge of the terrain.
        adventurer->x = -1;
        adventurer->y = -1;
    }

    // Update the adventurer's distance traveled.
    adventurer->distance_traveled += adventurer->speed;
}

// Find the adventurer with the greatest distance traveled.
adventurer_t* find_fastest_adventurer(adventurer_t** adventurers, int num_adventurers) {
    adventurer_t* fastest_adventurer = NULL;
    int max_distance_traveled = 0;

    for (int i = 0; i < num_adventurers; i++) {
        if (adventurers[i]->distance_traveled > max_distance_traveled) {
            fastest_adventurer = adventurers[i];
            max_distance_traveled = adventurers[i]->distance_traveled;
        }
    }

    return fastest_adventurer;
}

// Print the results of the race.
void print_results(adventurer_t** adventurers, int num_adventurers) {
    printf("The adventurers have finished their journey.\n");
    for (int i = 0; i < num_adventurers; i++) {
        printf("Adventurer %d traveled %d tiles.\n", adventurers[i]->id, adventurers[i]->distance_traveled);
    }

    adventurer_t* fastest_adventurer = find_fastest_adventurer(adventurers, num_adventurers);
    printf("The fastest adventurer was adventurer %d, who traveled %d tiles.\n", fastest_adventurer->id, fastest_adventurer->distance_traveled);
}

// The main function.
int main(int argc, char** argv) {
    // Seed the random number generator.
    srand(time(NULL));

    // Create the terrain.
    int terrain_width = 100;
    int terrain_height = 100;
    terrain_t* terrain = create_terrain(terrain_width, terrain_height);

    // Create the adventurers.
    int num_adventurers = 10;
    adventurer_t** adventurers = malloc(num_adventurers * sizeof(adventurer_t*));
    for (int i = 0; i < num_adventurers; i++) {
        int x = rand() % terrain_width;
        int y = rand() % terrain_height;
        int speed = rand() % 10 + 1;
        int direction = rand() % 4;
        adventurers[i] = create_adventurer(i, x, y, speed, direction);
    }

    // Start the race.
    int time_limit = 100;
    for (int i = 0; i < time_limit; i++) {
        for (int j = 0; j < num_adventurers; j++) {
            move_adventurer(adventurers[j], terrain);
        }
    }

    // Stop the race.
    print_results(adventurers, num_adventurers);

    // Free the memory allocated for the adventurers and terrain.
    for (int i = 0; i < num_adventurers; i++) {
        destroy_adventurer(adventurers[i]);
    }
    destroy_terrain(terrain);

    return 0;
}