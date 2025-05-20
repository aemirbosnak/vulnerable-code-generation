//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for a hotel room
struct Room {
    char* roomNumber;
    int pricePerNight;
};

// Define a structure for a hotel
struct Hotel {
    char* name;
    int numOfRooms;
    struct Room* rooms;
};

// Function to initialize a hotel with a given name and number of rooms
struct Hotel* initHotel(char* name, int numOfRooms) {
    struct Hotel* hotel = malloc(sizeof(struct Hotel));
    hotel->name = name;
    hotel->numOfRooms = numOfRooms;
    hotel->rooms = malloc(numOfRooms * sizeof(struct Room));
    return hotel;
}

// Function to add a new room to the hotel
void addRoom(struct Hotel* hotel, char* roomNumber, int pricePerNight) {
    struct Room* newRoom = malloc(sizeof(struct Room));
    newRoom->roomNumber = roomNumber;
    newRoom->pricePerNight = pricePerNight;
    hotel->rooms[hotel->numOfRooms] = *newRoom;
    hotel->numOfRooms++;
}

// Function to print the details of a hotel
void printHotel(struct Hotel* hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Number of Rooms: %d\n", hotel->numOfRooms);
    printf("Rooms:\n");
    for (int i = 0; i < hotel->numOfRooms; i++) {
        printf("Room %d: %s - $%.2f\n", i+1, hotel->rooms[i].roomNumber, hotel->rooms[i].pricePerNight);
    }
}

// Function to check if a room is available
int isRoomAvailable(struct Hotel* hotel, char* roomNumber) {
    for (int i = 0; i < hotel->numOfRooms; i++) {
        if (strcmp(hotel->rooms[i].roomNumber, roomNumber) == 0) {
            return 0; // Room is available
        }
    }
    return 1; // Room is not available
}

// Function to book a room
void bookRoom(struct Hotel* hotel, char* roomNumber) {
    if (isRoomAvailable(hotel, roomNumber)) {
        printf("Room %s has been booked!\n", roomNumber);
    } else {
        printf("Room %s is not available!\n", roomNumber);
    }
}

// Function to check out a room
void checkOutRoom(struct Hotel* hotel, char* roomNumber) {
    if (isRoomAvailable(hotel, roomNumber)) {
        printf("Room %s has been checked out!\n", roomNumber);
    } else {
        printf("Room %s is not available!\n", roomNumber);
    }
}

// Function to generate a random room number
char* generateRandomRoomNumber() {
    char* roomNumber = malloc(10);
    strcpy(roomNumber, "ROOM");
    for (int i = 0; i < 8; i++) {
        roomNumber[i] = '0' + rand() % 10;
    }
    return roomNumber;
}

// Main function
int main() {
    // Create a hotel with a name and number of rooms
    char* hotelName = "C Hotel";
    int numOfRooms = 10;
    struct Hotel* hotel = initHotel(hotelName, numOfRooms);

    // Add rooms to the hotel
    addRoom(hotel, generateRandomRoomNumber(), 100.00);
    addRoom(hotel, generateRandomRoomNumber(), 150.00);
    addRoom(hotel, generateRandomRoomNumber(), 200.00);

    // Print the details of the hotel
    printf("Hotel Details:\n");
    printHotel(hotel);

    // Book a room
    char* roomNumber = generateRandomRoomNumber();
    bookRoom(hotel, roomNumber);

    // Check out a room
    checkOutRoom(hotel, roomNumber);

    free(hotel); // Free the memory allocated for the hotel
    return 0;
}