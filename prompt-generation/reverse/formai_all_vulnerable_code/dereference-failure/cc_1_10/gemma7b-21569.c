//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_num;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_num;
    int occupancy;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head, char* name, int room_num) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_num = room_num;
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

Room* insertRoom(Room* head, int room_num, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_num = room_num;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }

    return head;
}

int main() {
    Guest* guests = NULL;
    Room* rooms = NULL;

    insertGuest(guests, "John Doe", 1);
    insertGuest(guests, "Jane Doe", 2);
    insertGuest(guests, "Jack Doe", 3);

    insertRoom(rooms, 1, 2);
    insertRoom(rooms, 2, 1);
    insertRoom(rooms, 3, 0);

    // Print guests and rooms
    for (Guest* guest = guests; guest != NULL; guest = guest->next) {
        printf("Guest: %s, Room: %d\n", guest->name, guest->room_num);
    }

    for (Room* room = rooms; room != NULL; room = room->next) {
        printf("Room: %d, Occupancy: %d\n", room->room_num, room->occupancy);
    }

    return 0;
}