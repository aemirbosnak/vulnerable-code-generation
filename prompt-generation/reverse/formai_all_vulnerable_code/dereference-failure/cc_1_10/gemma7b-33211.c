//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms
#define NUM_ROOMS 100

// Define the room structure
typedef struct Room {
    int room_number;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Define the hotel management system
typedef struct HotelManagementSystem {
    Room* head;
    int num_rooms_available;
    int num_rooms_occupied;
} HotelManagementSystem;

// Function to insert a room into the hotel management system
void insert_room(HotelManagementSystem* hms, int room_number) {
    // Allocate memory for the new room
    Room* new_room = (Room*)malloc(sizeof(Room));

    // Initialize the new room
    new_room->room_number = room_number;
    new_room->status = 'A';
    new_room->occupancy = 0;
    new_room->next = NULL;

    // If the head of the hotel management system is NULL, then this is the first room
    if (hms->head == NULL) {
        hms->head = new_room;
    } else {
        // Traverse the hotel management system until the last room is reached
        Room* current_room = hms->head;
        while (current_room->next != NULL) {
            current_room = current_room->next;
        }

        // Insert the new room after the last room
        current_room->next = new_room;
    }

    // Update the number of rooms available and occupied
    hms->num_rooms_available++;
    hms->num_rooms_occupied--;
}

// Function to check if a room is available
int is_room_available(HotelManagementSystem* hms, int room_number) {
    // Traverse the hotel management system to find the room
    Room* current_room = hms->head;
    while (current_room != NULL) {
        if (current_room->room_number == room_number && current_room->status == 'A') {
            return 1;
        }
        current_room = current_room->next;
    }

    // The room is not available
    return 0;
}

// Function to check out of a room
void check_out(HotelManagementSystem* hms, int room_number) {
    // Traverse the hotel management system to find the room
    Room* current_room = hms->head;
    Room* previous_room = NULL;
    while (current_room != NULL) {
        if (current_room->room_number == room_number) {
            // Update the room status to available
            current_room->status = 'A';

            // If the previous room is not NULL, then update the previous room's next pointer
            if (previous_room) {
                previous_room->next = current_room->next;
            } else {
                hms->head = current_room->next;
            }

            // Update the number of rooms available and occupied
            hms->num_rooms_available++;
            hms->num_rooms_occupied--;
            return;
        }
        previous_room = current_room;
        current_room = current_room->next;
    }

    // The room is not found
    return;
}

int main() {
    // Create a hotel management system
    HotelManagementSystem* hms = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    hms->head = NULL;
    hms->num_rooms_available = NUM_ROOMS;
    hms->num_rooms_occupied = 0;

    // Insert some rooms into the hotel management system
    insert_room(hms, 1);
    insert_room(hms, 2);
    insert_room(hms, 3);
    insert_room(hms, 4);

    // Check if a room is available
    if (is_room_available(hms, 2)) {
        printf("Room 2 is available\n");
    }

    // Check out of a room
    check_out(hms, 2);

    // Check if the room is available after checkout
    if (is_room_available(hms, 2)) {
        printf("Room 2 is available after checkout\n");
    }

    return 0;
}