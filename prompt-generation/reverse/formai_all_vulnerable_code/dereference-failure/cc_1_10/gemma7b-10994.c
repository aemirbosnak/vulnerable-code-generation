//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_num;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_num;
    int num_guests;
    Guest** guests;
} Room;

Room** create_room(int room_num) {
    Room** room = malloc(sizeof(Room));
    (*room)->room_num = room_num;
    (*room)->num_guests = 0;
    (*room)->guests = NULL;
    return room;
}

Guest* create_guest(char* name, int room_num) {
    Guest* guest = malloc(sizeof(Guest));
    strcpy(guest->name, name);
    guest->room_num = room_num;
    guest->next = NULL;
    return guest;
}

void add_guest(Room* room, Guest* guest) {
    room->num_guests++;
    guest->next = room->guests;
    room->guests = guest;
}

void check_in(Guest* guest) {
    printf("Welcome, %s! You have been assigned to room %d.\n", guest->name, guest->room_num);
}

void check_out(Guest* guest) {
    printf("Goodbye, %s. Have a nice day.\n", guest->name);
}

int main() {
    Guest* head = NULL;
    Room** rooms = create_room(1);
    add_guest(rooms[0], create_guest("John Doe", 1));
    add_guest(rooms[0], create_guest("Jane Doe", 1));
    check_in(head);
    check_out(head);
    return 0;
}