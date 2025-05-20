//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for room and reservation
typedef struct {
    int room_number;
    char name[50];
    int price;
} Room;

typedef struct {
    int reservation_number;
    char name[50];
    int check_in_date;
    int check_out_date;
    int price;
} Reservation;

// Define functions for room and reservation management
void print_room(Room* room) {
    printf("Room Number: %d\n", room->room_number);
    printf("Name: %s\n", room->name);
    printf("Price: %d\n", room->price);
}

void print_reservation(Reservation* reservation) {
    printf("Reservation Number: %d\n", reservation->reservation_number);
    printf("Name: %s\n", reservation->name);
    printf("Check-In Date: %d\n", reservation->check_in_date);
    printf("Check-Out Date: %d\n", reservation->check_out_date);
    printf("Price: %d\n", reservation->price);
}

void add_room(Room** rooms, int* num_rooms, char* name, int price) {
    Room* new_room = malloc(sizeof(Room));
    if (new_room == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for new room.\n");
        exit(1);
    }
    new_room->room_number = *num_rooms;
    (*num_rooms)++;
    strcpy(new_room->name, name);
    new_room->price = price;
    rooms[new_room->room_number] = new_room;
}

void delete_room(Room** rooms, int* num_rooms, int room_number) {
    if (room_number >= *num_rooms) {
        fprintf(stderr, "Error: Room number out of range.\n");
        exit(1);
    }
    free(rooms[room_number]);
    (*num_rooms)--;
}

void add_reservation(Reservation** reservations, int* num_reservations, char* name, int check_in_date, int check_out_date, int price) {
    Reservation* new_reservation = malloc(sizeof(Reservation));
    if (new_reservation == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for new reservation.\n");
        exit(1);
    }
    new_reservation->reservation_number = *num_reservations;
    (*num_reservations)++;
    strcpy(new_reservation->name, name);
    new_reservation->check_in_date = check_in_date;
    new_reservation->check_out_date = check_out_date;
    new_reservation->price = price;
    reservations[new_reservation->reservation_number] = new_reservation;
}

void delete_reservation(Reservation** reservations, int* num_reservations, int reservation_number) {
    if (reservation_number >= *num_reservations) {
        fprintf(stderr, "Error: Reservation number out of range.\n");
        exit(1);
    }
    free(reservations[reservation_number]);
    (*num_reservations)--;
}

int main() {
    // Initialize room and reservation arrays
    int num_rooms = 0;
    Room* rooms = malloc(100 * sizeof(Room));
    if (rooms == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for room array.\n");
        exit(1);
    }
    int num_reservations = 0;
    Reservation* reservations = malloc(100 * sizeof(Reservation));
    if (reservations == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for reservation array.\n");
        exit(1);
    }

    // Add rooms and reservations
    add_room(&rooms, &num_rooms, "Room 1", 100);
    add_room(&rooms, &num_rooms, "Room 2", 200);
    add_room(&rooms, &num_rooms, "Room 3", 300);
    add_reservation(&reservations, &num_reservations, "John Doe", 1, 5, 500);
    add_reservation(&reservations, &num_reservations, "Jane Smith", 2, 7, 600);
    add_reservation(&reservations, &num_reservations, "Bob Johnson", 3, 10, 700);

    // Print room and reservation information
    printf("Rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        print_room(&rooms[i]);
    }
    printf("\nReservations:\n");
    for (int i = 0; i < num_reservations; i++) {
        print_reservation(&reservations[i]);
    }

    // Delete rooms and reservations
    delete_room(&rooms, &num_rooms, 2);
    delete_reservation(&reservations, &num_reservations, 0);

    // Print room and reservation information after deletion
    printf("Rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        print_room(&rooms[i]);
    }
    printf("\nReservations:\n");
    for (int i = 0; i < num_reservations; i++) {
        print_reservation(&reservations[i]);
    }

    return 0;
}