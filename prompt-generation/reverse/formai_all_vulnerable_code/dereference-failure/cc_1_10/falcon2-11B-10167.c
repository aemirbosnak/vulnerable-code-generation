//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int roomNumber;
    char roomType[50];
    int capacity;
    int occupied;
};

struct hotel {
    struct room* rooms;
    int roomCount;
    int totalRooms;
};

struct hotel createHotel(int roomCount, int totalRooms) {
    struct hotel hotel;
    hotel.roomCount = roomCount;
    hotel.totalRooms = totalRooms;
    hotel.rooms = (struct room*) malloc(roomCount * sizeof(struct room));
    for (int i = 0; i < hotel.roomCount; i++) {
        hotel.rooms[i].roomNumber = i + 1;
        hotel.rooms[i].roomType[0] = '\0';
        hotel.rooms[i].capacity = 2;
        hotel.rooms[i].occupied = 0;
    }
    return hotel;
}

void printHotelInfo(struct hotel hotel) {
    printf("Hotel Info:\n");
    printf("Room Count: %d\n", hotel.roomCount);
    printf("Total Rooms: %d\n", hotel.totalRooms);
}

void addRoom(struct hotel hotel, char* roomType, int capacity) {
    int roomIndex = hotel.roomCount;
    hotel.rooms[roomIndex-1].roomType[0] = '\0';
    strcpy(hotel.rooms[roomIndex-1].roomType, roomType);
    hotel.rooms[roomIndex-1].capacity = capacity;
    hotel.rooms[roomIndex-1].occupied = 0;
    hotel.roomCount++;
}

void bookRoom(struct hotel hotel, int roomNumber) {
    if (hotel.rooms[roomNumber-1].occupied == 1) {
        printf("Room %d is already occupied.\n", roomNumber);
    } else {
        hotel.rooms[roomNumber-1].occupied = 1;
        printf("Room %d is booked.\n", roomNumber);
    }
}

void cancelRoom(struct hotel hotel, int roomNumber) {
    if (hotel.rooms[roomNumber-1].occupied == 0) {
        printf("Room %d is not booked.\n", roomNumber);
    } else {
        hotel.rooms[roomNumber-1].occupied = 0;
        printf("Room %d is canceled.\n", roomNumber);
    }
}

int main() {
    struct hotel hotel = createHotel(10, 20);
    printHotelInfo(hotel);
    addRoom(hotel, "Deluxe", 4);
    addRoom(hotel, "Standard", 2);
    bookRoom(hotel, 1);
    bookRoom(hotel, 2);
    bookRoom(hotel, 3);
    cancelRoom(hotel, 1);
    cancelRoom(hotel, 4);
    printHotelInfo(hotel);
    return 0;
}