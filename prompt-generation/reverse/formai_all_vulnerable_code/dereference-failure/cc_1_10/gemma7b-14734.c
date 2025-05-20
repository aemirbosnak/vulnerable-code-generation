//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_NAME_LENGTH 255
#define MAX_ROOM_NUMBER 100

typedef struct Guest {
    char name[MAX_GUEST_NAME_LENGTH];
    int roomNumber;
    struct Guest* nextGuest;
} Guest;

typedef struct Room {
    int number;
    struct Room* nextRoom;
} Room;

Room* createRoom(int number) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->nextRoom = NULL;
    return newRoom;
}

Guest* createGuest(char* name, int roomNumber) {
    Guest* newGuest = malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->roomNumber = roomNumber;
    newGuest->nextGuest = NULL;
    return newGuest;
}

void addGuest(Guest* guest, Guest* nextGuest) {
    guest->nextGuest = nextGuest;
}

void checkIn(Guest* guest) {
    printf("Welcome, %s, to room number %d!\n", guest->name, guest->roomNumber);
}

void checkOut(Guest* guest) {
    printf("Goodbye, %s. Have a nice day!\n", guest->name);
}

int main() {
    Guest* headGuest = NULL;
    Room* headRoom = createRoom(1);

    Guest* newGuest = createGuest("John Doe", 1);
    addGuest(newGuest, headGuest);
    headGuest = newGuest;

    newGuest = createGuest("Jane Doe", 2);
    addGuest(newGuest, headGuest);
    headGuest = newGuest;

    checkOut(headGuest);
    checkOut(headGuest->nextGuest);

    return 0;
}