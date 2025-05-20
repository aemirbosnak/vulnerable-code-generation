//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <string.h>

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
    Guest* guests;
} Room;

Room* createRoom(int number) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->nextRoom = NULL;
    newRoom->guests = NULL;
    return newRoom;
}

Guest* createGuest(char* name, int roomNumber) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->roomNumber = roomNumber;
    newGuest->nextGuest = NULL;
    return newGuest;
}

void addGuestToRoom(Guest* guest, Room* room) {
    room->guests = guest;
}

void printGuestsInRoom(Room* room) {
    Guest* guest = room->guests;
    while (guest) {
        printf("%s ", guest->name);
    }
    printf("\n");
}

int main() {
    Room* hotel = createRoom(1);
    createGuest("John Doe", 1);
    createGuest("Jane Doe", 1);
    createGuest("Peter Pan", 2);
    printGuestsInRoom(hotel);

    return 0;
}