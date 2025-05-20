//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 1000

// Define the room types
typedef enum {
    STANDARD,
    DELUXE,
    SUITE
} room_type;

// Define the guest status
typedef enum {
    CHECKED_IN,
    CHECKED_OUT
} guest_status;

// Define the room structure
typedef struct {
    int room_number;
    room_type type;
    float price;
    guest_status status;
} room;

// Define the guest structure
typedef struct {
    int guest_id;
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    room* room;
} guest;

// Define the hotel structure
typedef struct {
    room rooms[MAX_ROOMS];
    guest guests[MAX_GUESTS];
    int num_rooms;
    int num_guests;
} hotel;

// Create a new hotel
hotel* create_hotel() {
    hotel* h = (hotel*)malloc(sizeof(hotel));
    h->num_rooms = 0;
    h->num_guests = 0;
    return h;
}

// Add a new room to the hotel
void add_room(hotel* h, room_type type, float price) {
    if (h->num_rooms < MAX_ROOMS) {
        room* r = &h->rooms[h->num_rooms++];
        r->room_number = h->num_rooms;
        r->type = type;
        r->price = price;
        r->status = CHECKED_OUT;
    }
}

// Add a new guest to the hotel
void add_guest(hotel* h, char* name, char* address, char* phone, char* email) {
    if (h->num_guests < MAX_GUESTS) {
        guest* g = &h->guests[h->num_guests++];
        g->guest_id = h->num_guests;
        strcpy(g->name, name);
        strcpy(g->address, address);
        strcpy(g->phone, phone);
        strcpy(g->email, email);
        g->room = NULL;
    }
}

// Check in a guest
void check_in_guest(hotel* h, guest* g, room* r) {
    g->room = r;
    r->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(hotel* h, guest* g) {
    g->room->status = CHECKED_OUT;
    g->room = NULL;
}

// Print the hotel information
void print_hotel(hotel* h) {
    printf("Hotel Information\n");
    printf("Number of Rooms: %d\n", h->num_rooms);
    printf("Number of Guests: %d\n", h->num_guests);
    for (int i = 0; i < h->num_rooms; i++) {
        room* r = &h->rooms[i];
        printf("Room %d: Type %d, Price %f, Status %d\n", r->room_number, r->type, r->price, r->status);
    }
    for (int i = 0; i < h->num_guests; i++) {
        guest* g = &h->guests[i];
        printf("Guest %d: Name %s, Address %s, Phone %s, Email %s\n", g->guest_id, g->name, g->address, g->phone, g->email);
    }
}

// Free the hotel memory
void free_hotel(hotel* h) {
    free(h);
}

// Main function
int main() {
    // Create a new hotel
    hotel* h = create_hotel();

    // Add some rooms to the hotel
    add_room(h, STANDARD, 100.00);
    add_room(h, DELUXE, 150.00);
    add_room(h, SUITE, 200.00);

    // Add some guests to the hotel
    add_guest(h, "John Doe", "123 Main Street", "555-1212", "john.doe@email.com");
    add_guest(h, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com");

    // Check in a guest
    check_in_guest(h, &h->guests[0], &h->rooms[0]);

    // Print the hotel information
    print_hotel(h);

    // Free the hotel memory
    free_hotel(h);

    return 0;
}