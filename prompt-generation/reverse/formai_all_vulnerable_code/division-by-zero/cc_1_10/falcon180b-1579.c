//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the dungeon
#define MAX_ROOMS 100
#define MAX_ROOM_SIZE 10

// Define the structure for a room
typedef struct {
    int x, y;
    int width, height;
} Room;

// Define the structure for the dungeon
typedef struct {
    int num_rooms;
    Room rooms[MAX_ROOMS];
} Dungeon;

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random room
void generate_room(Dungeon* dungeon, int num_rooms, int room_width, int room_height) {
    Room* room = &dungeon->rooms[num_rooms];

    // Set the initial position of the room
    room->x = rand_range(0, room_width - room->width);
    room->y = rand_range(0, room_height - room->height);

    // Set the width and height of the room
    room->width = rand_range(2, room_width - 2);
    room->height = rand_range(2, room_height - 2);
}

// Function to generate a dungeon with the given number of rooms
void generate_dungeon(Dungeon* dungeon, int num_rooms, int room_width, int room_height) {
    // Initialize the number of rooms
    dungeon->num_rooms = 0;

    // Generate the specified number of rooms
    for (int i = 0; i < num_rooms; i++) {
        generate_room(dungeon, dungeon->num_rooms, room_width, room_height);
        dungeon->num_rooms++;
    }
}

// Function to print the dungeon
void print_dungeon(Dungeon* dungeon) {
    for (int i = 0; i < dungeon->num_rooms; i++) {
        Room* room = &dungeon->rooms[i];
        for (int j = 0; j < room->height; j++) {
            for (int k = 0; k < room->width; k++) {
                printf(" ");
            }
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize the dungeon
    Dungeon dungeon;
    generate_dungeon(&dungeon, 10, 20, 20);

    // Print the dungeon
    printf("Dungeon:\n");
    print_dungeon(&dungeon);

    return 0;
}