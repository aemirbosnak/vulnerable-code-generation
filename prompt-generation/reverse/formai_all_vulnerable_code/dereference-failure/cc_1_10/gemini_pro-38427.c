//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the structure of a room
typedef struct Room {
    int room_number;
    char room_type[20];
    int is_occupied;
    float price;
} Room;

// Define the structure of a guest
typedef struct Guest {
    char name[50];
    char address[100];
    char phone_number[20];
    char email_address[50];
    int room_number;
    int check_in_date;
    int check_out_date;
} Guest;

// Define the structure of the hotel
typedef struct Hotel {
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_ROOMS];
    int num_rooms;
    int num_guests;
} Hotel;

// Create a new hotel
Hotel* create_hotel() {
    Hotel* hotel = malloc(sizeof(Hotel));
    hotel->num_rooms = 0;
    hotel->num_guests = 0;
    return hotel;
}

// Add a new room to the hotel
void add_room(Hotel* hotel, int room_number, char* room_type, float price) {
    hotel->rooms[hotel->num_rooms].room_number = room_number;
    strcpy(hotel->rooms[hotel->num_rooms].room_type, room_type);
    hotel->rooms[hotel->num_rooms].is_occupied = 0;
    hotel->rooms[hotel->num_rooms].price = price;
    hotel->num_rooms++;
}

// Add a new guest to the hotel
void add_guest(Hotel* hotel, char* name, char* address, char* phone_number, char* email_address, int room_number, int check_in_date, int check_out_date) {
    strcpy(hotel->guests[hotel->num_guests].name, name);
    strcpy(hotel->guests[hotel->num_guests].address, address);
    strcpy(hotel->guests[hotel->num_guests].phone_number, phone_number);
    strcpy(hotel->guests[hotel->num_guests].email_address, email_address);
    hotel->guests[hotel->num_guests].room_number = room_number;
    hotel->guests[hotel->num_guests].check_in_date = check_in_date;
    hotel->guests[hotel->num_guests].check_out_date = check_out_date;
    hotel->num_guests++;
}

// Print the details of a room
void print_room(Room room) {
    printf("Room Number: %d\n", room.room_number);
    printf("Room Type: %s\n", room.room_type);
    printf("Is Occupied: %d\n", room.is_occupied);
    printf("Price: %.2f\n", room.price);
}

// Print the details of a guest
void print_guest(Guest guest) {
    printf("Name: %s\n", guest.name);
    printf("Address: %s\n", guest.address);
    printf("Phone Number: %s\n", guest.phone_number);
    printf("Email Address: %s\n", guest.email_address);
    printf("Room Number: %d\n", guest.room_number);
    printf("Check In Date: %d\n", guest.check_in_date);
    printf("Check Out Date: %d\n", guest.check_out_date);
}

// Print the details of the hotel
void print_hotel(Hotel* hotel) {
    printf("Hotel Rooms:\n");
    for (int i = 0; i < hotel->num_rooms; i++) {
        print_room(hotel->rooms[i]);
        printf("\n");
    }

    printf("Hotel Guests:\n");
    for (int i = 0; i < hotel->num_guests; i++) {
        print_guest(hotel->guests[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new hotel
    Hotel* hotel = create_hotel();

    // Add some rooms to the hotel
    add_room(hotel, 101, "Standard", 100.00);
    add_room(hotel, 102, "Deluxe", 150.00);
    add_room(hotel, 103, "Suite", 200.00);

    // Add some guests to the hotel
    add_guest(hotel, "John Smith", "123 Main Street", "555-1212", "john.smith@email.com", 101, 20230301, 20230303);
    add_guest(hotel, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com", 102, 20230302, 20230304);
    add_guest(hotel, "Bill Jones", "789 Oak Street", "555-1214", "bill.jones@email.com", 103, 20230303, 20230305);

    // Print the details of the hotel
    print_hotel(hotel);

    return 0;
}