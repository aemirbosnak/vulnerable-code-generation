//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* south;
    struct room* east;
    struct room* west;
} room;

room* create_room(char* name, char* description) {
    room* new_room = (room*) malloc(sizeof(room));
    new_room->name = (char*) malloc(strlen(name) + 1);
    strcpy(new_room->name, name);
    new_room->description = (char*) malloc(strlen(description) + 1);
    strcpy(new_room->description, description);
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    return new_room;
}

void destroy_room(room* room) {
    free(room->name);
    free(room->description);
    free(room);
}

void print_room(room* room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
    if (room->north != NULL) {
        printf("To the north is %s.\n", room->north->name);
    }
    if (room->south != NULL) {
        printf("To the south is %s.\n", room->south->name);
    }
    if (room->east != NULL) {
        printf("To the east is %s.\n", room->east->name);
    }
    if (room->west != NULL) {
        printf("To the west is %s.\n", room->west->name);
    }
}

room* create_world() {
    room* world = create_room("The Void", "You are in a vast, empty void. There is nothing here but darkness.");

    room* room1 = create_room("The Forest", "You are in a dense forest. The trees are tall and the leaves are a deep green. The air is filled with the sound of birdsong.");
    room* room2 = create_room("The Cave", "You are in a dark cave. The walls are covered in stalactites and stalagmites. The only light comes from a small fire in the center of the room.");
    room* room3 = create_room("The Castle", "You are in a grand castle. The walls are made of stone and the windows are stained glass. The air is filled with the sound of music.");

    world->north = room1;
    room1->south = world;
    room1->east = room2;
    room2->west = room1;
    room2->east = room3;
    room3->west = room2;

    return world;
}

void destroy_world(room* world) {
    destroy_room(world);
    destroy_room(world->north);
    destroy_room(world->south);
    destroy_room(world->east);
    destroy_room(world->west);
}

int main() {
    room* world = create_world();

    room* current_room = world;

    while (1) {
        print_room(current_room);

        char input[256];
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "north", 5) == 0) {
            if (current_room->north != NULL) {
                current_room = current_room->north;
            } else {
                printf("You cannot go north.\n");
            }
        } else if (strncmp(input, "south", 5) == 0) {
            if (current_room->south != NULL) {
                current_room = current_room->south;
            } else {
                printf("You cannot go south.\n");
            }
        } else if (strncmp(input, "east", 4) == 0) {
            if (current_room->east != NULL) {
                current_room = current_room->east;
            } else {
                printf("You cannot go east.\n");
            }
        } else if (strncmp(input, "west", 4) == 0) {
            if (current_room->west != NULL) {
                current_room = current_room->west;
            } else {
                printf("You cannot go west.\n");
            }
        } else if (strncmp(input, "quit", 4) == 0) {
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }

    destroy_world(world);

    return 0;
}