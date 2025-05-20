//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insertRoom(Room* head, int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        newRoom->next = head;
        head = newRoom;
    }
}

// Define a function to search for a room
Room* searchRoom(Room* head, int number) {
    while (head) {
        if (head->number == number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

int main() {
    // Create a linked list of rooms
    Room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'D', 2);
    insertRoom(head, 102, 'S', 1);
    insertRoom(head, 103, 'D', 3);
    insertRoom(head, 104, 'S', 0);

    // Search for a room
    Room* room = searchRoom(head, 102);

    // Print the room information
    if (room) {
        printf("Room number: %d\n", room->number);
        printf("Room type: %c\n", room->type);
        printf("Occupancy: %d\n", room->occupancy);
    } else {
        printf("Room not found\n");
    }

    return 0;
}