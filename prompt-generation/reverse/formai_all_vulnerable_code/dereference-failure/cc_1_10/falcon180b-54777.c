//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game's introduction
void introduction() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You find yourself in a dark and mysterious forest.\n");
    printf("The air is thick with mist, and the only sound you hear is the rustling of leaves under your feet.\n");
    printf("As you look around, you notice a faint light in the distance.\n");
    printf("Do you dare venture towards it?\n\n");
}

// Function to print the game's instructions
void instructions() {
    printf("To play the game, simply type your choice of action.\n");
    printf("For example, if you want to move forward, type'move forward'.\n");
    printf("You can also interact with objects by typing 'interact' followed by the object's name.\n");
    printf("Good luck on your adventure!\n\n");
}

// Function to handle user input
void handle_input(char* input) {
    char* action = strtok(input, " ");
    char* object = strtok(NULL, " ");

    if (strcmp(action, "move") == 0) {
        if (strcmp(object, "forward") == 0) {
            printf("You take a step forward and feel the ground beneath your feet.\n");
        } else if (strcmp(object, "backward") == 0) {
            printf("You take a step backward and feel the ground beneath your feet.\n");
        } else {
            printf("Invalid direction.\n");
        }
    } else if (strcmp(action, "interact") == 0) {
        if (strcmp(object, "light") == 0) {
            printf("As you approach the light, you realize it's coming from a lantern hanging on a tree.\n");
            printf("Do you want to take the lantern? (y/n)\n");
            char choice;
            scanf("%c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("You take the lantern and hold it in your hand.\n");
            } else {
                printf("You leave the lantern hanging on the tree.\n");
            }
        } else {
            printf("There's nothing here to interact with.\n");
        }
    } else {
        printf("Invalid action.\n");
    }
}

// Main function
int main() {
    srand(time(NULL));

    introduction();
    instructions();

    char input[100];
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        handle_input(input);
    }

    return 0;
}