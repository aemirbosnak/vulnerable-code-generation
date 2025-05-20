//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 5
#define ROOM_NUM 10

typedef struct Guest {
    char name[20];
    int room_num;
    struct Guest* next;
} Guest;

typedef struct Room {
    int number;
    Guest* guests;
    struct Room* next;
} Room;

Room* createRoom(int number);
Guest* createGuest(char* name, int room_num);

int main() {
    Room* hotel = createRoom(1);
    Guest* guest_list = createGuest("Mr. Gomez", 1);
    guest_list->next = createGuest("Ms. Jones", 2);
    guest_list->next->next = createGuest("Mr. Smith", 3);

    printf("Guests in hotel:");
    for (Guest* guest = guest_list; guest; guest = guest->next) {
        printf(" %s", guest->name);
    }

    printf("\nRooms in hotel:");
    for (Room* room = hotel; room; room = room->next) {
        printf(" Room %d: ", room->number);
        for (Guest* guest = room->guests; guest; guest = guest->next) {
            printf(" %s ", guest->name);
        }
    }

    return 0;
}

Room* createRoom(int number) {
    Room* room = malloc(sizeof(Room));
    room->number = number;
    room->guests = NULL;
    room->next = NULL;

    return room;
}

Guest* createGuest(char* name, int room_num) {
    Guest* guest = malloc(sizeof(Guest));
    strcpy(guest->name, name);
    guest->room_num = room_num;
    guest->next = NULL;

    return guest;
}