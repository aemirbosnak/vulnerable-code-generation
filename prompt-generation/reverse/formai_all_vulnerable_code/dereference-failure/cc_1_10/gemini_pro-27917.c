//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel information
typedef struct hotel {
    char name[50];
    char address[100];
    int num_rooms;
    int num_floors;
    int num_stars;
} hotel_t;

// Structure to store room information
typedef struct room {
    int room_number;
    int floor;
    int type; // 1 = single, 2 = double, 3 = suite
    int price;
    int is_occupied;
} room_t;

// Structure to store guest information
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int num_nights;
    int checkin_date;
    int checkout_date;
} guest_t;

// Function to create a new hotel
hotel_t* create_hotel(char* name, char* address, int num_rooms, int num_floors, int num_stars) {
    hotel_t* hotel = (hotel_t*)malloc(sizeof(hotel_t));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    hotel->num_rooms = num_rooms;
    hotel->num_floors = num_floors;
    hotel->num_stars = num_stars;
    return hotel;
}

// Function to create a new room
room_t* create_room(int room_number, int floor, int type, int price) {
    room_t* room = (room_t*)malloc(sizeof(room_t));
    room->room_number = room_number;
    room->floor = floor;
    room->type = type;
    room->price = price;
    room->is_occupied = 0;
    return room;
}

// Function to create a new guest
guest_t* create_guest(char* name, char* address, char* phone, char* email, int num_nights, int checkin_date, int checkout_date) {
    guest_t* guest = (guest_t*)malloc(sizeof(guest_t));
    strcpy(guest->name, name);
    strcpy(guest->address, address);
    strcpy(guest->phone, phone);
    strcpy(guest->email, email);
    guest->num_nights = num_nights;
    guest->checkin_date = checkin_date;
    guest->checkout_date = checkout_date;
    return guest;
}

// Function to print hotel information
void print_hotel(hotel_t* hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Floors: %d\n", hotel->num_floors);
    printf("Number of Stars: %d\n", hotel->num_stars);
}

// Function to print room information
void print_room(room_t* room) {
    printf("Room Number: %d\n", room->room_number);
    printf("Floor: %d\n", room->floor);
    printf("Type: %d\n", room->type);
    printf("Price: %d\n", room->price);
    printf("Is Occupied: %d\n", room->is_occupied);
}

// Function to print guest information
void print_guest(guest_t* guest) {
    printf("Guest Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone: %s\n", guest->phone);
    printf("Email: %s\n", guest->email);
    printf("Number of Nights: %d\n", guest->num_nights);
    printf("Checkin Date: %d\n", guest->checkin_date);
    printf("Checkout Date: %d\n", guest->checkout_date);
}

// Main function
int main() {
    // Create a new hotel
    hotel_t* hotel = create_hotel("The Grand Hotel", "123 Main Street", 100, 10, 5);

    // Create a new room
    room_t* room = create_room(101, 2, 2, 100);

    // Create a new guest
    guest_t* guest = create_guest("John Doe", "123 Any Street", "555-1212", "john.doe@example.com", 3, 20230301, 20230304);

    // Print hotel information
    printf("Hotel Information:\n");
    print_hotel(hotel);

    // Print room information
    printf("\nRoom Information:\n");
    print_room(room);

    // Print guest information
    printf("\nGuest Information:\n");
    print_guest(guest);

    return 0;
}