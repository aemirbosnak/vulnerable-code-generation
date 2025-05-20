//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char *name;
    char *description;
    int num_exits;
    int *exits;
} Room;

typedef struct {
    char *name;
    int location;
} Player;

Room rooms[MAX_ROOMS];
Player player;

void create_rooms() {
    // Create the rooms
    rooms[0].name = "The Entrance Hall";
    rooms[0].description = "You are in a large, dimly lit hall. There are doors to the north, east, and west.";
    rooms[0].num_exits = 3;
    rooms[0].exits = malloc(sizeof(int) * rooms[0].num_exits);
    rooms[0].exits[0] = 1;
    rooms[0].exits[1] = 2;
    rooms[0].exits[2] = 3;

    rooms[1].name = "The Library";
    rooms[1].description = "You are in a large, well-lit library. There are shelves of books lining the walls, and a large desk in the center of the room.";
    rooms[1].num_exits = 1;
    rooms[1].exits = malloc(sizeof(int) * rooms[1].num_exits);
    rooms[1].exits[0] = 0;

    rooms[2].name = "The Dining Room";
    rooms[2].description = "You are in a large, elegant dining room. There is a long table in the center of the room, and chairs are arranged around it.";
    rooms[2].num_exits = 1;
    rooms[2].exits = malloc(sizeof(int) * rooms[2].num_exits);
    rooms[2].exits[0] = 0;

    rooms[3].name = "The Kitchen";
    rooms[3].description = "You are in a large, well-equipped kitchen. There is a stove, oven, and refrigerator in the room, as well as a large pantry.";
    rooms[3].num_exits = 1;
    rooms[3].exits = malloc(sizeof(int) * rooms[3].num_exits);
    rooms[3].exits[0] = 0;

    rooms[4].name = "The Master Bedroom";
    rooms[4].description = "You are in a large, luxurious master bedroom. There is a king-sized bed in the center of the room, and a large wardrobe in the corner.";
    rooms[4].num_exits = 1;
    rooms[4].exits = malloc(sizeof(int) * rooms[4].num_exits);
    rooms[4].exits[0] = 5;

    rooms[5].name = "The Guest Room";
    rooms[5].description = "You are in a small, cozy guest room. There is a twin-sized bed in the center of the room, and a small dresser in the corner.";
    rooms[5].num_exits = 1;
    rooms[5].exits = malloc(sizeof(int) * rooms[5].num_exits);
    rooms[5].exits[0] = 4;

    rooms[6].name = "The Bathroom";
    rooms[6].description = "You are in a small, clean bathroom. There is a toilet, sink, and bathtub in the room.";
    rooms[6].num_exits = 1;
    rooms[6].exits = malloc(sizeof(int) * rooms[6].num_exits);
    rooms[6].exits[0] = 5;

    rooms[7].name = "The Attic";
    rooms[7].description = "You are in a large, dusty attic. There are boxes and furniture piled up everywhere.";
    rooms[7].num_exits = 1;
    rooms[7].exits = malloc(sizeof(int) * rooms[7].num_exits);
    rooms[7].exits[0] = 4;

    rooms[8].name = "The Basement";
    rooms[8].description = "You are in a large, dark basement. There is a workbench in the center of the room, and tools are hanging on the walls.";
    rooms[8].num_exits = 1;
    rooms[8].exits = malloc(sizeof(int) * rooms[8].num_exits);
    rooms[8].exits[0] = 4;

    rooms[9].name = "The Garden";
    rooms[9].description = "You are in a large, beautiful garden. There are flowers of all colors blooming everywhere.";
    rooms[9].num_exits = 1;
    rooms[9].exits = malloc(sizeof(int) * rooms[9].num_exits);
    rooms[9].exits[0] = 4;
}

void create_player() {
    // Create the player
    player.name = "John Doe";
    player.location = 0;
}

void print_room() {
    // Print the current room
    printf("%s\n", rooms[player.location].name);
    printf("%s\n", rooms[player.location].description);
    printf("Exits:");
    for (int i = 0; i < rooms[player.location].num_exits; i++) {
        printf(" %s", rooms[rooms[player.location].exits[i]].name);
    }
    printf("\n");
}

void process_input() {
    // Get the player's input
    char input[256];
    printf("> ");
    fgets(input, 256, stdin);

    // Parse the input
    char *verb = strtok(input, " ");
    char *noun = strtok(NULL, " ");

    // Execute the command
    if (strcmp(verb, "go") == 0) {
        // Move the player to the specified room
        for (int i = 0; i < rooms[player.location].num_exits; i++) {
            if (strcmp(rooms[rooms[player.location].exits[i]].name, noun) == 0) {
                player.location = rooms[player.location].exits[i];
                break;
            }
        }
    } else if (strcmp(verb, "look") == 0) {
        // Print the current room
        print_room();
    } else if (strcmp(verb, "quit") == 0) {
        // Quit the game
        exit(0);
    } else {
        // Print an error message and ask the player to enter a new command
        printf("Invalid command\n");
    }
}

int main() {
    // Create the rooms and the player
    create_rooms();
    create_player();

    // Print the welcome message
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    // Game loop
    while (1) {
        // Print the current room
        print_room();

        // Process the player's input
        process_input();
    }

    return 0;
}