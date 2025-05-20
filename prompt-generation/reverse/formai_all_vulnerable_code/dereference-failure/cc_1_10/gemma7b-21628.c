//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

struct Guest {
    char name[20];
    int room_number;
    char status;
    struct Guest* next;
};

struct Room {
    int number;
    int capacity;
    struct Room* next;
};

struct Hotel {
    struct Room* rooms;
    struct Guest* guests;
    int num_rooms;
    int num_guests;
};

void insert_guest(struct Hotel* h, char* name, int room_number) {
    struct Guest* new_guest = (struct Guest*)malloc(sizeof(struct Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->status = 'O';
    new_guest->next = NULL;

    if (h->guests == NULL) {
        h->guests = new_guest;
    } else {
        struct Guest* temp = h->guests;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }

    h->num_guests++;
}

void insert_room(struct Hotel* h, int number, int capacity) {
    struct Room* new_room = (struct Room*)malloc(sizeof(struct Room));
    new_room->number = number;
    new_room->capacity = capacity;
    new_room->next = NULL;

    if (h->rooms == NULL) {
        h->rooms = new_room;
    } else {
        struct Room* temp = h->rooms;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_room;
    }

    h->num_rooms++;
}

int main() {
    struct Hotel* h = (struct Hotel*)malloc(sizeof(struct Hotel));
    h->rooms = NULL;
    h->guests = NULL;
    h->num_rooms = 0;
    h->num_guests = 0;

    insert_room(h, 101, 2);
    insert_room(h, 102, 2);
    insert_room(h, 103, 2);
    insert_guest(h, "John Doe", 101);
    insert_guest(h, "Jane Doe", 102);
    insert_guest(h, "Peter Pan", 103);

    printf("Number of rooms: %d\n", h->num_rooms);
    printf("Number of guests: %d\n", h->num_guests);

    return 0;
}