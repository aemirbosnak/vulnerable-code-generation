//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Structure to store information about a hotel
typedef struct {
    char name[50];
    int rooms;
    int checkIn;
    int checkOut;
} Hotel;

// Structure to store information about a room
typedef struct {
    char name[50];
    int price;
    int occupied;
} Room;

// Function to create a new hotel
Hotel* createHotel(char name[], int rooms) {
    Hotel* hotel = malloc(sizeof(Hotel));
    strcpy(hotel->name, name);
    hotel->rooms = rooms;
    hotel->checkIn = 0;
    hotel->checkOut = 0;
    return hotel;
}

// Function to create a new room
Room* createRoom(char name[], int price) {
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, name);
    room->price = price;
    room->occupied = 0;
    return room;
}

// Function to add a new guest to a hotel
void addGuest(Hotel* hotel, char name[], int days) {
    if (hotel->checkIn == 0 && hotel->checkOut == 0) {
        hotel->checkIn = time(NULL);
        hotel->checkOut = hotel->checkIn + days;
    } else {
        printf("Error: Hotel is already full.\n");
        return;
    }
    printf("Guest %s has checked in.\n", name);
}

// Function to check out a guest from a hotel
void checkOutGuest(Hotel* hotel, char name[]) {
    if (hotel->checkIn!= 0 && hotel->checkOut!= 0 && strcmp(name, hotel->name) == 0) {
        printf("Guest %s has checked out.\n", name);
    } else {
        printf("Error: Guest not found.\n");
    }
}

// Function to book a room in a hotel
void bookRoom(Hotel* hotel, char name[], int days) {
    if (hotel->checkIn == 0 && hotel->checkOut == 0) {
        printf("Room %s has been booked for %d days.\n", name, days);
        Room* room = createRoom(name, hotel->rooms);
        hotel->rooms--;
        hotel->checkIn = time(NULL);
        hotel->checkOut = hotel->checkIn + days;
    } else {
        printf("Error: Hotel is already full.\n");
    }
}

// Function to cancel a room booking in a hotel
void cancelRoom(Hotel* hotel, char name[]) {
    if (hotel->checkIn!= 0 && hotel->checkOut!= 0 && strcmp(name, hotel->name) == 0) {
        printf("Room %s has been cancelled.\n", name);
    } else {
        printf("Error: Room not found.\n");
    }
}

int main() {
    // Create a new hotel
    Hotel* hotel = createHotel("The Grand Hotel", 50);
    addGuest(hotel, "John Doe", 3);
    bookRoom(hotel, "Deluxe Suite", 7);
    checkOutGuest(hotel, "John Doe");
    cancelRoom(hotel, "Deluxe Suite");

    return 0;
}