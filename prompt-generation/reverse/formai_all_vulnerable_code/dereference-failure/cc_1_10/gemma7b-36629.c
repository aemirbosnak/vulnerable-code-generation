//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    int num_days;
    struct Guest* next;
} Guest;

typedef struct Room {
    int no;
    int occupancy;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head, char* name, int room_no, int num_days) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->num_days = num_days;
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

Room* insertRoom(Room* head, int no, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->no = no;
    newRoom->occupancy = occupancy;
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
    Guest* guests = NULL;
    Room* rooms = NULL;

    // Insert some guests
    insertGuest(guests, "John Doe", 101, 3);
    insertGuest(guests, "Jane Doe", 102, 2);
    insertGuest(guests, "Peter Pan", 103, 4);

    // Insert some rooms
    insertRoom(rooms, 101, 2);
    insertRoom(rooms, 102, 1);
    insertRoom(rooms, 103, 3);

    // Print the guest list
    Guest* tempGuest = guests;
    while (tempGuest) {
        printf("Name: %s, Room No: %d, Number of Days: %d\n", tempGuest->name, tempGuest->room_no, tempGuest->num_days);
        tempGuest = tempGuest->next;
    }

    // Print the room list
    Room* tempRoom = rooms;
    while (tempRoom) {
        printf("No: %d, Occupancy: %d\n", tempRoom->no, tempRoom->occupancy);
        tempRoom = tempRoom->next;
    }

    return 0;
}