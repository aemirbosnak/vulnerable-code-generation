//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold hotel information
typedef struct {
    char name[50];
    int num_rooms;
    int num_guests;
} hotel_info;

// Function to create a new hotel
 hotel_info* create_hotel(char* name) {
    hotel_info* new_hotel = (hotel_info*) malloc(sizeof(hotel_info));
    strcpy(new_hotel->name, name);
    new_hotel->num_rooms = 0;
    new_hotel->num_guests = 0;
    return new_hotel;
}

// Function to add a room to a hotel
void add_room(hotel_info* hotel, int num_guests) {
    hotel->num_rooms++;
    hotel->num_guests += num_guests;
}

// Function to check if a hotel has available rooms
int has_avail_rooms(hotel_info* hotel) {
    return hotel->num_rooms < hotel->num_guests;
}

// Function to check if a hotel is full
int is_full(hotel_info* hotel) {
    return hotel->num_rooms >= hotel->num_guests;
}

// Function to make a reservation
void make_reservation(hotel_info* hotel, int num_nights) {
    if (has_avail_rooms(hotel)) {
        hotel->num_guests += num_nights;
    } else {
        printf("Sorry, the hotel is full.\n");
    }
}

// Function to display hotel information
void display_hotel(hotel_info* hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Number of rooms: %d\n", hotel->num_rooms);
    printf("Number of guests: %d\n", hotel->num_guests);
}

int main() {
    hotel_info* hotels[] = {
        create_hotel("Hotel A"),
        create_hotel("Hotel B"),
        create_hotel("Hotel C")
    };

    int choice;

    do {
        printf("Welcome to the Hotel Management System!\n");
        printf("Please select a hotel: ");
        scanf("%d", &choice);

        if (choice < 0 || choice >= sizeof(hotels) / sizeof(hotels[0])) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        display_hotel(hotels[choice]);

        switch (choice) {
            case 0:
                add_room(hotels[0], 5);
                break;
            case 1:
                add_room(hotels[1], 3);
                break;
            case 2:
                add_room(hotels[2], 2);
                break;
            default:
                break;
        }

        make_reservation(hotels[choice], 2);

    } while (1);

    return 0;
}