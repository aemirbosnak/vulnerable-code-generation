//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUEST_NAME_LENGTH 20
#define MAX_ROOM_NUMBER 10

typedef struct Guest {
    char name[MAX_GUEST_NAME_LENGTH];
    int roomNumber;
    struct Guest* nextGuest;
} Guest;

typedef struct Room {
    int number;
    struct Room* nextRoom;
    Guest* guest;
} Room;

Room* createRoom(int number) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->nextRoom = NULL;
    newRoom->guest = NULL;
    return newRoom;
}

Guest* createGuest(char* name, int roomNumber) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->roomNumber = roomNumber;
    newGuest->nextGuest = NULL;
    return newGuest;
}

void addGuest(Guest* guest, Room* room) {
    room->guest = guest;
}

void checkIn(Guest* guest, Room* room) {
    addGuest(guest, room);
    printf("Welcome, %s, to Room %d!\n", guest->name, room->number);
}

void checkOut(Guest* guest) {
    free(guest);
}

int main() {
    Room* hotel = createRoom(1);
    Room* suite = createRoom(2);

    Guest* guest1 = createGuest("John Doe", 1);
    Guest* guest2 = createGuest("Jane Doe", 2);

    checkOut(guest1);
    checkOut(guest2);

    return 0;
}