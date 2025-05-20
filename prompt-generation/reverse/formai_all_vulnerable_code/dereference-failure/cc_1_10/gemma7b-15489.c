//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest *next;
} Guest;

typedef struct Room {
    int number;
    int occupancy;
    struct Room *next;
} Room;

Guest *insertGuest(Guest *head, char *name, int room_number) {
    Guest *newGuest = (Guest *)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_number = room_number;
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

Room *insertRoom(Room *head, int number, int occupancy) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }

    return head;
}

void printGuests(Guest *head) {
    Guest *temp = head;
    while (temp) {
        printf("%s, room number %d\n", temp->name, temp->room_number);
        temp = temp->next;
    }
}

void printRooms(Room *head) {
    Room *temp = head;
    while (temp) {
        printf("Room number %d, occupancy %d\n", temp->number, temp->occupancy);
        temp = temp->next;
    }
}

int main() {
    Guest *guests = NULL;
    Room *rooms = NULL;

    insertGuest(guests, "John Doe", 101);
    insertGuest(guests, "Jane Doe", 102);
    insertGuest(guests, "Peter Pan", 103);

    insertRoom(rooms, 101, 2);
    insertRoom(rooms, 102, 1);
    insertRoom(rooms, 103, 0);

    printGuests(guests);
    printRooms(rooms);

    return 0;
}