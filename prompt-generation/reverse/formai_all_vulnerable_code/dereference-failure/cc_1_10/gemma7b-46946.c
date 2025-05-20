//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
typedef struct Room {
    int number;
    char status;
    int occupied;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* createRoomList() {
    Room* head = NULL;
    for (int i = 0; i < NUM_ROOMS; i++) {
        Room* newRoom = malloc(sizeof(Room));
        newRoom->number = i + 1;
        newRoom->status = 'O';
        newRoom->occupied = 0;
        newRoom->next = head;
        head = newRoom;
    }
    return head;
}

// Check if a room is available
int isRoomAvailable(int roomNumber) {
    Room* head = createRoomList();
    for (Room* currentRoom = head; currentRoom; currentRoom = currentRoom->next) {
        if (currentRoom->number == roomNumber && currentRoom->status == 'O' && currentRoom->occupied == 0) {
            return 1;
        }
    }
    return 0;
}

// Occupy a room
void occupyRoom(int roomNumber) {
    Room* head = createRoomList();
    for (Room* currentRoom = head; currentRoom; currentRoom = currentRoom->next) {
        if (currentRoom->number == roomNumber) {
            currentRoom->status = 'X';
            currentRoom->occupied = 1;
        }
    }
}

int main() {
    // Create a linked list of rooms
    Room* head = createRoomList();

    // Check if room 5 is available
    if (isRoomAvailable(5)) {
        // Occupy room 5
        occupyRoom(5);

        // Check if room 5 is occupied
        if (isRoomAvailable(5) == 0) {
            printf("Room 5 is occupied.\n");
        }
    } else {
        printf("Room 5 is not available.\n");
    }

    return 0;
}