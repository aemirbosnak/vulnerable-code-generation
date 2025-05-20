//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 5

typedef struct room {
    char name[20];
    int description;
    struct room *next;
} room;

room *create_room(char *name, int description) {
    room *new_room = (room *)malloc(sizeof(room));
    strcpy(new_room->name, name);
    new_room->description = description;
    new_room->next = NULL;
    return new_room;
}

void play_game(room *current_room) {
    printf("%s\n", current_room->name);
    printf("%d\n", current_room->description);
    printf("What do you want to do? ");

    char command[20];
    scanf("%s", command);

    if (strcmp(command, "go") == 0) {
        char direction[20];
        scanf("%s", direction);

        if (direction[0] == 'n') {
            current_room = current_room->next;
        }
    }
    play_game(current_room);
}

int main() {
    room *start_room = create_room("The Hallway", 0);
    room *second_room = create_room("The Kitchen", 1);
    room *third_room = create_room("The Bedroom", 2);

    start_room->next = second_room;
    second_room->next = third_room;

    play_game(start_room);

    return 0;
}