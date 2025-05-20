//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to handle player input
char *getInput() {
    char *input = malloc(100);
    scanf("%s", input);
    return input;
}

// Function to run the game loop
void runGame() {
    // Initialize the game state
    int gameOver = 0;
    char *currentRoom = "start";

    while (!gameOver) {
        // Print the current room description
        printf("You are in the %s.\n", currentRoom);

        // Get player input
        char *input = getInput();

        // Process player input
        if (strcmp(input, "quit") == 0) {
            gameOver = 1;
        } else if (strcmp(input, "go north") == 0) {
            if (strcmp(currentRoom, "start") == 0) {
                currentRoom = "room1";
            } else if (strcmp(currentRoom, "room1") == 0) {
                currentRoom = "room2";
            } else if (strcmp(currentRoom, "room2") == 0) {
                currentRoom = "end";
            }
        } else if (strcmp(input, "go south") == 0) {
            if (strcmp(currentRoom, "room2") == 0) {
                currentRoom = "room1";
            } else if (strcmp(currentRoom, "room1") == 0) {
                currentRoom = "start";
            }
        } else {
            printf("Invalid input.\n");
        }

        // Free the input string
        free(input);
    }
}

int main() {
    // Run the game loop
    runGame();

    return 0;
}