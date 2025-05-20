//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
    int room_num;
    char room_name[20];
    struct Room* next_room;
} Room;

Room* create_room(int room_num, char* room_name, Room* next_room) {
    Room* new_room = malloc(sizeof(Room));
    new_room->room_num = room_num;
    strcpy(new_room->room_name, room_name);
    new_room->next_room = next_room;
    return new_room;
}

void play_adventure() {
    Room* current_room = create_room(1, "The Entrance Hall", NULL);
    current_room = create_room(2, "The Living Room", current_room);
    current_room = create_room(3, "The Kitchen", current_room);
    current_room = create_room(4, "The Bedroom", current_room);
    current_room = create_room(5, "The Secret Room", current_room);

    printf("You are in the %s.\n", current_room->room_name);

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
            // Move to the north room
            current_room = current_room->next_room;
            printf("You have moved north to the %s.\n", current_room->room_name);
        } else if (strcmp(direction, "south") == 0) {
            // Move to the south room
            current_room = current_room->next_room->next_room;
            printf("You have moved south to the %s.\n", current_room->room_name);
        } else if (strcmp(direction, "east") == 0) {
            // Move to the east room
            current_room = current_room->next_room->next_room->next_room;
            printf("You have moved east to the %s.\n", current_room->room_name);
        } else if (strcmp(direction, "west") == 0) {
            // Move to the west room
            current_room = current_room->next_room->next_room->next_room->next_room;
            printf("You have moved west to the %s.\n", current_room->room_name);
        } else {
            printf("Invalid command.\n");
        }
    } else {
        printf("Invalid command.\n");
    }

    play_adventure();
}

int main() {
    play_adventure();
    return 0;
}