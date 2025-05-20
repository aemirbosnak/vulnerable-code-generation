//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 5

typedef struct Room {
    char name[20];
    struct Room* next;
} Room;

Room* createRoom(char* name) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

int main() {
    Room* rooms[MAX_ROOM] = {
        createRoom("The Dark Alley"),
        createRoom("The Neon Bar"),
        createRoom("The Cybernetic Lab"),
        createRoom("The Ancient Temple"),
        createRoom("The Final Boss")
    };

    connectRooms(rooms[0], rooms[1]);
    connectRooms(rooms[1], rooms[2]);
    connectRooms(rooms[2], rooms[3]);
    connectRooms(rooms[3], rooms[4]);

    printf("Welcome to the neon-lit city of Cyberia!\n");

    // The player's current position
    Room* currentRoom = rooms[0];

    // The player's command
    char command[20];

    // Game loop
    while (1) {
        // Display the current room's name
        printf("You are in: %s\n", currentRoom->name);

        // Get the player's command
        printf("Enter your command: ");
        scanf("%s", command);

        // Check if the player wants to go north, south, east, or west
        if (strcmp(command, "north") == 0) {
            if (currentRoom->next) {
                currentRoom = currentRoom->next;
            } else {
                printf("There is no way to go north.\n");
            }
        } else if (strcmp(command, "south") == 0) {
            if (currentRoom->next) {
                currentRoom = currentRoom->next->next;
            } else {
                printf("There is no way to go south.\n");
            }
        } else if (strcmp(command, "east") == 0) {
            printf("There is no way to go east.\n");
        } else if (strcmp(command, "west") == 0) {
            printf("There is no way to go west.\n");
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}