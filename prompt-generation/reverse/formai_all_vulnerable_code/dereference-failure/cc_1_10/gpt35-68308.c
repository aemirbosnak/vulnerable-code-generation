//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEVELS 10
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Structure defining a room
typedef struct Room {
    int x, y, width, height;
} Room;

// Structure defining a level
typedef struct Level {
    int width, height;
    int **tiles; // 2D array of tiles
    Room *rooms; // Array of rooms
    int num_rooms;
} Level;

// Generate random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Create a room with given position and size
Room create_room(int x, int y, int width, int height) {
    Room r;
    r.x = x;
    r.y = y;
    r.width = width;
    r.height = height;
    return r;
}

// Check if two rooms overlap
int rooms_overlap(Room r1, Room r2) {
    return (r1.x <= r2.x + r2.width && r1.x + r1.width >= r2.x && r1.y <= r2.y + r2.height && r1.y + r1.height >= r2.y);
}

// Carve out a room in a level
void carve_room(Level *level, Room room) {
    int x, y;
    for (x = room.x; x < room.x + room.width; x++) {
        for (y = room.y; y < room.y + room.height; y++) {
            if (x == room.x || x == room.x + room.width - 1 || y == room.y || y == room.y + room.height - 1) {
                level->tiles[x][y] = 1; // Wall tile
            } else {
                level->tiles[x][y] = 0; // Floor tile
            }
        }
    }
}

// Carve out a corridor in a level
void carve_corridor(Level *level, int x1, int y1, int x2, int y2) {
    int x, y, dx, dy, step;
    dx = x2 - x1;
    dy = y2 - y1;
    step = dx > 0 ? 1 : -1; // Determine direction of movement on x-axis
    for (x = x1; x != x2 + step; x += step) {
        level->tiles[x][y1] = 0; // Floor tile
    }
    step = dy > 0 ? 1 : -1; // Determine direction of movement on y-axis
    for (y = y1; y != y2 + step; y += step) {
        level->tiles[x2][y] = 0; // Floor tile
    }
}

// Generate a level using recursive division algorithm
void generate_level(Level *level, int min_size, int max_size, int depth) {
    int i, j, split, position, width, height;
    if (depth == MAX_LEVELS) {
        return;
    }
    // Vertical split or horizontal split
    split = rand_int(0, 1); // 0 = vertical, 1 = horizontal
    if (split == 0) {
        // Vertical split
        position = rand_int(min_size, level->width - min_size);
        for (i = 0; i < level->height; i++) {
            level->tiles[position][i] = 1; // Wall tile
        }
        // Divide the level into two sub-levels and generate them recursively
        generate_level(&(Level) { position, level->height, level->tiles, NULL, 0 }, min_size, max_size, depth + 1);
        generate_level(&(Level) { level->width - position, level->height, &(level->tiles[position][0]), NULL, 0 }, min_size, max_size, depth + 1);
        // Carve out a corridor between the sub-levels
        int y = rand_int(1, level->height - 2);
        carve_corridor(level, position, y, position + level->width - position - 1, y);
    } else {
        // Horizontal split
        position = rand_int(min_size, level->height - min_size);
        for (i = 0; i < level->width; i++) {
            level->tiles[i][position] = 1; // Wall tile
        }
        // Divide the level into two sub-levels and generate them recursively
        generate_level(&(Level) { level->width, position, level->tiles, NULL, 0 }, min_size, max_size, depth + 1);
        generate_level(&(Level) { level->width, level->height - position, &(level->tiles[0][position]), NULL, 0 }, min_size, max_size, depth + 1);
        // Carve out a corridor between the sub-levels
        int x = rand_int(1, level->width - 2);
        carve_corridor(level, x, position, x, position + level->height - position - 1);
    }
    // Create some rooms in the current level
    level->num_rooms = rand_int(1, 3);
    level->rooms = (Room *) malloc(level->num_rooms * sizeof(Room));
    for (i = 0; i < level->num_rooms; i++) {
        width = rand_int(min_size, max_size);
        height = rand_int(min_size, max_size);
        if (split == 0) {
            j = rand_int(0, level->height - height - 1);
            level->rooms[i] = create_room(position + 1, j + 1, width - 1, height - 1);
        } else {
            j = rand_int(0, level->width - width - 1);
            level->rooms[i] = create_room(j + 1, position + 1, width - 1, height - 1);
        }
        carve_room(level, level->rooms[i]); // Carve out the room
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    Level level = { .width = MAX_WIDTH, .height = MAX_HEIGHT };
    level.tiles = (int **) malloc(level.width * sizeof(int *));
    int i, j;
    for (i = 0; i < level.width; i++) {
        level.tiles[i] = (int *) malloc(level.height * sizeof(int));
        for (j = 0; j < level.height; j++) {
            level.tiles[i][j] = 1; // Wall tile
        }
    }
    generate_level(&level, 10, 20, 0);
    // Print the level
    for (j = 0; j < level.height; j++) {
        for (i = 0; i < level.width; i++) {
            printf("%c", level.tiles[i][j] == 0 ? '.' : '#');
        }
        printf("\n");
    }
    return 0;
}