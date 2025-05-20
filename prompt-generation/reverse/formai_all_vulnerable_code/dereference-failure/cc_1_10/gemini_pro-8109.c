//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world.
typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

room* create_room(char* name, char* description) {
    room* new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

void free_room(room* room) {
    free(room->name);
    free(room->description);
    free(room);
}

// Define the player.
typedef struct player {
    char* name;
    room* current_room;
} player;

player* create_player(char* name, room* current_room) {
    player* new_player = malloc(sizeof(player));
    new_player->name = strdup(name);
    new_player->current_room = current_room;
    return new_player;
}

void free_player(player* player) {
    free(player->name);
    free(player);
}

// The main game loop.
int main() {
    // Create the game world.
    room* room1 = create_room("The Forest", "You are standing in a lush forest. The trees are tall and the air is fresh.");
    room* room2 = create_room("The Cave", "You are standing in a dark cave. The air is cold and damp.");
    room* room3 = create_room("The Castle", "You are standing in a grand castle. The walls are made of stone and the floor is covered in tapestries.");

    // Link the rooms together.
    room1->north = room2;
    room2->south = room1;
    room2->east = room3;
    room3->west = room2;

    // Create the player.
    player* player1 = create_player("Player 1", room1);

    // The game loop.
    while (1) {
        // Display the player's current location.
        printf("You are in %s.\n", player1->current_room->name);
        printf("%s\n", player1->current_room->description);

        // Get the player's input.
        char input[80];
        printf("> ");
        scanf("%s", input);

        // Check if the player wants to quit.
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Check if the player wants to move.
        else if (strcmp(input, "north") == 0) {
            if (player1->current_room->north != NULL) {
                player1->current_room = player1->current_room->north;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            if (player1->current_room->east != NULL) {
                player1->current_room = player1->current_room->east;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (player1->current_room->south != NULL) {
                player1->current_room = player1->current_room->south;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(input, "west") == 0) {
            if (player1->current_room->west != NULL) {
                player1->current_room = player1->current_room->west;
            } else {
                printf("You cannot go that way.\n");
            }
        }

        // Check if the player wants to examine something.
        else if (strcmp(input, "look") == 0) {
            printf("%s\n", player1->current_room->description);
        }

        // Check if the player wants to pick up an item.
        else if (strcmp(input, "get") == 0) {
            printf("What do you want to get?\n");
            char item[80];
            scanf("%s", item);
            if (strcmp(item, "sword") == 0) {
                printf("You pick up the sword.\n");
            } else {
                printf("You cannot find that item.\n");
            }
        }

        // Check if the player wants to use an item.
        else if (strcmp(input, "use") == 0) {
            printf("What do you want to use?\n");
            char item[80];
            scanf("%s", item);
            if (strcmp(item, "sword") == 0) {
                printf("You swing the sword at the monster.\n");
            } else {
                printf("You cannot use that item.\n");
            }
        }

        // Check if the player wants to talk to someone.
        else if (strcmp(input, "talk") == 0) {
            printf("Who do you want to talk to?\n");
            char person[80];
            scanf("%s", person);
            if (strcmp(person, "guard") == 0) {
                printf("The guard says, \"Halt! Who goes there?\"\n");
            } else {
                printf("You cannot find that person.\n");
            }
        }

        // Check if the player wants to attack someone.
        else if (strcmp(input, "attack") == 0) {
            printf("Who do you want to attack?\n");
            char person[80];
            scanf("%s", person);
            if (strcmp(person, "monster") == 0) {
                printf("You attack the monster with your sword.\n");
            } else {
                printf("You cannot attack that person.\n");
            }
        }
    }

    // Free the game world.
    free_room(room1);
    free_room(room2);
    free_room(room3);

    // Free the player.
    free_player(player1);

    return 0;
}