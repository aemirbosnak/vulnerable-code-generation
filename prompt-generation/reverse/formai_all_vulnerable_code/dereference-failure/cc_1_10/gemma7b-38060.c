//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUEST_ROOMS 10
#define MAX_GUEST_ROOMS_PER_FLOOR 5

typedef struct GuestRoom {
    int room_number;
    char status;
    char floor;
    struct GuestRoom* next;
} GuestRoom;

GuestRoom* createGuestRoom(int room_number, char status, char floor) {
    GuestRoom* newGuestRoom = (GuestRoom*)malloc(sizeof(GuestRoom));
    newGuestRoom->room_number = room_number;
    newGuestRoom->status = status;
    newGuestRoom->floor = floor;
    newGuestRoom->next = NULL;
    return newGuestRoom;
}

void insertGuestRoom(GuestRoom* head, GuestRoom* newGuestRoom) {
    if (head == NULL) {
        head = newGuestRoom;
    } else {
        newGuestRoom->next = head;
        head = newGuestRoom;
    }
}

void printGuestRooms(GuestRoom* head) {
    GuestRoom* currentGuestRoom = head;
    while (currentGuestRoom) {
        printf("Room number: %d, Status: %c, Floor: %c\n", currentGuestRoom->room_number, currentGuestRoom->status, currentGuestRoom->floor);
        currentGuestRoom = currentGuestRoom->next;
    }
}

int main() {
    GuestRoom* head = NULL;
    insertGuestRoom(head, createGuestRoom(101, 'A', 'A'));
    insertGuestRoom(head, createGuestRoom(102, 'B', 'A'));
    insertGuestRoom(head, createGuestRoom(103, 'C', 'A'));
    insertGuestRoom(head, createGuestRoom(104, 'D', 'A'));
    insertGuestRoom(head, createGuestRoom(105, 'E', 'A'));

    printGuestRooms(head);

    return 0;
}