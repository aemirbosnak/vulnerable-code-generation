//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_no;
    char room_type;
    int available;
    float rate;
} Room;

// Define a function to search for a room
Room* search_room(int room_no) {
    // Allocate memory for the room structure
    Room* room = (Room*)malloc(sizeof(Room));

    // Initialize the room structure
    room->room_no = room_no;
    room->room_type = 'A';
    room->available = 1;
    room->rate = 1000.0;

    return room;
}

// Define a function to book a room
void book_room(Room* room) {
    // Mark the room as booked
    room->available = 0;

    // Print a confirmation message
    printf("Room booked successfully!\n");
}

int main() {
    // Create an array of rooms
    Room rooms[10] = {
        {101, 'A', 1, 1000.0},
        {102, 'B', 0, 1200.0},
        {103, 'A', 1, 1100.0},
        {104, 'B', 0, 1300.0},
        {105, 'A', 1, 1050.0},
        {106, 'B', 0, 1250.0},
        {107, 'A', 1, 1150.0},
        {108, 'B', 0, 1350.0},
        {109, 'A', 1, 1000.0},
        {110, 'B', 0, 1200.0}
    };

    // Search for a room
    Room* room = search_room(103);

    // Book the room
    book_room(room);

    return 0;
}