//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum length of a guest name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a room type
#define MAX_ROOM_TYPE_LENGTH 20

// Define the maximum length of a date
#define MAX_DATE_LENGTH 11

// Define the maximum number of days a guest can stay
#define MAX_DAYS 30

// Define the room rates
#define STANDARD_ROOM_RATE 100
#define DELUXE_ROOM_RATE 150
#define SUITE_ROOM_RATE 200

// Define the data structure for a guest
typedef struct guest {
    char name[MAX_NAME_LENGTH];
    char room_type[MAX_ROOM_TYPE_LENGTH];
    char arrival_date[MAX_DATE_LENGTH];
    char departure_date[MAX_DATE_LENGTH];
    int num_days;
    double total_cost;
} guest;

// Define the data structure for the hotel
typedef struct hotel {
    guest guests[MAX_ROOMS];
    int num_guests;
} hotel;

// Create a new hotel
hotel* create_hotel() {
    hotel* h = malloc(sizeof(hotel));
    h->num_guests = 0;
    return h;
}

// Add a guest to the hotel
void add_guest(hotel* h, guest* g) {
    h->guests[h->num_guests] = *g;
    h->num_guests++;
}

// Find a guest by name
guest* find_guest(hotel* h, char* name) {
    for (int i = 0; i < h->num_guests; i++) {
        if (strcmp(h->guests[i].name, name) == 0) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Print the details of a guest
void print_guest(guest* g) {
    printf("Name: %s\n", g->name);
    printf("Room Type: %s\n", g->room_type);
    printf("Arrival Date: %s\n", g->arrival_date);
    printf("Departure Date: %s\n", g->departure_date);
    printf("Number of Days: %d\n", g->num_days);
    printf("Total Cost: $%.2f\n", g->total_cost);
}

// Print the details of all guests in the hotel
void print_all_guests(hotel* h) {
    for (int i = 0; i < h->num_guests; i++) {
        print_guest(&h->guests[i]);
        printf("\n");
    }
}

// Calculate the total cost of a guest's stay
double calculate_total_cost(guest* g) {
    double total_cost = 0;
    if (strcmp(g->room_type, "Standard") == 0) {
        total_cost = STANDARD_ROOM_RATE * g->num_days;
    } else if (strcmp(g->room_type, "Deluxe") == 0) {
        total_cost = DELUXE_ROOM_RATE * g->num_days;
    } else if (strcmp(g->room_type, "Suite") == 0) {
        total_cost = SUITE_ROOM_RATE * g->num_days;
    }
    return total_cost;
}

// Main function
int main() {
    // Create a new hotel
    hotel* h = create_hotel();

    // Add some guests to the hotel
    guest g1 = {"Ada Lovelace", "Standard", "2023-03-01", "2023-03-05", 4, 0};
    add_guest(h, &g1);
    guest g2 = {"Charles Babbage", "Deluxe", "2023-03-06", "2023-03-10", 4, 0};
    add_guest(h, &g2);
    guest g3 = {"Grace Hopper", "Suite", "2023-03-11", "2023-03-15", 4, 0};
    add_guest(h, &g3);

    // Calculate the total cost of each guest's stay
    for (int i = 0; i < h->num_guests; i++) {
        h->guests[i].total_cost = calculate_total_cost(&h->guests[i]);
    }

    // Print the details of all guests in the hotel
    print_all_guests(h);

    return 0;
}