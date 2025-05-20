//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define TRUE 1
#define FALSE 0

typedef struct room {
    int id;
    char *name;
    int is_haunted;
    struct room *next;
} room;

room *rooms = NULL;

void add_room(int id, char *name, int is_haunted) {
    room *new_room = (room *) malloc(sizeof(room));
    new_room->id = id;
    new_room->name = strdup(name);
    new_room->is_haunted = is_haunted;
    new_room->next = rooms;
    rooms = new_room;
}

void print_room(room *room) {
    printf("Room %d: %s\n", room->id, room->name);
    if (room->is_haunted)
        printf("It's haunted!\n");
    else
        printf("It's not haunted.\n");
}

void explore_room(room *room) {
    if (room->is_haunted) {
        printf("You hear a strange noise.\n");
        sleep(1);
        printf("Suddenly, the room goes dark!\n");
        sleep(2);
        printf("You feel a cold breath on your neck.\n");
        sleep(3);
        printf("A ghost appears in front of you!\n");
        sleep(5);
        printf("You have been scared to death!\n");
        exit(EXIT_FAILURE);
    }
    printf("You explore the room and find nothing.\n");
    room = room->next;
    explore_room(room);
}

int main() {
    int i;
    srand(time(NULL));

    add_room(1, "Living Room", FALSE);
    add_room(2, "Kitchen", FALSE);
    add_room(3, "Bedroom", TRUE);
    add_room(4, "Bathroom", FALSE);
    add_room(5, "Library", FALSE);
    add_room(6, "Garage", FALSE);
    add_room(7, "Attic", TRUE);
    add_room(8, "Basement", TRUE);
    add_room(9, "Dining Room", FALSE);
    add_room(10, "Study", FALSE);

    room *current_room = rooms;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are in Room %d: %s\n", current_room->id, current_room->name);

    while (current_room != NULL) {
        print_room(current_room);
        if (current_room->is_haunted)
            explore_room(current_room);
        current_room = current_room->next;
    }

    return EXIT_SUCCESS;
}