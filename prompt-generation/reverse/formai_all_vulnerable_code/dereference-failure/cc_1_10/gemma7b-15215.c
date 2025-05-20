//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_no;
    char occupancy;
    float rate;
} Room;

// Define a function to search for a room
Room* search_room(int room_no) {
    // Allocate memory for the room structure
    Room* room = (Room*)malloc(sizeof(Room));

    // Initialize the room structure
    room->room_no = room_no;
    room->occupancy = 'O';
    room->rate = 100.0;

    return room;
}

// Define a function to book a room
void book_room(Room* room) {
    // Set the room occupancy to 'B'
    room->occupancy = 'B';

    // Print a confirmation message
    printf("Room booked successfully!\n");
}

int main() {
    // Create an array of rooms
    Room rooms[10] = {
        {1, 'O', 100.0},
        {2, 'B', 120.0},
        {3, 'O', 110.0},
        {4, 'B', 130.0},
        {5, 'O', 105.0},
        {6, 'B', 125.0},
        {7, 'O', 115.0},
        {8, 'B', 135.0},
        {9, 'O', 100.0},
        {10, 'B', 120.0}
    };

    // Search for a room
    Room* room = search_room(2);

    // Book the room
    book_room(room);

    return 0;
}