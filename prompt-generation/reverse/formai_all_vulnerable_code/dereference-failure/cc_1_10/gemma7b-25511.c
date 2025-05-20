//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a room
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
    // Set the room as booked
    room->available = 0;
}

// Define a function to calculate the total cost of a stay
float calculate_cost(Room* room, int num_days) {
    // Calculate the total cost
    float total_cost = room->rate * num_days;

    return total_cost;
}

int main() {
    // Create an array of rooms
    Room rooms[10] = {
        {1, 'A', 1, 1000.0},
        {2, 'B', 0, 1200.0},
        {3, 'A', 1, 1000.0},
        {4, 'B', 0, 1200.0},
        {5, 'A', 1, 1000.0},
        {6, 'B', 0, 1200.0},
        {7, 'A', 1, 1000.0},
        {8, 'B', 0, 1200.0},
        {9, 'A', 1, 1000.0},
        {10, 'B', 0, 1200.0}
    };

    // Search for a room
    Room* room = search_room(3);

    // Book the room
    book_room(room);

    // Calculate the total cost of the stay
    float total_cost = calculate_cost(room, 5);

    // Print the total cost
    printf("The total cost of the stay is: $%.2f", total_cost);

    return 0;
}