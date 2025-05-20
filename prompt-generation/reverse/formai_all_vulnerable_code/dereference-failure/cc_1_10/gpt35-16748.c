//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 8
#define MIN_ROOM_WIDTH 4
#define MIN_ROOM_HEIGHT 3

typedef struct room {
    int x, y, width, height;
} Room;

// Create a new room
Room new_room(int x, int y, int width, int height) {
    Room r;
    r.x = x;
    r.y = y;
    r.width = width;
    r.height = height;
    return r;
}

// Create a path between two rooms
void create_path(int **map, Room r1, Room r2) {
    int x1 = r1.x + r1.width / 2;
    int y1 = r1.y + r1.height / 2;
    int x2 = r2.x + r2.width / 2;
    int y2 = r2.y + r2.height / 2;

    while (x1 != x2 || y1 != y2) {
        if (x1 != x2 && rand() % 2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
        } else if (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
        }
        map[x1][y1] = 1;
    }
}

// Check if two rooms overlap
int rooms_overlap(Room r1, Room r2) {
    return r1.x < r2.x + r2.width &&
           r1.x + r1.width > r2.x &&
           r1.y < r2.y + r2.height &&
           r1.y + r1.height > r2.y;
}

// Generate a new map with rooms and corridors
int **generate_map() {
    int **map = malloc(WIDTH * sizeof(int *));
    for (int x = 0; x < WIDTH; x++) {
        map[x] = calloc(HEIGHT, sizeof(int));
    }

    srand(time(NULL));

    // Generate rooms
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = rand() % (WIDTH / 4) + MIN_ROOM_WIDTH;
        int height = rand() % (HEIGHT / 4) + MIN_ROOM_HEIGHT;
        int x = rand() % (WIDTH - width - 2) + 1;
        int y = rand() % (HEIGHT - height - 2) + 1;
        Room room = new_room(x, y, width, height);

        int overlaps = 0;
        for (int j = 0; j < num_rooms; j++) {
            if (rooms_overlap(room, rooms[j])) {
                overlaps = 1;
                break;
            }
        }
        if (!overlaps) {
            for (int rx = x; rx < x + width; rx++) {
                for (int ry = y; ry < y + height; ry++) {
                    map[rx][ry] = 1;
                }
            }
            rooms[num_rooms] = room;
            num_rooms++;
        }
    }

    // Generate corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        create_path(map, rooms[i], rooms[i+1]);
    }

    return map;
}

// Print the map in ASCII
void print_map(int **map) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[x][y] == 1) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int **map = generate_map();
    print_map(map);
    return 0;
}