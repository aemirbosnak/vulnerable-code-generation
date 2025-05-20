//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_NAME_LENGTH 20
#define MAX_ROOM_NUMBER 10

typedef struct Guest {
    char name[MAX_GUEST_NAME_LENGTH];
    int roomNumber;
    struct Guest* next;
} Guest;

typedef struct Room {
    int number;
    struct Room* next;
} Room;

Guest* createGuest(char* name, int roomNumber) {
    Guest* newGuest = malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->roomNumber = roomNumber;
    newGuest->next = NULL;
    return newGuest;
}

Room* createRoom(int number) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->next = NULL;
    return newRoom;
}

void insertGuest(Guest* guest, Guest* tail) {
    if (tail) {
        tail->next = guest;
        tail = guest;
    } else {
        tail = guest;
    }
}

void insertRoom(Room* room, Room* tail) {
    if (tail) {
        tail->next = room;
        tail = room;
    } else {
        tail = room;
    }
}

void printGuests(Guest* head) {
    Guest* currentGuest = head;
    while (currentGuest) {
        printf("%s - Room No. %d\n", currentGuest->name, currentGuest->roomNumber);
        currentGuest = currentGuest->next;
    }
}

void printRooms(Room* head) {
    Room* currentRoom = head;
    while (currentRoom) {
        printf("Room No. %d\n", currentRoom->number);
        currentRoom = currentRoom->next;
    }
}

int main() {
    Guest* headGuest = NULL;
    Guest* tailGuest = NULL;

    Room* headRoom = NULL;
    Room* tailRoom = NULL;

    // Create some guests
    createGuest("John Doe", 1);
    createGuest("Jane Doe", 2);
    createGuest("Peter Pan", 3);

    // Create some rooms
    createRoom(1);
    createRoom(2);
    createRoom(3);

    // Insert guests into the hotel
    insertGuest(headGuest, tailGuest);
    insertGuest(headGuest, tailGuest);
    insertGuest(headGuest, tailGuest);

    // Insert rooms into the hotel
    insertRoom(headRoom, tailRoom);
    insertRoom(headRoom, tailRoom);
    insertRoom(headRoom, tailRoom);

    // Print the guests
    printGuests(headGuest);

    // Print the rooms
    printRooms(headRoom);

    return 0;
}