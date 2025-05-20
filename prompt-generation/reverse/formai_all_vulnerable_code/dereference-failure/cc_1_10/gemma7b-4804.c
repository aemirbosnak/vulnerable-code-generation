//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_ROOMS 10

typedef struct GuestRoom {
    int room_number;
    char guest_name[50];
    char room_type;
    int number_of_guests;
    struct GuestRoom* next;
} GuestRoom;

GuestRoom* insertGuestRoom(GuestRoom* head, int room_number, char guest_name[], char room_type, int number_of_guests) {
    GuestRoom* new_room = (GuestRoom*)malloc(sizeof(GuestRoom));
    new_room->room_number = room_number;
    strcpy(new_room->guest_name, guest_name);
    new_room->room_type = room_type;
    new_room->number_of_guests = number_of_guests;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

void printGuestRooms(GuestRoom* head) {
    GuestRoom* current_room = head;
    while (current_room) {
        printf("Room Number: %d\n", current_room->room_number);
        printf("Guest Name: %s\n", current_room->guest_name);
        printf("Room Type: %c\n", current_room->room_type);
        printf("Number of Guests: %d\n", current_room->number_of_guests);
        printf("\n");
        current_room = current_room->next;
    }
}

int main() {
    GuestRoom* head = NULL;

    insertGuestRoom(head, 101, "John Doe", 'A', 2);
    insertGuestRoom(head, 102, "Jane Doe", 'B', 1);
    insertGuestRoom(head, 103, "Peter Pan", 'A', 3);

    printGuestRooms(head);

    return 0;
}