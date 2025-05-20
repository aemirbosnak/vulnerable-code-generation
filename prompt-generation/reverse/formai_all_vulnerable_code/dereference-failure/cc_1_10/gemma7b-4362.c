//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
struct room {
    int number;
    char status;
    int occupancy;
    struct room* next;
};

// Define a function to insert a room into the linked list
void insertRoom(struct room** head, int number, char status, int occupancy) {
    struct room* newRoom = (struct room*)malloc(sizeof(struct room));
    newRoom->number = number;
    newRoom->status = status;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Define a function to search for a room
struct room* searchRoom(struct room* head, int number) {
    while (head) {
        if (head->number == number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Define a function to update the status of a room
void updateRoomStatus(struct room* head, int number, char status) {
    struct room* room = searchRoom(head, number);

    if (room) {
        room->status = status;
    }
}

// Define a function to update the occupancy of a room
void updateRoomOccupancy(struct room* head, int number, int occupancy) {
    struct room* room = searchRoom(head, number);

    if (room) {
        room->occupancy = occupancy;
    }
}

int main() {
    struct room* head = NULL;

    // Insert some rooms
    insertRoom(&head, 101, 'O', 2);
    insertRoom(&head, 102, 'A', 1);
    insertRoom(&head, 103, 'A', 0);

    // Search for a room
    struct room* room = searchRoom(head, 102);

    // Update the status of a room
    updateRoomStatus(head, 101, 'A');

    // Update the occupancy of a room
    updateRoomOccupancy(head, 102, 3);

    // Print the updated room information
    room = searchRoom(head, 102);
    printf("Room number: %d, Status: %c, Occupancy: %d\n", room->number, room->status, room->occupancy);

    return 0;
}