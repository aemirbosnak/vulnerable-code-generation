//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hotel structure
typedef struct hotel {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int num_rooms;
    int num_floors;
    int num_guests;
    float avg_rating;
} hotel;

// Define the room structure
typedef struct room {
    int room_number;
    char type[20];
    int capacity;
    float price;
    int is_occupied;
} room;

// Define the guest structure
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int check_in_date;
    int check_out_date;
} guest;

// Define the function to create a new hotel
hotel *create_hotel(char *name, char *address, char *phone, char *email, int num_rooms, int num_floors, int num_guests, float avg_rating) {
    hotel *new_hotel = (hotel *)malloc(sizeof(hotel));
    strcpy(new_hotel->name, name);
    strcpy(new_hotel->address, address);
    strcpy(new_hotel->phone, phone);
    strcpy(new_hotel->email, email);
    new_hotel->num_rooms = num_rooms;
    new_hotel->num_floors = num_floors;
    new_hotel->num_guests = num_guests;
    new_hotel->avg_rating = avg_rating;

    return new_hotel;
}

// Define the function to create a new room
room *create_room(int room_number, char *type, int capacity, float price, int is_occupied) {
    room *new_room = (room *)malloc(sizeof(room));
    new_room->room_number = room_number;
    strcpy(new_room->type, type);
    new_room->capacity = capacity;
    new_room->price = price;
    new_room->is_occupied = is_occupied;

    return new_room;
}

// Define the function to create a new guest
guest *create_guest(char *name, char *address, char *phone, char *email, int room_number, int check_in_date, int check_out_date) {
    guest *new_guest = (guest *)malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    strcpy(new_guest->address, address);
    strcpy(new_guest->phone, phone);
    strcpy(new_guest->email, email);
    new_guest->room_number = room_number;
    new_guest->check_in_date = check_in_date;
    new_guest->check_out_date = check_out_date;

    return new_guest;
}

// Define the main function
int main() {
    // Create a new hotel
    hotel *hotel1 = create_hotel("The Grand Hotel", "123 Main Street", "555-1212", "info@grandhotel.com", 100, 10, 50, 4.5);

    // Create a new room
    room *room1 = create_room(101, "Deluxe", 2, 100.00, 0);

    // Create a new guest
    guest *guest1 = create_guest("John Smith", "123 Main Street", "555-1212", "john.smith@email.com", 101, 20230310, 20230315);

    // Print the hotel information
    printf("Hotel Name: %s\n", hotel1->name);
    printf("Hotel Address: %s\n", hotel1->address);
    printf("Hotel Phone: %s\n", hotel1->phone);
    printf("Hotel Email: %s\n", hotel1->email);
    printf("Hotel Number of Rooms: %d\n", hotel1->num_rooms);
    printf("Hotel Number of Floors: %d\n", hotel1->num_floors);
    printf("Hotel Number of Guests: %d\n", hotel1->num_guests);
    printf("Hotel Average Rating: %f\n", hotel1->avg_rating);

    // Print the room information
    printf("\nRoom Number: %d\n", room1->room_number);
    printf("Room Type: %s\n", room1->type);
    printf("Room Capacity: %d\n", room1->capacity);
    printf("Room Price: %f\n", room1->price);
    printf("Room Is Occupied: %d\n", room1->is_occupied);

    // Print the guest information
    printf("\nGuest Name: %s\n", guest1->name);
    printf("Guest Address: %s\n", guest1->address);
    printf("Guest Phone: %s\n", guest1->phone);
    printf("Guest Email: %s\n", guest1->email);
    printf("Guest Room Number: %d\n", guest1->room_number);
    printf("Guest Check-In Date: %d\n", guest1->check_in_date);
    printf("Guest Check-Out Date: %d\n", guest1->check_out_date);

    return 0;
}