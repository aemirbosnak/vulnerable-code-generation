//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define ROOM_NUM 10
#define MAX_GUESTS 2

typedef struct Room {
    int room_num;
    int guests;
    char *name;
    struct Room *next;
} Room;

typedef struct Guest {
    char *name;
    int room_num;
    struct Guest *next;
} Guest;

Room *createRoom(int room_num, char *name, int guests) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    newRoom->room_num = room_num;
    newRoom->guests = guests;
    newRoom->name = name;
    newRoom->next = NULL;

    return newRoom;
}

Guest *createGuest(char *name, int room_num) {
    Guest *newGuest = (Guest *)malloc(sizeof(Guest));
    newGuest->name = name;
    newGuest->room_num = room_num;
    newGuest->next = NULL;

    return newGuest;
}

void checkIn(Guest *guest, Room *room) {
    guest->room_num = room->room_num;
    room->guests++;
    guest->next = createGuest(NULL, room->room_num);
}

void checkOut(Guest *guest, Room *room) {
    room->guests--;
    guest->next = NULL;
}

int main() {
    Room *head = NULL;
    Guest *headGuest = NULL;

    head = createRoom(1, "The Velvet Room", MAX_GUESTS);
    head = createRoom(2, "The Whispering Hall", MAX_GUESTS);
    head = createRoom(3, "The Clock Tower", MAX_GUESTS);

    headGuest = createGuest("Mr. Smith", 1);
    headGuest = createGuest("Ms. Jones", 2);

    checkOut(headGuest, head);
    checkOut(headGuest, head);

    printf("The hotel is full!\n");

    return 0;
}