//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a room
typedef struct Room {
    int room_number;
    char status;
    int capacity;
    struct Room* next;
} Room;

// Define the structure of a guest
typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

// Create a linked list of rooms
Room* create_room_list() {
    Room* head = NULL;
    Room* tail = NULL;

    // Allocate memory for the first room
    head = (Room*)malloc(sizeof(Room));
    tail = head;

    // Initialize the room
    head->room_number = 1;
    head->status = 'O';
    head->capacity = 2;
    head->next = NULL;

    // Create the remaining rooms
    for (int i = 2; i <= 10; i++) {
        tail->next = (Room*)malloc(sizeof(Room));
        tail = tail->next;

        tail->room_number = i;
        tail->status = 'A';
        tail->capacity = 2;
        tail->next = NULL;
    }

    return head;
}

// Create a linked list of guests
Guest* create_guest_list() {
    Guest* head = NULL;
    Guest* tail = NULL;

    // Allocate memory for the first guest
    head = (Guest*)malloc(sizeof(Guest));
    tail = head;

    // Initialize the guest
    head->name[0] = 'J';
    head->room_number = 1;
    head->next = NULL;

    // Create the remaining guests
    for (int i = 1; i <= 5; i++) {
        tail->next = (Guest*)malloc(sizeof(Guest));
        tail = tail->next;

        tail->name[0] = 'A' + i;
        tail->room_number = i;
        tail->next = NULL;
    }

    return head;
}

// Check if a room is available
int is_room_available(int room_number) {
    Room* head = create_room_list();

    for (Room* current_room = head; current_room; current_room = current_room->next) {
        if (current_room->room_number == room_number && current_room->status == 'A') {
            return 1;
        }
    }

    return 0;
}

// Assign a room to a guest
void assign_room(char* guest_name, int room_number) {
    Guest* head = create_guest_list();

    for (Guest* current_guest = head; current_guest; current_guest = current_guest->next) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            current_guest->room_number = room_number;
            break;
        }
    }
}

int main() {
    // Check if room 3 is available
    if (is_room_available(3)) {
        // Assign room 3 to guest John Doe
        assign_room("John Doe", 3);
    }

    return 0;
}