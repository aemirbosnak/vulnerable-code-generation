//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
typedef struct Room {
    int room_no;
    char status;
    char guest_name[20];
    int num_guests;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* head = NULL;

// Function to insert a room into the linked list
void insertRoom(int room_no, char status, char guest_name[], int num_guests) {
    // Allocate memory for the new room
    Room* newRoom = (Room*)malloc(sizeof(Room));

    // Initialize the room data
    newRoom->room_no = room_no;
    newRoom->status = status;
    strcpy(newRoom->guest_name, guest_name);
    newRoom->num_guests = num_guests;
    newRoom->next = NULL;

    // If the list is empty, make the new room the head
    if (head == NULL) {
        head = newRoom;
    } else {
        // Traverse the list to the end
        Room* currentRoom = head;
        while (currentRoom->next != NULL) {
            currentRoom = currentRoom->next;
        }

        // Insert the new room at the end
        currentRoom->next = newRoom;
    }
}

// Function to search for a room
Room* searchRoom(int room_no) {
    // Traverse the list of rooms
    Room* currentRoom = head;
    while (currentRoom) {
        // Check if the room number matches
        if (currentRoom->room_no == room_no) {
            return currentRoom;
        }
        currentRoom = currentRoom->next;
    }

    // Room not found
    return NULL;
}

// Function to update the status of a room
void updateRoomStatus(int room_no, char new_status) {
    // Search for the room
    Room* room = searchRoom(room_no);

    // If the room was found, update its status
    if (room) {
        room->status = new_status;
    }
}

// Function to check if a room is available
int isRoomAvailable(int room_no) {
    // Search for the room
    Room* room = searchRoom(room_no);

    // If the room was found and it is available, return 1
    if (room && room->status == 'A') {
        return 1;
    }

    // Room is not available
    return 0;
}

// Main function
int main() {
    // Insert some rooms
    insertRoom(1, 'A', "John Doe", 2);
    insertRoom(2, 'O', "Jane Doe", 1);
    insertRoom(3, 'B', "Peter Pan", 3);

    // Check if room 1 is available
    if (isRoomAvailable(1)) {
        printf("Room 1 is available\n");
    }

    // Update the status of room 2 to occupied
    updateRoomStatus(2, 'O');

    // Check if room 2 is available
    if (isRoomAvailable(2)) {
        printf("Room 2 is not available\n");
    }

    return 0;
}