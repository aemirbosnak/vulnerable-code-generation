//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum length of a string
#define MAX_STR_LEN 100

// Define the structure of a room
typedef struct room {
    int room_number;
    char room_type[MAX_STR_LEN];
    int is_occupied;
    float price;
} room_t;

// Define the structure of a hotel
typedef struct hotel {
    char name[MAX_STR_LEN];
    room_t rooms[MAX_ROOMS];
    int num_rooms;
} hotel_t;

// Function to create a new hotel
hotel_t *create_hotel(char *name) {
    hotel_t *hotel = (hotel_t *)malloc(sizeof(hotel_t));
    strcpy(hotel->name, name);
    hotel->num_rooms = 0;
    return hotel;
}

// Function to add a new room to the hotel
void add_room(hotel_t *hotel, int room_number, char *room_type, float price) {
    room_t *room = &hotel->rooms[hotel->num_rooms];
    room->room_number = room_number;
    strcpy(room->room_type, room_type);
    room->is_occupied = 0;
    room->price = price;
    hotel->num_rooms++;
}

// Function to find a room by room number
room_t *find_room(hotel_t *hotel, int room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        room_t *room = &hotel->rooms[i];
        if (room->room_number == room_number) {
            return room;
        }
    }
    return NULL;
}

// Function to check in a guest
void check_in(hotel_t *hotel, int room_number) {
    room_t *room = find_room(hotel, room_number);
    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }
    if (room->is_occupied) {
        printf("Room is already occupied.\n");
        return;
    }
    room->is_occupied = 1;
    printf("Guest checked in to room %d.\n", room_number);
}

// Function to check out a guest
void check_out(hotel_t *hotel, int room_number) {
    room_t *room = find_room(hotel, room_number);
    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }
    if (!room->is_occupied) {
        printf("Room is already empty.\n");
        return;
    }
    room->is_occupied = 0;
    printf("Guest checked out of room %d.\n", room_number);
}

// Function to print the hotel information
void print_hotel(hotel_t *hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Number of rooms: %d\n", hotel->num_rooms);
    for (int i = 0; i < hotel->num_rooms; i++) {
        room_t *room = &hotel->rooms[i];
        printf("Room %d: %s, %s, $%.2f\n", room->room_number, room->room_type, room->is_occupied ? "Occupied" : "Empty", room->price);
    }
}

int main() {
    // Create a new hotel
    hotel_t *hotel = create_hotel("The Grand Hotel");

    // Add some rooms to the hotel
    add_room(hotel, 101, "Standard", 100.00);
    add_room(hotel, 102, "Deluxe", 150.00);
    add_room(hotel, 103, "Suite", 200.00);

    // Check in a guest to room 101
    check_in(hotel, 101);

    // Check out a guest from room 102
    check_out(hotel, 102);

    // Print the hotel information
    print_hotel(hotel);

    return 0;
}