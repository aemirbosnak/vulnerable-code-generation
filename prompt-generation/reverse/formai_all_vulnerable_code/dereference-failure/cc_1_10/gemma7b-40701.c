//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HAUNTED_HOUSE_ROOMS 10

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Room* prev;
    int is_occupied;
    int haunted_level;
} Room;

Room* create_room(char* name, int haunted_level) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    new_room->prev = NULL;
    new_room->is_occupied = 0;
    new_room->haunted_level = haunted_level;
    return new_room;
}

void add_room(Room* current_room, char* name, int haunted_level) {
    Room* new_room = create_room(name, haunted_level);
    if (current_room->next) {
        current_room->next->prev = new_room;
    } else {
        current_room->next = new_room;
    }
    new_room->prev = current_room;
}

void traverse_haunted_house(Room* current_room) {
    printf("%s\n", current_room->name);
    if (current_room->next) {
        traverse_haunted_house(current_room->next);
    }
}

int main() {
    srand(time(NULL));

    Room* haunted_house = create_room("The Haunted Manor", 10);
    add_room(haunted_house, "The Bloody Dining Hall", 8);
    add_room(haunted_house, "The Twisted Staircase", 6);
    add_room(haunted_house, "The Spooky Library", 5);
    add_room(haunted_house, "The Haunted Ballroom", 7);

    traverse_haunted_house(haunted_house);

    return 0;
}