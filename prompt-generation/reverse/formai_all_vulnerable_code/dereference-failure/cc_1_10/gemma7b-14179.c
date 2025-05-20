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
    int room_no;
    char type[50];
    int available;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head, char* name, int room_no) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

Room* insertRoom(Room* head, int room_no, char* type, int available) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    strcpy(newRoom->type, type);
    newRoom->available = available;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }

    return head;
}

int main() {

    Guest* headGuest = NULL;
    Room* headRoom = NULL;

    insertGuest(headGuest, "John Doe", 101);
    insertGuest(headGuest, "Jane Doe", 102);
    insertGuest(headGuest, "Peter Pan", 103);

    insertRoom(headRoom, 101, "Standard", 1);
    insertRoom(headRoom, 102, "Suite", 0);
    insertRoom(headRoom, 103, "Family", 2);

    Guest* currentGuest = headGuest;
    while (currentGuest) {
        printf("Name: %s, Room No: %d\n", currentGuest->name, currentGuest->room_no);
        currentGuest = currentGuest->next;
    }

    Room* currentRoom = headRoom;
    while (currentRoom) {
        printf("Room No: %d, Type: %s, Available: %d\n", currentRoom->room_no, currentRoom->type, currentRoom->available);
        currentRoom = currentRoom->next;
    }

    return 0;
}