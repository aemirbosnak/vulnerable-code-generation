//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 50

// Structure to store hotel information
typedef struct {
    int num_rooms;
    int num_guests;
    int available_rooms;
    int available_guests;
    struct room {
        char name[20];
        int num_beds;
        int current_guest;
    } rooms[MAX_ROOMS];
} hotel_info;

// Function to create a new hotel
hotel_info* create_hotel(int num_rooms) {
    hotel_info* hotel = (hotel_info*) malloc(sizeof(hotel_info));
    hotel->num_rooms = num_rooms;
    hotel->num_guests = 0;
    hotel->available_rooms = num_rooms;
    hotel->available_guests = 0;
    for (int i = 0; i < num_rooms; i++) {
        hotel->rooms[i].name[0] = '\0';
        hotel->rooms[i].num_beds = 0;
        hotel->rooms[i].current_guest = 0;
    }
    return hotel;
}

// Function to check availability of rooms and guests
int check_availability(hotel_info* hotel) {
    int available_rooms = hotel->available_rooms;
    int available_guests = hotel->available_guests;
    if (available_rooms > 0 && available_guests > 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to book a room
void book_room(hotel_info* hotel, char* room_name) {
    int i;
    for (i = 0; i < hotel->num_rooms; i++) {
        if (strcmp(room_name, hotel->rooms[i].name) == 0) {
            hotel->rooms[i].current_guest++;
            hotel->available_rooms--;
            hotel->available_guests++;
            break;
        }
    }
}

// Function to check out a guest
void check_out(hotel_info* hotel) {
    int i;
    for (i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].current_guest > 0) {
            hotel->rooms[i].current_guest--;
            hotel->available_rooms++;
            hotel->available_guests--;
            break;
        }
    }
}

// Function to display information about the hotel
void display_info(hotel_info* hotel) {
    printf("Hotel Information:\n");
    printf("Number of rooms: %d\n", hotel->num_rooms);
    printf("Number of guests: %d\n", hotel->num_guests);
    printf("Available rooms: %d\n", hotel->available_rooms);
    printf("Available guests: %d\n", hotel->available_guests);
    for (int i = 0; i < hotel->num_rooms; i++) {
        printf("Room %d: %s (%d guests)\n", i, hotel->rooms[i].name, hotel->rooms[i].current_guest);
    }
}

int main() {
    hotel_info* hotel = create_hotel(10);
    char room_name[20];
    int num_guests = 5;

    // Book rooms and check availability
    book_room(hotel, "Single Bed");
    book_room(hotel, "Double Bed");
    book_room(hotel, "Suite");
    check_availability(hotel);

    // Check out guests
    check_out(hotel);

    // Display information about the hotel
    display_info(hotel);

    return 0;
}