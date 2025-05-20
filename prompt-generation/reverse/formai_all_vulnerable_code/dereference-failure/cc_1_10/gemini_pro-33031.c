//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct room {
    int id;
    char type[20];
    int capacity;
    double price;
    int available;
} room;

typedef struct reservation {
    int id;
    int room_id;
    char guest_name[50];
    char guest_email[50];
    char guest_phone[20];
    time_t check_in;
    time_t check_out;
    int num_guests;
    double total_price;
} reservation;

// Function to create a new room
room* create_room(int id, char* type, int capacity, double price, int available) {
    room* new_room = (room*)malloc(sizeof(room));
    new_room->id = id;
    strcpy(new_room->type, type);
    new_room->capacity = capacity;
    new_room->price = price;
    new_room->available = available;
    return new_room;
}

// Function to create a new reservation
reservation* create_reservation(int id, int room_id, char* guest_name, char* guest_email, char* guest_phone, time_t check_in, time_t check_out, int num_guests, double total_price) {
    reservation* new_reservation = (reservation*)malloc(sizeof(reservation));
    new_reservation->id = id;
    new_reservation->room_id = room_id;
    strcpy(new_reservation->guest_name, guest_name);
    strcpy(new_reservation->guest_email, guest_email);
    strcpy(new_reservation->guest_phone, guest_phone);
    new_reservation->check_in = check_in;
    new_reservation->check_out = check_out;
    new_reservation->num_guests = num_guests;
    new_reservation->total_price = total_price;
    return new_reservation;
}

// Function to print the details of a room
void print_room(room* room) {
    printf("Room ID: %d\n", room->id);
    printf("Room Type: %s\n", room->type);
    printf("Room Capacity: %d\n", room->capacity);
    printf("Room Price: %.2f\n", room->price);
    printf("Room Availability: %d\n", room->available);
}

// Function to print the details of a reservation
void print_reservation(reservation* reservation) {
    printf("Reservation ID: %d\n", reservation->id);
    printf("Room ID: %d\n", reservation->room_id);
    printf("Guest Name: %s\n", reservation->guest_name);
    printf("Guest Email: %s\n", reservation->guest_email);
    printf("Guest Phone: %s\n", reservation->guest_phone);
    printf("Check-In Date: %s\n", ctime(&reservation->check_in));
    printf("Check-Out Date: %s\n", ctime(&reservation->check_out));
    printf("Number of Guests: %d\n", reservation->num_guests);
    printf("Total Price: %.2f\n", reservation->total_price);
}

// Main function
int main() {
    // Create a few rooms
    room* room1 = create_room(1, "Standard", 2, 100.0, 1);
    room* room2 = create_room(2, "Deluxe", 4, 150.0, 1);
    room* room3 = create_room(3, "Suite", 6, 200.0, 1);

    // Create a few reservations
    reservation* reservation1 = create_reservation(1, 1, "John Doe", "john.doe@example.com", "+1 (555) 123-4567", time(NULL) + 86400, time(NULL) + 86400 * 2, 2, 200.0);
    reservation* reservation2 = create_reservation(2, 2, "Jane Doe", "jane.doe@example.com", "+1 (555) 234-5678", time(NULL) + 86400 * 3, time(NULL) + 86400 * 5, 4, 600.0);
    reservation* reservation3 = create_reservation(3, 3, "Peter Parker", "peter.parker@example.com", "+1 (555) 345-6789", time(NULL) + 86400 * 6, time(NULL) + 86400 * 8, 6, 1200.0);

    // Print the details of each room
    printf("Rooms:\n");
    print_room(room1);
    print_room(room2);
    print_room(room3);

    // Print the details of each reservation
    printf("Reservations:\n");
    print_reservation(reservation1);
    print_reservation(reservation2);
    print_reservation(reservation3);

    return 0;
}