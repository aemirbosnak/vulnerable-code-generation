//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: retro
/* A rudimentary text adventure game in the grand tradition of the 1980s */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char *name;
    char *description;
    int num_exits;
    int exits[MAX_ROOMS];
} Room;

Room rooms[MAX_ROOMS];
int current_room;

void init_rooms() {
    // Create the rooms
    rooms[0].name = "The Foyer";
    rooms[0].description = "You are in the foyer of a large house. There is a door to the north and a door to the east.";
    rooms[0].num_exits = 2;
    rooms[0].exits[0] = 1;
    rooms[0].exits[1] = 2;

    rooms[1].name = "The Living Room";
    rooms[1].description = "You are in the living room of the house. There is a door to the south and a door to the west.";
    rooms[1].num_exits = 2;
    rooms[1].exits[0] = 0;
    rooms[1].exits[1] = 3;

    rooms[2].name = "The Dining Room";
    rooms[2].description = "You are in the dining room of the house. There is a door to the west and a door to the south.";
    rooms[2].num_exits = 2;
    rooms[2].exits[0] = 0;
    rooms[2].exits[1] = 4;

    rooms[3].name = "The Kitchen";
    rooms[3].description = "You are in the kitchen of the house. There is a door to the east and a door to the south.";
    rooms[3].num_exits = 2;
    rooms[3].exits[0] = 1;
    rooms[3].exits[1] = 5;

    rooms[4].name = "The Master Bedroom";
    rooms[4].description = "You are in the master bedroom of the house. There is a door to the north and a door to the east.";
    rooms[4].num_exits = 2;
    rooms[4].exits[0] = 2;
    rooms[4].exits[1] = 6;

    rooms[5].name = "The Guest Bedroom";
    rooms[5].description = "You are in the guest bedroom of the house. There is a door to the north and a door to the west.";
    rooms[5].num_exits = 2;
    rooms[5].exits[0] = 3;
    rooms[5].exits[1] = 7;

    rooms[6].name = "The Bathroom";
    rooms[6].description = "You are in the bathroom of the house. There is a door to the west.";
    rooms[6].num_exits = 1;
    rooms[6].exits[0] = 4;

    rooms[7].name = "The Attic";
    rooms[7].description = "You are in the attic of the house. There is a door to the east.";
    rooms[7].num_exits = 1;
    rooms[7].exits[0] = 5;

    // Set the current room to the foyer
    current_room = 0;
}

void print_room() {
    // Print the room's name and description
    printf("%s\n", rooms[current_room].name);
    printf("%s\n", rooms[current_room].description);

    // Print the room's exits
    printf("Exits:\n");
    for (int i = 0; i < rooms[current_room].num_exits; i++) {
        printf("  %s\n", rooms[rooms[current_room].exits[i]].name);
    }
}

int main() {
    // Initialize the rooms
    init_rooms();

    // Print the current room
    print_room();

    // Get the user's input
    char input[100];
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Parse the user's input
    char *command = strtok(input, " ");
    char *argument = strtok(NULL, " ");

    // Execute the user's command
    if (strcmp(command, "go") == 0) {
        // Try to move to the specified room
        int new_room = -1;
        for (int i = 0; i < rooms[current_room].num_exits; i++) {
            if (strcmp(argument, rooms[rooms[current_room].exits[i]].name) == 0) {
                new_room = rooms[current_room].exits[i];
                break;
            }
        }

        if (new_room != -1) {
            // Move to the new room
            current_room = new_room;

            // Print the new room
            print_room();
        } else {
            // The specified room does not exist
            printf("I can't go there.\n");
        }
    } else if (strcmp(command, "quit") == 0) {
        // Quit the game
        printf("Goodbye!\n");
        return 0;
    } else {
        // The user entered an invalid command
        printf("I don't understand that command.\n");
    }

    // Repeat until the user quits the game
    while (1) {
        // Get the user's input
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Parse the user's input
        command = strtok(input, " ");
        argument = strtok(NULL, " ");

        // Execute the user's command
        if (strcmp(command, "go") == 0) {
            // Try to move to the specified room
            int new_room = -1;
            for (int i = 0; i < rooms[current_room].num_exits; i++) {
                if (strcmp(argument, rooms[rooms[current_room].exits[i]].name) == 0) {
                    new_room = rooms[current_room].exits[i];
                    break;
                }
            }

            if (new_room != -1) {
                // Move to the new room
                current_room = new_room;

                // Print the new room
                print_room();
            } else {
                // The specified room does not exist
                printf("I can't go there.\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            // Quit the game
            printf("Goodbye!\n");
            return 0;
        } else {
            // The user entered an invalid command
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}