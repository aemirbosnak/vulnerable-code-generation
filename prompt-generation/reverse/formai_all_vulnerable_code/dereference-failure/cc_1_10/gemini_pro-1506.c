//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A spooky mansion with multiple rooms
typedef struct room {
    char *name;
    char *description;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
} room;

// The player's current location
room *currentRoom;

// Create a new room
room *createRoom(char *name, char *description) {
    room *newRoom = malloc(sizeof(room));
    newRoom->name = malloc(strlen(name) + 1);
    strcpy(newRoom->name, name);
    newRoom->description = malloc(strlen(description) + 1);
    strcpy(newRoom->description, description);
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;
    return newRoom;
}

// Connect two rooms
void connectRooms(room *room1, room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            break;
        case 's':
            room1->south = room2;
            break;
        case 'e':
            room1->east = room2;
            break;
        case 'w':
            room1->west = room2;
            break;
    }
}

// Initialize the mansion
void initMansion() {
    // Create the rooms
    room *foyer = createRoom("Foyer", "A grand foyer with a sweeping staircase and a flickering chandelier.");
    room *livingRoom = createRoom("Living Room", "A cozy living room with a crackling fireplace and comfortable armchairs.");
    room *diningRoom = createRoom("Dining Room", "A formal dining room with a long table and elegant chairs.");
    room *kitchen = createRoom("Kitchen", "A spacious kitchen with a large stove, oven, and refrigerator.");
    room *library = createRoom("Library", "A well-stocked library with shelves full of books and a cozy reading nook.");
    room *masterBedroom = createRoom("Master Bedroom", "A luxurious master bedroom with a king-sized bed and a private bathroom.");
    room *guestBedroom = createRoom("Guest Bedroom", "A cozy guest bedroom with a queen-sized bed and a dresser.");
    room *bathroom = createRoom("Bathroom", "A small bathroom with a toilet, sink, and shower.");
    room *secretRoom = createRoom("Secret Room", "A hidden room behind a bookcase, containing a dusty old chest.");

    // Connect the rooms
    connectRooms(foyer, livingRoom, 'n');
    connectRooms(foyer, diningRoom, 'e');
    connectRooms(foyer, kitchen, 'w');
    connectRooms(livingRoom, library, 'n');
    connectRooms(livingRoom, masterBedroom, 'e');
    connectRooms(diningRoom, kitchen, 'w');
    connectRooms(kitchen, bathroom, 'n');
    connectRooms(library, secretRoom, 'e');

    // Set the current room to the foyer
    currentRoom = foyer;
}

// Print the current room's description
void printRoomDescription() {
    printf("%s\n\n", currentRoom->description);
}

// Get the player's input
char getInput() {
    char input;
    printf("> ");
    scanf(" %c", &input);
    return input;
}

// Check if the player can move in a given direction
int canMove(char direction) {
    switch (direction) {
        case 'n':
            return currentRoom->north != NULL;
        case 's':
            return currentRoom->south != NULL;
        case 'e':
            return currentRoom->east != NULL;
        case 'w':
            return currentRoom->west != NULL;
        default:
            return 0;
    }
}

// Move the player in a given direction
void movePlayer(char direction) {
    switch (direction) {
        case 'n':
            currentRoom = currentRoom->north;
            break;
        case 's':
            currentRoom = currentRoom->south;
            break;
        case 'e':
            currentRoom = currentRoom->east;
            break;
        case 'w':
            currentRoom = currentRoom->west;
            break;
    }
}

// Play the game
void playGame() {
    while (1) {
        printRoomDescription();
        char input = getInput();
        if (input == 'q') {
            break;
        } else if (input == 'n' || input == 's' || input == 'e' || input == 'w') {
            if (canMove(input)) {
                movePlayer(input);
            } else {
                printf("You can't go that way.\n");
            }
        } else {
            printf("Invalid input. Please enter 'n', 's', 'e', 'w', or 'q' to quit.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    initMansion();
    playGame();
    return 0;
}