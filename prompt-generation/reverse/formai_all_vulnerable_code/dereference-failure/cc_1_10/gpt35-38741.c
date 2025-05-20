//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Room {
    char* name;
    char* description;
    int numConnections;
    struct Room** connections;
    int isEndRoom;
} Room;

// Function to return a random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to connect two rooms together
void connectRooms(Room* roomA, Room* roomB) {
    roomA->connections[roomA->numConnections] = roomB;
    roomA->numConnections++;
    roomB->connections[roomB->numConnections] = roomA;
    roomB->numConnections++;
}

// Function to initialize a new room
Room* initRoom(char* name, char* description) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->name = name;
    newRoom->description = description;
    newRoom->numConnections = 0;
    newRoom->connections = malloc(sizeof(Room*)*6);
    newRoom->isEndRoom = 0;

    return newRoom;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Define the room names and descriptions
    char* roomNames[10] = {
        "Kitchen",
        "Living Room",
        "Bedroom",
        "Bathroom",
        "Dining Room",
        "Garage",
        "Basement",
        "Attic",
        "Library",
        "Study"
    };

    char* roomDescriptions[10] = {
        "This room has marble countertops and stainless steel appliances.",
        "There is a large television and comfortable couches in this room.",
        "There is a large bed and a dresser in this room.",
        "This room has a shower, toilet, and sink.",
        "There is a large wooden table and chairs in this room.",
        "This room has tools and a car inside.",
        "This room is dark and musty.",
        "This room has boxes and cobwebs scattered around.",
        "This room has many rows of bookshelves filled with books.",
        "This room has a large desk and computer."
    };

    // Define the start and end rooms
    int startRoomIndex = getRandomInt(0,9);
    int endRoomIndex = getRandomInt(0,9);
    while (endRoomIndex == startRoomIndex) { // Make sure the start and end rooms aren't the same
        endRoomIndex = getRandomInt(0,9);
    }

    // Create the rooms
    Room* rooms[10];
    int i;
    for (i = 0; i < 10; i++) {
        rooms[i] = initRoom(roomNames[i], roomDescriptions[i]);
        if (i == startRoomIndex) {
            rooms[i]->connections[0] = initRoom(roomNames[i], roomDescriptions[i]); // Set the start room to connect to itself
            rooms[i]->numConnections = 1;
        } else if (i == endRoomIndex) {
            rooms[i]->isEndRoom = 1; // Set the end room to be the end room
        }
    }

    // Connect the rooms together
    while (1) {
        int roomIndexA = getRandomInt(0,9);
        int roomIndexB = getRandomInt(0,9);
        if (roomIndexA == roomIndexB) { // Make sure the two rooms aren't the same
            continue;
        }

        if (rooms[roomIndexA]->numConnections < 6 && rooms[roomIndexB]->numConnections < 6) { // Make sure the rooms aren't already connected
            connectRooms(rooms[roomIndexA], rooms[roomIndexB]);
        }

        // Check if all rooms have at least 3 connections
        int allConnected = 1;
        for (i = 0; i < 10; i++) {
            if (rooms[i]->numConnections < 3) {
                allConnected = 0;
                break;
            }
        }
        if (allConnected) {
            break;
        }
    }

    // Set up the game
    Room* currentRoom = rooms[startRoomIndex]->connections[0];
    int stepsTaken = 0;
    char* path[100];
    int pathIndex = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are starting in the %s.\n", currentRoom->name);

    // Start the game loop
    while (1) {
        printf("You are currently in the %s.\n", currentRoom->name);
        printf("%s\n", currentRoom->description);

        // Check if the current room is the end room
        if (currentRoom->isEndRoom) {
            printf("Congratulations, you made it to the end room in %d steps!\n", stepsTaken);
            printf("Your path was:\n");
            int j;
            for (j = 0; j < pathIndex; j++) {
                printf("%s\n", path[j]);
            }
            break;
        }

        // Get the user's next move
        char userInput[256];
        printf("Where would you like to go next? Enter the name of the room.\n");
        fgets(userInput, 256, stdin);
        userInput[strcspn(userInput, "\n")] = 0; // Remove the newline character at the end of the input

        // Check if the user wants to see their path
        if (strcmp(userInput, "path") == 0) {
            printf("Your path so far is:\n");
            int j;
            for (j = 0; j < pathIndex; j++) {
                printf("%s\n", path[j]);
            }
            continue;
        }

        // Check if the user entered a valid room name
        int isValidRoom = 0;
        int k;
        for (k = 0; k < currentRoom->numConnections; k++) {
            if (strcmp(userInput, currentRoom->connections[k]->name) == 0) {
                currentRoom = currentRoom->connections[k];
                stepsTaken++;
                path[pathIndex] = currentRoom->name;
                pathIndex++;
                isValidRoom = 1;
                break;
            }
        }
        if (!isValidRoom) {
            printf("Sorry, that is not a valid room name. Please try again.\n");
        }
    }

    // Free the memory
    for (i = 0; i < 10; i++) {
        free(rooms[i]->connections);
        free(rooms[i]);
    }

    return 0;
}