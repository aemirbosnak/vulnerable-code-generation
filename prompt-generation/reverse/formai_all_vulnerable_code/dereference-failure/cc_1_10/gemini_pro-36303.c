//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 1000

// Define the room types
enum room_type {
    SINGLE,
    DOUBLE,
    SUITE
};

// Define the guest status
enum guest_status {
    CHECKED_IN,
    CHECKED_OUT
};

// Define the hotel structure
struct hotel {
    char name[50];
    char address[100];
    char phone[20];
    int num_rooms;
    int num_guests;
    struct room *rooms;
    struct guest *guests;
};

// Define the room structure
struct room {
    int number;
    enum room_type type;
    int price;
    enum guest_status status;
    struct guest *guest;
};

// Define the guest structure
struct guest {
    char name[50];
    char address[100];
    char phone[20];
    enum guest_status status;
    struct room *room;
};

// Create a new hotel
struct hotel *create_hotel(char *name, char *address, char *phone, int num_rooms, int num_guests) {
    struct hotel *hotel = malloc(sizeof(struct hotel));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    strcpy(hotel->phone, phone);
    hotel->num_rooms = num_rooms;
    hotel->num_guests = num_guests;
    hotel->rooms = malloc(sizeof(struct room) * num_rooms);
    hotel->guests = malloc(sizeof(struct guest) * num_guests);
    return hotel;
}

// Add a new room to the hotel
void add_room(struct hotel *hotel, int number, enum room_type type, int price) {
    struct room *room = &hotel->rooms[number - 1];
    room->number = number;
    room->type = type;
    room->price = price;
    room->status = CHECKED_OUT;
    room->guest = NULL;
}

// Add a new guest to the hotel
void add_guest(struct hotel *hotel, char *name, char *address, char *phone) {
    struct guest *guest = &hotel->guests[hotel->num_guests];
    strcpy(guest->name, name);
    strcpy(guest->address, address);
    strcpy(guest->phone, phone);
    guest->status = CHECKED_IN;
    guest->room = NULL;
}

// Check in a guest
void check_in_guest(struct hotel *hotel, struct guest *guest, int room_number) {
    struct room *room = &hotel->rooms[room_number - 1];
    guest->room = room;
    room->guest = guest;
    room->status = CHECKED_IN;
    guest->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(struct hotel *hotel, struct guest *guest) {
    struct room *room = guest->room;
    guest->room = NULL;
    room->guest = NULL;
    room->status = CHECKED_OUT;
    guest->status = CHECKED_OUT;
}

// Print the hotel information
void print_hotel_info(struct hotel *hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Hotel Address: %s\n", hotel->address);
    printf("Hotel Phone: %s\n", hotel->phone);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Guests: %d\n", hotel->num_guests);
}

// Print the room information
void print_room_info(struct room *room) {
    printf("Room Number: %d\n", room->number);
    printf("Room Type: %s\n", room->type == SINGLE ? "SINGLE" : room->type == DOUBLE ? "DOUBLE" : "SUITE");
    printf("Room Price: %d\n", room->price);
    printf("Room Status: %s\n", room->status == CHECKED_IN ? "CHECKED_IN" : "CHECKED_OUT");
    if (room->guest != NULL) {
        printf("Guest Name: %s\n", room->guest->name);
        printf("Guest Address: %s\n", room->guest->address);
        printf("Guest Phone: %s\n", room->guest->phone);
    }
}

// Print the guest information
void print_guest_info(struct guest *guest) {
    printf("Guest Name: %s\n", guest->name);
    printf("Guest Address: %s\n", guest->address);
    printf("Guest Phone: %s\n", guest->phone);
    printf("Guest Status: %s\n", guest->status == CHECKED_IN ? "CHECKED_IN" : "CHECKED_OUT");
    if (guest->room != NULL) {
        printf("Room Number: %d\n", guest->room->number);
    }
}

// Main function
int main() {
    // Create a new hotel
    struct hotel *hotel = create_hotel("My Hotel", "123 Main Street", "555-1212", 10, 20);

    // Add some rooms to the hotel
    add_room(hotel, 1, SINGLE, 100);
    add_room(hotel, 2, DOUBLE, 150);
    add_room(hotel, 3, SUITE, 200);

    // Add some guests to the hotel
    add_guest(hotel, "John Smith", "123 Main Street", "555-1212");
    add_guest(hotel, "Jane Doe", "456 Elm Street", "555-1213");

    // Check in a guest
    check_in_guest(hotel, &hotel->guests[0], 1);

    // Print the hotel information
    print_hotel_info(hotel);

    // Print the room information
    print_room_info(&hotel->rooms[0]);

    // Print the guest information
    print_guest_info(&hotel->guests[0]);

    return 0;
}