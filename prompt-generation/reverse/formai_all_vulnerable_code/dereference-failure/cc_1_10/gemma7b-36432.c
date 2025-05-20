//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10
#define ROOM_TYPE_REGULAR 1
#define ROOM_TYPE_FAMILY 2
#define ROOM_TYPE_EXECUTIVE 3

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_number;
    int room_type;
    Guest* guests;
    struct Room* next;
} Room;

Room* createRoom(int room_number, int room_type, Guest* guests) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_number = room_number;
    newRoom->room_type = room_type;
    newRoom->guests = guests;
    newRoom->next = NULL;
    return newRoom;
}

void addGuest(Guest* guests, char* name, int room_number) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_number = room_number;
    newGuest->next = NULL;

    if (guests == NULL) {
        guests = newGuest;
    } else {
        guests->next = newGuest;
        guests = newGuest;
    }
}

void printGuests(Room* room) {
    Guest* guests = room->guests;
    while (guests) {
        printf("%s, ", guests->name);
        guests = guests->next;
    }
    printf("\n");
}

int main() {
    Room* hotel = NULL;
    Guest* guests = NULL;

    hotel = createRoom(101, ROOM_TYPE_REGULAR, guests);
    addGuest(guests, "John Doe", 101);
    addGuest(guests, "Jane Doe", 101);

    hotel = createRoom(102, ROOM_TYPE_FAMILY, guests);
    addGuest(guests, "Peter Pan", 102);
    addGuest(guests, "Wendy Darling", 102);

    hotel = createRoom(103, ROOM_TYPE_EXECUTIVE, guests);
    addGuest(guests, "Mr. Burns", 103);

    printGuests(hotel);

    return 0;
}