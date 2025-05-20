//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold room details
typedef struct {
    int roomNumber;
    char roomType[50];
    int pricePerNight;
    int occupancy;
} Room;

// Define the structure to hold hotel details
typedef struct {
    char hotelName[100];
    int numRooms;
    Room rooms[100];
} Hotel;

// Function to allocate memory for a room
Room* allocateRoom(void) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    if (newRoom == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    memset(newRoom, 0, sizeof(Room));
    return newRoom;
}

// Function to allocate memory for a hotel
Hotel* allocateHotel(void) {
    Hotel* newHotel = (Hotel*)malloc(sizeof(Hotel));
    if (newHotel == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    memset(newHotel, 0, sizeof(Hotel));
    return newHotel;
}

// Function to add a new room to the hotel
void addRoom(Hotel* hotel, Room* room) {
    hotel->rooms[hotel->numRooms] = *room;
    hotel->numRooms++;
}

// Function to print the details of a room
void printRoom(Room* room) {
    printf("Room Number: %d\n", room->roomNumber);
    printf("Room Type: %s\n", room->roomType);
    printf("Price per night: %d\n", room->pricePerNight);
    printf("Occupancy: %d\n", room->occupancy);
}

// Function to print the details of the hotel
void printHotel(Hotel* hotel) {
    printf("Hotel Name: %s\n", hotel->hotelName);
    printf("Number of rooms: %d\n", hotel->numRooms);
    for (int i = 0; i < hotel->numRooms; i++) {
        printRoom(&hotel->rooms[i]);
    }
}

// Function to update the occupancy of a room
void updateOccupancy(Hotel* hotel, int roomNumber, int occupancy) {
    for (int i = 0; i < hotel->numRooms; i++) {
        if (hotel->rooms[i].roomNumber == roomNumber) {
            hotel->rooms[i].occupancy = occupancy;
            break;
        }
    }
}

// Function to check if a room is available
int isRoomAvailable(Hotel* hotel, int roomNumber) {
    for (int i = 0; i < hotel->numRooms; i++) {
        if (hotel->rooms[i].roomNumber == roomNumber) {
            if (hotel->rooms[i].occupancy == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to book a room
void bookRoom(Hotel* hotel, int roomNumber) {
    if (isRoomAvailable(hotel, roomNumber)) {
        printf("Room %d is available\n", roomNumber);
        updateOccupancy(hotel, roomNumber, 1);
        printf("Room %d booked\n", roomNumber);
    } else {
        printf("Room %d is not available\n", roomNumber);
    }
}

int main(void) {
    Hotel* hotel = allocateHotel();
    if (hotel == NULL) {
        return 1;
    }
    Room* room = allocateRoom();
    if (room == NULL) {
        return 1;
    }
    room->roomNumber = 101;
    strcpy(room->roomType, "Standard");
    room->pricePerNight = 100;
    room->occupancy = 0;
    addRoom(hotel, room);
    Room* anotherRoom = allocateRoom();
    if (anotherRoom == NULL) {
        return 1;
    }
    anotherRoom->roomNumber = 102;
    strcpy(anotherRoom->roomType, "Deluxe");
    anotherRoom->pricePerNight = 200;
    anotherRoom->occupancy = 0;
    addRoom(hotel, anotherRoom);
    printHotel(hotel);
    printf("\n");
    bookRoom(hotel, 101);
    printHotel(hotel);
    printf("\n");
    bookRoom(hotel, 101);
    printHotel(hotel);
    printf("\n");
    return 0;
}