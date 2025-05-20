//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of guests and rooms
#define MAX_GUESTS 100
#define MAX_ROOMS 50

// Define the guest structure
typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    int room_number;
    int days_stayed;
    float bill_amount;
} guest;

// Define the room structure
typedef struct {
    int room_number;
    char room_type[20];
    float room_rate;
    int is_occupied;
} room;

// Define the hotel structure
typedef struct {
    char hotel_name[50];
    char address[100];
    char phone[20];
    guest guests[MAX_GUESTS];
    room rooms[MAX_ROOMS];
    int num_guests;
    int num_rooms;
} hotel;

// Create a new hotel
hotel *create_hotel() {
    hotel *h = (hotel *)malloc(sizeof(hotel));
    strcpy(h->hotel_name, "Grand Hotel");
    strcpy(h->address, "123 Main Street");
    strcpy(h->phone, "555-1212");
    h->num_guests = 0;
    h->num_rooms = 0;
    return h;
}

// Add a new guest to the hotel
void add_guest(hotel *h, guest *g) {
    h->guests[h->num_guests] = *g;
    h->num_guests++;
}

// Add a new room to the hotel
void add_room(hotel *h, room *r) {
    h->rooms[h->num_rooms] = *r;
    h->num_rooms++;
}

// Check in a guest
void check_in(hotel *h, guest *g, room *r) {
    g->room_number = r->room_number;
    g->days_stayed = 0;
    g->bill_amount = 0;
    r->is_occupied = 1;
    add_guest(h, g);
}

// Check out a guest
void check_out(hotel *h, guest *g) {
    int i;
    for (i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].room_number == g->room_number) {
            h->rooms[i].is_occupied = 0;
            break;
        }
    }
    for (i = 0; i < h->num_guests; i++) {
        if (strcmp(h->guests[i].name, g->name) == 0) {
            h->guests[i] = h->guests[h->num_guests - 1];
            h->num_guests--;
            break;
        }
    }
}

// Print the hotel information
void print_hotel_info(hotel *h) {
    printf("Hotel Name: %s\n", h->hotel_name);
    printf("Address: %s\n", h->address);
    printf("Phone: %s\n", h->phone);
    printf("Number of Guests: %d\n", h->num_guests);
    printf("Number of Rooms: %d\n", h->num_rooms);
}

// Print the guest information
void print_guest_info(guest *g) {
    printf("Name: %s\n", g->name);
    printf("Address: %s\n", g->address);
    printf("Phone: %s\n", g->phone);
    printf("Room Number: %d\n", g->room_number);
    printf("Days Stayed: %d\n", g->days_stayed);
    printf("Bill Amount: %.2f\n", g->bill_amount);
}

// Print the room information
void print_room_info(room *r) {
    printf("Room Number: %d\n", r->room_number);
    printf("Room Type: %s\n", r->room_type);
    printf("Room Rate: %.2f\n", r->room_rate);
    printf("Is Occupied: %d\n", r->is_occupied);
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel();

    // Add some guests to the hotel
    guest g1 = {"John Smith", "123 Main Street", "555-1212"};
    guest g2 = {"Jane Doe", "456 Elm Street", "555-1213"};
    add_guest(h, &g1);
    add_guest(h, &g2);

    // Add some rooms to the hotel
    room r1 = {101, "Standard", 100.00, 0};
    room r2 = {102, "Deluxe", 150.00, 0};
    add_room(h, &r1);
    add_room(h, &r2);

    // Check in a guest
    check_in(h, &g1, &r1);

    // Check out a guest
    check_out(h, &g1);

    // Print the hotel information
    print_hotel_info(h);

    // Print the guest information
    print_guest_info(&g1);

    // Print the room information
    print_room_info(&r1);

    return 0;
}