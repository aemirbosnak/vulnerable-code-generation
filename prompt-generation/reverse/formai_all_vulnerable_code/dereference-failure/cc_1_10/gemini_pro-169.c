//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: active
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
    CHECK_IN,
    CHECK_OUT
} guest_status;

// Define the room structure
typedef struct {
    int room_number;
    room_type type;
    int price;
    int availability;
} room;

// Define the guest structure
typedef struct {
    int guest_id;
    char name[50];
    char address[100];
    char phone_number[20];
    guest_status status;
    room *room;
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
    hotel *h = (hotel *)malloc(sizeof(hotel));
    h->num_rooms = 0;
    h->num_guests = 0;
    return h;
}

// Add a new room to the hotel
void add_room(hotel *h, room *r) {
    h->rooms[h->num_rooms++] = *r;
}

// Add a new guest to the hotel
void add_guest(hotel *h, guest *g) {
    h->guests[h->num_guests++] = *g;
}

// Check in a guest
void check_in(hotel *h, guest *g) {
    // Find an available room
    for (int i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].availability) {
            // Assign the room to the guest
            g->room = &h->rooms[i];
            h->rooms[i].availability = 0;
            break;
        }
    }
    
    // Update the guest's status
    g->status = CHECK_IN;
}

// Check out a guest
void check_out(hotel *h, guest *g) {
    // Make the room available
    g->room->availability = 1;
    
    // Update the guest's status
    g->status = CHECK_OUT;
}

// Print the hotel's information
void print_hotel(hotel *h) {
    printf("Hotel Information:\n");
    printf("Number of Rooms: %d\n", h->num_rooms);
    printf("Number of Guests: %d\n", h->num_guests);
    
    printf("\nRooms:\n");
    for (int i = 0; i < h->num_rooms; i++) {
        printf("Room Number: %d\n", h->rooms[i].room_number);
        printf("Room Type: %s\n", h->rooms[i].type == STANDARD ? "Standard" : h->rooms[i].type == DELUXE ? "Deluxe" : "Suite");
        printf("Room Price: %d\n", h->rooms[i].price);
        printf("Room Availability: %s\n", h->rooms[i].availability ? "Available" : "Occupied");
        printf("\n");
    }
    
    printf("\nGuests:\n");
    for (int i = 0; i < h->num_guests; i++) {
        printf("Guest ID: %d\n", h->guests[i].guest_id);
        printf("Guest Name: %s\n", h->guests[i].name);
        printf("Guest Address: %s\n", h->guests[i].address);
        printf("Guest Phone Number: %s\n", h->guests[i].phone_number);
        printf("Guest Status: %s\n", h->guests[i].status == CHECK_IN ? "Checked In" : "Checked Out");
        printf("Guest Room Number: %d\n", h->guests[i].room->room_number);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel();

    // Add some rooms to the hotel
    room r1 = {1, STANDARD, 100, 1};
    add_room(h, &r1);
    room r2 = {2, DELUXE, 150, 1};
    add_room(h, &r2);
    room r3 = {3, SUITE, 200, 1};
    add_room(h, &r3);

    // Add some guests to the hotel
    guest g1 = {1, "John Doe", "123 Main Street", "555-1212", CHECK_IN, &r1};
    add_guest(h, &g1);
    guest g2 = {2, "Jane Doe", "456 Elm Street", "555-1213", CHECK_IN, &r2};
    add_guest(h, &g2);
    guest g3 = {3, "John Smith", "789 Oak Street", "555-1214", CHECK_OUT, &r3};
    add_guest(h, &g3);

    // Print the hotel's information
    print_hotel(h);

    return 0;
}