//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* create_room_list() {
    Room* head = NULL;
    Room* tail = NULL;

    head = malloc(sizeof(Room));
    tail = head;

    tail->room_no = 1;
    tail->status = 'O';
    tail->occupancy = 2;

    tail->next = malloc(sizeof(Room));
    tail = tail->next;

    tail->room_no = 2;
    tail->status = 'A';
    tail->occupancy = 1;

    tail->next = malloc(sizeof(Room));
    tail = tail->next;

    tail->room_no = 3;
    tail->status = 'O';
    tail->occupancy = 3;

    return head;
}

// Check if a room is available
int is_room_available(int room_no) {
    Room* current_room = create_room_list();

    for (current_room = current_room; current_room; current_room = current_room->next) {
        if (current_room->room_no == room_no && current_room->status == 'A') {
            return 1;
        }
    }

    return 0;
}

// Book a room
void book_room(int room_no, int occupancy) {
    Room* current_room = create_room_list();

    for (current_room = current_room; current_room; current_room = current_room->next) {
        if (current_room->room_no == room_no && current_room->status == 'A') {
            current_room->status = 'O';
            current_room->occupancy = occupancy;
            printf("Room booked successfully!\n");
            return;
        }
    }

    printf("Sorry, the room is not available.\n");
}

int main() {
    book_room(2, 1);
    book_room(3, 3);
    book_room(1, 2);

    return 0;
}