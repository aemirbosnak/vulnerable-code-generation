//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a hotel room
typedef struct Room {
    int room_number;
    char room_type;
    int capacity;
    int availability;
    float price;
} Room;

// Structure to represent a hotel guest
typedef struct Guest {
    char name[50];
    char address[100];
    char phone_number[20];
    char email_address[50];
    int number_of_guests;
    char check_in_date[20];
    char check_out_date[20];
    int room_number;
} Guest;

// Function to create a new room
Room* create_room(int room_number, char room_type, int capacity, int availability, float price) {
    Room* room = (Room*)malloc(sizeof(Room));
    room->room_number = room_number;
    room->room_type = room_type;
    room->capacity = capacity;
    room->availability = availability;
    room->price = price;
    return room;
}

// Function to create a new guest
Guest* create_guest(char* name, char* address, char* phone_number, char* email_address, int number_of_guests, char* check_in_date, char* check_out_date, int room_number) {
    Guest* guest = (Guest*)malloc(sizeof(Guest));
    strcpy(guest->name, name);
    strcpy(guest->address, address);
    strcpy(guest->phone_number, phone_number);
    strcpy(guest->email_address, email_address);
    guest->number_of_guests = number_of_guests;
    strcpy(guest->check_in_date, check_in_date);
    strcpy(guest->check_out_date, check_out_date);
    guest->room_number = room_number;
    return guest;
}

// Function to check availability of a room
int is_room_available(Room* room) {
    return room->availability;
}

// Function to book a room
void book_room(Room* room, Guest* guest) {
    room->availability = 0;
    guest->room_number = room->room_number;
}

// Function to check out a guest
void check_out_guest(Room* room, Guest* guest) {
    room->availability = 1;
    guest->room_number = 0;
}

// Function to print the details of a room
void print_room_details(Room* room) {
    printf("Room Number: %d\n", room->room_number);
    printf("Room Type: %c\n", room->room_type);
    printf("Capacity: %d\n", room->capacity);
    printf("Availability: %d\n", room->availability);
    printf("Price: %f\n", room->price);
}

// Function to print the details of a guest
void print_guest_details(Guest* guest) {
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone Number: %s\n", guest->phone_number);
    printf("Email Address: %s\n", guest->email_address);
    printf("Number of Guests: %d\n", guest->number_of_guests);
    printf("Check-In Date: %s\n", guest->check_in_date);
    printf("Check-Out Date: %s\n", guest->check_out_date);
    printf("Room Number: %d\n", guest->room_number);
}

// Main function
int main() {
    // Create a few rooms
    Room* room1 = create_room(1, 'S', 2, 1, 100.0);
    Room* room2 = create_room(2, 'D', 4, 1, 150.0);
    Room* room3 = create_room(3, 'T', 6, 0, 200.0);

    // Create a few guests
    Guest* guest1 = create_guest("John Doe", "123 Main Street", "555-123-4567", "john.doe@email.com", 2, "2023-03-01", "2023-03-03", 0);
    Guest* guest2 = create_guest("Jane Doe", "456 Elm Street", "555-234-5678", "jane.doe@email.com", 4, "2023-03-04", "2023-03-06", 0);
    Guest* guest3 = create_guest("John Smith", "789 Oak Street", "555-345-6789", "john.smith@email.com", 6, "2023-03-07", "2023-03-09", 0);

    // Check availability of a room
    if (is_room_available(room1)) {
        printf("Room 1 is available.\n");
    } else {
        printf("Room 1 is not available.\n");
    }

    // Book a room
    book_room(room1, guest1);

    // Check out a guest
    check_out_guest(room1, guest1);

    // Print the details of a room
    print_room_details(room1);

    // Print the details of a guest
    print_guest_details(guest1);

    return 0;
}