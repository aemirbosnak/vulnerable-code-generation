//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: expert-level
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a room
typedef struct Room {
    int x, y;
    char **map;
    struct Room *next;
} Room;

// Function to generate a procedural dungeon
Room *generateDungeon(int width, int height) {
    // Allocate memory for the room
    Room *room = malloc(sizeof(Room));
    room->x = width;
    room->y = height;
    room->map = malloc(height * width * sizeof(char));

    // Fill the room map with walls
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            room->map[y][x] = '#';
        }
    }

    // Create a few corridors
    int numCorridors = rand() % 3;
    for (int i = 0; i < numCorridors; i++) {
        int x1 = rand() % width;
        int y1 = rand() % height;
        int x2 = rand() % width;
        int y2 = rand() % height;

        // Dig a corridor between the two points
        room->map[y1][x1] = ' ';
        room->map[y2][x2] = ' ';
    }

    // Return the room
    return room;
}

int main() {
    // Generate a dungeon
    Room *dungeon = generateDungeon(10, 10);

    // Print the dungeon map
    for (int y = 0; y < dungeon->y; y++) {
        for (int x = 0; x < dungeon->x; x++) {
            printf("%c ", dungeon->map[y][x]);
        }
        printf("\n");
    }

    // Free the dungeon memory
    free(dungeon->map);
    free(dungeon);

    return 0;
}