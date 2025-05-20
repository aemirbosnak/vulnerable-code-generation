//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store hotel room information
typedef struct Room {
    char room_no[10];
    char room_type[20];
    int available;
    double rate;
} Room;

// Define a function to search for a room
Room* search_room(char* room_type, int available) {
    // Create an array of rooms
    Room rooms[] = {
        {"101", "Standard", 1, 5000},
        {"102", "Deluxe", 0, 7000},
        {"103", "Suite", 1, 9000},
        {"104", "Family", 0, 6000}
    };

    // Iterate over the array of rooms to find a match
    for (int i = 0; i < 4; i++) {
        // Check if the room type and availability match the search criteria
        if (strcmp(rooms[i].room_type, room_type) == 0 && rooms[i].available == available) {
            // Return the room
            return &rooms[i];
        }
    }

    // Return NULL if no room is found
    return NULL;
}

int main() {
    // Search for a room
    Room* room = search_room("Standard", 1);

    // Print the room information
    if (room) {
        printf("Room No: %s\n", room->room_no);
        printf("Room Type: %s\n", room->room_type);
        printf("Available: %d\n", room->available);
        printf("Rate: %.2lf\n", room->rate);
    } else {
        printf("No room found\n");
    }

    return 0;
}