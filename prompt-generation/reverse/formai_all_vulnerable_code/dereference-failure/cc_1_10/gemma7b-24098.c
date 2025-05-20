//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_no;
    char room_type;
    int available;
    float rate;
} Room;

// Define a function to search for a room
Room* search_room(char type, int no) {
    // Create an array of rooms
    Room rooms[] = {
        {101, 'A', 1, 5000},
        {102, 'B', 0, 4000},
        {103, 'A', 1, 5500},
        {104, 'B', 0, 3500}
    };

    // Iterate over the array of rooms
    for (int i = 0; i < 4; i++) {
        // Check if the room number and type match the search criteria
        if (rooms[i].room_no == no && rooms[i].room_type == type && rooms[i].available) {
            // Return the room information
            return &rooms[i];
        }
    }

    // Return null if no room matches the search criteria
    return NULL;
}

// Main function
int main() {
    // Search for a room
    Room* room = search_room('A', 101);

    // Print the room information
    if (room) {
        printf("Room number: %d\n", room->room_no);
        printf("Room type: %c\n", room->room_type);
        printf("Available: %d\n", room->available);
        printf("Rate: %.2f\n", room->rate);
    } else {
        printf("No room found\n");
    }

    return 0;
}