//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

// Define the map structure
typedef struct Map {
    int **data;
    int width;
    int height;
} Map;

// Function to generate the map
Map* generate_map() {
    Map* map = malloc(sizeof(Map));
    map->data = malloc(sizeof(int *) * map->height);
    for (int i = 0; i < map->height; i++) {
        map->data[i] = malloc(sizeof(int) * map->width);
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the map tiles
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->data[y][x] = rand() % 3;
        }
    }

    map->width = MAP_WIDTH;
    map->height = MAP_HEIGHT;

    return map;
}

// Function to print the map
void print_map(Map* map) {
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            printf("%d ", map->data[y][x]);
        }
        printf("\n");
    }
}

int main() {
    // Generate the map
    Map* map = generate_map();

    // Print the map
    print_map(map);

    // Free the map memory
    free(map->data);
    free(map);

    return 0;
}