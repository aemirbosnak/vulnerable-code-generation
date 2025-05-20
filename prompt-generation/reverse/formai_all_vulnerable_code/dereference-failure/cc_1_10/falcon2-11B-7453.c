//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a room
typedef struct {
    int roomNumber;
    char roomType[50];
    int pricePerNight;
    int totalOccupants;
} Room;

// Define the structure for a hotel
typedef struct {
    int hotelNumber;
    char hotelName[50];
    int numOfRooms;
    int totalOccupants;
} Hotel;

int main() {
    // Create a hotel
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    hotel->hotelNumber = 1;
    strcpy(hotel->hotelName, "ABC Hotel");
    hotel->numOfRooms = 10;
    hotel->totalOccupants = 0;

    // Create a room
    Room* room = (Room*)malloc(sizeof(Room));
    room->roomNumber = 101;
    strcpy(room->roomType, "Standard");
    room->pricePerNight = 100;
    room->totalOccupants = 1;

    // Add the room to the hotel
    hotel->numOfRooms++;
    hotel->totalOccupants++;

    // Print the hotel information
    printf("Hotel Information:\n");
    printf("Hotel Number: %d\n", hotel->hotelNumber);
    printf("Hotel Name: %s\n", hotel->hotelName);
    printf("Number of Rooms: %d\n", hotel->numOfRooms);
    printf("Total Occupants: %d\n", hotel->totalOccupants);

    // Print the room information
    printf("Room Information:\n");
    printf("Room Number: %d\n", room->roomNumber);
    printf("Room Type: %s\n", room->roomType);
    printf("Price Per Night: %d\n", room->pricePerNight);
    printf("Total Occupants: %d\n", room->totalOccupants);

    // Free the memory
    free(room);
    free(hotel);

    return 0;
}