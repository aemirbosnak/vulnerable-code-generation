//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int has_key;
    int has_door;
} Room;

Room* create_room(char* name, int has_key, int has_door) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    new_room->has_key = has_key;
    new_room->has_door = has_door;
    return new_room;
}

void play_game() {
    Room* current_room = create_room("The Hallway", 0, 1);
    Room* second_room = create_room("The Kitchen", 1, 0);
    Room* third_room = create_room("The Bedroom", 0, 0);
    Room* fourth_room = create_room("The Library", 1, 1);
    Room* fifth_room = create_room("The Treasure Room", 0, 0);

    current_room->next = second_room;
    second_room->next = third_room;
    third_room->next = fourth_room;
    fourth_room->next = fifth_room;

    char command[20];
    int is_finished = 0;

    while (!is_finished) {
        printf("What do you want to do? (look, go, take, use): ");
        scanf("%s", command);

        if (strcmp(command, "look") == 0) {
            printf("You see: %s", current_room->name);
        } else if (strcmp(command, "go") == 0) {
            if (current_room->next) {
                current_room = current_room->next;
                printf("You go to: %s", current_room->name);
            } else {
                printf("There is no door there.");
            }
        } else if (strcmp(command, "take") == 0) {
            if (current_room->has_key) {
                current_room->has_key = 0;
                printf("You took the key.");
            } else {
                printf("There is no key here.");
            }
        } else if (strcmp(command, "use") == 0) {
            if (current_room->has_door && current_room->has_key) {
                is_finished = 1;
                printf("You use the key and open the door. You have won!");
            } else {
                printf("You need the key to open the door.");
            }
        } else {
            printf("Invalid command.");
        }
    }
}

int main() {
    play_game();
    return 0;
}