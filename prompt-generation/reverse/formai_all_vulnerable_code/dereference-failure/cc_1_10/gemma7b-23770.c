//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_number;
    char room_type;
    int available;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* create_room_list() {
    Room* head = NULL;
    Room* tail = NULL;

    // Allocate memory for the first room
    head = (Room*)malloc(sizeof(Room));
    tail = head;

    // Initialize the room information
    head->room_number = 1;
    head->room_type = 'A';
    head->available = 1;

    // Create the remaining rooms
    for (int i = 2; i <= 10; i++) {
        tail->next = (Room*)malloc(sizeof(Room));
        tail = tail->next;

        tail->room_number = i;
        tail->room_type = 'B';
        tail->available = 0;
    }

    return head;
}

// Search for a room in the linked list
Room* search_room(int room_number) {
    Room* head = create_room_list();

    // Traverse the list until the room is found or the end of the list is reached
    for (Room* current = head; current; current = current->next) {
        if (current->room_number == room_number) {
            return current;
        }
    }

    return NULL;
}

// Book a room in the linked list
void book_room(int room_number) {
    Room* room = search_room(room_number);

    // If the room is available, book it
    if (room && room->available) {
        room->available = 0;
        printf("Room booked.\n");
    } else {
        printf("Room not available.\n");
    }
}

int main() {
    book_room(5);
    book_room(2);
    book_room(1);

    return 0;
}