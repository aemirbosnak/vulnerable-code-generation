//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest *next;
} Guest;

typedef struct Room {
    int number;
    struct Room *next;
    Guest *guests;
} Room;

void insertGuest(Guest **head, char *name, int room_number) {
    Guest *newGuest = malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_number = room_number;
    newGuest->next = NULL;

    if (*head == NULL) {
        *head = newGuest;
    } else {
        (*head)->next = newGuest;
    }
}

void checkIn(Room **head, char *name, int room_number) {
    Room *newRoom = malloc(sizeof(Room));
    newRoom->number = room_number;
    newRoom->next = NULL;
    newRoom->guests = NULL;

    insertGuest(&newRoom->guests, name, room_number);

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

void checkOut(Room *room, char *name) {
    Guest *guest = room->guests;

    while (guest) {
        if (strcmp(guest->name, name) == 0) {
            guest = guest->next;
            free(room->guests);
            room->guests = guest;
            return;
        }
        guest = guest->next;
    }

    printf("Error: Guest not found.\n");
}

int main() {
    Guest *head = NULL;
    Room *rooms = NULL;

    char name[50];
    int room_number;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the room number: ");
    scanf("%d", &room_number);

    checkOut(rooms, name);

    return 0;
}