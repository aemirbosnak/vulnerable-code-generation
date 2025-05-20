//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Function to generate a random integer between min and max
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if two strings are equal
bool isEqual(char* str1, char* str2) {
    return strcmp(str1, str2) == 0;
}

// Function to wait for user input
char* waitForInput() {
    char* input = (char*)malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    // replace newline character with null character
    input[strlen(input)-1] = '\0';
    return input;
}

// Function to display the game title
void showTitle() {
    printf("\nWelcome to The Adventure Game!\n");
    printf("************************************\n");
}

// Function to display the game introduction
void showIntro() {
    printf("\nYou are about to embark on an exciting adventure!\n");
    printf("You find yourself in a magical land full of wonder and danger.\n");
    printf("Your quest is to find the fabled treasure of ancient kings.\n");
    printf("But beware, many have tried and failed.\n");
    printf("Are you brave enough to succeed where others have failed?\n");
}

int main() {
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Display the game title and introduction
    showTitle();
    showIntro();
    
    // GAME LOOP
    char* currentLocation = "forest";
    bool gameOver = false;
    while (!gameOver) {
        
        // Display the current location and ask for user input
        printf("\nYou are in the %s.\n", currentLocation);
        printf("What would you like to do?\n");
        char* userInput = waitForInput();
        
        // Check if the user wants to quit
        if (isEqual(userInput, "quit")) {
            gameOver = true;
            printf("\nThanks for playing! Goodbye!\n");
            break;
        }
        
        // Check if the user wants to look around
        if (isEqual(userInput, "look")) {
            // Generate a random description of the current location
            int randomNum = randomInt(1, 3);
            if (isEqual(currentLocation, "forest")) {
                switch (randomNum) {
                    case 1: printf("\nYou see trees all around you, their branches swaying in the breeze.\n"); break;
                    case 2: printf("\nYou can hear a babbling brook nearby, but you can't see it through the dense foliage.\n"); break;
                    case 3: printf("\nYou sense that you are being watched... but you can't see anything out of the ordinary.\n"); break;
                }
            }
            else if (isEqual(currentLocation, "mountain")) {
                switch (randomNum) {
                    case 1: printf("\nYou are surrounded by towering peaks, their snow-capped summits glistening in the sunlight.\n"); break;
                    case 2: printf("\nYou can see a faint path winding its way up the mountain, but it looks treacherous.\n"); break;
                    case 3: printf("\nYou feel the wind whipping around you, as if it is trying to push you back down the mountain.\n"); break;
                }
            }
            else if (isEqual(currentLocation, "cave")) {
                switch (randomNum) {
                    case 1: printf("\nYou can barely see your hand in front of your face in the darkness.\n"); break;
                    case 2: printf("\nYou hear strange noises coming from deeper inside the cave.\n"); break;
                    case 3: printf("\nYour torch flickers and sputters, casting eerie shadows on the walls.\n"); break;
                }
            }
        }
        
        // Check if the user wants to move to a different location
        if (isEqual(userInput, "north") || isEqual(userInput, "east") || isEqual(userInput, "south") || isEqual(userInput, "west")) {
            if (isEqual(currentLocation, "forest")) {
                if (isEqual(userInput, "north")) {
                    currentLocation = "mountain";
                }
                else if (isEqual(userInput, "east")) {
                    printf("\nYou can't go that way.\n");
                }
                else if (isEqual(userInput, "south")) {
                    printf("\nYou can't go that way.\n");
                }
                else if (isEqual(userInput, "west")) {
                    printf("\nYou can't go that way.\n");
                }
            }
            else if (isEqual(currentLocation, "mountain")) {
                if (isEqual(userInput, "north")) {
                    printf("\nYou can't go that way.\n");
                }
                else if (isEqual(userInput, "east")) {
                    printf("\nYou can't go that way.\n");
                }
                else if (isEqual(userInput, "south")) {
                    currentLocation = "forest";
                }
                else if (isEqual(userInput, "west")) {
                    currentLocation = "cave";
                }
            }
            else if (isEqual(currentLocation, "cave")) {
                if (isEqual(userInput, "north")) {
                    printf("\nYou can't go that way.\n");
                }
                else if (isEqual(userInput, "east")) {
                    currentLocation = "mountain";
                }
                else if (isEqual(userInput, "south")) {
                    printf("\nYou can't go that way.\n");
                }
                else if (isEqual(userInput, "west")) {
                    printf("\nYou can't go that way.\n");
                }
            }
        }
        
        // Check if the user wants to do something else
        if (!isEqual(userInput, "look") && !isEqual(userInput, "north") && !isEqual(userInput, "east") && !isEqual(userInput, "south") && !isEqual(userInput, "west")) {
            printf("\nI don't understand what you want to do.\n");
        }
        
        // Free memory for user input
        free(userInput);
    }
    
    return 0;
}