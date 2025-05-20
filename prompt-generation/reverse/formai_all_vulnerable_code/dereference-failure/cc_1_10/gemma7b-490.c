//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the room structure
typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Define the hotel management system
typedef struct Hotel {
    Room* head;
    int num_rooms;
} Hotel;

// Create a new room
Room* create_room(int room_no) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_no = room_no;
    new_room->status = 'O';
    new_room->occupancy = 0;
    new_room->next = NULL;
    return new_room;
}

// Insert a new room into the hotel
void insert_room(Hotel* hotel, int room_no) {
    Room* new_room = create_room(room_no);
    if (hotel->head == NULL) {
        hotel->head = new_room;
    } else {
        hotel->head->next = new_room;
        hotel->head = new_room;
    }
    hotel->num_rooms++;
}

// Check if a room is available
int is_room_available(Hotel* hotel, int room_no) {
    Room* current_room = hotel->head;
    while (current_room) {
        if (current_room->room_no == room_no && current_room->status == 'O') {
            return 1;
        }
        current_room = current_room->next;
    }
    return 0;
}

// Book a room
void book_room(Hotel* hotel, int room_no, int num_guests) {
    Room* current_room = hotel->head;
    while (current_room) {
        if (current_room->room_no == room_no && current_room->status == 'O') {
            current_room->occupancy = num_guests;
            current_room->status = 'B';
            printf("Room booked successfully!\n");
            return;
        }
        current_room = current_room->next;
    }
    printf("Room not available.\n");
}

int main() {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    hotel->head = NULL;
    hotel->num_rooms = 0;

    insert_room(hotel, 101);
    insert_room(hotel, 102);
    insert_room(hotel, 103);

    if (is_room_available(hotel, 102)) {
        book_room(hotel, 102, 2);
    }

    if (is_room_available(hotel, 103)) {
        book_room(hotel, 103, 3);
    }

    return 0;
}