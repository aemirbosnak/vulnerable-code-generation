//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 1000

// Define the room types
#define SINGLE 1
#define DOUBLE 2
#define SUITE 3

// Define the guest status
#define CHECKED_IN 1
#define CHECKED_OUT 0

// Define the hotel structure
struct Hotel {
    int num_rooms;
    int num_guests;
    struct Room *rooms;
    struct Guest *guests;
};

// Define the room structure
struct Room {
    int room_number;
    int room_type;
    int room_status;
    struct Guest *guest;
};

// Define the guest structure
struct Guest {
    int guest_id;
    char *guest_name;
    int guest_status;
    struct Room *room;
};

// Create a new hotel
struct Hotel *create_hotel(int num_rooms) {
    struct Hotel *hotel = malloc(sizeof(struct Hotel));
    hotel->num_rooms = num_rooms;
    hotel->num_guests = 0;
    hotel->rooms = malloc(sizeof(struct Room) * num_rooms);
    hotel->guests = malloc(sizeof(struct Guest) * MAX_GUESTS);
    return hotel;
}

// Add a new room to the hotel
void add_room(struct Hotel *hotel, int room_number, int room_type) {
    struct Room *room = &hotel->rooms[room_number];
    room->room_number = room_number;
    room->room_type = room_type;
    room->room_status = 0;
    room->guest = NULL;
}

// Add a new guest to the hotel
void add_guest(struct Hotel *hotel, int guest_id, char *guest_name) {
    struct Guest *guest = &hotel->guests[guest_id];
    guest->guest_id = guest_id;
    guest->guest_name = guest_name;
    guest->guest_status = CHECKED_OUT;
    guest->room = NULL;
}

// Check in a guest
void check_in_guest(struct Hotel *hotel, int guest_id, int room_number) {
    struct Guest *guest = &hotel->guests[guest_id];
    struct Room *room = &hotel->rooms[room_number];
    guest->guest_status = CHECKED_IN;
    guest->room = room;
    room->room_status = 1;
    room->guest = guest;
}

// Check out a guest
void check_out_guest(struct Hotel *hotel, int guest_id) {
    struct Guest *guest = &hotel->guests[guest_id];
    struct Room *room = guest->room;
    guest->guest_status = CHECKED_OUT;
    guest->room = NULL;
    room->room_status = 0;
    room->guest = NULL;
}

// Print the hotel information
void print_hotel(struct Hotel *hotel) {
    printf("Hotel Information\n");
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Guests: %d\n", hotel->num_guests);
    for (int i = 0; i < hotel->num_rooms; i++) {
        struct Room *room = &hotel->rooms[i];
        printf("Room %d:\n", room->room_number);
        printf("Room Type: %d\n", room->room_type);
        printf("Room Status: %d\n", room->room_status);
        if (room->guest != NULL) {
            struct Guest *guest = room->guest;
            printf("Guest Name: %s\n", guest->guest_name);
            printf("Guest Status: %d\n", guest->guest_status);
        }
    }
}

// Free the memory allocated for the hotel
void destroy_hotel(struct Hotel *hotel) {
    free(hotel->rooms);
    free(hotel->guests);
    free(hotel);
}

// Main function
int main() {
    // Create a new hotel
    struct Hotel *hotel = create_hotel(10);

    // Add some rooms to the hotel
    add_room(hotel, 1, SINGLE);
    add_room(hotel, 2, DOUBLE);
    add_room(hotel, 3, SUITE);

    // Add some guests to the hotel
    add_guest(hotel, 1, "John Doe");
    add_guest(hotel, 2, "Jane Doe");
    add_guest(hotel, 3, "Peter Parker");

    // Check in some guests
    check_in_guest(hotel, 1, 1);
    check_in_guest(hotel, 2, 2);
    check_in_guest(hotel, 3, 3);

    // Print the hotel information
    print_hotel(hotel);

    // Check out some guests
    check_out_guest(hotel, 1);
    check_out_guest(hotel, 2);

    // Print the hotel information again
    print_hotel(hotel);

    // Free the memory allocated for the hotel
    destroy_hotel(hotel);

    return 0;
}