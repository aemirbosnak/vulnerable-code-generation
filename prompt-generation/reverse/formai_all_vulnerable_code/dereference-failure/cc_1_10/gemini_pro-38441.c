//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// A guest
struct guest {
    char *name;
    char *room_number;
    int nights;
    float bill;
};

// The hotel
struct hotel {
    char *name;
    int num_rooms;
    struct guest *guests;
};

// Create a new guest
struct guest *create_guest(char *name, char *room_number, int nights, float bill) {
    struct guest *guest = malloc(sizeof(struct guest));
    guest->name = name;
    guest->room_number = room_number;
    guest->nights = nights;
    guest->bill = bill;
    return guest;
}

// Create a new hotel
struct hotel *create_hotel(char *name, int num_rooms) {
    struct hotel *hotel = malloc(sizeof(struct hotel));
    hotel->name = name;
    hotel->num_rooms = num_rooms;
    hotel->guests = malloc(num_rooms * sizeof(struct guest));
    return hotel;
}

// Print the hotel's information
void print_hotel(struct hotel *hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Number of rooms: %d\n", hotel->num_rooms);
    printf("Guests:\n");
    for (int i = 0; i < hotel->num_rooms; i++) {
        struct guest *guest = &hotel->guests[i];
        printf("  - Name: %s\n", guest->name);
        printf("    - Room number: %s\n", guest->room_number);
        printf("    - Nights: %d\n", guest->nights);
        printf("    - Bill: %f\n", guest->bill);
    }
}

// Check in a guest
void check_in(struct hotel *hotel, struct guest *guest) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->guests[i].name == NULL) {
            hotel->guests[i] = *guest;
            return;
        }
    }
    printf("Sorry, the hotel is full.\n");
}

// Check out a guest
void check_out(struct hotel *hotel, char *room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (strcmp(hotel->guests[i].room_number, room_number) == 0) {
            hotel->guests[i].name = NULL;
            hotel->guests[i].room_number = NULL;
            hotel->guests[i].nights = 0;
            hotel->guests[i].bill = 0;
            return;
        }
    }
    printf("Sorry, there is no guest in room %s.\n", room_number);
}


int main() {
    // Create a new hotel
    struct hotel *hotel = create_hotel("The Grand Budapest Hotel", 100);

    // Create some guests
    struct guest *guest1 = create_guest("M. Gustave", "101", 3, 100.00);
    struct guest *guest2 = create_guest("Zero Moustafa", "102", 2, 50.00);
    struct guest *guest3 = create_guest("Agatha", "103", 1, 25.00);

    // Check in the guests
    check_in(hotel, guest1);
    check_in(hotel, guest2);
    check_in(hotel, guest3);

    // Print the hotel's information
    print_hotel(hotel);

    // Check out a guest
    check_out(hotel, "102");

    // Print the hotel's information again
    print_hotel(hotel);

    return 0;
}