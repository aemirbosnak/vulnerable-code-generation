//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[20];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int no;
    Guest* guests;
    struct Room* next;
} Room;

Room* createRoom(int no) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->no = no;
    newRoom->guests = NULL;
    newRoom->next = NULL;
    return newRoom;
}

Guest* createGuest(char* name, int roomNo) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = roomNo;
    newGuest->next = NULL;
    return newGuest;
}

void addGuestToRoom(Room* room, Guest* guest) {
    Guest* tempGuest = room->guests;
    if (tempGuest == NULL) {
        room->guests = guest;
    } else {
        while (tempGuest->next) {
            tempGuest = tempGuest->next;
        }
        tempGuest->next = guest;
    }
}

int findGuestRoomNo(Guest* guest) {
    return guest->room_no;
}

void printGuestsInRoom(Room* room) {
    Guest* tempGuest = room->guests;
    while (tempGuest) {
        printf("%s ", tempGuest->name);
    }
    printf("\n");
}

int main() {
    Room* hotel = createRoom(1);
    Guest* guest1 = createGuest("John Doe", 1);
    addGuestToRoom(hotel, guest1);

    Room* room2 = createRoom(2);
    Guest* guest2 = createGuest("Mary Smith", 2);
    addGuestToRoom(room2, guest2);

    printGuestsInRoom(room2);

    int roomNo = findGuestRoomNo(guest1);
    printf("Room no of guest1: %d\n", roomNo);

    return 0;
}