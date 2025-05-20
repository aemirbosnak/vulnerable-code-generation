//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
typedef struct Room {
    char name[20];
    int available;
    int price;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* head = NULL;

// Function to insert a room into the linked list
void insertRoom(char* name, int available, int price) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->available = available;
    newRoom->price = price;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
        head = newRoom;
    }
}

// Function to check if a room is available
int isRoomAvailable(char* name) {
    Room* currentRoom = head;

    while (currentRoom) {
        if (strcmp(currentRoom->name, name) == 0 && currentRoom->available) {
            return 1;
        }
        currentRoom = currentRoom->next;
    }

    return 0;
}

// Function to book a room
void bookRoom(char* name, int numGuests) {
    Room* currentRoom = head;

    while (currentRoom) {
        if (strcmp(currentRoom->name, name) == 0 && currentRoom->available) {
            currentRoom->available = 0;
            printf("Room booked for %s with %d guests\n", name, numGuests);
            return;
        }
        currentRoom = currentRoom->next;
    }

    printf("No room available for %s\n", name);
}

int main() {
    // Insert some rooms
    insertRoom("Room 1", 1, 100);
    insertRoom("Room 2", 0, 120);
    insertRoom("Room 3", 1, 150);

    // Check if a room is available
    if (isRoomAvailable("Room 1")) {
        printf("Room 1 is available\n");
    }

    // Book a room
    bookRoom("Room 1", 2);

    // Check if the room is booked
    if (!isRoomAvailable("Room 1")) {
        printf("Room 1 is booked\n");
    }

    return 0;
}