//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 10

typedef struct {
    int number;
    int is_haunted;
    struct Room *next;
} Room;

Room *rooms = NULL;

void create_rooms(int count) {
    int i;
    if (count == 0) {
        return;
    }

    Room *new_room = (Room *) malloc(sizeof(Room));
    new_room->number = count;
    new_room->is_haunted = rand() % 2;
    new_room->next = NULL;

    rooms = (Room *) malloc(sizeof(Room));
    rooms->number = 0;
    rooms->is_haunted = 0;
    rooms->next = new_room;

    create_rooms(count - 1);
}

void explore_room(Room *room) {
    if (room == NULL) {
        printf("You have explored all rooms.\n");
        return;
    }

    printf("You are in room %d.\n", room->number);

    if (room->is_haunted) {
        printf("A ghost appeared!\n");
        explore_room(room->next);
    } else {
        printf("The room is empty.\n");
        explore_room(room->next);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");

    create_rooms(ROOM_COUNT);

    Room *current_room = rooms;

    printf("You are in room %d.\n", current_room->number);

    explore_room(current_room->next);

    free(rooms);

    return 0;
}