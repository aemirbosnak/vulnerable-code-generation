//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int roomNumber;
    int isOccupied;
    char *name;
    char *address;
    char *phoneNumber;
};

struct hotel {
    int hotelNumber;
    char *name;
    struct room *rooms;
};

int main() {
    struct hotel hotel;

    hotel.hotelNumber = 100;
    hotel.name = "The Grand";

    struct room room1;
    room1.roomNumber = 101;
    room1.isOccupied = 0;
    strcpy(room1.name, "John Doe");
    strcpy(room1.address, "123 Main St");
    strcpy(room1.phoneNumber, "555-1234");

    struct room room2;
    room2.roomNumber = 102;
    room2.isOccupied = 1;
    strcpy(room2.name, "Jane Doe");
    strcpy(room2.address, "456 Elm St");
    strcpy(room2.phoneNumber, "555-5678");

    hotel.rooms = malloc(sizeof(struct room) * 2);
    hotel.rooms[0] = room1;
    hotel.rooms[1] = room2;

    printf("Hotel Number: %d\n", hotel.hotelNumber);
    printf("Hotel Name: %s\n", hotel.name);

    printf("Room 1\n");
    printf("Room Number: %d\n", room1.roomNumber);
    printf("Is Occupied: %d\n", room1.isOccupied);
    printf("Name: %s\n", room1.name);
    printf("Address: %s\n", room1.address);
    printf("Phone Number: %s\n", room1.phoneNumber);

    printf("Room 2\n");
    printf("Room Number: %d\n", room2.roomNumber);
    printf("Is Occupied: %d\n", room2.isOccupied);
    printf("Name: %s\n", room2.name);
    printf("Address: %s\n", room2.address);
    printf("Phone Number: %s\n", room2.phoneNumber);

    free(hotel.rooms);
    return 0;
}