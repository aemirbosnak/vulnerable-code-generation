//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room *next;
} Room;

// Create a linked list of rooms
Room *create_room_list() {
    Room *head = NULL;
    for (int i = 0; i < NUM_ROOMS; i++) {
        Room *new_room = (Room *)malloc(sizeof(Room));
        new_room->room_no = i + 1;
        new_room->status = 'O';
        new_room->occupancy = 0;
        new_room->next = head;
        head = new_room;
    }
    return head;
}

// Function to check if a room is available
int is_room_available(int room_no) {
    Room *head = create_room_list();
    Room *current_room = head;
    while (current_room) {
        if (current_room->room_no == room_no && current_room->status == 'O') {
            return 1;
        }
        current_room = current_room->next;
    }
    return 0;
}

// Function to book a room
int book_room(int room_no, int num_guests) {
    Room *head = create_room_list();
    Room *current_room = head;
    while (current_room) {
        if (current_room->room_no == room_no && current_room->status == 'O') {
            current_room->occupancy = num_guests;
            current_room->status = 'B';
            return 1;
        }
        current_room = current_room->next;
    }
    return 0;
}

int main() {
    // Book a room
    book_room(2, 3);

    // Check if the room is available
    if (is_room_available(2)) {
        printf("Room 2 is available");
    } else {
        printf("Room 2 is not available");
    }

    return 0;
}