//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int no;
    char type[20];
    struct Room* next;
    Guest* guests;
} Room;

Room* createRoom(int no, char* type) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->no = no;
    strcpy(newRoom->type, type);
    newRoom->next = NULL;
    newRoom->guests = NULL;
    return newRoom;
}

Guest* createGuest(char* name, int roomNo) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = roomNo;
    newGuest->next = NULL;
    return newGuest;
}

int main() {
    Room* rooms = createRoom(1, "Standard");
    rooms = createRoom(2, "Suite");
    rooms = createRoom(3, "Family");

    Guest* guests = createGuest("John Doe", 1);
    guests = createGuest("Jane Doe", 2);
    guests = createGuest("Peter Pan", 3);

    // Print room information
    for (Room* room = rooms; room; room = room->next) {
        printf("Room No: %d, Type: %s\n", room->no, room->type);
    }

    // Print guest information
    for (Guest* guest = guests; guest; guest = guest->next) {
        printf("Name: %s, Room No: %d\n", guest->name, guest->room_no);
    }

    return 0;
}