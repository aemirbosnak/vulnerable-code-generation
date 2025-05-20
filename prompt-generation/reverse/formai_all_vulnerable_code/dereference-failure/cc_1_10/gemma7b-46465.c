//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: safe
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
    Room* newNode = malloc(sizeof(Room));
    newNode->number = number;
    newNode->type = type;
    newNode->occupancy = occupancy;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Define a function to search for a room in the linked list
Room* searchRoom(Room* head, int number) {
    while (head) {
        if (head->number == number) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Define a function to update the occupancy of a room in the linked list
void updateOccupancy(Room* head, int number, int newOccupancy) {
    Room* room = searchRoom(head, number);

    if (room) {
        room->occupancy = newOccupancy;
    }
}

// Main function
int main() {
    // Create a linked list of rooms
    Room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'A', 2);
    insertRoom(head, 102, 'B', 1);
    insertRoom(head, 103, 'A', 3);

    // Search for a room
    Room* room = searchRoom(head, 102);

    // If the room is found, update its occupancy
    if (room) {
        updateOccupancy(head, 102, 4);
    }

    // Print the updated room information
    room = searchRoom(head, 102);
    printf("Room number: %d\n", room->number);
    printf("Room type: %c\n", room->type);
    printf("Occupancy: %d\n", room->occupancy);

    return 0;
}