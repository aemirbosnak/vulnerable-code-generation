//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Room {
    int roomNumber;
    int capacity;
    char *type;
    int availability;
} Room;

typedef struct Guest {
    int guestID;
    char *name;
    char *email;
    char *phoneNumber;
    int roomNumber;
    int checkInDate;
    int checkOutDate;
} Guest;

typedef struct Booking {
    int bookingID;
    int guestID;
    int roomNumber;
    int checkInDate;
    int checkOutDate;
} Booking;

// Function to create a new room
Room *createRoom(int roomNumber, int capacity, char *type, int availability) {
    Room *room = (Room *)malloc(sizeof(Room));
    room->roomNumber = roomNumber;
    room->capacity = capacity;
    room->type = type;
    room->availability = availability;
    return room;
}

// Function to create a new guest
Guest *createGuest(int guestID, char *name, char *email, char *phoneNumber, int roomNumber, int checkInDate, int checkOutDate) {
    Guest *guest = (Guest *)malloc(sizeof(Guest));
    guest->guestID = guestID;
    guest->name = name;
    guest->email = email;
    guest->phoneNumber = phoneNumber;
    guest->roomNumber = roomNumber;
    guest->checkInDate = checkInDate;
    guest->checkOutDate = checkOutDate;
    return guest;
}

// Function to create a new booking
Booking *createBooking(int bookingID, int guestID, int roomNumber, int checkInDate, int checkOutDate) {
    Booking *booking = (Booking *)malloc(sizeof(Booking));
    booking->bookingID = bookingID;
    booking->guestID = guestID;
    booking->roomNumber = roomNumber;
    booking->checkInDate = checkInDate;
    booking->checkOutDate = checkOutDate;
    return booking;
}

// Function to print the details of a room
void printRoom(Room *room) {
    printf("Room Number: %d\n", room->roomNumber);
    printf("Capacity: %d\n", room->capacity);
    printf("Type: %s\n", room->type);
    printf("Availability: %d\n", room->availability);
}

// Function to print the details of a guest
void printGuest(Guest *guest) {
    printf("Guest ID: %d\n", guest->guestID);
    printf("Name: %s\n", guest->name);
    printf("Email: %s\n", guest->email);
    printf("Phone Number: %s\n", guest->phoneNumber);
    printf("Room Number: %d\n", guest->roomNumber);
    printf("Check In Date: %d\n", guest->checkInDate);
    printf("Check Out Date: %d\n", guest->checkOutDate);
}

// Function to print the details of a booking
void printBooking(Booking *booking) {
    printf("Booking ID: %d\n", booking->bookingID);
    printf("Guest ID: %d\n", booking->guestID);
    printf("Room Number: %d\n", booking->roomNumber);
    printf("Check In Date: %d\n", booking->checkInDate);
    printf("Check Out Date: %d\n", booking->checkOutDate);
}

// Main function
int main() {
    // Create a few rooms
    Room *room1 = createRoom(101, 2, "Standard", 1);
    Room *room2 = createRoom(102, 4, "Deluxe", 1);
    Room *room3 = createRoom(103, 6, "Suite", 0);

    // Create a few guests
    Guest *guest1 = createGuest(1, "John Doe", "john.doe@email.com", "0123456789", 101, 20230301, 20230305);
    Guest *guest2 = createGuest(2, "Jane Doe", "jane.doe@email.com", "0987654321", 102, 20230306, 20230310);
    Guest *guest3 = createGuest(3, "Jack Doe", "jack.doe@email.com", "1234567890", 103, 20230311, 20230315);

    // Create a few bookings
    Booking *booking1 = createBooking(1, 1, 101, 20230301, 20230305);
    Booking *booking2 = createBooking(2, 2, 102, 20230306, 20230310);
    Booking *booking3 = createBooking(3, 3, 103, 20230311, 20230315);

    // Print the details of the rooms
    printf("Rooms:\n");
    printRoom(room1);
    printRoom(room2);
    printRoom(room3);

    // Print the details of the guests
    printf("\nGuests:\n");
    printGuest(guest1);
    printGuest(guest2);
    printGuest(guest3);

    // Print the details of the bookings
    printf("\nBookings:\n");
    printBooking(booking1);
    printBooking(booking2);
    printBooking(booking3);

    return 0;
}