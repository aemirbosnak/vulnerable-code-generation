//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rooms and their descriptions
typedef struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

// Declare the functions to be used in the program
Room* createRoom(char*, char*);
void printRoom(Room*);
void printIntro();
int playGame(Room*);
void printSuccess();

int main() {
    // Create the rooms with their names and descriptions
    Room* start = createRoom("Start Room", "You're in a room with no windows and no doors, but somehow you got in. You can see faint outlines of something on the walls.");
    Room* r1 = createRoom("Room 1", "You enter a pitch-black room. You can hear whispers all around you, but you can't see anything.");
    Room* r2 = createRoom("Room 2", "You find yourself in a room with a floor made of clouds and walls made of rainbows. It's breathtaking.");
    Room* r3 = createRoom("Room 3", "You step into a room with a giant, talking fishbowl in the center. The fish introduces itself as Ferdinand.");
    Room* r4 = createRoom("Room 4", "You enter a room with a giant, pulsating brain hanging from the ceiling. It seems to be alive.");

    // Connect the rooms to each other
    start->north = r1;
    r1->south = start;
    r1->east = r2;
    r2->west = r1;
    r2->north = r3;
    r3->south = r2;
    r3->east = r4;
    r4->west = r3;

    // Print the introduction and start the game
    printIntro();
    playGame(start);

    return 0;
}

// Create a room with a name and description
Room* createRoom(char* name, char* description) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->name = name;
    newRoom->description = description;
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;
    return newRoom;
}

// Print the name and description of a room
void printRoom(Room* room) {
    printf("\n%s\n\n%s\n", room->name, room->description);
}

// Print the introduction to the game
void printIntro() {
    printf("\nWelcome to the Surrealist Text Adventure Game!\n");
    printf("In this game, you'll encounter strange rooms and surreal objects as you navigate through the game world.\n");
    printf("To play the game, type in the appropriate command when prompted.\n\n");
}

// Play the game, starting from the given room
int playGame(Room* currRoom) {
    printf("\nYou are currently in the %s.\n", currRoom->name);

    // Keep playing until the player reaches the end of the game
    while (1) {
        // Print the options for the player
        printf("\nWhat would you like to do?\n");
        printf("- 'look' to view your surroundings\n");
        printf("- 'north' to move north\n");
        printf("- 'south' to move south\n");
        printf("- 'east' to move east\n");
        printf("- 'west' to move west\n");
        printf("- 'quit' to quit the game\n");
        printf("\nEnter your command: ");

        // Read the player's input and process it
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "look") == 0) {
            // Print the description of the current room
            printRoom(currRoom);
        } else if (strcmp(input, "north") == 0) {
            // Check if there's a room to the north and move there if there is
            if (currRoom->north == NULL) {
                printf("\nYou can't go that way!\n");
            } else {
                currRoom = currRoom->north;
                printf("\nYou move to the %s.\n", currRoom->name);
                printRoom(currRoom);
            }
        } else if (strcmp(input, "south") == 0) {
            // Check if there's a room to the south and move there if there is
            if (currRoom->south == NULL) {
                printf("\nYou can't go that way!\n");
            } else {
                currRoom = currRoom->south;
                printf("\nYou move to the %s.\n", currRoom->name);
                printRoom(currRoom);
            }
        } else if (strcmp(input, "east") == 0) {
            // Check if there's a room to the east and move there if there is
            if (currRoom->east == NULL) {
                printf("\nYou can't go that way!\n");
            } else {
                currRoom = currRoom->east;
                printf("\nYou move to the %s.\n", currRoom->name);
                printRoom(currRoom);
            }
        } else if (strcmp(input, "west") == 0) {
            // Check if there's a room to the west and move there if there is
            if (currRoom->west == NULL) {
                printf("\nYou can't go that way!\n");
            } else {
                currRoom = currRoom->west;
                printf("\nYou move to the %s.\n", currRoom->name);
                printRoom(currRoom);
            }
        } else if (strcmp(input, "quit") == 0) {
            // Quit the game if the player types in "quit"
            printf("\nThanks for playing the Surrealist Text Adventure Game!\n");
            return 0;
        } else {
            // If the player types in an invalid command, ask them to try again
            printf("\nInvalid command. Please try again.\n");
        }

        // Check if the player has reached the end of the game
        if (strcmp(currRoom->name, "Room 4") == 0) {
            printSuccess();
            return 0;
        }
    }
}

// Print a message telling the player they've won the game
void printSuccess() {
    printf("\nCongratulations! You've completed the Surrealist Text Adventure Game!\n");
    printf("We hope you enjoyed the experience.\n");
}