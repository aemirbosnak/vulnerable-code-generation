//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct room {
    char name[20];
    struct room* next;
} room;

void create_room(room** head, char* name) {
    room* new_room = malloc(sizeof(room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    *head = new_room;
}

int main() {
    room* head = NULL;
    create_room(&head, "The Hallway");
    create_room(&head, "The Kitchen");
    create_room(&head, "The Bedroom");

    printf("You are in the %s.\n", head->name);

    // Prompt the user to enter a command
    char command[20];
    printf("Enter a command: ");
    scanf("%s", command);

    // Check if the command is valid
    if (strcmp(command, "go") == 0) {
        // Get the direction the user wants to go
        char direction[20];
        printf("Enter the direction you want to go: ");
        scanf("%s", direction);

        // Check if the direction is valid
        if (strcmp(direction, "north") == 0) {
            // The user goes north
            if (head->next) {
                head = head->next;
                printf("You are now in the %s.\n", head->name);
            } else {
                printf("There is no room to the north.\n");
            }
        } else if (strcmp(direction, "south") == 0) {
            // The user goes south
            if (head->next->next) {
                head = head->next->next;
                printf("You are now in the %s.\n", head->name);
            } else {
                printf("There is no room to the south.\n");
            }
        } else {
            printf("Invalid direction.\n");
        }
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}