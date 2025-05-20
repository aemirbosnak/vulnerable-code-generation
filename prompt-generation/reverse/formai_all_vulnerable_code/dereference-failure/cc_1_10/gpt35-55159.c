//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 50
#define MAX_ACTION_SIZE 10

/* Here are the prototypes for the functions used in the program */
void startGame();
void playGame();
void printIntro();
void printHelp();
void printWin();
void printLose(char *);
void cleanInput(char *);
bool match(char *, char *);
void takeAction(char**, char**, int);
void move(char**, char**, int);
void look(char**, char**, int);

int main() {
    startGame();
    return 0;
}
 
/*
 * Function: startGame
 * ----------------------------
 * This function prints the game introduction and starts the main game loop.
 * 
 * returns: void
*/ 
void startGame() {
    char *input = malloc(MAX_INPUT_SIZE * sizeof(char));    // Allocate memory for input string
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printIntro();
    while(true) {
        printf("\n> ");
        fgets(input, MAX_INPUT_SIZE, stdin);                 // Get user input
        cleanInput(input);                                  // Clean the input of any user errors
        playGame(input);                                    // Call the function to play the game with the user's input
    } 
}

/*
 * Function: playGame
 * ----------------------------
 * This function takes the user input and performs an action depending on what the user input is.
 * 
 * input: char* - The user input.
 * 
 * returns: void
*/ 
void playGame(char *input) {
    char *actions[MAX_ACTION_SIZE] = {"help", "take", "move", "look", "quit"};
    char *verbs[MAX_ACTION_SIZE] = {"take", "move", "look"};
    char *current_location = "Start";                       // Initialize location to Start
    char *items = "";                                       // Initialize no items to be in inventory
    bool validAction = false;                               // Flag to check if user's input matches any action
    int i;

    for (i = 0; i < MAX_ACTION_SIZE; i++) {
        if (match(input, actions[i])) {                     // If input matches an available action
            takeAction(&current_location, &items, i);        // Call takeAction function
            validAction = true;                              // Raise flag that input matches action 
            break;
        }
    }
    if (!validAction && input != "") {                       // If input does not match any action and is not empty
        printf("Invalid input. Type 'help' for instructions.\n"); // Prints error message and asks user to type 'help' for instructions
    }   
}

/*
 * Function: printIntro
 * ----------------------------
 * This function prints the game's introduction and main objective.
 * 
 * returns: void
*/ 
void printIntro() {
    printf("You are lost in a forest and have to find your way out.\n");
    printf("You can move and look around to find clues on how to get out.\n");
    printf("You can also take items that you find lying around with you to help you.\n");
    printf("Type 'help' for instructions on how to play the game.\n");   
}

/*
 * Function: printHelp
 * ----------------------------
 * This function prints the game's instructions for the player.
 * 
 * returns: void
*/ 
void printHelp() {
    printf("\nYour objective is to successfully navigate your way out of the forest\n");
    printf("Use the following commands to navigate the game:\n");
    printf("  move <direction> : Moves the player in the specified direction (north, south, east, west)\n");
    printf("  look : Provides a description of the current location and any items in the area\n");
    printf("  take <item> : Adds the specified item to the player's inventory\n");
    printf("  quit : Exits the game\n");
}

/*
 * Function: printWin
 * ----------------------------
 * This function prints the game's win message.
 * 
 * returns: void
*/
void printWin() {
    printf("\nCongratulations! You have successfully navigated your way out of the forest!\n");
    printf("Thanks for playing!\n");
    exit(0);                                                // Exit the game, successful completion!
}

/*
 * Function: printLose
 * ----------------------------
 * This function prints the game's lose message.
 * 
 * returns: void
*/ 
void printLose(char *reason) {
    printf("\nSorry, you lost the game.\n");
    printf("%s\n", reason);
    printf("Thanks for playing!\n");
    exit(0);                                                // Exit the game, unsuccessful completion.
}

/*
 * Function: cleanInput
 * ----------------------------
 * This function checks and removes any excessive spaces in the user's input.
 * 
 * input: char* - The user input.
 * 
 * returns: void
*/ 
void cleanInput(char *input) {
    int i = strlen(input)-1;
    if( input[ i ] == '\n') {       // If the last character of user input is the newline character
        input[i] = '\0';            // Replace the newline character with a Null character
    }
    while(isspace(*input)) {        // Check if the first character in the user input is a whitespace character
        *input++;                   // If it is, point the input to the next character in memory
    }
}

/*
 * Function: match
 * ----------------------------
 * This function compares two strings ignoring cases.
 * 
 * input1: char* - First string to compare.
 *
 * input2: char* - Second string to compare.
 * 
 * returns: bool - True if both strings are the same ignoring cases; False, otherwise.
*/ 
bool match(char *input1, char *input2) {
    char *temp1 = strdup(input1);       // Create temporary copy of input1 to avoid modifying its value
    char *temp2 = strdup(input2);       // Create temporary copy of input2 to avoid modifying its value
    bool result = false;                // Initialize result flag to False
    for (int i = 0; i <= strlen(temp1); i++) {
        temp1[i] = tolower(temp1[i]);   // Convert the characters in temp1 to lowercase
    }
    for (int i = 0; i <= strlen(temp2); i++) {
        temp2[i] = tolower(temp2[i]);   // Convert the characters in temp2 to lowercase
    }
    if (strcmp(temp1, temp2) == 0) {    // Compare the two strings ignoring cases
        result = true;
    }
    free(temp1);                        // Free the memory allocated for temp1
    free(temp2);                        // Free the memory allocated for temp2
    return result;
}

/*
 * Function: takeAction
 * ----------------------------
 * This function determines which action to take based on the user's input.
 * 
 * location: char** - Points to the character string containing the current location.
 *
 * items: char** - Points to the character string containing the inventory.
 * 
 * action: int - The index of the action to perform.
 * 
 * returns: void
*/ 
void takeAction(char **location, char **items, int action) {
    switch (action) {
        case 0:                 // If action is 'help'
            printHelp();
            break;
        case 1:                 // If action is 'take'
            printf("Nothing to take.\n");
            break;
        case 2:                 // If action is 'move'
            move(location, items, action);
            break;
        case 3:                 // If action is 'look'
            look(location, items, action);
            break;
        case 4:                 // If action is 'quit'
            exit(0);
    }
}

/*
 * Function: move
 * ----------------------------
 * This function moves the player to the specified direction. Available directions are north, south, east, and west.
 * 
 * location: char** - Points to the character string containing the current location.
 *
 * items: char** - Points to the character string containing the inventory.
 * 
 * action: int - The index of the action to perform.
 * 
 * returns: void
*/ 
void move(char **location, char **items, int action) {
    char *direction = malloc(MAX_INPUT_SIZE * sizeof(char));
    printf("Which direction?\n");
    fgets(direction, MAX_INPUT_SIZE, stdin);
    cleanInput(direction);
    if (match(direction, "north")) {
        *location = "North";
        printf("Moved to %s\n", *location);
    } else if (match(direction, "south")) {
        *location = "South";
        printf("Moved to %s\n", *location);
    } else if (match(direction, "east")) {
        *location = "East";
        printf("Moved to %s\n", *location);
    } else if (match(direction, "west")) {
        *location = "West";
        printf("Moved to %s\n", *location);
    } else {
        printf("Invalid direction. Type 'look' for locations.\n");
    }
    free(direction);
}

/*
 * Function: look
 * ----------------------------
 * This function describes the current location and any items in it.
 * 
 * location: char** - Points to the character string containing the current location.
 *
 * items: char** - Points to the character string containing the inventory.
 * 
 * action: int - The index of the action to perform.
 * 
 * returns: void
*/ 
void look(char **location, char **items, int action) {
    if (match(*location, "Start")) {
        printf("You are at the start point.\n");  
    } else if (match(*location, "North")) {
        printf("You are at the northern part of the forest.\n");
    } else if (match(*location, "South")) {
        printf("You are at the southern part of the forest.\n");
    } else if (match(*location, "East")) {
        printf("You are at the eastern part of the forest.\n");
    } else if (match(*location, "West")) {
        printf("You are at the western part of the forest.\n");
    } else {
        printf("You found nothing.\n");
    }
}