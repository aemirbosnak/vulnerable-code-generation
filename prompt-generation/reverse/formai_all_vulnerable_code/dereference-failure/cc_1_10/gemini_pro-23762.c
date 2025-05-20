//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

room* createRoom(char* name, char* description) {
    room* newRoom = malloc(sizeof(room));
    newRoom->name = strdup(name);
    newRoom->description = strdup(description);
    newRoom->north = NULL;
    newRoom->east = NULL;
    newRoom->south = NULL;
    newRoom->west = NULL;
    return newRoom;
}

void freeRoom(room* room) {
    free(room->name);
    free(room->description);
    free(room);
}

room* rooms[MAX_ROOMS];
int numRooms = 0;

void addRoom(room* room) {
    rooms[numRooms++] = room;
}

void printRoom(room* room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
}

void printCommands() {
    printf("Commands:\n");
    printf(" - go north\n");
    printf(" - go east\n");
    printf(" - go south\n");
    printf(" - go west\n");
    printf(" - look\n");
    printf(" - quit\n");
}

void look(room* room) {
    printRoom(room);
}

void goNorth(room** room) {
    if ((*room)->north != NULL) {
        *room = (*room)->north;
    } else {
        printf("You can't go that way!\n");
    }
}

void goEast(room** room) {
    if ((*room)->east != NULL) {
        *room = (*room)->east;
    } else {
        printf("You can't go that way!\n");
    }
}

void goSouth(room** room) {
    if ((*room)->south != NULL) {
        *room = (*room)->south;
    } else {
        printf("You can't go that way!\n");
    }
}

void goWest(room** room) {
    if ((*room)->west != NULL) {
        *room = (*room)->west;
    } else {
        printf("You can't go that way!\n");
    }
}

int main() {
    // Create rooms
    room* room1 = createRoom("Room 1", "This is room 1.");
    room* room2 = createRoom("Room 2", "This is room 2.");
    room* room3 = createRoom("Room 3", "This is room 3.");
    room* room4 = createRoom("Room 4", "This is room 4.");
    room* room5 = createRoom("Room 5", "This is room 5.");

    // Connect rooms
    room1->north = room2;
    room1->east = room3;
    room2->south = room1;
    room2->east = room4;
    room3->west = room1;
    room3->north = room5;
    room4->west = room2;
    room5->south = room3;

    // Add rooms to array
    addRoom(room1);
    addRoom(room2);
    addRoom(room3);
    addRoom(room4);
    addRoom(room5);

    // Start in room 1
    room* currentRoom = room1;

    // Main game loop
    while (1) {
        // Print room description
        printRoom(currentRoom);

        // Print commands
        printCommands();

        // Get user input
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);

        // Parse input
        char* command = strtok(input, " ");
        char* argument = strtok(NULL, " ");

        // Execute command
        if (strcmp(command, "go") == 0) {
            if (strcmp(argument, "north") == 0) {
                goNorth(&currentRoom);
            } else if (strcmp(argument, "east") == 0) {
                goEast(&currentRoom);
            } else if (strcmp(argument, "south") == 0) {
                goSouth(&currentRoom);
            } else if (strcmp(argument, "west") == 0) {
                goWest(&currentRoom);
            } else {
                printf("Invalid direction!\n");
            }
        } else if (strcmp(command, "look") == 0) {
            look(currentRoom);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    // Free rooms
    for (int i = 0; i < numRooms; i++) {
        freeRoom(rooms[i]);
    }

    return 0;
}