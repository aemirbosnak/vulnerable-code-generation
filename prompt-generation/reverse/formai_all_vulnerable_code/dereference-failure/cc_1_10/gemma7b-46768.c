//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a room
typedef struct Room {
    int room_no;
    char status;
    float rate;
} Room;

// Define a function to search for a room
Room* search_room(int room_no) {
    // Allocate memory for the room structure
    Room* room = (Room*)malloc(sizeof(Room));

    // Get the room number from the user
    room->room_no = room_no;

    // Set the room status to available
    room->status = 'A';

    // Set the room rate
    room->rate = 1000;

    return room;
}

// Define a function to book a room
void book_room(Room* room) {
    // Get the room number from the user
    room->room_no = room->room_no;

    // Set the room status to booked
    room->status = 'B';

    // Display the booking confirmation
    printf("Room booked successfully.\n");
}

int main() {
    // Create an array of rooms
    Room rooms[10] = {
        {1, 'A', 1000},
        {2, 'A', 1200},
        {3, 'A', 1400},
        {4, 'A', 1600},
        {5, 'A', 1800},
        {6, 'A', 2000},
        {7, 'A', 2200},
        {8, 'A', 2400},
        {9, 'A', 2600},
        {10, 'A', 2800}
    };

    // Search for a room
    Room* room = search_room(5);

    // Book a room
    book_room(room);

    return 0;
}