//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Structure to hold guest details
typedef struct Guest {
    char name[50];
    char address[100];
    int room_no;
    int checkin_date;
    int checkout_date;
} Guest;

// Structure to hold hotel details
typedef struct Hotel {
    int rooms;
    int total_guests;
} Hotel;

// Function to create a new guest
Guest* createGuest(char* name, char* address, int room_no, int checkin_date, int checkout_date) {
    Guest* guest = (Guest*) malloc(sizeof(Guest));
    strcpy(guest->name, name);
    strcpy(guest->address, address);
    guest->room_no = room_no;
    guest->checkin_date = checkin_date;
    guest->checkout_date = checkout_date;
    return guest;
}

// Function to display hotel details
void displayHotel(Hotel* hotel) {
    printf("Hotel Details\n");
    printf("Number of rooms: %d\n", hotel->rooms);
    printf("Total number of guests: %d\n", hotel->total_guests);
}

// Function to display guest details
void displayGuest(Guest* guest) {
    printf("Guest Details\n");
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Room number: %d\n", guest->room_no);
    printf("Check-in date: %d\n", guest->checkin_date);
    printf("Check-out date: %d\n", guest->checkout_date);
}

// Function to check if guest has checked out
int guestCheckedOut(Guest* guest) {
    return guest->checkout_date > 0;
}

// Function to check if guest has checked in
int guestCheckedIn(Guest* guest) {
    return guest->checkin_date > 0;
}

// Function to create a new hotel
Hotel* createHotel(int rooms, int total_guests) {
    Hotel* hotel = (Hotel*) malloc(sizeof(Hotel));
    hotel->rooms = rooms;
    hotel->total_guests = total_guests;
    return hotel;
}

// Function to handle guest check-in
void guestCheckIn(Guest* guest) {
    printf("Guest %s checked in.\n", guest->name);
}

// Function to handle guest check-out
void guestCheckOut(Guest* guest) {
    printf("Guest %s checked out.\n", guest->name);
}

int main() {
    Hotel* hotel = createHotel(100, 0);
    Guest* guest1 = createGuest("John Doe", "123 Main St", 1, 1, 5);
    Guest* guest2 = createGuest("Jane Doe", "456 Elm St", 2, 2, 4);

    // Display hotel details
    displayHotel(hotel);

    // Check if guests have checked in
    printf("Guest %s has checked in: %d\n", guest1->name, guestCheckedIn(guest1));
    printf("Guest %s has checked in: %d\n", guest2->name, guestCheckedIn(guest2));

    // Check if guests have checked out
    printf("Guest %s has checked out: %d\n", guest1->name, guestCheckedOut(guest1));
    printf("Guest %s has checked out: %d\n", guest2->name, guestCheckedOut(guest2));

    // Handle guest check-in
    guestCheckIn(guest1);
    guestCheckIn(guest2);

    // Handle guest check-out
    guestCheckOut(guest1);
    guestCheckOut(guest2);

    // Display hotel details after guest check-in and check-out
    displayHotel(hotel);

    return 0;
}