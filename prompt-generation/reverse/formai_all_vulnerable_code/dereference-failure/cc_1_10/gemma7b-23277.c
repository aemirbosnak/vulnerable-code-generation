//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the room structure
typedef struct Room {
    int room_number;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    Room* head;
    int num_rooms;
    int num_occupancy;
} HotelManagementSystem;

// Function to create a new room
Room* create_room(int room_number) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->status = 'O';
    new_room->occupancy = 0;
    new_room->next = NULL;
    return new_room;
}

// Function to insert a new room into the hotel management system
void insert_room(HotelManagementSystem* hms, int room_number) {
    Room* new_room = create_room(room_number);
    if (hms->head == NULL) {
        hms->head = new_room;
    } else {
        hms->head->next = new_room;
        hms->head = new_room;
    }
    hms->num_rooms++;
}

// Function to check if a room is available
int is_room_available(HotelManagementSystem* hms, int room_number) {
    Room* current_room = hms->head;
    while (current_room) {
        if (current_room->room_number == room_number && current_room->status == 'O') {
            return 1;
        }
        current_room = current_room->next;
    }
    return 0;
}

// Function to book a room
void book_room(HotelManagementSystem* hms, int room_number, int num_guests) {
    Room* current_room = hms->head;
    while (current_room) {
        if (current_room->room_number == room_number && current_room->status == 'O') {
            current_room->occupancy = num_guests;
            current_room->status = 'B';
            hms->num_occupancy++;
            return;
        }
        current_room = current_room->next;
    }
    printf("Error: Room not available.\n");
}

// Function to list all available rooms
void list_available_rooms(HotelManagementSystem* hms) {
    Room* current_room = hms->head;
    while (current_room) {
        if (current_room->status == 'O') {
            printf("Room number: %d, Occupancy: %d\n", current_room->room_number, current_room->occupancy);
        }
        current_room = current_room->next;
    }
}

int main() {
    HotelManagementSystem* hms = malloc(sizeof(HotelManagementSystem));
    hms->head = NULL;
    hms->num_rooms = 0;
    hms->num_occupancy = 0;

    // Insert some rooms into the hotel management system
    insert_room(hms, 1);
    insert_room(hms, 2);
    insert_room(hms, 3);
    insert_room(hms, 4);
    insert_room(hms, 5);

    // Check if room 2 is available
    if (is_room_available(hms, 2)) {
        printf("Room 2 is available.\n");
    }

    // Book room 2
    book_room(hms, 2, 3);

    // List all available rooms
    list_available_rooms(hms);

    return 0;
}