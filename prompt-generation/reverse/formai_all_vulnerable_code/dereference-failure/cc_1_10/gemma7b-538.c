//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 5

typedef struct Room {
    int number;
    char type;
    int available;
    struct Guest *guests;
} Room;

typedef struct Guest {
    char name[20];
    int room_number;
    struct Guest *next;
} Guest;

Room rooms[MAX_ROOMS];
Guest guests[MAX_GUESTS];

void init_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].number = i + 1;
        rooms[i].type = 'A';
        rooms[i].available = 1;
        rooms[i].guests = NULL;
    }
}

void init_guests() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_number = 0;
        guests[i].next = NULL;
    }
}

void book_room(char *name, int room_number) {
    Guest *new_guest = malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->next = NULL;

    Room *room = &rooms[room_number - 1];
    room->available = 0;
    room->guests = new_guest;
}

void list_guests() {
    for (Guest *guest = guests; guest; guest = guest->next) {
        printf("%s - Room %d\n", guest->name, guest->room_number);
    }
}

int main() {
    init_rooms();
    init_guests();

    book_room("John Doe", 10);
    book_room("Jane Doe", 12);
    book_room("Peter Pan", 14);

    list_guests();

    return 0;
}