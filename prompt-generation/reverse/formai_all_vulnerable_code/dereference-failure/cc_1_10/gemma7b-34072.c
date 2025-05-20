//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_ROOMS 10
#define MAX_GUEST_ROOMS_PER_FLOOR 20

typedef struct GuestRoom {
    int room_number;
    char floor;
    int available;
    struct GuestRoom* next;
} GuestRoom;

GuestRoom* createGuestRoom(int room_number, char floor, int available) {
    GuestRoom* new_room = (GuestRoom*)malloc(sizeof(GuestRoom));
    new_room->room_number = room_number;
    new_room->floor = floor;
    new_room->available = available;
    new_room->next = NULL;
    return new_room;
}

void insertGuestRoom(GuestRoom* head, GuestRoom* new_room) {
    if (head == NULL) {
        head = new_room;
    } else {
        new_room->next = head;
        head = new_room;
    }
}

GuestRoom* searchGuestRoom(GuestRoom* head, int room_number) {
    GuestRoom* current_room = head;
    while (current_room) {
        if (current_room->room_number == room_number) {
            return current_room;
        }
        current_room = current_room->next;
    }
    return NULL;
}

int main() {
    GuestRoom* head = NULL;
    insertGuestRoom(head, createGuestRoom(101, 'A', 1));
    insertGuestRoom(head, createGuestRoom(102, 'A', 1));
    insertGuestRoom(head, createGuestRoom(103, 'A', 0));
    insertGuestRoom(head, createGuestRoom(104, 'B', 1));
    insertGuestRoom(head, createGuestRoom(105, 'B', 0));

    GuestRoom* found_room = searchGuestRoom(head, 102);
    if (found_room) {
        printf("Room number: %d, Floor: %c, Available: %d\n", found_room->room_number, found_room->floor, found_room->available);
    } else {
        printf("Room not found.\n");
    }

    return 0;
}