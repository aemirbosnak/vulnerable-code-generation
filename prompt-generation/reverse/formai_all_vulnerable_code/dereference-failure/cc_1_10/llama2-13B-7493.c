//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold hotel information
typedef struct {
    char name[50];
    int num_rooms;
    int current_occupancy;
} hotel_info_t;

// Function to create a new hotel
hotel_info_t* create_hotel(char* name, int num_rooms) {
    hotel_info_t* new_hotel = (hotel_info_t*) malloc(sizeof(hotel_info_t));
    strcpy(new_hotel->name, name);
    new_hotel->num_rooms = num_rooms;
    new_hotel->current_occupancy = 0;
    return new_hotel;
}

// Function to check if a hotel has availability
int has_availability(hotel_info_t* hotel) {
    return hotel->current_occupancy < hotel->num_rooms;
}

// Function to book a room in a hotel
void book_room(hotel_info_t* hotel, int room_number) {
    if (has_availability(hotel)) {
        hotel->current_occupancy++;
        printf("Room %d booked\n", room_number);
    } else {
        printf("No availability in hotel %s\n", hotel->name);
    }
}

// Function to check if a hotel is fully booked
int is_fully_booked(hotel_info_t* hotel) {
    return hotel->current_occupancy == hotel->num_rooms;
}

// Function to display hotel information
void display_hotel(hotel_info_t* hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Number of rooms: %d\n", hotel->num_rooms);
    printf("Current occupancy: %d\n", hotel->current_occupancy);
}

int main() {
    hotel_info_t* hotel1 = create_hotel("Hotel 1", 50);
    hotel_info_t* hotel2 = create_hotel("Hotel 2", 20);

    book_room(hotel1, 10);
    book_room(hotel2, 5);

    display_hotel(hotel1);
    display_hotel(hotel2);

    if (is_fully_booked(hotel1)) {
        printf("Hotel 1 is fully booked\n");
    }

    return 0;
}