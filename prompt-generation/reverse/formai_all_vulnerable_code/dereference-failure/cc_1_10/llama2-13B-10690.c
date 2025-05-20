//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

// Structure to store guest information
struct guest {
    char name[50];
    char email[50];
    int checkin_date;
    int checkout_date;
    int room_id;
};

// Structure to store room information
struct room {
    char name[50];
    int capacity;
    int available;
    int price;
};

// Global variables
int num_guests = 0;
struct guest *guests = NULL;
struct room *rooms = NULL;

// Function to check if a room is available
int is_room_available(int room_id) {
    struct room *room = rooms + room_id;
    return room->available > 0;
}

// Function to check if a guest has checked out
int has_guest_checked_out(int guest_id) {
    struct guest *guest = guests + guest_id;
    return guest->checkout_date > 0;
}

// Function to check if a room has been booked
int has_room_been_booked(int room_id) {
    struct room *room = rooms + room_id;
    return room->available <= 0;
}

// Function to book a room
void book_room(int room_id) {
    struct room *room = rooms + room_id;
    if (room->available > 0) {
        room->available--;
        printf("Room %d has been booked\n", room_id);
    } else {
        printf("Sorry, there are no more rooms available\n");
    }
}

// Function to check in a guest
void check_in(int guest_id) {
    struct guest *guest = guests + guest_id;
    guest->checkin_date = time(NULL);
    printf("Guest %d has checked in\n", guest_id);
}

// Function to check out a guest
void check_out(int guest_id) {
    struct guest *guest = guests + guest_id;
    guest->checkout_date = time(NULL);
    printf("Guest %d has checked out\n", guest_id);
}

int main() {
    // Initialize the guest and room structures
    for (int i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].email[0] = '\0';
        guests[i].checkin_date = 0;
        guests[i].checkout_date = 0;
        guests[i].room_id = 0;
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].name[0] = '\0';
        rooms[i].capacity = 0;
        rooms[i].available = 0;
        rooms[i].price = 0;
    }

    // Main loop
    while (1) {
        // Check if there are any bookings to be made
        for (int i = 0; i < MAX_ROOMS; i++) {
            if (rooms[i].available > 0) {
                printf("Room %d is available\n", i);
                book_room(i);
            }
        }

        // Check if there are any guests checking in
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (guests[i].checkin_date == 0) {
                printf("Guest %d is checking in\n", i);
                check_in(i);
            }
        }

        // Check if there are any guests checking out
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (guests[i].checkout_date > 0) {
                printf("Guest %d is checking out\n", i);
                check_out(i);
            }
        }

        // Check if there are any rooms available
        for (int i = 0; i < MAX_ROOMS; i++) {
            if (rooms[i].available > 0) {
                printf("Room %d is available\n", i);
            }
        }

        // Wait for a key press
        getchar();
    }

    return 0;
}