//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* create_room_list() {
    Room* head = NULL;
    for (int i = 0; i < NUM_ROOMS; i++) {
        Room* new_room = (Room*)malloc(sizeof(Room));
        new_room->room_no = i + 1;
        new_room->status = 'O';
        new_room->occupancy = 0;
        new_room->next = head;
        head = new_room;
    }
    return head;
}

// Check if a room is available
int is_room_available(int room_no) {
    Room* head = create_room_list();
    for (Room* current_room = head; current_room; current_room = current_room->next) {
        if (current_room->room_no == room_no && current_room->status == 'O') {
            return 1;
        }
    }
    return 0;
}

// Book a room
void book_room(int room_no, int num_guests) {
    Room* head = create_room_list();
    for (Room* current_room = head; current_room; current_room = current_room->next) {
        if (current_room->room_no == room_no && current_room->status == 'O') {
            current_room->occupancy = num_guests;
            current_room->status = 'B';
            printf("Room %d booked for %d guests.\n", room_no, num_guests);
            return;
        }
    }
    printf("Room not available.\n");
}

int main() {
    book_room(2, 3);
    book_room(5, 2);
    book_room(1, 4);
    book_room(3, 1);
    book_room(4, 2);

    return 0;
}