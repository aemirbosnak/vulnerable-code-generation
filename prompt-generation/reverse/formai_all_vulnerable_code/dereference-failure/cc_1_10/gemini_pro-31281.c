//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum number of guests in a room
#define MAX_GUESTS 4

// Define the structure of a room
typedef struct room {
    int room_number;
    int num_guests;
    char guest_names[MAX_GUESTS][50];
    time_t check_in_time;
    time_t check_out_time;
} room;

// Define the structure of the hotel
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

// Add a new room to the hotel
void add_room(hotel *h, int room_number) {
    h->rooms[h->num_rooms].room_number = room_number;
    h->rooms[h->num_rooms].num_guests = 0;
    h->num_rooms++;
}

// Check in a guest to a room
void check_in_guest(hotel *h, int room_number, char *guest_name) {
    room *r = &h->rooms[room_number - 1];
    strcpy(r->guest_names[r->num_guests], guest_name);
    r->num_guests++;
    r->check_in_time = time(NULL);
}

// Check out a guest from a room
void check_out_guest(hotel *h, int room_number, char *guest_name) {
    room *r = &h->rooms[room_number - 1];
    int i;
    for (i = 0; i < r->num_guests; i++) {
        if (strcmp(r->guest_names[i], guest_name) == 0) {
            break;
        }
    }
    if (i < r->num_guests) {
        for (; i < r->num_guests - 1; i++) {
            strcpy(r->guest_names[i], r->guest_names[i + 1]);
        }
        r->num_guests--;
        r->check_out_time = time(NULL);
    }
}

// Print the status of the hotel
void print_hotel_status(hotel *h) {
    int i, j;
    for (i = 0; i < h->num_rooms; i++) {
        room *r = &h->rooms[i];
        printf("Room %d:\n", r->room_number);
        printf("Number of guests: %d\n", r->num_guests);
        for (j = 0; j < r->num_guests; j++) {
            printf("Guest %d: %s\n", j + 1, r->guest_names[j]);
        }
        printf("Check-in time: %s", ctime(&r->check_in_time));
        printf("Check-out time: %s", ctime(&r->check_out_time));
    }
}

// Free the memory allocated for the hotel
void free_hotel(hotel *h) {
    free(h);
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel();

    // Add some rooms to the hotel
    add_room(h, 1);
    add_room(h, 2);
    add_room(h, 3);

    // Check in some guests to the hotel
    check_in_guest(h, 1, "John Doe");
    check_in_guest(h, 1, "Jane Doe");
    check_in_guest(h, 2, "Bob Smith");
    check_in_guest(h, 3, "Alice Johnson");

    // Print the status of the hotel
    print_hotel_status(h);

    // Check out some guests from the hotel
    check_out_guest(h, 1, "John Doe");
    check_out_guest(h, 2, "Bob Smith");

    // Print the status of the hotel again
    print_hotel_status(h);

    // Free the memory allocated for the hotel
    free_hotel(h);

    return 0;
}