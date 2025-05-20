//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a hotel room
typedef struct room {
    int number;
    char status;
    char occupancy;
    struct room* next;
} room;

// Define the function to insert a room into the linked list
void insertRoom(room* head, int number, char status, char occupancy) {
    room* newRoom = malloc(sizeof(room));
    newRoom->number = number;
    newRoom->status = status;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        room* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }
}

// Define the function to search for a room
room* searchRoom(room* head, int number) {
    room* temp = head;
    while (temp) {
        if (temp->number == number) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Define the function to update the status of a room
void updateRoomStatus(room* head, int number, char status) {
    room* temp = searchRoom(head, number);
    if (temp) {
        temp->status = status;
    }
}

// Define the function to update the occupancy of a room
void updateRoomOccupancy(room* head, int number, char occupancy) {
    room* temp = searchRoom(head, number);
    if (temp) {
        temp->occupancy = occupancy;
    }
}

// Main function
int main() {
    // Create a linked list of rooms
    room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'A', 'O');
    insertRoom(head, 102, 'B', 'C');
    insertRoom(head, 103, 'A', 'H');

    // Search for a room
    room* temp = searchRoom(head, 102);
    if (temp) {
        printf("Room number: %d\n", temp->number);
        printf("Status: %c\n", temp->status);
        printf("Occupancy: %c\n", temp->occupancy);
    }

    // Update the status of a room
    updateRoomStatus(head, 101, 'B');

    // Update the occupancy of a room
    updateRoomOccupancy(head, 103, 'A');

    // Search for the updated room
    temp = searchRoom(head, 101);
    if (temp) {
        printf("Updated room number: %d\n", temp->number);
        printf("Updated status: %c\n", temp->status);
        printf("Updated occupancy: %c\n", temp->occupancy);
    }

    return 0;
}