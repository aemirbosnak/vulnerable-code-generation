//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the room structure
typedef struct Room {
    char name[20];
    int number;
    float price;
    struct Room* next;
} Room;

// Define the booking structure
typedef struct Booking {
    char name[20];
    int number;
    int days;
    struct Booking* next;
} Booking;

// Global variables
Room* headRoom = NULL;
Booking* headBooking = NULL;

// Function to insert a room
void insertRoom(char* name, int number, float price) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->price = price;
    newRoom->next = NULL;

    if (headRoom == NULL) {
        headRoom = newRoom;
    } else {
        headRoom->next = newRoom;
        headRoom = newRoom;
    }
}

// Function to insert a booking
void insertBooking(char* name, int number, int days) {
    Booking* newBooking = (Booking*)malloc(sizeof(Booking));
    strcpy(newBooking->name, name);
    newBooking->number = number;
    newBooking->days = days;
    newBooking->next = NULL;

    if (headBooking == NULL) {
        headBooking = newBooking;
    } else {
        headBooking->next = newBooking;
        headBooking = newBooking;
    }
}

// Function to display all rooms
void displayRooms() {
    Room* currentRoom = headRoom;
    while (currentRoom) {
        printf("Name: %s, Number: %d, Price: %.2f\n", currentRoom->name, currentRoom->number, currentRoom->price);
        currentRoom = currentRoom->next;
    }
}

// Function to display all bookings
void displayBookings() {
    Booking* currentBooking = headBooking;
    while (currentBooking) {
        printf("Name: %s, Number: %d, Days: %d\n", currentBooking->name, currentBooking->number, currentBooking->days);
        currentBooking = currentBooking->next;
    }
}

int main() {
    // Insert some rooms
    insertRoom("Suite", 101, 200.0);
    insertRoom("Deluxe", 102, 150.0);
    insertRoom("Standard", 103, 100.0);

    // Insert some bookings
    insertBooking("John Doe", 101, 3);
    insertBooking("Jane Doe", 102, 2);
    insertBooking("Peter Pan", 103, 4);

    // Display all rooms
    displayRooms();

    // Display all bookings
    displayBookings();

    return 0;
}