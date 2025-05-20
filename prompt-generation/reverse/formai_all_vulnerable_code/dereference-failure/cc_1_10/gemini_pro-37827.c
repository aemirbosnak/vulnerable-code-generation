//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store room data
typedef struct Room {
    int id;
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

// Function to create a new room
Room *createRoom(int id, char *description) {
    Room *room = malloc(sizeof(Room));
    room->id = id;
    room->description = description;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

// Function to connect two rooms
void connectRooms(Room *room1, Room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

// Function to print the description of a room
void printRoom(Room *room) {
    printf("%s\n", room->description);
    if (room->north != NULL) {
        printf("To the north, you see %s.\n", room->north->description);
    }
    if (room->south != NULL) {
        printf("To the south, you see %s.\n", room->south->description);
    }
    if (room->east != NULL) {
        printf("To the east, you see %s.\n", room->east->description);
    }
    if (room->west != NULL) {
        printf("To the west, you see %s.\n", room->west->description);
    }
}

// Function to play the game
void playGame() {
    // Create the rooms
    Room *room1 = createRoom(1, "You are in a dark and musty room. The air is thick with the smell of decay. You can hear the sound of dripping water in the distance.");
    Room *room2 = createRoom(2, "You are in a dimly lit room. The walls are covered in strange symbols. There is a large table in the center of the room, with a book lying open on it.");
    Room *room3 = createRoom(3, "You are in a large and empty room. The walls are bare and the floor is covered in dust. There is a single window in the far wall, but it is boarded up.");
    Room *room4 = createRoom(4, "You are in a small and cozy room. The walls are painted a cheerful yellow color, and there is a fireplace in the corner. There is a bed in the middle of the room, with a book lying open on the bedside table.");

    // Connect the rooms
    connectRooms(room1, room2, 'n');
    connectRooms(room2, room3, 'e');
    connectRooms(room3, room4, 's');
    connectRooms(room4, room1, 'w');

    // Start the game in room 1
    Room *currentRoom = room1;

    // Loop until the player quits the game
    while (1) {
        // Print the description of the current room
        printRoom(currentRoom);

        // Get the player's input
        char input[80];
        printf("> ");
        fgets(input, 80, stdin);

        // Parse the player's input
        char command[80];
        char argument[80];
        sscanf(input, "%s %s", command, argument);

        // Execute the player's command
        if (strcmp(command, "go") == 0) {
            // Move to the specified room
            if (strcmp(argument, "north") == 0) {
                currentRoom = currentRoom->north;
            } else if (strcmp(argument, "south") == 0) {
                currentRoom = currentRoom->south;
            } else if (strcmp(argument, "east") == 0) {
                currentRoom = currentRoom->east;
            } else if (strcmp(argument, "west") == 0) {
                currentRoom = currentRoom->west;
            } else {
                printf("Invalid direction.\n");
            }
        } else if (strcmp(command, "look") == 0) {
            // Print the description of the current room
            printRoom(currentRoom);
        } else if (strcmp(command, "quit") == 0) {
            // Quit the game
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    // Free the memory used by the rooms
    free(room1);
    free(room2);
    free(room3);
    free(room4);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    playGame();

    return 0;
}