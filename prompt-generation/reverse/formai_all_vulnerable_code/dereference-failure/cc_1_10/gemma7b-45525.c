//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Room {
    int number;
    char status;
    struct Room* next;
};

void check_room(struct Room* room) {
    if (room) {
        if (room->status == 'O') {
            printf("Room %d is occupied.\n", room->number);
        } else {
            printf("Room %d is available.\n", room->number);
        }
        check_room(room->next);
    }
}

int main() {
    struct Room* head = NULL;
    struct Room* tail = NULL;

    // Create some rooms
    struct Room* room1 = malloc(sizeof(struct Room));
    room1->number = 1;
    room1->status = 'A';
    room1->next = NULL;

    struct Room* room2 = malloc(sizeof(struct Room));
    room2->number = 2;
    room2->status = 'O';
    room2->next = NULL;

    struct Room* room3 = malloc(sizeof(struct Room));
    room3->number = 3;
    room3->status = 'A';
    room3->next = NULL;

    struct Room* room4 = malloc(sizeof(struct Room));
    room4->number = 4;
    room4->status = 'O';
    room4->next = NULL;

    // Connect rooms
    head = room1;
    tail = room4;

    // Check rooms
    check_room(head);

    return 0;
}