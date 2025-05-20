//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 50

// Function to print out the game's introduction
void printIntro() {
    printf("Welcome to the Mysterious Island!\n\n");
    sleep(1);
    printf("You find yourself stranded on an island after your plane crashes.\n\n");
    sleep(1);
    printf("Your goal is to survive and find a way off the island.\n\n");
    sleep(1);
    printf("You look around and see three paths in front of you.\n\n");
    sleep(1);
    printf("Which path will you take?\n");
}

// Function to get user input
char *getUserInput() {
    char *input = malloc(MAX_INPUT);
    fgets(input, MAX_INPUT, stdin);
    return input;
}

int main() {
    // Print out the game introduction
    printIntro();
    
    // Define variables for user input and game state
    char *input;
    int gameWon = 0;
    int health = 100;
    int food = 50;
    int water = 50;
    
    // Loop through the game until the player wins or dies
    while(!gameWon && health > 0) {
        // Get user input and convert to lower case for easy comparison
        input = getUserInput();
        for(int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }
        
        // Check user input and update game state accordingly
        if(strstr(input, "left")) {
            printf("You follow the left path.\n\n");
            sleep(1);
            printf("You find a freshwater stream and refill your water bottles.\n\n");
            water = 100;
        } else if(strstr(input, "middle")) {
            printf("You follow the middle path.\n\n");
            sleep(1);
            printf("You come across a wild boar.\n\n");
            sleep(1);
            printf("Do you try to hunt it for food?\n");
            input = getUserInput();
            for(int i = 0; i < strlen(input); i++) {
                input[i] = tolower(input[i]);
            }
            if(strstr(input, "yes")) {
                printf("You successfully hunt the boar and gain 25 food.\n\n");
                food += 25;
            } else {
                printf("You decide to leave the boar alone and continue on your way.\n\n");
            }
        } else if(strstr(input, "right")) {
            printf("You follow the right path.\n\n");
            sleep(1);
            printf("You come across a cave entrance.\n\n");
            sleep(1);
            printf("Do you want to explore the cave?\n");
            input = getUserInput();
            for(int i = 0; i < strlen(input); i++) {
                input[i] = tolower(input[i]);
            }
            if(strstr(input, "yes")) {
                printf("You enter the cave and find a treasure chest.\n\n");
                sleep(1);
                printf("You open the chest and find a map of the island.\n\n");
                sleep(1);
                printf("The map shows the location of a nearby village.\n\n");
                sleep(1);
                printf("You make your way to the village and are rescued by a passing boat.\n\n");
                gameWon = 1;
            } else {
                printf("You decide not to explore the cave and continue on your way.\n\n");
            }
        } else {
            printf("Sorry, I didn't understand your command. Please try again.\n");
        }
        
        // Update health based on thirst and hunger
        water -= 10;
        food -= 20;
        if(water <= 0) {
            health -= 20;
            printf("You are dehydrated and lose 20 health.\n\n");
            water = 0;
        }
        if(food <= 0) {
            health -= 10;
            printf("You are hungry and lose 10 health.\n\n");
            food = 0;
        }
        
        // Print out current game state
        printf("Current Health: %d\n", health);
        printf("Current Water: %d\n", water);
        printf("Current Food: %d\n\n", food);
    }
    
    // Print out game over message
    if(health <= 0) {
        printf("You have died.\n\n");
    } else {
        printf("Congratulations, you have escaped the island!\n\n");
    }
    
    // Free memory and exit program
    free(input);
    return 0;
}