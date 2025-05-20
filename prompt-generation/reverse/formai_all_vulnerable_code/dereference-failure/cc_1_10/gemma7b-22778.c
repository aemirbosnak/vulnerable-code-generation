//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 20

typedef struct Room {
    int x, y;
    struct Room* next;
} Room;

Room* generate_room(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->next = NULL;
    return room;
}

void generate_map(int w, int h) {
    // Allocate memory for the map
    int** map = malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        map[i] = malloc(w * sizeof(int));
    }

    // Generate the rooms
    int num_rooms = rand() % MAX_ROOMS;
    for (int i = 0; i < num_rooms; i++) {
        int x = rand() % w;
        int y = rand() % h;
        generate_room(x, y);
    }

    // Connect the rooms
    Room* current_room = NULL;
    for (Room* room = generate_room(0, 0); room; room = room->next) {
        if (current_room) {
            current_room->next = room;
        }
        current_room = room;
    }

    // Free the memory
    for (int i = 0; i < h; i++) {
        free(map[i]);
    }
    free(map);
}

int main() {
    generate_map(10, 10);
    return 0;
}