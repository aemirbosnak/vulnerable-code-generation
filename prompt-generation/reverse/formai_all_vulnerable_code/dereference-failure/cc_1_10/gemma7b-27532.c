//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 50

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

Guest* create_guest(char* name, int room_number) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->next = NULL;
    return new_guest;
}

Room* create_room(int number, char status) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->number = number;
    new_room->status = status;
    new_room->next = NULL;
    return new_room;
}

int main() {

    Guest* head_guest = NULL;
    Room* head_room = NULL;

    // Create a few guests
    Guest* guest1 = create_guest("John Doe", 1);
    Guest* guest2 = create_guest("Jane Doe", 2);
    Guest* guest3 = create_guest("Jack Sparrow", 3);

    // Create a few rooms
    Room* room1 = create_room(1, 'O');
    Room* room2 = create_room(2, 'A');
    Room* room3 = create_room(3, 'F');

    // Assign guests to rooms
    guest1->room_number = room1->number;
    guest2->room_number = room2->number;
    guest3->room_number = room3->number;

    // Print the guest list
    Guest* current_guest = head_guest;
    while (current_guest) {
        printf("Name: %s, Room Number: %d\n", current_guest->name, current_guest->room_number);
        current_guest = current_guest->next;
    }

    // Print the room list
    Room* current_room = head_room;
    while (current_room) {
        printf("Number: %d, Status: %c\n", current_room->number, current_room->status);
        current_room = current_room->next;
    }

    return 0;
}