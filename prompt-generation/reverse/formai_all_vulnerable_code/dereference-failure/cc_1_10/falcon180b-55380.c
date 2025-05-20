//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define LINES_PER_ROOM 5
#define SCARE_CHANCE 2
#define MAX_SCARES 3

typedef struct {
    char *description;
    int is_scary;
} Room;

void generate_room(Room *room) {
    room->description = malloc(LINES_PER_ROOM * sizeof(char*));

    int i;
    for (i = 0; i < LINES_PER_ROOM; i++) {
        char *line = malloc(50 * sizeof(char));
        sprintf(line, "You are in a %s room. ", (i % 2 == 0)? "spooky" : "creepy");
        room->description[i] = line;
    }

    room->is_scary = rand() % SCARE_CHANCE == 0;
}

int main() {
    srand(time(NULL));

    Room rooms[ROOMS];

    int i;
    for (i = 0; i < ROOMS; i++) {
        generate_room(&rooms[i]);
    }

    int current_room = 0;
    int scares = 0;

    while (scares < MAX_SCARES && current_room < ROOMS) {
        printf("You enter room %d:\n", current_room + 1);

        int j;
        for (j = 0; j < LINES_PER_ROOM; j++) {
            printf("%s\n", rooms[current_room].description[j]);
        }

        if (rooms[current_room].is_scary) {
            scares++;
        }

        current_room++;
    }

    return 0;
}