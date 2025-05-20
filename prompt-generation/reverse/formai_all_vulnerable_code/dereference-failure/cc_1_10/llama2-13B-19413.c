//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the hotel structure
struct hotel {
    char name[50];
    int num_rooms;
    int num_guests;
    int capacity;
};

// Define a function to create a new hotel
struct hotel *new_hotel(char *name, int num_rooms, int capacity) {
    struct hotel *hotel = (struct hotel *) malloc(sizeof(struct hotel));
    strcpy(hotel->name, name);
    hotel->num_rooms = num_rooms;
    hotel->num_guests = 0;
    hotel->capacity = capacity;
    return hotel;
}

// Define a function to add a guest to a hotel
void add_guest(struct hotel *hotel, char *name, int room_number) {
    if (hotel->num_guests >= hotel->capacity) {
        printf("The hotel is full. Sorry, we cannot accommodate any more guests.\n");
        return;
    }
    hotel->num_guests++;
    printf("Welcome, %s, to our humble abode! You have been assigned room %d.\n", name, room_number);
}

// Define a function to check if a room is available
int is_room_available(struct hotel *hotel, int room_number) {
    if (hotel->num_guests >= hotel->capacity) {
        return 0;
    }
    if (room_number < 0 || room_number >= hotel->num_rooms) {
        return 0;
    }
    return 1;
}

// Define a function to check if the hotel is full
int is_hotel_full(struct hotel *hotel) {
    return hotel->num_guests >= hotel->capacity;
}

// Define a function to print the hotel's status
void print_status(struct hotel *hotel) {
    printf("Hotel Status:\n");
    printf("Name: %s\n", hotel->name);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Guests: %d\n", hotel->num_guests);
    printf("Capacity: %d\n", hotel->capacity);
}

int main() {
    struct hotel *hotel;

    // Create a new hotel
    hotel = new_hotel("The Royal Inn", 50, 100);

    // Add some guests
    add_guest(hotel, "Sir Lancelot", 1);
    add_guest(hotel, "Lady Guinevere", 2);
    add_guest(hotel, "Sir Gawain", 3);

    // Check if the hotel is full
    if (is_hotel_full(hotel)) {
        printf("The hotel is full. Sorry, we cannot accommodate any more guests.\n");
    }

    // Check if a room is available
    if (!is_room_available(hotel, 4)) {
        printf("Room 4 is not available. Please choose another room.\n");
    }

    // Print the hotel's status
    print_status(hotel);

    return 0;
}