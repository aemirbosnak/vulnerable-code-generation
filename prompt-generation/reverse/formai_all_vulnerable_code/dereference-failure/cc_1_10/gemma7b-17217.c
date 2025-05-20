//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[20];
    int room_num;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_num;
    int occupancy;
    struct Room* next;
} Room;

Guest* insert_guest(Guest* head, char* name, int room_num) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_num = room_num;
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        head->next = new_guest;
    }

    return head;
}

Room* insert_room(Room* head, int room_num, int occupancy) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_num = room_num;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

int main() {
    Guest* guests = NULL;
    Room* rooms = NULL;

    // Insert some sample guests
    insert_guest(guests, "John Doe", 1);
    insert_guest(guests, "Jane Doe", 2);
    insert_guest(guests, "Peter Pan", 3);

    // Insert some sample rooms
    insert_room(rooms, 1, 2);
    insert_room(rooms, 2, 1);
    insert_room(rooms, 3, 0);

    // Print the list of guests
    Guest* current_guest = guests;
    while (current_guest) {
        printf("Name: %s, Room Number: %d\n", current_guest->name, current_guest->room_num);
        current_guest = current_guest->next;
    }

    // Print the list of rooms
    Room* current_room = rooms;
    while (current_room) {
        printf("Room Number: %d, Occupancy: %d\n", current_room->room_num, current_room->occupancy);
        current_room = current_room->next;
    }

    return 0;
}