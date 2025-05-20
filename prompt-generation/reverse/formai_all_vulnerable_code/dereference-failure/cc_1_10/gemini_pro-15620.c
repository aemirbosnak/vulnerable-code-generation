//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    char name[50];
    int num_rooms;
    float price_per_night;
    struct hotel *next;
};

struct reservation {
    char name[50];
    char check_in[11];
    char check_out[11];
    int num_people;
    struct reservation *next;
};

struct hotel *head_hotel = NULL;
struct reservation *head_reservation = NULL;

void add_hotel(char *name, int num_rooms, float price_per_night) {
    struct hotel *new_hotel = malloc(sizeof(struct hotel));
    strcpy(new_hotel->name, name);
    new_hotel->num_rooms = num_rooms;
    new_hotel->price_per_night = price_per_night;
    new_hotel->next = NULL;
    if (head_hotel == NULL) {
        head_hotel = new_hotel;
    } else {
        struct hotel *current_hotel = head_hotel;
        while (current_hotel->next != NULL) {
            current_hotel = current_hotel->next;
        }
        current_hotel->next = new_hotel;
    }
}

void add_reservation(char *name, char *check_in, char *check_out, int num_people) {
    struct reservation *new_reservation = malloc(sizeof(struct reservation));
    strcpy(new_reservation->name, name);
    strcpy(new_reservation->check_in, check_in);
    strcpy(new_reservation->check_out, check_out);
    new_reservation->num_people = num_people;
    new_reservation->next = NULL;
    if (head_reservation == NULL) {
        head_reservation = new_reservation;
    } else {
        struct reservation *current_reservation = head_reservation;
        while (current_reservation->next != NULL) {
            current_reservation = current_reservation->next;
        }
        current_reservation->next = new_reservation;
    }
}

void print_hotels() {
    struct hotel *current_hotel = head_hotel;
    while (current_hotel != NULL) {
        printf("Name: %s\n", current_hotel->name);
        printf("Number of Rooms: %d\n", current_hotel->num_rooms);
        printf("Price per Night: %.2f\n\n", current_hotel->price_per_night);
        current_hotel = current_hotel->next;
    }
}

void print_reservations() {
    struct reservation *current_reservation = head_reservation;
    while (current_reservation != NULL) {
        printf("Name: %s\n", current_reservation->name);
        printf("Check In: %s\n", current_reservation->check_in);
        printf("Check Out: %s\n", current_reservation->check_out);
        printf("Number of People: %d\n\n", current_reservation->num_people);
        current_reservation = current_reservation->next;
    }
}

int main() {
    add_hotel("Hotel A", 100, 100.00);
    add_hotel("Hotel B", 200, 150.00);
    add_hotel("Hotel C", 300, 200.00);

    add_reservation("John Doe", "2023-01-01", "2023-01-07", 2);
    add_reservation("Jane Doe", "2023-02-01", "2023-02-07", 4);
    add_reservation("John Smith", "2023-03-01", "2023-03-07", 6);

    print_hotels();
    print_reservations();

    return 0;
}