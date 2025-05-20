//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a room
typedef struct Room {
    int number;
    char type;
    int available;
    struct Room* next;
} Room;

// Define a structure for a guest
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
    head->number = 1;
    head->type = 'A';
    head->available = 1;

    // Create the remaining rooms
    for (int i = 2; i <= 10; i++) {
        tail->next = (Room*)malloc(sizeof(Room));
        tail = tail->next;

        tail->number = i;
        tail->type = 'A';
        tail->available = 1;
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

    // Create the remaining guests
    for (int i = 1; i <= 5; i++) {
        tail->next = (Guest*)malloc(sizeof(Guest));
        tail = tail->next;

        tail->name[0] = 'A' + i;
        tail->room_number = i + 1;
    }

    return head;
}

// Check if a room is available
int is_room_available(Room* room) {
    return room->available;
}

// Assign a room to a guest
void assign_room(Guest* guest, Room* room) {
    guest->room_number = room->number;
    room->available = 0;
}

// Print the guest list
void print_guest_list(Guest* guest) {
    Guest* current = guest;

    while (current) {
        printf("Name: %s, Room Number: %d\n", current->name, current->room_number);
        current = current->next;
    }
}

int main() {
    // Create the room list
    Room* rooms = create_room_list();

    // Create the guest list
    Guest* guests = create_guest_list();

    // Assign a room to a guest
    assign_room(guests, rooms);

    // Print the guest list
    print_guest_list(guests);

    return 0;
}