//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    char status;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_no;
    int capacity;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head, char* name, int room_no, char status) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->status = status;
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

Room* insertRoom(Room* head, int room_no, int capacity) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    newRoom->capacity = capacity;
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

void printGuests(Guest* head) {
    Guest* temp = head;
    while (temp) {
        printf("%s, room no. %d, status: %c\n", temp->name, temp->room_no, temp->status);
        temp = temp->next;
    }
}

void printRooms(Room* head) {
    Room* temp = head;
    while (temp) {
        printf("room no. %d, capacity: %d\n", temp->room_no, temp->capacity);
        temp = temp->next;
    }
}

int main() {
    Guest* guests = NULL;
    Room* rooms = NULL;

    insertGuest(guests, "John Doe", 101, 'O');
    insertGuest(guests, "Jane Doe", 102, 'A');
    insertGuest(guests, "Peter Pan", 103, 'C');

    insertRoom(rooms, 101, 2);
    insertRoom(rooms, 102, 3);
    insertRoom(rooms, 103, 4);

    printGuests(guests);
    printRooms(rooms);

    return 0;
}