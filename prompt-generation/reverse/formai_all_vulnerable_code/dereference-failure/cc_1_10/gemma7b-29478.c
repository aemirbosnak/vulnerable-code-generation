//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 2

typedef struct Room {
    int number;
    char status;
    int guests;
    struct Room* next;
} Room;

typedef struct Guest {
    char name[20];
    int room_number;
    struct Guest* next;
} Guest;

Room* createRoom(int number) {
    Room* room = (Room*)malloc(sizeof(Room));
    room->number = number;
    room->status = 'O';
    room->guests = 0;
    room->next = NULL;
    return room;
}

Guest* createGuest(char name, int room_number) {
    Guest* guest = (Guest*)malloc(sizeof(Guest));
    strcpy(guest->name, name);
    guest->room_number = room_number;
    guest->next = NULL;
    return guest;
}

void addGuest(Room* room, Guest* guest) {
    room->guests++;
    room->next = guest;
    guest->next = NULL;
}

void checkIn(Room* room, Guest* guest) {
    room->status = 'C';
    addGuest(room, guest);
}

void checkOut(Room* room, Guest* guest) {
    room->status = 'O';
    room->guests--;
    free(guest);
}

int main() {
    Room* head = createRoom(1);
    Guest* guest1 = createGuest("John Doe", 1);
    Guest* guest2 = createGuest("Jane Doe", 1);
    checkOut(head, guest1);
    checkOut(head, guest2);
    return 0;
}