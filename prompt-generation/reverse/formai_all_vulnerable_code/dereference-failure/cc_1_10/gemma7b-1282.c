//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the room structure
typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

// Define the hotel structure
typedef struct Hotel {
    Room* head;
    int numRooms;
    char name[20];
} Hotel;

// Function to insert a room into the hotel
void insertRoom(Hotel* hotel, int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (hotel->head == NULL) {
        hotel->head = newRoom;
    } else {
        hotel->head->next = newRoom;
    }

    hotel->numRooms++;
}

// Function to check if a room is available
int isRoomAvailable(Hotel* hotel, int number) {
    Room* currentRoom = hotel->head;

    while (currentRoom) {
        if (currentRoom->number == number && currentRoom->occupancy == 0) {
            return 1;
        }
        currentRoom = currentRoom->next;
    }

    return 0;
}

// Function to book a room
void bookRoom(Hotel* hotel, int number, int occupancy) {
    Room* currentRoom = hotel->head;

    while (currentRoom) {
        if (currentRoom->number == number && currentRoom->occupancy == 0) {
            currentRoom->occupancy = occupancy;
            printf("Room booked successfully!\n");
            return;
        }
        currentRoom = currentRoom->next;
    }

    printf("Sorry, the room is not available.\n");
}

int main() {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    hotel->head = NULL;
    hotel->numRooms = 0;
    strcpy(hotel->name, "The Grand Hotel");

    insertRoom(hotel, 101, 'A', 0);
    insertRoom(hotel, 102, 'B', 0);
    insertRoom(hotel, 103, 'A', 0);
    insertRoom(hotel, 104, 'B', 0);

    bookRoom(hotel, 102, 2);
    bookRoom(hotel, 103, 1);

    if (isRoomAvailable(hotel, 101)) {
        printf("Room 101 is available.\n");
    }

    return 0;
}