//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

typedef struct Room {
    char name[20];
    struct Room *next;
    int items;
    int visited;
} Room;

Room *createRoom(char *name, int items) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->items = items;
    newRoom->visited = 0;
    return newRoom;
}

void playGame() {
    Room *currentRoom = createRoom("The Hallway", 5);
    Room *northRoom = createRoom("The Kitchen", 3);
    Room *southRoom = createRoom("The Bedroom", 2);

    currentRoom->next = northRoom;
    currentRoom->next = southRoom;

    // Game loop
    while (1) {
        printf("You are in %s. What do you want to do? (north, south, east, west, inventory, quit): ", currentRoom->name);
        char input[20];
        scanf("%s", input);

        // Check if the input is valid
        if (strcmp(input, "north") == 0 || strcmp(input, "south") == 0 || strcmp(input, "east") == 0 || strcmp(input, "west") == 0 || strcmp(input, "inventory") == 0 || strcmp(input, "quit") == 0) {
            // Execute the action
            if (strcmp(input, "north") == 0) {
                currentRoom = northRoom;
            } else if (strcmp(input, "south") == 0) {
                currentRoom = southRoom;
            } else if (strcmp(input, "east") == 0) {} else if (strcmp(input, "west") == 0) {} else if (strcmp(input, "inventory") == 0) {
                // Show inventory items
            } else if (strcmp(input, "quit") == 0) {
                printf("Thank you for playing! Goodbye!\n");
                exit(0);
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

int main() {
    playGame();

    return 0;
}