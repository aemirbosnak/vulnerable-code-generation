//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_SIZE 10
#define MAX_ROOMS 100

typedef struct {
    int x, y;
} point;

typedef struct {
    point pos;
    int type;
} room;

typedef struct {
    room *rooms;
    int num_rooms;
} map;

void generate_map(map *m) {
    // Create a list of empty rooms
    m->rooms = malloc(sizeof(room) * MAX_ROOMS);
    m->num_rooms = 0;

    // Create a random seed
    srand(time(NULL));

    // Generate rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Get a random position for the room
        m->rooms[i].pos.x = rand() % MAX_ROOM_SIZE;
        m->rooms[i].pos.y = rand() % MAX_ROOM_SIZE;

        // Get a random type for the room
        m->rooms[i].type = rand() % 3;

        // Add the room to the list
        m->num_rooms++;
    }
}

void print_map(map *m) {
    // Print the map
    for (int y = 0; y < MAX_ROOM_SIZE; y++) {
        for (int x = 0; x < MAX_ROOM_SIZE; x++) {
            // Find the room at the current position
            room *r = NULL;
            for (int i = 0; i < m->num_rooms; i++) {
                if (m->rooms[i].pos.x == x && m->rooms[i].pos.y == y) {
                    r = &m->rooms[i];
                    break;
                }
            }

            // Print the room type
            if (r == NULL) {
                printf(" ");
            } else {
                switch (r->type) {
                    case 0:
                        printf(".");
                        break;
                    case 1:
                        printf("#");
                        break;
                    case 2:
                        printf("@");
                        break;
                }
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a map
    map m;

    // Generate the map
    generate_map(&m);

    // Print the map
    print_map(&m);

    return 0;
}