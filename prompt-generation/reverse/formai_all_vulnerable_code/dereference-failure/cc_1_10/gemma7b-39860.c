//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
    int room_number;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Function to insert a room into the linked list
void insertRoom(Room* head, int room_number, char status, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_number = room_number;
    newRoom->status = status;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }
}

// Function to search for a room in the linked list
Room* searchRoom(Room* head, int room_number) {
    Room* temp = head;
    while (temp) {
        if (temp->room_number == room_number) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the status of a room
void updateRoomStatus(Room* head, int room_number, char status) {
    Room* room = searchRoom(head, room_number);
    if (room) {
        room->status = status;
    }
}

// Function to update the occupancy of a room
void updateRoomOccupancy(Room* head, int room_number, int occupancy) {
    Room* room = searchRoom(head, room_number);
    if (room) {
        room->occupancy = occupancy;
    }
}

// Main function
int main() {
    // Create a linked list of rooms
    Room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'O', 2);
    insertRoom(head, 102, 'A', 1);
    insertRoom(head, 103, 'O', 3);

    // Search for a room
    Room* room = searchRoom(head, 102);
    if (room) {
        printf("Room number: %d\n", room->room_number);
        printf("Status: %c\n", room->status);
        printf("Occupancy: %d\n", room->occupancy);
    }

    // Update the status of a room
    updateRoomStatus(head, 101, 'A');

    // Update the occupancy of a room
    updateRoomOccupancy(head, 103, 2);

    // Search for the updated room
    room = searchRoom(head, 101);
    if (room) {
        printf("Room number: %d\n", room->room_number);
        printf("Status: %c\n", room->status);
        printf("Occupancy: %d\n", room->occupancy);
    }

    return 0;
}