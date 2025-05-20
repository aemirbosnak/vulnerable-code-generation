//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ROOMS 100

typedef struct room {
    int x, y;
    struct room* next;
} room_t;

room_t* create_room(int x, int y) {
    room_t* new_room = malloc(sizeof(room_t));
    new_room->x = x;
    new_room->y = y;
    new_room->next = NULL;
    return new_room;
}

void generate_maze(int num_rooms) {
    srand(time(NULL));

    // Create a list of rooms
    room_t* rooms = NULL;
    for (int i = 0; i < num_rooms; i++) {
        rooms = create_room(rand() % 10, rand() % 10);
        if (rooms) {
            rooms->next = rooms;
            rooms = rooms->next;
        }
    }

    // Connect rooms randomly
    for (int i = 0; i < num_rooms; i++) {
        room_t* current_room = rooms;
        room_t* next_room = rooms;

        while (next_room) {
            if (current_room != next_room) {
                int chance = rand() % 100;
                if (chance < 20) {
                    current_room->next = next_room;
                    break;
                }
            }
            next_room = next_room->next;
        }
    }

    // Print the maze
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            room_t* current_room = rooms;
            int found = 0;
            while (current_room) {
                if (current_room->x == x && current_room->y == y) {
                    printf("O ");
                    found = 1;
                    break;
                }
                current_room = current_room->next;
            }
            if (!found) {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_maze(MAX_ROOMS);
    return 0;
}