//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a hotel room
typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

// Create a function to insert a room into the hotel
void insertRoom(Room* head, int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newRoom;
    }
}

// Create a function to check if a room is available
int isRoomAvailable(Room* head, int number) {
    Room* current = head;
    while (current) {
        if (current->number == number && current->occupancy == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Create a function to check if a room type is available
int isRoomTypeAvailable(Room* head, char type) {
    Room* current = head;
    while (current) {
        if (current->type == type && current->occupancy == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Main function
int main() {
    // Create a hotel room list
    Room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'A', 2);
    insertRoom(head, 102, 'B', 1);
    insertRoom(head, 103, 'A', 0);
    insertRoom(head, 104, 'B', 2);

    // Check if room 103 is available
    if (isRoomAvailable(head, 103)) {
        printf("Room 103 is available.\n");
    }

    // Check if room type A is available
    if (isRoomTypeAvailable(head, 'A')) {
        printf("Room type A is available.\n");
    }

    return 0;
}