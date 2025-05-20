//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *description;
    char *next;
} node;

node *start = NULL, *current = NULL;

void add_node(char *desc, char *next) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->description = strdup(desc);
    new_node->next = strdup(next);

    if (!start) {
        start = new_node;
        current = start;
    } else {
        current->next = new_node;
        current = new_node;
    }
}

void print_intro() {
    printf("\n---------------------------------\n");
    printf("|     Welcome to the Dungeon!    |\n");
    printf("|             Find the key!      |\n");
    printf("---------------------------------\n\n");
}

void print_current_room() {
    node *room = current;

    printf("\n%s\n", room->description);

    if (room->next) {
        printf("You see exits to the %s and %s.\n", room->next[0], room->next[1]);
    }
}

void go_north(char *room_name) {
    node *room = start;

    while (room) {
        if (strcmp(room->description, room_name) == 0) {
            current = room;
            break;
        }
        room = room->next;
    }
}

int main() {
    print_intro();

    add_node("You are in a dark and damp room. There is a north exit.", "north chamber");
    add_node("This is the north chamber. There is a key here! You found it! Congratulations!", "end");

    go_north("dark and damp room");

    print_current_room();

    while (strcmp(current->description, "end") != 0) {
        char cmd[10];
        printf("> ");
        scanf("%s", cmd);

        if (strcmp(cmd, "go") == 0) {
            char direction[5];
            scanf("%s", direction);

            if (strcmp(current->next, "") != 0) {
                if (strcmp(direction, current->next[0]) == 0) {
                    go_north(current->next);
                    print_current_room();
                } else {
                    printf("There is no exit in that direction.\n");
                }
            } else {
                printf("There is no exit in this room.\n");
            }
        }
    }

    printf("\nCongratulations! You found the key!\n");

    return 0;
}