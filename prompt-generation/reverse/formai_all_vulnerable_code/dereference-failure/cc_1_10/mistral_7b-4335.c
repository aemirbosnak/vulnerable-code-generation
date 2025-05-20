//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define HAUNTED_HOUSE_SIZE 10
#define GHOST_SPEED 3

struct room {
    int haunted_level;
    struct room *next;
};

struct ghost {
    struct room *current_room;
    struct ghost *next;
};

struct room *house = NULL;
struct ghost *ghosts = NULL;

void print_house() {
    struct room *room = house;
    printf("\n");
    while (room != NULL) {
        printf("Room %d: ", room->haunted_level);
        if (room->haunted_level > 0) {
            printf("Haunted!\n");
        } else {
            printf("Safe!\n");
        }
        room = room->next;
    }
    printf("\n");
}

void haunt_room(int room_index) {
    if (room_index < 0 || room_index >= HAUNTED_HOUSE_SIZE) {
        printf("Invalid room index!\n");
        return;
    }

    struct room *room = house;
    while (room != NULL && room_index != room->haunted_level) {
        room = room->next;
    }

    if (room == NULL) {
        room = (struct room *) malloc(sizeof(struct room));
        room->haunted_level = room_index;
        room->next = house;
        house = room;
    } else {
        room->haunted_level++;
    }
}

void move_ghosts() {
    struct ghost *ghost = ghosts;
    while (ghost != NULL) {
        struct room *room = ghost->current_room;
        if (room->haunted_level > 0) {
            room->haunted_level--;
            if (room->haunted_level == 0) {
                room->next->haunted_level++;
                ghost->current_room = room->next;
            }
        }
        ghost = ghost->next;
        usleep(GHOST_SPEED * 1000000);
    }
}

void spawn_ghost() {
    if (ghosts == NULL) {
        ghosts = (struct ghost *) malloc(sizeof(struct ghost));
        ghosts->current_room = house;
        ghosts->next = NULL;
    } else {
        struct ghost *current_ghost = ghosts;
        while (current_ghost->next != NULL) {
            current_ghost = current_ghost->next;
        }
        current_ghost->next = (struct ghost *) malloc(sizeof(struct ghost));
        current_ghost->next->current_room = house;
        current_ghost->next->next = NULL;
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < HAUNTED_HOUSE_SIZE; i++) {
        haunt_room(i);
    }

    for (int i = 0; i < 10; i++) {
        spawn_ghost();
    }

    while (1) {
        print_house();
        move_ghosts();
    }

    return 0;
}