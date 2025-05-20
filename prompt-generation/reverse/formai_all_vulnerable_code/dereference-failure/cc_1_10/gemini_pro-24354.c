//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum length of a guest name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a room type
#define MAX_ROOM_TYPE_LENGTH 20

// Define the various room types
enum room_type {
    SINGLE,
    DOUBLE,
    SUITE
};

// Define the structure of a guest
typedef struct guest {
    char name[MAX_NAME_LENGTH];
    char room_type[MAX_ROOM_TYPE_LENGTH];
    int room_number;
    int check_in_date;
    int check_out_date;
} guest;

// Define the structure of the hotel
typedef struct hotel {
    guest guests[MAX_ROOMS];
    int num_guests;
} hotel;

// Create a new hotel
hotel *create_hotel() {
    hotel *h = malloc(sizeof(hotel));
    h->num_guests = 0;
    return h;
}

// Add a new guest to the hotel
void add_guest(hotel *h, guest *g) {
    h->guests[h->num_guests++] = *g;
}

// Find a guest by name
guest *find_guest_by_name(hotel *h, char *name) {
    for (int i = 0; i < h->num_guests; i++) {
        if (strcmp(h->guests[i].name, name) == 0) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Find a guest by room number
guest *find_guest_by_room_number(hotel *h, int room_number) {
    for (int i = 0; i < h->num_guests; i++) {
        if (h->guests[i].room_number == room_number) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Print the details of all guests
void print_all_guests(hotel *h) {
    for (int i = 0; i < h->num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", h->guests[i].name);
        printf("Room type: %s\n", h->guests[i].room_type);
        printf("Room number: %d\n", h->guests[i].room_number);
        printf("Check-in date: %d\n", h->guests[i].check_in_date);
        printf("Check-out date: %d\n\n", h->guests[i].check_out_date);
    }
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel();

    // Add some guests to the hotel
    guest g1 = {"John Doe", "Single", 101, 20230301, 20230303};
    add_guest(h, &g1);

    guest g2 = {"Jane Doe", "Double", 102, 20230302, 20230304};
    add_guest(h, &g2);

    guest g3 = {"John Smith", "Suite", 103, 20230303, 20230305};
    add_guest(h, &g3);

    // Print the details of all guests
    print_all_guests(h);

    // Find a guest by name
    guest *g = find_guest_by_name(h, "John Doe");
    if (g != NULL) {
        printf("Found guest by name: %s\n", g->name);
    } else {
        printf("Guest not found by name.\n");
    }

    // Find a guest by room number
    g = find_guest_by_room_number(h, 102);
    if (g != NULL) {
        printf("Found guest by room number: %s\n", g->name);
    } else {
        printf("Guest not found by room number.\n");
    }

    return 0;
}