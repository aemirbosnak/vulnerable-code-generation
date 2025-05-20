//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct room {
    int number;
    int capacity;
    int price;
    int status; // 0 for empty, 1 for occupied
} room_t;

typedef struct hotel {
    char *name;
    int num_rooms;
    room_t *rooms;
} hotel_t;

// Create a new hotel
hotel_t *hotel_create(char *name, int num_rooms) {
    hotel_t *hotel = malloc(sizeof(hotel_t));
    assert(hotel != NULL);

    hotel->name = name;
    hotel->num_rooms = num_rooms;
    hotel->rooms = malloc(sizeof(room_t) * num_rooms);
    assert(hotel->rooms != NULL);

    for (int i = 0; i < num_rooms; i++) {
        hotel->rooms[i].number = i + 1;
        hotel->rooms[i].capacity = 2;
        hotel->rooms[i].price = 100;
        hotel->rooms[i].status = 0;
    }

    return hotel;
}

// Destroy a hotel
void hotel_destroy(hotel_t *hotel) {
    free(hotel->name);
    free(hotel->rooms);
    free(hotel);
}

// Book a room
int hotel_book_room(hotel_t *hotel, int room_number) {
    if (room_number < 1 || room_number > hotel->num_rooms) {
        return -1;
    }

    room_t *room = &hotel->rooms[room_number - 1];
    if (room->status == 1) {
        return -1;
    }

    room->status = 1;
    return 0;
}

// Check out a room
int hotel_check_out_room(hotel_t *hotel, int room_number) {
    if (room_number < 1 || room_number > hotel->num_rooms) {
        return -1;
    }

    room_t *room = &hotel->rooms[room_number - 1];
    if (room->status == 0) {
        return -1;
    }

    room->status = 0;
    return 0;
}

// Print the hotel's information
void hotel_print_info(hotel_t *hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Number of rooms: %d\n", hotel->num_rooms);

    for (int i = 0; i < hotel->num_rooms; i++) {
        room_t *room = &hotel->rooms[i];
        printf("Room %d: capacity %d, price %d, status %d\n", room->number, room->capacity, room->price, room->status);
    }
}

int main() {
    // Create a new hotel
    hotel_t *hotel = hotel_create("My Hotel", 10);

    // Book a room
    int room_number = 5;
    int result = hotel_book_room(hotel, room_number);
    if (result == 0) {
        printf("Room %d booked successfully.\n", room_number);
    } else {
        printf("Error booking room %d.\n", room_number);
    }

    // Check out a room
    room_number = 3;
    result = hotel_check_out_room(hotel, room_number);
    if (result == 0) {
        printf("Room %d checked out successfully.\n", room_number);
    } else {
        printf("Error checking out room %d.\n", room_number);
    }

    // Print the hotel's information
    hotel_print_info(hotel);

    // Destroy the hotel
    hotel_destroy(hotel);

    return 0;
}