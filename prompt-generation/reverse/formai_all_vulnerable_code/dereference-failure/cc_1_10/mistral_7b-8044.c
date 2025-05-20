//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define MONSTERS 3

typedef struct room {
    char name[20];
    int monster;
    struct room *next;
} Room;

void createRooms(Room **start, char names[ROOMS][20]);
void addMonster(Room **start, int numMonsters);
void printRooms(Room *rooms);

int main() {
    Room *rooms = NULL;
    char names[ROOMS][20] = {"Bedroom", "Kitchen", "Bathroom", "Garage", "Living Room"};

    createRooms(&rooms, names);
    addMonster(&rooms, MONSTERS);
    printRooms(rooms);

    return 0;
}

void createRooms(Room **start, char names[ROOMS][20]) {
    Room *room, *current = NULL;

    for (int i = 0; i < ROOMS; i++) {
        room = (Room *)malloc(sizeof(Room));
        strcpy(room->name, names[i]);
        room->monster = 0;
        room->next = NULL;

        if (*start == NULL) {
            *start = room;
        } else {
            current->next = room;
        }

        current = room;
    }
}

void addMonster(Room **start, int numMonsters) {
    Room *room = *start;

    for (int i = 0; i < numMonsters; i++) {
        if (room->next == NULL) {
            room->next = (Room *)malloc(sizeof(Room));
            room->next->monster = 1;
            room->next->next = NULL;
            room = room->next;
        } else {
            room = room->next;
        }
    }
}

void printRooms(Room *rooms) {
    Room *room = rooms;

    printf("\nHaunted House Simulator\n\n");

    while (room != NULL) {
        printf("%s: ", room->name);

        if (room->monster == 1) {
            printf("Monster\n");
        } else {
            printf("Empty\n");
        }

        room = room->next;
    }
}