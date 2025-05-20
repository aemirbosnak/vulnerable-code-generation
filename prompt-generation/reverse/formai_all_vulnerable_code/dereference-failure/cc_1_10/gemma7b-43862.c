//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
};

struct Room {
    int no;
    struct Guest* guests;
    struct Room* next;
};

void insert_guest(struct Guest** head, char* name, int room_no) {
    struct Guest* new_guest = (struct Guest*)malloc(sizeof(struct Guest));
    strcpy(new_guest->name, name);
    new_guest->room_no = room_no;
    new_guest->next = NULL;

    if (*head == NULL) {
        *head = new_guest;
    } else {
        (*head)->next = new_guest;
    }
}

void insert_room(struct Room** head, int no) {
    struct Room* new_room = (struct Room*)malloc(sizeof(struct Room));
    new_room->no = no;
    new_room->guests = NULL;
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

int main() {
    struct Guest* guests = NULL;
    struct Room* rooms = NULL;

    insert_guest(&guests, "John Doe", 101);
    insert_guest(&guests, "Jane Doe", 102);
    insert_guest(&guests, "Peter Pan", 103);

    insert_room(&rooms, 101);
    insert_room(&rooms, 102);
    insert_room(&rooms, 103);

    printf("Guests:");
    struct Guest* current_guest = guests;
    while (current_guest) {
        printf(" %s", current_guest->name);
        current_guest = current_guest->next;
    }

    printf("\nRooms:");
    struct Room* current_room = rooms;
    while (current_room) {
        printf(" %d", current_room->no);
        current_room = current_room->next;
    }

    return 0;
}