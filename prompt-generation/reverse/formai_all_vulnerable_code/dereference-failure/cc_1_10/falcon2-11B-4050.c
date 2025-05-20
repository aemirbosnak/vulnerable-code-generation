//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hotel_t {
    char name[100];
    int capacity;
    int current_occupancy;
    int price_per_night;
    int availability;
} hotel_t;

hotel_t* create_hotel(const char* name, int capacity, int price_per_night) {
    hotel_t* hotel = malloc(sizeof(hotel_t));
    strcpy(hotel->name, name);
    hotel->capacity = capacity;
    hotel->price_per_night = price_per_night;
    hotel->current_occupancy = 0;
    hotel->availability = capacity;
    return hotel;
}

void destroy_hotel(hotel_t* hotel) {
    free(hotel);
}

void display_hotel_info(hotel_t* hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Current Occupancy: %d\n", hotel->current_occupancy);
    printf("Price per Night: %d\n", hotel->price_per_night);
    printf("Availability: %d\n", hotel->availability);
}

int check_availability(hotel_t* hotel) {
    return hotel->availability > 0;
}

void book_room(hotel_t* hotel, int room_id, int nights) {
    if (hotel->current_occupancy + nights > hotel->capacity) {
        printf("Room not available for booking.\n");
        return;
    }
    hotel->current_occupancy += nights;
    hotel->availability -= nights;
    printf("Room %d booked for %d nights.\n", room_id, nights);
}

void cancel_booking(hotel_t* hotel, int room_id, int nights) {
    if (hotel->current_occupancy < nights) {
        printf("Room not booked for cancellation.\n");
        return;
    }
    hotel->current_occupancy -= nights;
    hotel->availability += nights;
    printf("Booking for room %d canceled.\n", room_id);
}

int main() {
    hotel_t* hotel = create_hotel("Calm Hotel", 100, 50);
    display_hotel_info(hotel);

    int room_id = 1;
    int nights = 2;
    book_room(hotel, room_id, nights);
    display_hotel_info(hotel);

    cancel_booking(hotel, room_id, nights);
    display_hotel_info(hotel);

    destroy_hotel(hotel);

    return 0;
}