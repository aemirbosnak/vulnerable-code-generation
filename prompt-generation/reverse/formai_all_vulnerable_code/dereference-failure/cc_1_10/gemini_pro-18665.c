//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct room {
    char* name;
    char* description;
    struct room* exits[4]; // north, east, south, west
} room;

room* create_room(char* name, char* description) {
    room* new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    for (int i = 0; i < 4; i++) {
        new_room->exits[i] = NULL;
    }
    return new_room;
}

void destroy_room(room* room) {
    free(room->name);
    free(room->description);
    free(room);
}

// Create all the rooms for the game
room* room_start;
room* room_kitchen;
room* room_dining_room;
room* room_living_room;
room* room_hallway;
room* room_bedroom1;
room* room_bedroom2;
room* room_bathroom;
room* room_attic;
room* room_basement;

void create_rooms() {
    room_start = create_room("Start", "You are standing in a dark room. The only light comes from a small window high up on the wall. There is a door to the north.");
    room_kitchen = create_room("Kitchen", "You are in a large kitchen. There is a stove, a refrigerator, and a sink. There is a door to the south.");
    room_dining_room = create_room("Dining Room", "You are in a large dining room. There is a long table with chairs. There is a door to the west.");
    room_living_room = create_room("Living Room", "You are in a large living room. There is a couch, a coffee table, and a TV. There is a door to the north.");
    room_hallway = create_room("Hallway", "You are in a long hallway. There are doors to the east, west, and south.");
    room_bedroom1 = create_room("Bedroom 1", "You are in a small bedroom. There is a bed, a dresser, and a nightstand. There is a door to the west.");
    room_bedroom2 = create_room("Bedroom 2", "You are in a small bedroom. There is a bed, a dresser, and a nightstand. There is a door to the east.");
    room_bathroom = create_room("Bathroom", "You are in a small bathroom. There is a toilet, a sink, and a shower. There is a door to the north.");
    room_attic = create_room("Attic", "You are in a large attic. There are boxes and furniture stored here. There is a door to the south.");
    room_basement = create_room("Basement", "You are in a large basement. There is a furnace, a water heater, and a workbench. There is a door to the north.");

    // Set the exits for each room
    room_start->exits[0] = room_living_room;
    room_kitchen->exits[1] = room_dining_room;
    room_dining_room->exits[3] = room_kitchen;
    room_living_room->exits[0] = room_start;
    room_living_room->exits[1] = room_hallway;
    room_hallway->exits[0] = room_bedroom1;
    room_hallway->exits[1] = room_bedroom2;
    room_hallway->exits[2] = room_bathroom;
    room_bedroom1->exits[1] = room_hallway;
    room_bedroom2->exits[3] = room_hallway;
    room_bathroom->exits[0] = room_hallway;
    room_attic->exits[1] = room_basement;
    room_basement->exits[0] = room_attic;
}

// Play the game
void play_game() {
    room* current_room = room_start;

    while (1) {
        // Print the description of the current room
        printf("%s\n", current_room->description);

        // Print the exits from the current room
        printf("Exits:");
        for (int i = 0; i < 4; i++) {
            if (current_room->exits[i] != NULL) {
                printf(" %s", current_room->exits[i]->name);
            }
        }
        printf("\n");

        // Get the player's input
        char input[100];
        printf("> ");
        scanf("%s", input);

        // Process the player's input
        if (strcmp(input, "n") == 0 || strcmp(input, "north") == 0) {
            if (current_room->exits[0] != NULL) {
                current_room = current_room->exits[0];
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "e") == 0 || strcmp(input, "east") == 0) {
            if (current_room->exits[1] != NULL) {
                current_room = current_room->exits[1];
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "s") == 0 || strcmp(input, "south") == 0) {
            if (current_room->exits[2] != NULL) {
                current_room = current_room->exits[2];
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "w") == 0 || strcmp(input, "west") == 0) {
            if (current_room->exits[3] != NULL) {
                current_room = current_room->exits[3];
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("I don't understand your input.\n");
        }
    }
}

// Free all the rooms
void destroy_rooms() {
    destroy_room(room_start);
    destroy_room(room_kitchen);
    destroy_room(room_dining_room);
    destroy_room(room_living_room);
    destroy_room(room_hallway);
    destroy_room(room_bedroom1);
    destroy_room(room_bedroom2);
    destroy_room(room_bathroom);
    destroy_room(room_attic);
    destroy_room(room_basement);
}

int main() {
    create_rooms();
    play_game();
    destroy_rooms();
    return 0;
}