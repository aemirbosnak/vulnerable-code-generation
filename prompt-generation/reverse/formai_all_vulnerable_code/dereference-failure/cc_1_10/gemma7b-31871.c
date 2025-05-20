//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the structure of a room
typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* head = NULL;

// Function to insert a room into the linked list
void insertRoom(int room_no, char status, int occupancy) {
    // Allocate memory for the new room
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    newRoom->status = status;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    // If the linked list is empty, make the new room the head
    if (head == NULL) {
        head = newRoom;
    } else {
        // Traverse the linked list until the last room is reached
        Room* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        // Insert the new room after the last room
        temp->next = newRoom;
    }
}

// Function to check if a room is available
int isRoomAvailable(int room_no) {
    // Traverse the linked list to find the room
    Room* temp = head;
    while (temp) {
        // If the room number is found and the room is available, return 1
        if (temp->room_no == room_no && temp->status == 'A') {
            return 1;
        }
        temp = temp->next;
    }

    // If the room number is not found or the room is not available, return 0
    return 0;
}

// Function to check if a room is occupied
int isRoomOccupied(int room_no) {
    // Traverse the linked list to find the room
    Room* temp = head;
    while (temp) {
        // If the room number is found and the room is occupied, return 1
        if (temp->room_no == room_no && temp->status == 'O') {
            return 1;
        }
        temp = temp->next;
    }

    // If the room number is not found or the room is not occupied, return 0
    return 0;
}

// Function to update the status of a room
void updateRoomStatus(int room_no, char status) {
    // Traverse the linked list to find the room
    Room* temp = head;
    while (temp) {
        // If the room number is found, update the room status
        if (temp->room_no == room_no) {
            temp->status = status;
        }
        temp = temp->next;
    }
}

// Function to list all rooms
void listRooms() {
    // Traverse the linked list to list all rooms
    Room* temp = head;
    while (temp) {
        printf("Room No: %d, Status: %c, Occupancy: %d\n", temp->room_no, temp->status, temp->occupancy);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Insert some rooms into the linked list
    insertRoom(101, 'A', 2);
    insertRoom(102, 'A', 3);
    insertRoom(103, 'O', 4);
    insertRoom(104, 'A', 5);
    insertRoom(105, 'O', 6);

    // Check if room 101 is available
    if (isRoomAvailable(101)) {
        printf("Room 101 is available\n");
    }

    // Check if room 103 is occupied
    if (isRoomOccupied(103)) {
        printf("Room 103 is occupied\n");
    }

    // Update the status of room 102 to occupied
    updateRoomStatus(102, 'O');

    // List all rooms
    listRooms();

    return 0;
}