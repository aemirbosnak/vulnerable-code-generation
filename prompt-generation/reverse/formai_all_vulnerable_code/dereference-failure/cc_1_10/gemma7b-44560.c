//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Room {
    char name[50];
    int number;
    struct Room* next;
} Room;

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

Room* insertRoom(Room* head, char* name, int number) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->next = head;
    head = newRoom;
    return head;
}

Guest* insertGuest(Guest* head, char* name, int room_number) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_number = room_number;
    newGuest->next = head;
    head = newGuest;
    return head;
}

void printRooms(Room* head) {
    while (head) {
        printf("Room name: %s, Number: %d\n", head->name, head->number);
        head = head->next;
    }
}

void printGuests(Guest* head) {
    while (head) {
        printf("Guest name: %s, Room number: %d\n", head->name, head->room_number);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;
    Guest* guestHead = NULL;

    insertRoom(head, "Room A", 1);
    insertRoom(head, "Room B", 2);
    insertRoom(head, "Room C", 3);

    insertGuest(guestHead, "Guest 1", 1);
    insertGuest(guestHead, "Guest 2", 2);
    insertGuest(guestHead, "Guest 3", 3);

    printRooms(head);
    printGuests(guestHead);

    return 0;
}