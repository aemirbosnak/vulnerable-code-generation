//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 50

// Structure to store information about a room
typedef struct {
    int id; // Room ID
    char name[20]; // Room name
    int capacity; // Maximum number of guests
    int occupied; // Number of guests currently occupying the room
} room_t;

// Structure to store information about a guest
typedef struct {
    int id; // Guest ID
    char name[20]; // Guest name
    int room_id; // Room ID where the guest is staying
    time_t check_in; // Time of check-in
    time_t check_out; // Time of check-out
} guest_t;

// Function to create a new room
room_t *create_room(int capacity) {
    room_t *new_room = (room_t *) malloc(sizeof(room_t));
    new_room->id = MAX_ROOMS;
    new_room->name[0] = '\0';
    new_room->capacity = capacity;
    new_room->occupied = 0;
    return new_room;
}

// Function to create a new guest
guest_t *create_guest(int room_id) {
    guest_t *new_guest = (guest_t *) malloc(sizeof(guest_t));
    new_guest->id = MAX_GUESTS;
    new_guest->name[0] = '\0';
    new_guest->room_id = room_id;
    new_guest->check_in = time(NULL);
    new_guest->check_out = 0;
    return new_guest;
}

// Function to check if a room is available
int is_room_available(room_t *room) {
    return room->occupied < room->capacity;
}

// Function to check if a guest has checked out
int is_guest_checked_out(guest_t *guest) {
    return guest->check_out != 0;
}

// Function to check if a guest is staying in a room
int is_guest_staying_in_room(guest_t *guest, room_t *room) {
    return guest->room_id == room->id;
}

// Function to add a guest to a room
void add_guest_to_room(guest_t *guest, room_t *room) {
    if (is_room_available(room)) {
        room->occupied++;
        guest->room_id = room->id;
    }
}

// Function to remove a guest from a room
void remove_guest_from_room(guest_t *guest, room_t *room) {
    if (is_guest_staying_in_room(guest, room)) {
        room->occupied--;
        guest->room_id = 0;
    }
}

// Function to check if a room is full
int is_room_full(room_t *room) {
    return room->occupied == room->capacity;
}

// Function to print the status of a room
void print_room_status(room_t *room) {
    printf("Room %d (%s) is currently occupied by %d guests\n",
           room->id, room->name, room->occupied);
}

// Function to print the status of a guest
void print_guest_status(guest_t *guest) {
    printf("Guest %d (%s) is staying in Room %d and checked in on %s\n",
           guest->id, guest->name, guest->room_id, ctime(&guest->check_in));
}

int main() {
    // Create some sample data
    room_t *rooms[MAX_ROOMS];
    guest_t *guests[MAX_GUESTS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = create_room(10);
    }
    for (int i = 0; i < MAX_GUESTS; i++) {
        guests[i] = create_guest(i % MAX_ROOMS);
    }

    // Add guests to rooms
    for (int i = 0; i < MAX_GUESTS; i++) {
        add_guest_to_room(guests[i], rooms[i % MAX_ROOMS]);
    }

    // Print the status of the rooms and guests
    for (int i = 0; i < MAX_ROOMS; i++) {
        print_room_status(rooms[i]);
    }
    for (int i = 0; i < MAX_GUESTS; i++) {
        print_guest_status(guests[i]);
    }

    // Check if a guest has checked out
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (is_guest_checked_out(guests[i])) {
            remove_guest_from_room(guests[i], rooms[guests[i]->room_id]);
        }
    }

    // Check if a room is full
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (is_room_full(rooms[i])) {
            printf("Room %d is full\n", rooms[i]->id);
        }
    }

    return 0;
}