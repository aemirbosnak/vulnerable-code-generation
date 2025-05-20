//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ROOM STRUCT */
typedef struct Room {
    int number;
    int capacity;
    char* type;
    char* status;
} Room;

/* GUEST STRUCT */
typedef struct Guest {
    char* name;
    char* address;
    char* phone;
} Guest;

/* BOOKING STRUCT */
typedef struct Booking {
    int id;
    Guest* guest;
    Room* room;
    char* check_in_date;
    char* check_out_date;
    float total_amount;
} Booking;

/* FUNCTION TO CREATE A NEW ROOM */
Room* create_room(int number, int capacity, char* type, char* status) {
    Room* room = malloc(sizeof(Room));
    room->number = number;
    room->capacity = capacity;
    room->type = strdup(type);
    room->status = strdup(status);
    return room;
}

/* FUNCTION TO CREATE A NEW GUEST */
Guest* create_guest(char* name, char* address, char* phone) {
    Guest* guest = malloc(sizeof(Guest));
    guest->name = strdup(name);
    guest->address = strdup(address);
    guest->phone = strdup(phone);
    return guest;
}

/* FUNCTION TO CREATE A NEW BOOKING */
Booking* create_booking(int id, Guest* guest, Room* room, char* check_in_date, char* check_out_date, float total_amount) {
    Booking* booking = malloc(sizeof(Booking));
    booking->id = id;
    booking->guest = guest;
    booking->room = room;
    booking->check_in_date = strdup(check_in_date);
    booking->check_out_date = strdup(check_out_date);
    booking->total_amount = total_amount;
    return booking;
}

/* MAIN FUNCTION */
int main() {
    /* CREATE ROOMS */
    Room* room1 = create_room(101, 2, "Double", "Available");
    Room* room2 = create_room(102, 4, "Quad", "Available");
    Room* room3 = create_room(103, 1, "Single", "Occupied");

    /* CREATE GUESTS */
    Guest* guest1 = create_guest("John Doe", "123 Main St", "555-1234");
    Guest* guest2 = create_guest("Jane Smith", "456 Oak St", "555-5678");
    Guest* guest3 = create_guest("Bob Brown", "789 Elm St", "555-9101");

    /* CREATE BOOKINGS */
    Booking* booking1 = create_booking(1, guest1, room1, "10/1/2021", "10/6/2021", 500.00);
    Booking* booking2 = create_booking(2, guest2, room2, "10/3/2021", "10/7/2021", 800.00);
    Booking* booking3 = create_booking(3, guest3, room3, "10/5/2021", "10/8/2021", 300.00);

    /* PRINT ROOM INFO */
    printf("Room %d:\n Capacity: %d\n Type: %s\n Status: %s\n", room1->number, room1->capacity, room1->type, room1->status);
    printf("\nRoom %d:\n Capacity: %d\n Type: %s\n Status: %s\n", room2->number, room2->capacity, room2->type, room2->status);
    printf("\nRoom %d:\n Capacity: %d\n Type: %s\n Status: %s\n", room3->number, room3->capacity, room3->type, room3->status);

    /* PRINT GUEST INFO */
    printf("\nGuest 1:\n Name: %s\n Address: %s\n Phone: %s\n", guest1->name, guest1->address, guest1->phone);
    printf("\nGuest 2:\n Name: %s\n Address: %s\n Phone: %s\n", guest2->name, guest2->address, guest2->phone);
    printf("\nGuest 3:\n Name: %s\n Address: %s\n Phone: %s\n", guest3->name, guest3->address, guest3->phone);

    /* PRINT BOOKING INFO */
    printf("\nBooking 1:\n ID: %d\n Guest Name: %s\n Room Number: %d\n Check-in: %s\n Check-out: %s\n Total Amount: $%.2f\n",
        booking1->id, booking1->guest->name, booking1->room->number, booking1->check_in_date, booking1->check_out_date, booking1->total_amount);
    printf("\nBooking 2:\n ID: %d\n Guest Name: %s\n Room Number: %d\n Check-in: %s\n Check-out: %s\n Total Amount: $%.2f\n",
        booking2->id, booking2->guest->name, booking2->room->number, booking2->check_in_date, booking2->check_out_date, booking2->total_amount);
    printf("\nBooking 3:\n ID: %d\n Guest Name: %s\n Room Number: %d\n Check-in: %s\n Check-out: %s\n Total Amount: $%.2f\n",
        booking3->id, booking3->guest->name, booking3->room->number, booking3->check_in_date, booking3->check_out_date, booking3->total_amount);

    /* CLEANUP MEMORY */
    free(room1->type);
    free(room2->type);
    free(room3->type);
    free(room1->status);
    free(room2->status);
    free(room3->status);
    free(room1);
    free(room2);
    free(room3);
    free(guest1->name);
    free(guest2->name);
    free(guest3->name);
    free(guest1->address);
    free(guest2->address);
    free(guest3->address);
    free(guest1->phone);
    free(guest2->phone);
    free(guest3->phone);
    free(guest1);
    free(guest2);
    free(guest3);
    free(booking1->guest);
    free(booking2->guest);
    free(booking3->guest);
    free(booking1->room);
    free(booking2->room);
    free(booking3->room);
    free(booking1->check_in_date);
    free(booking2->check_in_date);
    free(booking3->check_in_date);
    free(booking1->check_out_date);
    free(booking2->check_out_date);
    free(booking3->check_out_date);
    free(booking1);
    free(booking2);
    free(booking3);

    return 0;
}