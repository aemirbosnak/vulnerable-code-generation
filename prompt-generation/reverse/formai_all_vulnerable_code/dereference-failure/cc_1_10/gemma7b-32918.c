//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a room
typedef struct Room {
    int room_number;
    char room_type;
    int available;
    struct Room* next;
} Room;

// Define the structure of a guest
typedef struct Guest {
    char guest_name[20];
    int guest_room_number;
    struct Guest* next;
} Guest;

// Create a linked list of rooms
Room* create_room_list() {
    Room* head = NULL;
    Room* tail = NULL;

    head = malloc(sizeof(Room));
    tail = head;
    tail->room_number = 1;
    tail->room_type = 'A';
    tail->available = 1;
    tail->next = NULL;

    head = malloc(sizeof(Room));
    tail->next = head;
    tail = head->next;
    tail->room_number = 2;
    tail->room_type = 'B';
    tail->available = 0;
    tail->next = NULL;

    return head;
}

// Create a linked list of guests
Guest* create_guest_list() {
    Guest* head = NULL;
    Guest* tail = NULL;

    head = malloc(sizeof(Guest));
    tail = head;
    tail->guest_name[0] = 'A';
    tail->guest_room_number = 1;
    tail->next = NULL;

    head = malloc(sizeof(Guest));
    tail->next = head;
    tail = head->next;
    tail->guest_name[0] = 'B';
    tail->guest_room_number = 2;
    tail->next = NULL;

    return head;
}

// Check if a room is available
int is_room_available(Room* room) {
    return room->available;
}

// Assign a room to a guest
void assign_room(Guest* guest, Room* room) {
    guest->guest_room_number = room->room_number;
    room->available = 0;
}

// Print the list of rooms
void print_rooms(Room* room) {
    while (room) {
        printf("Room Number: %d, Room Type: %c, Available: %d\n", room->room_number, room->room_type, room->available);
        room = room->next;
    }
}

// Print the list of guests
void print_guests(Guest* guest) {
    while (guest) {
        printf("Guest Name: %s, Room Number: %d\n", guest->guest_name, guest->guest_room_number);
        guest = guest->next;
    }
}

int main() {
    // Create a linked list of rooms and guests
    Room* rooms = create_room_list();
    Guest* guests = create_guest_list();

    // Print the list of rooms
    print_rooms(rooms);

    // Print the list of guests
    print_guests(guests);

    // Assign a room to a guest
    assign_room(guests, rooms);

    // Print the list of rooms after assigning a room to a guest
    print_rooms(rooms);

    // Print the list of guests after assigning a room to a guest
    print_guests(guests);

    return 0;
}