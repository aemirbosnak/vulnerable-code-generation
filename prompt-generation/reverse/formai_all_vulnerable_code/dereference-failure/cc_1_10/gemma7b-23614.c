//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
typedef struct Room {
    char name[20];
    int number;
    int availability;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* createRoomList() {
    Room* head = NULL;
    for (int i = 0; i < NUM_ROOMS; i++) {
        Room* newRoom = (Room*)malloc(sizeof(Room));
        strcpy(newRoom->name, "Room ");
        newRoom->number = i + 1;
        newRoom->availability = 1;
        newRoom->next = head;
        head = newRoom;
    }
    return head;
}

// Check if a room is available
int isRoomAvailable(int roomNumber) {
    Room* head = createRoomList();
    for (Room* currentRoom = head; currentRoom; currentRoom = currentRoom->next) {
        if (currentRoom->number == roomNumber && currentRoom->availability) {
            return 1;
        }
    }
    return 0;
}

// Book a room
void bookRoom(char* name, int roomNumber) {
    Room* head = createRoomList();
    for (Room* currentRoom = head; currentRoom; currentRoom = currentRoom->next) {
        if (currentRoom->number == roomNumber && currentRoom->availability) {
            strcpy(currentRoom->name, name);
            currentRoom->availability = 0;
            printf("Room booked successfully!\n");
            return;
        }
    }
    printf("Error booking room.\n");
}

int main() {
    bookRoom("John Doe", 1);
    bookRoom("Jane Doe", 2);
    bookRoom("Peter Pan", 3);

    if (isRoomAvailable(2)) {
        printf("Room 2 is available.\n");
    }

    return 0;
}