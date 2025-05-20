//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Haunted House Simulator\n");
    printf("Please choose your path:\n");
    printf("1. The Creaky Staircase\n");
    printf("2. The Haunted Library\n");
    printf("3. The Ghostly Kitchen\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You are now entering the Creaky Staircase.\n");
            printf("As you step onto the first step, it creaks loudly beneath your feet.\n");
            printf("The sound echoes through the empty house, sending chills down your spine.\n");
            printf("You continue up the staircase, each step creaking louder than the last.\n");
            printf("Suddenly, you hear a blood-curdling scream coming from upstairs.\n");
            printf("Do you continue up the staircase (Y/N)? ");
            char answer;
            scanf(" %c", &answer);
            if(answer == 'Y' || answer == 'y') {
                printf("You bravely continue up the staircase, your heart pounding in your chest.\n");
                printf("As you reach the top, you see a ghostly figure floating in the air.\n");
                printf("The figure lets out another scream and disappears into thin air.\n");
                printf("Congratulations! You have survived the Creaky Staircase.\n");
            } else {
                printf("You decide to turn back, your fear getting the best of you.\n");
            }
            break;
        case 2:
            printf("You are now entering the Haunted Library.\n");
            printf("As you walk through the rows of dusty books, you hear whispers coming from the shelves.\n");
            printf("The whispers grow louder and more urgent, as if the books are trying to tell you something.\n");
            printf("Suddenly, a book flies off the shelf and hits you in the head.\n");
            printf("Do you continue exploring the library (Y/N)? ");
            scanf(" %c", &answer);
            if(answer == 'Y' || answer == 'y') {
                printf("You shake off the pain and continue exploring the library.\n");
                printf("As you turn a corner, you come face to face with a ghostly librarian.\n");
                printf("The librarian glares at you with glowing red eyes and lets out an ear-piercing scream.\n");
                printf("You run out of the library, never looking back.\n");
                printf("Congratulations! You have survived the Haunted Library.\n");
            } else {
                printf("You decide to leave the library, your head throbbing from the book that hit you.\n");
            }
            break;
        case 3:
            printf("You are now entering the Ghostly Kitchen.\n");
            printf("As you step into the kitchen, you see pots and pans floating in the air.\n");
            printf("A ghostly chef appears before you, wielding a large knife.\n");
            printf("The chef lunges at you, but you dodge out of the way.\n");
            printf("Do you fight the chef (Y/N)? ");
            scanf(" %c", &answer);
            if(answer == 'Y' || answer == 'y') {
                printf("You grab a frying pan and engage in a fierce battle with the chef.\n");
                printf("After a long and grueling fight, you finally defeat the chef.\n");
                printf("Congratulations! You have survived the Ghostly Kitchen.\n");
            } else {
                printf("You decide to run away, leaving the chef to his ghostly cooking.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}