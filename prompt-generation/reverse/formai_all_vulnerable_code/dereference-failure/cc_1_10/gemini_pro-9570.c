//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 100

// Define the room types
typedef enum {
    STANDARD,
    DELUXE,
    SUITE
} room_type;

// Define the guest types
typedef enum {
    INDIVIDUAL,
    FAMILY,
    GROUP
} guest_type;

// Define the room structure
typedef struct {
    int room_number;
    room_type type;
    int capacity;
    float price;
    int is_occupied;
} room;

// Define the guest structure
typedef struct {
    int guest_id;
    guest_type type;
    int num_adults;
    int num_children;
    char *name;
    char *address;
    char *phone_number;
    int room_number;
    int check_in_date;
    int check_out_date;
} guest;

// Define the hotel structure
typedef struct {
    room rooms[MAX_ROOMS];
    guest guests[MAX_GUESTS];
    int num_rooms;
    int num_guests;
} hotel;

// Create a new hotel
hotel *create_hotel() {
    hotel *h = malloc(sizeof(hotel));
    h->num_rooms = 0;
    h->num_guests = 0;
    return h;
}

// Add a new room to the hotel
void add_room(hotel *h, room r) {
    h->rooms[h->num_rooms] = r;
    h->num_rooms++;
}

// Add a new guest to the hotel
void add_guest(hotel *h, guest g) {
    h->guests[h->num_guests] = g;
    h->num_guests++;
}

// Find a room by room number
room *find_room_by_number(hotel *h, int room_number) {
    for (int i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].room_number == room_number) {
            return &h->rooms[i];
        }
    }
    return NULL;
}

// Find a guest by guest id
guest *find_guest_by_id(hotel *h, int guest_id) {
    for (int i = 0; i < h->num_guests; i++) {
        if (h->guests[i].guest_id == guest_id) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Check in a guest
void check_in_guest(hotel *h, guest *g) {
    room *r = find_room_by_number(h, g->room_number);
    if (r == NULL) {
        printf("Room not found.\n");
        return;
    }
    if (r->is_occupied) {
        printf("Room is already occupied.\n");
        return;
    }
    r->is_occupied = 1;
    g->check_in_date = time(NULL);
}

// Check out a guest
void check_out_guest(hotel *h, guest *g) {
    room *r = find_room_by_number(h, g->room_number);
    if (r == NULL) {
        printf("Room not found.\n");
        return;
    }
    if (!r->is_occupied) {
        printf("Room is already empty.\n");
        return;
    }
    r->is_occupied = 0;
    g->check_out_date = time(NULL);
}

// Print the hotel information
void print_hotel_info(hotel *h) {
    printf("Hotel Information\n");
    printf("Number of rooms: %d\n", h->num_rooms);
    printf("Number of guests: %d\n", h->num_guests);
    for (int i = 0; i < h->num_rooms; i++) {
        printf("Room %d:\n", h->rooms[i].room_number);
        printf("Type: %s\n", h->rooms[i].type == STANDARD ? "Standard" : h->rooms[i].type == DELUXE ? "Deluxe" : "Suite");
        printf("Capacity: %d\n", h->rooms[i].capacity);
        printf("Price: %.2f\n", h->rooms[i].price);
        printf("Is occupied: %s\n", h->rooms[i].is_occupied ? "Yes" : "No");
    }
    for (int i = 0; i < h->num_guests; i++) {
        printf("Guest %d:\n", h->guests[i].guest_id);
        printf("Type: %s\n", h->guests[i].type == INDIVIDUAL ? "Individual" : h->guests[i].type == FAMILY ? "Family" : "Group");
        printf("Num adults: %d\n", h->guests[i].num_adults);
        printf("Num children: %d\n", h->guests[i].num_children);
        printf("Name: %s\n", h->guests[i].name);
        printf("Address: %s\n", h->guests[i].address);
        printf("Phone number: %s\n", h->guests[i].phone_number);
        printf("Room number: %d\n", h->guests[i].room_number);
        printf("Check in date: %d\n", h->guests[i].check_in_date);
        printf("Check out date: %d\n", h->guests[i].check_out_date);
    }
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel();

    // Add some rooms to the hotel
    room r1 = {1, STANDARD, 2, 50.0, 0};
    room r2 = {2, DELUXE, 4, 100.0, 0};
    room r3 = {3, SUITE, 6, 150.0, 0};
    add_room(h, r1);
    add_room(h, r2);
    add_room(h, r3);

    // Add some guests to the hotel
    guest g1 = {1, INDIVIDUAL, 1, 0, "John Doe", "123 Main Street", "555-1212", 1, time(NULL), 0};
    guest g2 = {2, FAMILY, 2, 2, "Jane Doe", "456 Elm Street", "555-1213", 2, time(NULL), 0};
    guest g3 = {3, GROUP, 10, 0, "Acme Corporation", "789 Oak Street", "555-1214", 3, time(NULL), 0};
    add_guest(h, g1);
    add_guest(h, g2);
    add_guest(h, g3);

    // Print the hotel information
    print_hotel_info(h);

    return 0;
}