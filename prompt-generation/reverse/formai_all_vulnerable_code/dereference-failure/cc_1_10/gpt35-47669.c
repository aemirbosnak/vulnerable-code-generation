//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

typedef struct room {
    char* name;
    char* description;
    struct room** exits;
} Room;

Room* current_room;

Room* create_room(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->exits = calloc(4, sizeof(Room*));
    return room;
}

void set_exit(Room* room, char* direction, Room* destination) {
    if (!strcmp(direction, "north")) {
        room->exits[0] = destination;
    } else if (!strcmp(direction, "east")) {
        room->exits[1] = destination;
    } else if (!strcmp(direction, "south")) {
        room->exits[2] = destination;
    } else if (!strcmp(direction, "west")) {
        room->exits[3] = destination;
    }
}

Room* move(char* direction) {
    Room* destination;
    if (!strcmp(direction, "north")) {
        destination = current_room->exits[0];
    } else if (!strcmp(direction, "east")) {
        destination = current_room->exits[1];
    } else if (!strcmp(direction, "south")) {
        destination = current_room->exits[2];
    } else if (!strcmp(direction, "west")) {
        destination = current_room->exits[3];
    } else {
        printf("Invalid direction.\n");
        destination = current_room;
    }
    if (destination == NULL) {
        printf("You can't go that way.\n");
        destination = current_room;
    }
    return destination;
}

void print_room_description(Room* room) {
    printf("%s\n\n%s\n", room->name, room->description);
    printf("Exits:\n");
    if (room->exits[0]) {
        printf("north\n");
    }
    if (room->exits[1]) {
        printf("east\n");
    }
    if (room->exits[2]) {
        printf("south\n");
    }
    if (room->exits[3]) {
        printf("west\n");
    }
}

int main() {
    // create rooms
    Room* hallway = create_room("Hallway", "You are in a dimly lit hallway.");
    Room* bedroom = create_room("Bedroom", "You are in a bedroom. The bed is unmade.");
    Room* bathroom = create_room("Bathroom", "You are in a bathroom. The sink is dripping.");
    Room* kitchen = create_room("Kitchen", "You are in a kitchen. There are dirty dishes in the sink.");

    // set up exits
    set_exit(hallway, "north", bedroom);
    set_exit(hallway, "east", bathroom);
    set_exit(bedroom, "south", hallway);
    set_exit(bathroom, "west", hallway);
    set_exit(bathroom, "east", kitchen);
    set_exit(kitchen, "west", bathroom);

    // start in the hallway
    current_room = hallway;

    // game loop
    char input[MAX_INPUT_LENGTH];
    bool running = true;
    while (running) {
        print_room_description(current_room);
        printf("\nWhat do you want to do?\n");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;  // remove newline character
        if (!strcmp(input, "quit")) {
            running = false;
        } else if (!strcmp(input, "north") || !strcmp(input, "east") || !strcmp(input, "south") || !strcmp(input, "west")) {
            current_room = move(input);
        } else {
            printf("I don't understand that command.\n");
        }
    }

    // free memory
    free(hallway->name);
    free(hallway->description);
    free(hallway->exits);
    free(bedroom->name);
    free(bedroom->description);
    free(bedroom->exits);
    free(bathroom->name);
    free(bathroom->description);
    free(bathroom->exits);
    free(kitchen->name);
    free(kitchen->description);
    free(kitchen->exits);
    free(hallway);
    free(bedroom);
    free(bathroom);
    free(kitchen);

    return 0;
}