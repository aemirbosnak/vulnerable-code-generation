//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: scalable
// Hotel Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms
#define MAX_ROOMS 100

// Define the room structure
typedef struct room {
    int room_number;
    char room_type;
    int is_occupied;
    char guest_name[50];
    char guest_phone[20];
    char guest_email[50];
} room;

// Define the hotel structure
typedef struct hotel {
    room rooms[MAX_ROOMS];
    int num_rooms;
} hotel;

// Create a new hotel
hotel *create_hotel() {
    hotel *h = (hotel *)malloc(sizeof(hotel));
    h->num_rooms = 0;
    return h;
}

// Add a new room to the hotel
void add_room(hotel *h, int room_number, char room_type) {
    if (h->num_rooms >= MAX_ROOMS) {
        printf("Error: Hotel is full.\n");
        return;
    }

    h->rooms[h->num_rooms].room_number = room_number;
    h->rooms[h->num_rooms].room_type = room_type;
    h->rooms[h->num_rooms].is_occupied = 0;
    h->num_rooms++;
}

// Check in a guest
void check_in_guest(hotel *h, int room_number, char *guest_name, char *guest_phone, char *guest_email) {
    int i;

    // Find the room
    for (i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].room_number == room_number) {
            break;
        }
    }

    // Check if the room is available
    if (h->rooms[i].is_occupied) {
        printf("Error: Room is not available.\n");
        return;
    }

    // Check in the guest
    strcpy(h->rooms[i].guest_name, guest_name);
    strcpy(h->rooms[i].guest_phone, guest_phone);
    strcpy(h->rooms[i].guest_email, guest_email);
    h->rooms[i].is_occupied = 1;
}

// Check out a guest
void check_out_guest(hotel *h, int room_number) {
    int i;

    // Find the room
    for (i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].room_number == room_number) {
            break;
        }
    }

    // Check if the room is occupied
    if (!h->rooms[i].is_occupied) {
        printf("Error: Room is not occupied.\n");
        return;
    }

    // Check out the guest
    h->rooms[i].is_occupied = 0;
    strcpy(h->rooms[i].guest_name, "");
    strcpy(h->rooms[i].guest_phone, "");
    strcpy(h->rooms[i].guest_email, "");
}

// Print the hotel information
void print_hotel_info(hotel *h) {
    int i;

    printf("Hotel Information\n");
    printf("-----------------\n");
    printf("Number of rooms: %d\n", h->num_rooms);
    for (i = 0; i < h->num_rooms; i++) {
        printf("Room %d: ", h->rooms[i].room_number);
        if (h->rooms[i].is_occupied) {
            printf("Occupied by %s\n", h->rooms[i].guest_name);
        } else {
            printf("Available\n");
        }
    }
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel();

    // Add some rooms to the hotel
    add_room(h, 101, 'S');
    add_room(h, 102, 'D');
    add_room(h, 103, 'Q');
    add_room(h, 104, 'K');

    // Check in some guests
    check_in_guest(h, 101, "John Doe", "555-1212", "john.doe@example.com");
    check_in_guest(h, 103, "Jane Doe", "555-1213", "jane.doe@example.com");

    // Check out a guest
    check_out_guest(h, 101);

    // Print the hotel information
    print_hotel_info(h);

    return 0;
}