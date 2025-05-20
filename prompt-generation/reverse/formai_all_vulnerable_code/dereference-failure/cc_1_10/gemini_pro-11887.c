//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 7

typedef struct room {
    char *name;
    char *description;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
} room;

room rooms[MAX_ROOMS];

void init_rooms() {
    // Room 1
    rooms[0].name = "Entrance";
    rooms[0].description = "You are in a small, dark room. There is a door to the north.";
    rooms[0].north = &rooms[1];

    // Room 2
    rooms[1].name = "Hallway";
    rooms[1].description = "You are in a long, dimly lit hallway. There are doors to the north, south, and east.";
    rooms[1].north = &rooms[2];
    rooms[1].south = &rooms[0];
    rooms[1].east = &rooms[3];

    // Room 3
    rooms[2].name = "Library";
    rooms[2].description = "You are in a large, well-lit library. There are bookshelves all around you, and a desk in the center of the room.";
    rooms[2].north = &rooms[3];
    rooms[2].west = &rooms[1];

    // Room 4
    rooms[3].name = "Laboratory";
    rooms[3].description = "You are in a small, windowless laboratory. There are strange machines and chemicals all around you.";
    rooms[3].north = &rooms[4];
    rooms[3].west = &rooms[1];

    // Room 5
    rooms[4].name = "Observatory";
    rooms[4].description = "You are in a small, circular room with a large telescope in the center. There is a window on the east wall that offers a stunning view of the stars.";
    rooms[4].west = &rooms[3];

    // Room 6
    rooms[5].name = "Dining Room";
    rooms[5].description = "You are in a large, elegant dining room. There is a long table in the center of the room, with chairs all around it.";
    rooms[5].east = &rooms[6];
    rooms[5].west = &rooms[2];

    // Room 7
    rooms[6].name = "Kitchen";
    rooms[6].description = "You are in a large, well-equipped kitchen. There are pots and pans hanging on the walls, and a large oven in the corner.";
    rooms[6].west = &rooms[5];
}

void print_room(room *room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
}

void play_game() {
    room *current_room = &rooms[0];

    while (1) {
        // Print the current room
        print_room(current_room);

        // Get the player's input
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);

        // Parse the player's input
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        // Handle the player's input
        if (strcmp(command, "go") == 0) {
            if (strcmp(argument, "north") == 0) {
                if (current_room->north != NULL) {
                    current_room = current_room->north;
                } else {
                    printf("There is no door to the north.\n");
                }
            } else if (strcmp(argument, "south") == 0) {
                if (current_room->south != NULL) {
                    current_room = current_room->south;
                } else {
                    printf("There is no door to the south.\n");
                }
            } else if (strcmp(argument, "east") == 0) {
                if (current_room->east != NULL) {
                    current_room = current_room->east;
                } else {
                    printf("There is no door to the east.\n");
                }
            } else if (strcmp(argument, "west") == 0) {
                if (current_room->west != NULL) {
                    current_room = current_room->west;
                } else {
                    printf("There is no door to the west.\n");
                }
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }
}

int main() {
    init_rooms();
    play_game();

    return 0;
}