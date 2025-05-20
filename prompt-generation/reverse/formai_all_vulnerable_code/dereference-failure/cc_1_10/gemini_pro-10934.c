//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the hotel's room types
#define SINGLE 1
#define DOUBLE 2
#define SUITE 3

// Define the hotel's rates
#define SINGLE_RATE 100
#define DOUBLE_RATE 150
#define SUITE_RATE 200

// Define the hotel's maximum number of rooms
#define MAX_ROOMS 100

// Define the hotel's check-in and check-out times
#define CHECK_IN_TIME 3
#define CHECK_OUT_TIME 12

// Declare the hotel's room data structure
typedef struct room {
    int number;
    int type;
    int occupied;
    time_t check_in_time;
    time_t check_out_time;
} room;

// Declare the hotel's data structure
typedef struct hotel {
    room rooms[MAX_ROOMS];
    int num_rooms;
} hotel;

// Create a new hotel
hotel *create_hotel() {
    hotel *h = malloc(sizeof(hotel));
    h->num_rooms = 0;
    return h;
}

// Add a room to the hotel
void add_room(hotel *h, int number, int type) {
    h->rooms[h->num_rooms].number = number;
    h->rooms[h->num_rooms].type = type;
    h->rooms[h->num_rooms].occupied = 0;
    h->num_rooms++;
}

// Print the hotel's room data
void print_rooms(hotel *h) {
    for (int i = 0; i < h->num_rooms; i++) {
        printf("Room %d: ", i);
        if (h->rooms[i].occupied) {
            printf("Occupied, ");
            if (h->rooms[i].type == SINGLE)
                printf("Single");
            else if (h->rooms[i].type == DOUBLE)
                printf("Double");
            else if (h->rooms[i].type == SUITE)
                printf("Suite");
            printf(", Check-in: %s, Check-out: %s\n", ctime(&h->rooms[i].check_in_time),
                   ctime(&h->rooms[i].check_out_time));
        } else {
            printf("Unoccupied, ");
            if (h->rooms[i].type == SINGLE)
                printf("Single");
            else if (h->rooms[i].type == DOUBLE)
                printf("Double");
            else if (h->rooms[i].type == SUITE)
                printf("Suite");
            printf("\n");
        }
    }
}

// Check in a guest
void check_in(hotel *h, int room_number, time_t check_in_time) {
    room *r = &h->rooms[room_number];
    r->occupied = 1;
    r->check_in_time = check_in_time;
    r->check_out_time = check_in_time + 24 * 3600; // Assume guests stay for 24 hours
}

// Check out a guest
void check_out(hotel *h, int room_number) {
    room *r = &h->rooms[room_number];
    r->occupied = 0;
}

// Get the total revenue for the hotel
int get_revenue(hotel *h) {
    int revenue = 0;
    for (int i = 0; i < h->num_rooms;
         i++) { if (h->rooms[i].occupied) {
            if (h->rooms[i].type == SINGLE)
                revenue += SINGLE_RATE;
            else if (h->rooms[i].type == DOUBLE)
                revenue += DOUBLE_RATE;
            else if (h->rooms[i].type == SUITE)
                revenue += SUITE_RATE;
        }
    }
    return revenue;
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel();

    // Add some rooms to the hotel
    add_room(h, 1, SINGLE);
    add_room(h, 2, DOUBLE);
    add_room(h, 3, SUITE);

    // Print the hotel's room data
    print_rooms(h);

    // Check in a guest
    check_in(h, 1, time(NULL));

    // Print the hotel's room data
    print_rooms(h);

    // Check out a guest
    check_out(h, 1);

    // Print the hotel's room data
    print_rooms(h);

    // Get the total revenue for the hotel
    int revenue = get_revenue(h);

    // Print the total revenue
    printf("Total revenue: %d\n", revenue);

    return 0;
}