//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct room {
    char description[100];
    char *next;
} room;

room *create_room(char *description) {
    room *new_room = malloc(sizeof(room));
    strcpy(new_room->description, description);
    new_room->next = NULL;
    return new_room;
}

void add_room_to_list(room **list, room *new_room) {
    room *current = *list;
    if (*list == NULL) {
        *list = new_room;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_room;
}

void print_room_description(room *room) {
    printf("\n%s\n", room->description);
}

void explore_room(room **list, char *direction) {
    room *current = *list;
    while (current != NULL) {
        if (strcmp(current->description, "You are in a room with a door to the east.") == 0) {
            if (strcmp(direction, "east") == 0) {
                current = current->next;
                print_room_description(current);
                return;
            }
        }
        current = current->next;
    }
    printf("You can't go that way.\n");
}

int main() {
    room *room1 = create_room("You are in a room with a door to the east.");
    room *room2 = create_room("You are in a room with a door to the west and north.");
    room *room3 = create_room("You are in a dark room. There is nothing to see here.");

    add_room_to_list(&room1, room2);
    add_room_to_list(&room2, room3);

    char command[50];
    char direction[10];

    while (1) {
        printf("\n%s\n%s", room1->description, "> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        sscanf(command, "%s %s", command, direction);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        explore_room(&room1, direction);
    }

    return 0;
}