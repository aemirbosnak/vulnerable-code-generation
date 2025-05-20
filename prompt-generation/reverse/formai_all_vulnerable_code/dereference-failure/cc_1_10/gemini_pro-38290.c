//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the structure of a room
typedef struct room {
    int room_number;
    char room_type;
    int is_occupied;
    float price;
} room;

// Define the structure of a guest
typedef struct guest {
    char name[50];
    char address[100];
    char phone_number[20];
    char email[50];
} guest;

// Define the structure of a reservation
typedef struct reservation {
    int reservation_number;
    char check_in_date[20];
    char check_out_date[20];
    int number_of_guests;
    room *room;
    guest *guest;
} reservation;

// Define the function to create a new room
room *create_room(int room_number, char room_type, float price) {
    room *new_room = (room *)malloc(sizeof(room));
    new_room->room_number = room_number;
    new_room->room_type = room_type;
    new_room->is_occupied = 0;
    new_room->price = price;
    return new_room;
}

// Define the function to create a new guest
guest *create_guest(char *name, char *address, char *phone_number, char *email) {
    guest *new_guest = (guest *)malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    strcpy(new_guest->address, address);
    strcpy(new_guest->phone_number, phone_number);
    strcpy(new_guest->email, email);
    return new_guest;
}

// Define the function to create a new reservation
reservation *create_reservation(int reservation_number, char *check_in_date, char *check_out_date, int number_of_guests, room *room, guest *guest) {
    reservation *new_reservation = (reservation *)malloc(sizeof(reservation));
    new_reservation->reservation_number = reservation_number;
    strcpy(new_reservation->check_in_date, check_in_date);
    strcpy(new_reservation->check_out_date, check_out_date);
    new_reservation->number_of_guests = number_of_guests;
    new_reservation->room = room;
    new_reservation->guest = guest;
    return new_reservation;
}

// Define the function to display the details of a room
void display_room(room *room) {
    printf("Room Number: %d\n", room->room_number);
    printf("Room Type: %c\n", room->room_type);
    printf("Is Occupied: %d\n", room->is_occupied);
    printf("Price: %.2f\n", room->price);
}

// Define the function to display the details of a guest
void display_guest(guest *guest) {
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone Number: %s\n", guest->phone_number);
    printf("Email: %s\n", guest->email);
}

// Define the function to display the details of a reservation
void display_reservation(reservation *reservation) {
    printf("Reservation Number: %d\n", reservation->reservation_number);
    printf("Check-In Date: %s\n", reservation->check_in_date);
    printf("Check-Out Date: %s\n", reservation->check_out_date);
    printf("Number of Guests: %d\n", reservation->number_of_guests);
    display_room(reservation->room);
    display_guest(reservation->guest);
}

// Define the main function
int main() {
    // Create an array of rooms
    room *rooms[MAX_ROOMS];

    // Create some rooms
    rooms[0] = create_room(101, 'S', 100.00);
    rooms[1] = create_room(102, 'D', 150.00);
    rooms[2] = create_room(103, 'Q', 200.00);
    rooms[3] = create_room(104, 'K', 250.00);

    // Create an array of guests
    guest *guests[MAX_ROOMS];

    // Create some guests
    guests[0] = create_guest("John Smith", "123 Main Street", "555-1212", "john.smith@email.com");
    guests[1] = create_guest("Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com");
    guests[2] = create_guest("Bill Jones", "789 Oak Street", "555-1214", "bill.jones@email.com");
    guests[3] = create_guest("Mary Brown", "1011 Maple Street", "555-1215", "mary.brown@email.com");

    // Create an array of reservations
    reservation *reservations[MAX_ROOMS];

    // Create some reservations
    reservations[0] = create_reservation(1, "2023-03-01", "2023-03-03", 2, rooms[0], guests[0]);
    reservations[1] = create_reservation(2, "2023-03-04", "2023-03-06", 1, rooms[1], guests[1]);
    reservations[2] = create_reservation(3, "2023-03-07", "2023-03-09", 3, rooms[2], guests[2]);
    reservations[3] = create_reservation(4, "2023-03-10", "2023-03-12", 4, rooms[3], guests[3]);

    // Display the details of all the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i] != NULL) {
            display_room(rooms[i]);
            printf("\n");
        }
    }

    // Display the details of all the guests
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (guests[i] != NULL) {
            display_guest(guests[i]);
            printf("\n");
        }
    }

    // Display the details of all the reservations
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (reservations[i] != NULL) {
            display_reservation(reservations[i]);
            printf("\n");
        }
    }

    return 0;
}