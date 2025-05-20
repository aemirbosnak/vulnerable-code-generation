//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10

// Define the room structure
typedef struct Room {
    char name[20];
    struct Room* nextRoom;
    int items[10];
} Room;

// Function to generate a random room
Room* generateRoom() {
    // Allocate memory for the room
    Room* room = (Room*)malloc(sizeof(Room));

    // Generate a unique name for the room
    room->name[0] = 'A' + rand() % MAX_ROOM_NUM;
    room->name[1] = '\0';

    // Populate the room with items
    for (int i = 0; i < 10; i++) {
        room->items[i] = rand() % 10;
    }

    // Connect the room to the next room
    room->nextRoom = NULL;

    return room;
}

// Main game loop
int main() {
    // Generate a list of rooms
    Room* rooms = generateRoom();

    // Traverse the rooms
    for (Room* room = rooms; room; room = room->nextRoom) {
        // Print the room name and items
        printf("You are in the %s.\n", room->name);
        printf("Items in the room: ");
        for (int i = 0; i < 10; i++) {
            if (room->items[i] != 0) {
                printf("%d ", room->items[i]);
            }
        }
        printf("\n");
    }

    return 0;
}