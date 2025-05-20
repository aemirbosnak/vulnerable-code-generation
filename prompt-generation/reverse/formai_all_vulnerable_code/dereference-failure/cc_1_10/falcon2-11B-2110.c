//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print out the haunted house
void printHauntedHouse() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("=========================================\n");
    printf("|                               |\n");
    printf("|                               |\n");
    printf("|   A Haunted House           |\n");
    printf("|                               |\n");
    printf("|                               |\n");
    printf("=========================================\n");
}

// Function to handle user input
void handleInput() {
    char input[100];
    printf("Enter a command: ");
    fgets(input, sizeof(input), stdin);
    
    // Split the input into separate commands
    char* command = strtok(input, " ");
    char* subcommand = strtok(NULL, " ");
    
    if (strcmp(command, "look") == 0) {
        if (strcmp(subcommand, "room") == 0) {
            printf("You are in the foyer.\n");
        } else if (strcmp(subcommand, "haunted") == 0) {
            printf("The room is haunted.\n");
        } else {
            printf("Invalid subcommand.\n");
        }
    } else if (strcmp(command, "move") == 0) {
        if (strcmp(subcommand, "up") == 0) {
            printf("You move up the stairs.\n");
        } else if (strcmp(subcommand, "down") == 0) {
            printf("You move down the stairs.\n");
        } else if (strcmp(subcommand, "left") == 0) {
            printf("You move to the left.\n");
        } else if (strcmp(subcommand, "right") == 0) {
            printf("You move to the right.\n");
        } else {
            printf("Invalid subcommand.\n");
        }
    } else if (strcmp(command, "exit") == 0) {
        printf("Thank you for playing the Haunted House Simulator!\n");
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    printHauntedHouse();
    
    while (1) {
        handleInput();
    }
    
    return 0;
}