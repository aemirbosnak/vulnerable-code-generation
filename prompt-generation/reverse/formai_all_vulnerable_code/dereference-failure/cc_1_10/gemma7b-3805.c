//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 5

typedef struct Room {
    char name[20];
    struct Room* nextRoom;
    int treasures;
} Room;

void createRoom(Room** head, char* name, int treasures) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->nextRoom = NULL;
    newRoom->treasures = treasures;
    *head = newRoom;
}

int main() {
    srand(time(NULL));

    Room* head = NULL;
    createRoom(&head, "The Grand Hall", 5);
    createRoom(&head, "The Library", 3);
    createRoom(&head, "The Kitchen", 2);
    createRoom(&head, "The Bedroom", 1);

    // Player starts in The Grand Hall
    Room* currentRoom = head;
    printf("You are in the %s.\n", currentRoom->name);

    // Game loop
    int isAlive = 1;
    while (isAlive) {
        // Print available actions
        printf("What do you want to do? (a) Attack, (b) Search, (c) Travel\n");

        // Get user input
        char input[20];
        scanf("%s", input);

        // Check user input
        switch (input[0]) {
            case 'a':
                // Attack the current room's treasures
                printf("You have stolen %d treasures.\n", currentRoom->treasures);
                currentRoom->treasures = 0;
                break;
            case 'b':
                // Search the current room for treasures
                printf("You have found %d treasures.\n", currentRoom->treasures);
                currentRoom->treasures = 0;
                break;
            case 'c':
                // Travel to the next room
                currentRoom = currentRoom->nextRoom;
                printf("You are in the %s.\n", currentRoom->name);
                break;
            default:
                // Invalid input
                printf("Invalid input.\n");
                break;
        }

        // Check if the player is still alive
        if (currentRoom->treasures == 0) {
            isAlive = 0;
            printf("You have won!\n");
        }
    }

    return 0;
}