//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int room_number;
    char *room_type;
    double price;
    int is_occupied;
} room;

typedef struct {
    char *name;
    char *address;
    char *phone_number;
    char *email_address;
} guest;

typedef struct {
    int booking_id;
    room *room;
    guest *guest;
    char *check_in_date;
    char *check_out_date;
    double total_price;
} booking;

room *create_room(int room_number, char *room_type, double price) {
    room *new_room = malloc(sizeof(room));
    new_room->room_number = room_number;
    new_room->room_type = malloc(strlen(room_type) + 1);
    strcpy(new_room->room_type, room_type);
    new_room->price = price;
    new_room->is_occupied = 0;
    return new_room;
}

guest *create_guest(char *name, char *address, char *phone_number, char *email_address) {
    guest *new_guest = malloc(sizeof(guest));
    new_guest->name = malloc(strlen(name) + 1);
    strcpy(new_guest->name, name);
    new_guest->address = malloc(strlen(address) + 1);
    strcpy(new_guest->address, address);
    new_guest->phone_number = malloc(strlen(phone_number) + 1);
    strcpy(new_guest->phone_number, phone_number);
    new_guest->email_address = malloc(strlen(email_address) + 1);
    strcpy(new_guest->email_address, email_address);
    return new_guest;
}

booking *create_booking(int booking_id, room *room, guest *guest, char *check_in_date, char *check_out_date) {
    booking *new_booking = malloc(sizeof(booking));
    new_booking->booking_id = booking_id;
    new_booking->room = room;
    new_booking->guest = guest;
    new_booking->check_in_date = malloc(strlen(check_in_date) + 1);
    strcpy(new_booking->check_in_date, check_in_date);
    new_booking->check_out_date = malloc(strlen(check_out_date) + 1);
    strcpy(new_booking->check_out_date, check_out_date);
    new_booking->total_price = 0;
    return new_booking;
}

void print_room(room *room) {
    printf("Room Number: %d\n", room->room_number);
    printf("Room Type: %s\n", room->room_type);
    printf("Price: %f\n", room->price);
    printf("Is Occupied: %d\n", room->is_occupied);
}

void print_guest(guest *guest) {
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone Number: %s\n", guest->phone_number);
    printf("Email Address: %s\n", guest->email_address);
}

void print_booking(booking *booking) {
    printf("Booking ID: %d\n", booking->booking_id);
    print_room(booking->room);
    print_guest(booking->guest);
    printf("Check In Date: %s\n", booking->check_in_date);
    printf("Check Out Date: %s\n", booking->check_out_date);
    printf("Total Price: %f\n", booking->total_price);
}

int main() {
    room *room1 = create_room(1, "Standard", 100.00);
    room *room2 = create_room(2, "Deluxe", 150.00);
    room *room3 = create_room(3, "Suite", 200.00);

    guest *guest1 = create_guest("John Doe", "123 Main Street", "555-1212", "john.doe@email.com");
    guest *guest2 = create_guest("Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com");
    guest *guest3 = create_guest("John Smith", "789 Oak Street", "555-1214", "john.smith@email.com");

    booking *booking1 = create_booking(1, room1, guest1, "2023-01-01", "2023-01-07");
    booking *booking2 = create_booking(2, room2, guest2, "2023-01-08", "2023-01-14");
    booking *booking3 = create_booking(3, room3, guest3, "2023-01-15", "2023-01-21");

    print_booking(booking1);
    print_booking(booking2);
    print_booking(booking3);

    return 0;
}