//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

typedef struct Room {
    int number;
    char status;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head, char* name, int room_number) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_number = room_number;
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

Room* insertRoom(Room* head, int number, char status) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->status = status;
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

    insertGuest(guests, "Donald Knuth", 1);
    insertGuest(guests, "John Doe", 2);
    insertGuest(guests, "Alice Smith", 3);

    insertRoom(rooms, 1, 'O');
    insertRoom(rooms, 2, 'C');
    insertRoom(rooms, 3, 'A');

    printf("Guests:");
    for (Guest* temp = guests; temp != NULL; temp = temp->next) {
        printf("\n%s", temp->name);
    }

    printf("\nRooms:");
    for (Room* temp = rooms; temp != NULL; temp = temp->next) {
        printf("\n%d, %c", temp->number, temp->status);
    }

    return 0;
}