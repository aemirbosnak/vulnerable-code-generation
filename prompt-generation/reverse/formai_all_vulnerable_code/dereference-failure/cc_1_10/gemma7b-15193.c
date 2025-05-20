//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: grateful
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
void insertRoom(Room** head, int number, char type, int occupancy) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
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

// Define a function to update room occupancy
void updateOccupancy(Room* head, int number, int newOccupancy) {
    Room* room = searchRoom(head, number);

    if (room) {
        room->occupancy = newOccupancy;
    }
}

// Define a function to print room information
void printRooms(Room* head) {
    while (head) {
        printf("Room number: %d, Type: %c, Occupancy: %d\n", head->number, head->type, head->occupancy);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;

    // Insert some rooms
    insertRoom(&head, 101, 'A', 2);
    insertRoom(&head, 102, 'B', 1);
    insertRoom(&head, 103, 'A', 3);

    // Print room information
    printRooms(head);

    // Update room occupancy
    updateOccupancy(head, 102, 4);

    // Print room information after update
    printRooms(head);

    return 0;
}