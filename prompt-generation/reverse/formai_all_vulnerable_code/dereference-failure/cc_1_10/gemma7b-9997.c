//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

struct Guest {
    char name[50];
    int room_no;
    char status;
    struct Guest* next;
};

struct Room {
    int no;
    struct Guest* guests;
    struct Room* next;
};

struct Receptionist {
    struct Guest* head_guest;
    struct Room* head_room;
    struct Receptionist* next;
};

int main() {
    struct Receptionist* receptionist = (struct Receptionist*)malloc(sizeof(struct Receptionist));
    receptionist->head_guest = NULL;
    receptionist->head_room = NULL;

    // Create some guests
    struct Guest* guest1 = (struct Guest*)malloc(sizeof(struct Guest));
    strcpy(guest1->name, "John Doe");
    guest1->room_no = 101;
    guest1->status = 'O';

    struct Guest* guest2 = (struct Guest*)malloc(sizeof(struct Guest));
    strcpy(guest2->name, "Jane Doe");
    guest2->room_no = 102;
    guest2->status = 'C';

    struct Guest* guest3 = (struct Guest*)malloc(sizeof(struct Guest));
    strcpy(guest3->name, "Peter Pan");
    guest3->room_no = 103;
    guest3->status = 'R';

    // Create some rooms
    struct Room* room1 = (struct Room*)malloc(sizeof(struct Room));
    room1->no = 101;
    room1->guests = guest1;

    struct Room* room2 = (struct Room*)malloc(sizeof(struct Room));
    room2->no = 102;
    room2->guests = guest2;

    struct Room* room3 = (struct Room*)malloc(sizeof(struct Room));
    room3->no = 103;
    room3->guests = guest3;

    // Link the rooms and guests
    room1->next = room2;
    room2->next = room3;
    guest1->next = guest2;
    guest2->next = guest3;

    // Print the guest list
    struct Guest* current_guest = receptionist->head_guest;
    while (current_guest) {
        printf("Name: %s, Room No: %d, Status: %c\n", current_guest->name, current_guest->room_no, current_guest->status);
        current_guest = current_guest->next;
    }

    return 0;
}