//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hotel Management System

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum number of guests per room
#define MAX_GUESTS_PER_ROOM 4

// Define the room types
typedef enum {
    STANDARD,
    DELUXE,
    SUITE
} room_type;

// Define the room status
typedef enum {
    VACANT,
    OCCUPIED
} room_status;

// Define the guest structure
typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
} guest;

// Define the room structure
typedef struct {
    int room_number;
    room_type type;
    room_status status;
    guest guests[MAX_GUESTS_PER_ROOM];
} room;

// Define the hotel structure
typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    room rooms[MAX_ROOMS];
} hotel;

// Create a new hotel
hotel *create_hotel(char *name, char *address, char *phone, char *email) {
    hotel *h = malloc(sizeof(hotel));
    strcpy(h->name, name);
    strcpy(h->address, address);
    strcpy(h->phone, phone);
    strcpy(h->email, email);
    return h;
}

// Add a new room to the hotel
void add_room(hotel *h, int room_number, room_type type) {
    room *r = &h->rooms[room_number];
    r->room_number = room_number;
    r->type = type;
    r->status = VACANT;
}

// Check in a guest
void check_in(hotel *h, int room_number, guest *guest) {
    room *r = &h->rooms[room_number];
    if (r->status == VACANT) {
        r->status = OCCUPIED;
        for (int i = 0; i < MAX_GUESTS_PER_ROOM; i++) {
            if (r->guests[i].name[0] == '\0') {
                strcpy(r->guests[i].name, guest->name);
                strcpy(r->guests[i].address, guest->address);
                strcpy(r->guests[i].phone, guest->phone);
                strcpy(r->guests[i].email, guest->email);
                break;
            }
        }
    }
}

// Check out a guest
void check_out(hotel *h, int room_number) {
    room *r = &h->rooms[room_number];
    if (r->status == OCCUPIED) {
        r->status = VACANT;
        for (int i = 0; i < MAX_GUESTS_PER_ROOM; i++) {
            r->guests[i].name[0] = '\0';
            r->guests[i].address[0] = '\0';
            r->guests[i].phone[0] = '\0';
            r->guests[i].email[0] = '\0';
        }
    }
}

// Print the hotel
void print_hotel(hotel *h) {
    printf("Hotel: %s\n", h->name);
    printf("Address: %s\n", h->address);
    printf("Phone: %s\n", h->phone);
    printf("Email: %s\n", h->email);
    printf("\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        room *r = &h->rooms[i];
        printf("Room %d:\n", r->room_number);
        printf("Type: %s\n", r->type == STANDARD ? "Standard" : (r->type == DELUXE ? "Deluxe" : "Suite"));
        printf("Status: %s\n", r->status == VACANT ? "Vacant" : "Occupied");
        if (r->status == OCCUPIED) {
            for (int j = 0; j < MAX_GUESTS_PER_ROOM; j++) {
                guest *g = &r->guests[j];
                if (g->name[0] != '\0') {
                    printf("Guest %d:\n", j + 1);
                    printf("Name: %s\n", g->name);
                    printf("Address: %s\n", g->address);
                    printf("Phone: %s\n", g->phone);
                    printf("Email: %s\n", g->email);
                    printf("\n");
                }
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel("The Grand Hotel",
                             "123 Main Street",
                             "123-456-7890",
                             "info@thegrandhotel.com");

    // Add some rooms to the hotel
    add_room(h, 101, STANDARD);
    add_room(h, 102, DELUXE);
    add_room(h, 103, SUITE);

    // Check in some guests
    guest guest1 = {"John Smith", "123 Main Street", "123-456-7890", "john.smith@email.com"};
    check_in(h, 101, &guest1);

    guest guest2 = {"Jane Doe", "456 Elm Street", "456-789-0123", "jane.doe@email.com"};
    check_in(h, 102, &guest2);

    guest guest3 = {"Bill Jones", "789 Oak Street", "789-012-3456", "bill.jones@email.com"};
    check_in(h, 103, &guest3);

    // Print the hotel
    print_hotel(h);

    // Check out some guests
    check_out(h, 101);
    check_out(h, 103);

    // Print the hotel again
    print_hotel(h);

    return 0;
}