//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int no;
    char type[50];
    struct Room* next;
    Guest* guests;
} Room;

Room* create_room(int no, char* type) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->no = no;
    strcpy(new_room->type, type);
    new_room->next = NULL;
    new_room->guests = NULL;
    return new_room;
}

Guest* create_guest(char* name, int room_no) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_no = room_no;
    new_guest->next = NULL;
    return new_guest;
}

void add_guest(Guest* guest, Room* room) {
    guest->next = room->guests;
    room->guests = guest;
}

void check_in(Guest* guest, Room* room) {
    add_guest(guest, room);
    printf("Welcome, %s, to room %d!\n", guest->name, room->no);
}

void check_out(Guest* guest) {
    guest->next = NULL;
    free(guest);
}

int main() {
    Room* hotel = create_room(1, "Standard");
    Room* suite = create_room(2, "Suite");

    Guest* guest1 = create_guest("John Doe", 1);
    Guest* guest2 = create_guest("Jane Doe", 2);

    check_in(guest1, hotel);
    check_in(guest2, suite);

    check_out(guest1);

    printf("Guests currently in the hotel:");
    for (Guest* guest = hotel->guests; guest; guest = guest->next) {
        printf(" %s", guest->name);
    }

    return 0;
}