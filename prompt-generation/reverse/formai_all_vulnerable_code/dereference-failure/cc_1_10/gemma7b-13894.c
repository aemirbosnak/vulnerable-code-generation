//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Room {
    int room_no;
    char status;
    int capacity;
    struct Room* next;
} Room;

typedef struct Guest {
    char name[20];
    int room_no;
    struct Guest* next;
} Guest;

Room* insertRoom(Room* head, int room_no, int capacity) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_no = room_no;
    new_room->status = 'O';
    new_room->capacity = capacity;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        Room* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_room;
    }

    return head;
}

Guest* insertGuest(Guest* head, char name, int room_no) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_no = room_no;
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }

    return head;
}

void displayRooms(Room* head) {
    while (head) {
        printf("Room No: %d, Capacity: %d, Status: %c\n", head->room_no, head->capacity, head->status);
        head = head->next;
    }
}

void displayGuests(Guest* head) {
    while (head) {
        printf("Name: %s, Room No: %d\n", head->name, head->room_no);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;
    Guest* headG = NULL;

    insertRoom(head, 101, 2);
    insertRoom(head, 102, 3);
    insertRoom(head, 103, 4);

    insertGuest(headG, "John Doe", 101);
    insertGuest(headG, "Jane Doe", 102);
    insertGuest(headG, "Peter Pan", 103);

    displayRooms(head);
    displayGuests(headG);

    return 0;
}