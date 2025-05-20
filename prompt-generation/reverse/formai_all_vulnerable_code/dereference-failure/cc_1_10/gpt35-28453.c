//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// function to print game instructions
void printInstructions() {
    printf("Welcome to Adventure Island!\n\n");
    printf("You have been stranded on a deserted island after your plane crashed.\n");
    printf("Your goal is to find a way off the island and get back home.\n");
    printf("You will encounter various challenges along the way, be prepared!\n\n");
    printf("Commands:\n");
    printf("  go [north | south | east | west]\n");
    printf("  look\n");
    printf("  inventory\n");
    printf("  take [item]\n");
    printf("  use [item]\n");
    printf("  help\n\n");
}

// function to handle "help" command
void help() {
    printf("Commands:\n");
    printf("  go [north | south | east | west]\n");
    printf("    Move in the specified direction.\n");
    printf("  look\n");
    printf("    Look around the current room.\n");
    printf("  inventory\n");
    printf("    Display your inventory.\n");
    printf("  take [item]\n");
    printf("    Take the specified item.\n");
    printf("  use [item]\n");
    printf("    Use the specified item.\n");
    printf("  help\n");
    printf("    Display this help message.\n\n");
}

// function to handle "go" command
void go(char *direction, int *currentRoom) {
    if (strcmp(direction, "north") == 0) {
        *currentRoom += 10;
        printf("You go north.\n");
    } else if (strcmp(direction, "south") == 0) {
        *currentRoom -= 10;
        printf("You go south.\n");
    } else if (strcmp(direction, "east") == 0) {
        *currentRoom += 1;
        printf("You go east.\n");
    } else if (strcmp(direction, "west") == 0) {
        *currentRoom -= 1;
        printf("You go west.\n");
    } else {
        printf("Invalid direction.\n");
    }
}

// function to handle "look" command
void look(int currentRoom, char *rooms[]) {
    printf("You are in %s.\n", rooms[currentRoom]);
}

// function to handle "inventory" command
void inventory(char *inventoryItems[], int numInventoryItems) {
    if (numInventoryItems == 0) {
        printf("You have no items.\n");
    } else {
        printf("Your inventory contains:\n");
        for (int i = 0; i < numInventoryItems; i++) {
            printf("  %s\n", inventoryItems[i]);
        }
    }
}

// function to handle "take" command
void take(char *item, char *rooms[], int currentRoom, char *inventoryItems[], int *numInventoryItems) {
    int found = 0;
    for (int i = 0; i < strlen(rooms[currentRoom]); i++) {
        if (rooms[currentRoom][i] == *item) {
            found = 1;
            break;
        }
    }
    if (found) {
        inventoryItems[*numInventoryItems] = item;
        (*numInventoryItems)++;
        printf("You take the %s.\n", item);
    } else {
        printf("That item is not here to take.\n");
    }
}

// function to handle "use" command
void use(char *item, char *inventoryItems[], int numInventoryItems) {
    int found = 0;
    for (int i = 0; i < numInventoryItems; i++) {
        if (strcmp(inventoryItems[i], item) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("You use the %s.\n", item);
    } else {
        printf("You don't have that item.\n");
    }
}

// game thread function
void *game(void *arg) {
    int currentRoom = 0;
    char *inventoryItems[10];
    int numInventoryItems = 0;
    char *rooms[] = {"the starting room", "the big tree", "the river", "the cave", "the beach"};
    printf("You wake up on a deserted island.\n");
    while (1) {
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);
        strtok(input, "\n");
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, "");
        if (strcmp(command, "help") == 0) {
            help();
        } else if (strcmp(command, "go") == 0) {
            if (argument == NULL) {
                printf("Invalid command.\n");
            } else {
                go(argument, &currentRoom);
            }
        } else if (strcmp(command, "look") == 0) {
            look(currentRoom, rooms);
        } else if (strcmp(command, "inventory") == 0) {
            inventory(inventoryItems, numInventoryItems);
        } else if (strcmp(command, "take") == 0) {
            if (argument == NULL) {
                printf("Invalid command.\n");
            } else {
                take(argument, rooms, currentRoom, inventoryItems, &numInventoryItems);
            }
        } else if (strcmp(command, "use") == 0) {
            if (argument == NULL) {
                printf("Invalid command.\n");
            } else {
                use(argument, inventoryItems, numInventoryItems);
            }
        } else {
            printf("Invalid command.\n");
        }
    }
}

// main function
int main() {
    pthread_t thread;
    int result = pthread_create(&thread, NULL, game, NULL);
    if (result != 0) {
        printf("Error creating thread.\n");
        return 1;
    }
    pthread_join(thread, NULL);
    return 0;
}