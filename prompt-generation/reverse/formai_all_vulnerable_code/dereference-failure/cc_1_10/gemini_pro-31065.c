//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the room types
typedef enum {
    STANDARD,
    DELUXE,
    SUITE
} room_type;

// Define the room status
typedef enum {
    VACANT,
    OCCUPIED,
    RESERVED
} room_status;

// Define the room structure
typedef struct {
    int room_number;
    room_type type;
    room_status status;
    float price;
} room;

// Define the hotel structure
typedef struct {
    int num_rooms;
    room *rooms;
} hotel;

// Create a new hotel
hotel *create_hotel(int num_rooms) {
    hotel *h = (hotel *)malloc(sizeof(hotel));
    h->num_rooms = num_rooms;
    h->rooms = (room *)malloc(num_rooms * sizeof(room));
    for (int i = 0; i < num_rooms; i++) {
        h->rooms[i].room_number = i + 1;
        h->rooms[i].type = STANDARD;
        h->rooms[i].status = VACANT;
        h->rooms[i].price = 100.0;
    }
    return h;
}

// Display the hotel information
void display_hotel(hotel *h) {
    printf("Hotel Information\n");
    printf("Number of Rooms: %d\n", h->num_rooms);
    for (int i = 0; i < h->num_rooms; i++) {
        printf("Room %d: ", h->rooms[i].room_number);
        switch (h->rooms[i].type) {
            case STANDARD:
                printf("Standard");
                break;
            case DELUXE:
                printf("Deluxe");
                break;
            case SUITE:
                printf("Suite");
                break;
        }
        printf(", ");
        switch (h->rooms[i].status) {
            case VACANT:
                printf("Vacant");
                break;
            case OCCUPIED:
                printf("Occupied");
                break;
            case RESERVED:
                printf("Reserved");
                break;
        }
        printf(", $%.2f\n", h->rooms[i].price);
    }
}

// Check in a guest
void check_in(hotel *h, int room_number) {
    if (room_number < 1 || room_number > h->num_rooms) {
        printf("Invalid room number\n");
        return;
    }
    room *r = &h->rooms[room_number - 1];
    if (r->status != VACANT) {
        printf("Room is not vacant\n");
        return;
    }
    r->status = OCCUPIED;
    printf("Check in successful\n");
}

// Check out a guest
void check_out(hotel *h, int room_number) {
    if (room_number < 1 || room_number > h->num_rooms) {
        printf("Invalid room number\n");
        return;
    }
    room *r = &h->rooms[room_number - 1];
    if (r->status != OCCUPIED) {
        printf("Room is not occupied\n");
        return;
    }
    r->status = VACANT;
    printf("Check out successful\n");
}

// Reserve a room
void reserve_room(hotel *h, int room_number) {
    if (room_number < 1 || room_number > h->num_rooms) {
        printf("Invalid room number\n");
        return;
    }
    room *r = &h->rooms[room_number - 1];
    if (r->status != VACANT) {
        printf("Room is not vacant\n");
        return;
    }
    r->status = RESERVED;
    printf("Reservation successful\n");
}

// Cancel a reservation
void cancel_reservation(hotel *h, int room_number) {
    if (room_number < 1 || room_number > h->num_rooms) {
        printf("Invalid room number\n");
        return;
    }
    room *r = &h->rooms[room_number - 1];
    if (r->status != RESERVED) {
        printf("Room is not reserved\n");
        return;
    }
    r->status = VACANT;
    printf("Reservation cancellation successful\n");
}

// Main function
int main() {
    // Create a hotel with 10 rooms
    hotel *h = create_hotel(10);

    // Display the hotel information
    display_hotel(h);

    // Check in a guest to room 5
    check_in(h, 5);

    // Display the hotel information
    display_hotel(h);

    // Check out a guest from room 5
    check_out(h, 5);

    // Display the hotel information
    display_hotel(h);

    // Reserve a room
    reserve_room(h, 7);

    // Display the hotel information
    display_hotel(h);

    // Cancel a reservation
    cancel_reservation(h, 7);

    // Display the hotel information
    display_hotel(h);

    return 0;
}