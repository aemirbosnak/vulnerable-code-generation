//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_GHOSTS 7

typedef struct {
    char name[20];
    char description[100];
    int isVisited;
} Room;

typedef struct {
    int id;
    Room* currentRoom;
} Ghost;

void printSeparator() {
    printf("=========================\n");
}

void printInstructions() {
    printSeparator();
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are lost in a haunted house and need to find your way out.\n");
    printf("There are ghosts lurking around, so be careful!\n");
    printf("Use the following commands to navigate the house:\n");
    printf(" - 'look' to look around the room\n");
    printf(" - 'go [direction]' to move to a neighboring room\n");
    printf(" - 'quit' to exit the game\n");
    printSeparator();
}

void printRoom(Room *room) {
    printf("You are in %s.\n", room->name);
    printf("%s\n\n", room->description);
    room->isVisited = 1;
}

Room* createRoom(char *name, char *description) {
    Room *room = malloc(sizeof(Room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    room->isVisited = 0;
    return room;
}

Ghost* createGhost(int id, Room *startingRoom) {
    Ghost *ghost = malloc(sizeof(Ghost));
    ghost->id = id;
    ghost->currentRoom = startingRoom;
    return ghost;
}

void updateGhost(Ghost *ghost, Room *newRoom) {
    ghost->currentRoom = newRoom;
}

char* readInput() {
    char *input = malloc(100 * sizeof(char));
    printf("> ");
    fgets(input, 100, stdin);
    return input;
}

void tokenizeInput(char *input, char **tokens) {
    char *token = strtok(input, " \n");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " \n");
    }
}

int isValidDirection(char *direction) {
    const char *validDirections[] = {"north", "south", "east", "west"};
    for (int i = 0; i < 4; i++) {
        if (strcmp(direction, validDirections[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

Room* getNextRoom(Room *currentRoom, char *direction) {
    if (strcmp(direction, "north") == 0) {
        return createRoom("Hallway", "You are in a dimly lit hallway.");
    } else if (strcmp(direction, "south") == 0) {
        return createRoom("Kitchen", "You are in a spooky kitchen.");
    } else if (strcmp(direction, "east") == 0) {
        return createRoom("Bedroom", "You are in a dusty bedroom.");
    } else if (strcmp(direction, "west") == 0) {
        return createRoom("Basement", "You are in a cold, damp basement.");
    }
    return NULL;
}

void runGame() {
    // Initialize rooms and ghost
    Room *rooms[MAX_ROOMS];
    rooms[0] = createRoom("Foyer", "You are in a grand foyer with a chandelier hanging from the ceiling.");
    rooms[1] = createRoom("Hallway", "You are in a dimly lit hallway with creepy portraits hanging on the walls.");
    rooms[2] = createRoom("Kitchen", "You are in a spooky kitchen with cobwebs covering the countertops.");
    rooms[3] = createRoom("Bedroom", "You are in a dusty bedroom with an old, creaky bed.");
    rooms[4] = createRoom("Basement", "You are in a cold, damp basement with a single light bulb swinging from the ceiling.");

    Ghost *ghosts[MAX_GHOSTS];
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i] = createGhost(i, rooms[rand() % MAX_ROOMS]);
    }

    // Initialize player's starting room and print instructions
    Room *currentRoom = rooms[0];
    printInstructions();

    while (1) {
        printRoom(currentRoom);

        // Check if all rooms have been visited
        int allVisited = 1;
        for (int i = 0; i < MAX_ROOMS; i++) {
            if (!rooms[i]->isVisited) {
                allVisited = 0;
                break;
            }
        }
        if (allVisited) {
            printf("Congratulations! You have visited all the rooms and escaped the haunted house.\n");
            break;
        }

        // Check for ghosts in the current room
        for (int i = 0; i < MAX_GHOSTS; i++) {
            if (ghosts[i]->currentRoom == currentRoom) {
                printf("A ghost appears and scares you!\n");
                break;
            }
        }

        // Read input and tokenize
        char *input = readInput();
        char *tokens[2];
        tokenizeInput(input, tokens);

        // Handle input
        if (strcmp(tokens[0], "look") == 0) {
            printRoom(currentRoom);
        } else if (strcmp(tokens[0], "go") == 0 && tokens[1] != NULL && isValidDirection(tokens[1])) {
            Room *nextRoom = getNextRoom(currentRoom, tokens[1]);
            if (nextRoom != NULL) {
                currentRoom = nextRoom;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(tokens[0], "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("I don't understand that command.\n");
        }

        free(input);
    }

    // Free memory
    for (int i = 0; i < MAX_ROOMS; i++) {
        free(rooms[i]);
    }
    for (int i = 0; i < MAX_GHOSTS; i++) {
        free(ghosts[i]);
    }
}

int main() {
    srand(time(NULL));
    runGame();
    return 0;
}