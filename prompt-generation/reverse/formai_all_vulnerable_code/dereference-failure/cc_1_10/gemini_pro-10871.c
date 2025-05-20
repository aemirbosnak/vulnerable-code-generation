//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 1000

// Define the room types
typedef enum {
    SINGLE,
    DOUBLE,
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
    room_type room_type;
    int room_number;
    guest_status status;
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
    hotel* h = malloc(sizeof(hotel));
    h->num_rooms = 0;
    h->num_guests = 0;
    return h;
}

// Add a new room to the hotel
void add_room(hotel* h, room r) {
    h->rooms[h->num_rooms] = r;
    h->num_rooms++;
}

// Add a new guest to the hotel
void add_guest(hotel* h, guest g) {
    h->guests[h->num_guests] = g;
    h->num_guests++;
}

// Check in a guest
void check_in(hotel* h, int guest_id, int room_number) {
    for (int i = 0; i < h->num_guests; i++) {
        if (h->guests[i].guest_id == guest_id) {
            h->guests[i].status = CHECKED_IN;
            h->guests[i].room_number = room_number;
            return;
        }
    }
    printf("Guest not found\n");
}

// Check out a guest
void check_out(hotel* h, int guest_id) {
    for (int i = 0; i < h->num_guests; i++) {
        if (h->guests[i].guest_id == guest_id) {
            h->guests[i].status = CHECKED_OUT;
            h->guests[i].room_number = -1;
            return;
        }
    }
    printf("Guest not found\n");
}

// Get the total revenue of the hotel
float get_revenue(hotel* h) {
    float revenue = 0;
    for (int i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].status == CHECKED_IN) {
            revenue += h->rooms[i].price;
        }
    }
    return revenue;
}

// Print the hotel information
void print_hotel(hotel* h) {
    printf("Hotel Information\n");
    printf("Number of Rooms: %d\n", h->num_rooms);
    printf("Number of Guests: %d\n", h->num_guests);
    printf("Total Revenue: %.2f\n", get_revenue(h));
    printf("\n");
    printf("Rooms:\n");
    for (int i = 0; i < h->num_rooms; i++) {
        printf("Room Number: %d\n", h->rooms[i].room_number);
        printf("Room Type: %d\n", h->rooms[i].type);
        printf("Room Price: %.2f\n", h->rooms[i].price);
        printf("Room Status: %d\n", h->rooms[i].status);
        printf("\n");
    }
    printf("Guests:\n");
    for (int i = 0; i < h->num_guests; i++) {
        printf("Guest ID: %d\n", h->guests[i].guest_id);
        printf("Guest Name: %s\n", h->guests[i].name);
        printf("Guest Address: %s\n", h->guests[i].address);
        printf("Guest Phone: %s\n", h->guests[i].phone);
        printf("Guest Email: %s\n", h->guests[i].email);
        printf("Guest Room Type: %d\n", h->guests[i].room_type);
        printf("Guest Room Number: %d\n", h->guests[i].room_number);
        printf("Guest Status: %d\n", h->guests[i].status);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new hotel
    hotel* h = create_hotel();

    // Add some rooms to the hotel
    room r1 = {1, SINGLE, 100.0, CHECKED_OUT};
    add_room(h, r1);
    room r2 = {2, DOUBLE, 150.0, CHECKED_OUT};
    add_room(h, r2);
    room r3 = {3, SUITE, 200.0, CHECKED_OUT};
    add_room(h, r3);

    // Add some guests to the hotel
    guest g1 = {1, "John Doe", "123 Main Street", "555-1212", "john.doe@email.com", SINGLE, -1, CHECKED_OUT};
    add_guest(h, g1);
    guest g2 = {2, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com", DOUBLE, -1, CHECKED_OUT};
    add_guest(h, g2);
    guest g3 = {3, "John Smith", "789 Oak Street", "555-1214", "john.smith@email.com", SUITE, -1, CHECKED_OUT};
    add_guest(h, g3);

    // Check in some guests
    check_in(h, 1, 1);
    check_in(h, 2, 2);
    check_in(h, 3, 3);

    // Print the hotel information
    print_hotel(h);

    return 0;
}