//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    int room_number;
    char *room_type;
    float price;
    int availability;
} room;

typedef struct hotel {
    char *hotel_name;
    room *rooms;
    int num_rooms;
} hotel;

// Function to create a new hotel
hotel *create_hotel(char *hotel_name, int num_rooms) {
    hotel *new_hotel = (hotel *)malloc(sizeof(hotel));
    new_hotel->hotel_name = hotel_name;
    new_hotel->rooms = (room *)malloc(sizeof(room) * num_rooms);
    new_hotel->num_rooms = num_rooms;
    return new_hotel;
}

// Function to add a new room to a hotel
void add_room(hotel *hotel, int room_number, char *room_type, float price) {
    room new_room;
    new_room.room_number = room_number;
    new_room.room_type = room_type;
    new_room.price = price;
    new_room.availability = 1;
    hotel->rooms[hotel->num_rooms++] = new_room;
}

// Function to book a room in a hotel
void book_room(hotel *hotel, int room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].room_number == room_number) {
            hotel->rooms[i].availability = 0;
            printf("Room %d has been booked.\n", room_number);
            return;
        }
    }
    printf("Room %d is not available.\n", room_number);
}

// Function to cancel a room booking in a hotel
void cancel_room_booking(hotel *hotel, int room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].room_number == room_number) {
            hotel->rooms[i].availability = 1;
            printf("Room %d has been canceled.\n", room_number);
            return;
        }
    }
    printf("Room %d is not booked.\n", room_number);
}

// Function to print the details of a hotel
void print_hotel_details(hotel *hotel) {
    printf("Hotel Name: %s\n", hotel->hotel_name);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    for (int i = 0; i < hotel->num_rooms; i++) {
        printf("Room %d: %s, $%.2f\n",
               hotel->rooms[i].room_number,
               hotel->rooms[i].room_type,
               hotel->rooms[i].price);
    }
}

int main() {
    // Create a new hotel
    hotel *hotel = create_hotel("The Grand Hotel", 10);

    // Add some rooms to the hotel
    add_room(hotel, 101, "Standard Room", 100.00);
    add_room(hotel, 102, "Deluxe Room", 150.00);
    add_room(hotel, 103, "Suite", 200.00);

    // Print the details of the hotel
    print_hotel_details(hotel);

    // Book a room in the hotel
    book_room(hotel, 101);

    // Cancel a room booking in the hotel
    cancel_room_booking(hotel, 101);

    return 0;
}