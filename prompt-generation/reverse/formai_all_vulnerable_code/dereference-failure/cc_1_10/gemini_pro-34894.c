//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_ROOM 100
#define MAX_OBJECT 100
#define MAX_ATTEMPTS 1000

// Structure to represent a room.
typedef struct room {
    char name[256];
    char description[1024];
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
    struct object *objects;
} room;

// Structure to represent an object.
typedef struct object {
    char name[256];
    char description[1024];
    int weight;
    struct object *next;
} object;

// Function to create a new room.
room *create_room(char *name, char *description) {
    room *new_room = malloc(sizeof(room));
    strcpy(new_room->name, name);
    strcpy(new_room->description, description);
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    new_room->objects = NULL;
    return new_room;
}

// Function to create a new object.
object *create_object(char *name, char *description, int weight) {
    object *new_object = malloc(sizeof(object));
    strcpy(new_object->name, name);
    strcpy(new_object->description, description);
    new_object->weight = weight;
    new_object->next = NULL;
    return new_object;
}

// Function to add an object to a room.
void add_object_to_room(room *room, object *object) {
    object->next = room->objects;
    room->objects = object;
}

// Function to generate a random number between two values.
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random room.
room *generate_room(char *name, char *description) {
    room *new_room = create_room(name, description);
    int num_objects = random_range(0, 5);
    for (int i = 0; i < num_objects; i++) {
        char *object_name = malloc(256);
        char *object_description = malloc(1024);
        int object_weight = random_range(1, 10);
        sprintf(object_name, "Object %d", i + 1);
        sprintf(object_description, "This is object %d.", i + 1);
        object *new_object = create_object(object_name, object_description, object_weight);
        add_object_to_room(new_room, new_object);
    }
    return new_room;
}

// Function to generate a random dungeon.
room *generate_dungeon(int num_rooms) {
    room *start_room = generate_room("Start Room", "This is the start room of the dungeon.");
    room *current_room = start_room;
    for (int i = 1; i < num_rooms; i++) {
        char *room_name = malloc(256);
        char *room_description = malloc(1024);
        sprintf(room_name, "Room %d", i + 1);
        sprintf(room_description, "This is room %d of the dungeon.", i + 1);
        room *new_room = generate_room(room_name, room_description);
        int direction = random_range(0, 3);
        switch (direction) {
            case 0:
                current_room->north = new_room;
                break;
            case 1:
                current_room->south = new_room;
                break;
            case 2:
                current_room->east = new_room;
                break;
            case 3:
                current_room->west = new_room;
                break;
        }
        current_room = new_room;
    }
    return start_room;
}

// Function to print a room.
void print_room(room *room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
    if (room->objects != NULL) {
        printf("Objects:\n");
        object *object = room->objects;
        while (object != NULL) {
            printf("  - %s (%d kg)\n", object->name, object->weight);
            object = object->next;
        }
    }
    if (room->north != NULL) {
        printf("North: %s\n", room->north->name);
    }
    if (room->south != NULL) {
        printf("South: %s\n", room->south->name);
    }
    if (room->east != NULL) {
        printf("East: %s\n", room->east->name);
    }
    if (room->west != NULL) {
        printf("West: %s\n", room->west->name);
    }
}

// Function to play the game.
void play_game(room *start_room) {
    room *current_room = start_room;
    while (1) {
        print_room(current_room);
        char *input = malloc(256);
        printf("What do you want to do? ");
        scanf("%s", input);
        if (strcmp(input, "n") == 0 || strcmp(input, "north") == 0) {
            if (current_room->north != NULL) {
                current_room = current_room->north;
            } else {
                printf("There is no door to the north.\n");
            }
        } else if (strcmp(input, "s") == 0 || strcmp(input, "south") == 0) {
            if (current_room->south != NULL) {
                current_room = current_room->south;
            } else {
                printf("There is no door to the south.\n");
            }
        } else if (strcmp(input, "e") == 0 || strcmp(input, "east") == 0) {
            if (current_room->east != NULL) {
                current_room = current_room->east;
            } else {
                printf("There is no door to the east.\n");
            }
        } else if (strcmp(input, "w") == 0 || strcmp(input, "west") == 0) {
            if (current_room->west != NULL) {
                current_room = current_room->west;
            } else {
                printf("There is no door to the west.\n");
            }
        } else if (strcmp(input, "look") == 0) {
            print_room(current_room);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
}

// Main function.
int main() {
    srand(time(NULL));
    room *dungeon = generate_dungeon(10);
    play_game(dungeon);
    return 0;
}