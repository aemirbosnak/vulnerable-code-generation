//FormAI DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our data structures

typedef struct {
    int room_number;
    char guest_name[50];
    int num_of_nights;
    float total_cost;
} Reservation;

typedef struct {
    Reservation **reservations;
    int num_of_rooms;
    float room_cost;
} Hotel;

// Define our functions

Hotel *create_hotel(int num_of_rooms, float room_cost) {
    Hotel *hotel = malloc(sizeof(Hotel));
    hotel->num_of_rooms = num_of_rooms;
    hotel->room_cost = room_cost;
    hotel->reservations = malloc(num_of_rooms * sizeof(Reservation*));
    for (int i = 0; i < num_of_rooms; i++) {
        hotel->reservations[i] = NULL;
    }
    return hotel;
}

Reservation *create_reservation(int room_number, char *guest_name, int num_of_nights) {
    Reservation *reservation = malloc(sizeof(Reservation));
    reservation->room_number = room_number;
    strcpy(reservation->guest_name, guest_name);
    reservation->num_of_nights = num_of_nights;
    reservation->total_cost = num_of_nights * 100.0; // Assume $100 per night
    return reservation;
}

int reserve_room(Hotel *hotel, Reservation *reservation) {
    if (hotel->reservations[reservation->room_number - 1] != NULL) {
        printf("Sorry, room %d is already reserved.\n", reservation->room_number);
        return 0;
    }
    hotel->reservations[reservation->room_number - 1] = reservation;
    printf("Room %d reserved for %s for %d nights at a total cost of $%.2f.\n", reservation->room_number, reservation->guest_name, reservation->num_of_nights, reservation->total_cost);
    return 1;
}

void cancel_reservation(Hotel *hotel, int room_number) {
    if (hotel->reservations[room_number - 1] == NULL) {
        printf("Sorry, room %d is not reserved.\n", room_number);
        return;
    }
    free(hotel->reservations[room_number - 1]);
    hotel->reservations[room_number - 1] = NULL;
    printf("Reservation for room %d cancelled.\n", room_number);
}

void print_hotel_reservations(Hotel *hotel) {
    printf("Hotel Reservations:\n");
    for (int i = 0; i < hotel->num_of_rooms; i++) {
        if (hotel->reservations[i] != NULL) {
            Reservation *reservation = hotel->reservations[i];
            printf("Room %d: %s, %d nights, $%.2f total cost.\n", reservation->room_number, reservation->guest_name, reservation->num_of_nights, reservation->total_cost);
        } else {
            printf("Room %d: Not reserved.\n", i+1);
        }
    }
}

// Our main function

int main() {
    Hotel *hotel = create_hotel(5, 100.0);
    Reservation *res1 = create_reservation(2, "John Smith", 3);
    Reservation *res2 = create_reservation(3, "Jane Doe", 4);
    reserve_room(hotel, res1);
    reserve_room(hotel, res2);
    print_hotel_reservations(hotel);
    cancel_reservation(hotel, 2);
    print_hotel_reservations(hotel);
    return 0;
}