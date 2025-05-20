//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum length of a guest name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a room type
#define MAX_ROOM_TYPE_LENGTH 20

// Define the structure of a guest
typedef struct guest {
    char name[MAX_NAME_LENGTH];
    char room_type[MAX_ROOM_TYPE_LENGTH];
    int room_number;
    int nights_staying;
    float total_cost;
} guest;

// Define the structure of a hotel
typedef struct hotel {
    guest guests[MAX_ROOMS];
    int num_guests;
} hotel;

// Create a new hotel
hotel* create_hotel() {
    hotel* h = (hotel*) malloc(sizeof(hotel));
    h->num_guests = 0;
    return h;
}

// Add a new guest to the hotel
void add_guest(hotel* h, guest* g) {
    h->guests[h->num_guests] = *g;
    h->num_guests++;
}

// Find a guest by name
guest* find_guest_by_name(hotel* h, char* name) {
    for (int i = 0; i < h->num_guests; i++) {
        if (strcmp(h->guests[i].name, name) == 0) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Find a guest by room number
guest* find_guest_by_room_number(hotel* h, int room_number) {
    for (int i = 0; i < h->num_guests; i++) {
        if (h->guests[i].room_number == room_number) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Print the details of a guest
void print_guest(guest* g) {
    printf("Name: %s\n", g->name);
    printf("Room type: %s\n", g->room_type);
    printf("Room number: %d\n", g->room_number);
    printf("Nights staying: %d\n", g->nights_staying);
    printf("Total cost: %.2f\n\n", g->total_cost);
}

// Print the details of all guests in the hotel
void print_all_guests(hotel* h) {
    for (int i = 0; i < h->num_guests; i++) {
        print_guest(&h->guests[i]);
    }
}

// Get the total revenue from all guests in the hotel
float get_total_revenue(hotel* h) {
    float total_revenue = 0;
    for (int i = 0; i < h->num_guests; i++) {
        total_revenue += h->guests[i].total_cost;
    }
    return total_revenue;
}

// Main function
int main() {
    // Create a new hotel
    hotel* h = create_hotel();

    // Add some guests to the hotel
    guest g1 = {"John Doe", "Standard", 101, 3, 150.00};
    add_guest(h, &g1);

    guest g2 = {"Jane Doe", "Deluxe", 202, 5, 250.00};
    add_guest(h, &g2);

    guest g3 = {"Bill Smith", "Suite", 303, 7, 350.00};
    add_guest(h, &g3);

    // Print the details of all guests in the hotel
    print_all_guests(h);

    // Find a guest by name
    guest* g = find_guest_by_name(h, "John Doe");
    if (g != NULL) {
        printf("Found guest:\n");
        print_guest(g);
    } else {
        printf("Guest not found.\n");
    }

    // Find a guest by room number
    g = find_guest_by_room_number(h, 202);
    if (g != NULL) {
        printf("Found guest:\n");
        print_guest(g);
    } else {
        printf("Guest not found.\n");
    }

    // Get the total revenue from all guests in the hotel
    float total_revenue = get_total_revenue(h);
    printf("Total revenue: %.2f\n", total_revenue);

    return 0;
}