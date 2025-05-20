//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score = 0;

void printOptions(char* options[], int length) {
    printf("\n");
    for(int i = 0; i < length; i++) {
        printf("%d. %s\n", i+1, options[i]);
    }
    printf("\nChoose an option: ");
}

int main() {
    char* name = (char*) malloc(sizeof(char) * 30);
    char* gender = (char*) malloc(sizeof(char) * 15);
    char* location = (char*) malloc(sizeof(char) * 30);

    printf("Welcome to The Future Adventure Game!\n");
    printf("What is your name? ");
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Hi, %s! Are you male or female? ", name);
    fgets(gender, 15, stdin);
    gender[strcspn(gender, "\n")] = 0;
    
    printf("Where do you want to go: The Moon or Mars? ");
    fgets(location, 30, stdin);
    location[strcspn(location, "\n")] = 0;

    printf("\nWelcome %s to %s!\n", name, location);

    // Start of The Moon game
    if(strcmp(location, "The Moon") == 0) {
        int option;
        char* moonOptions[] = {"Search for a water source", "Go to the nearest cave", "Find old rover parts"};
        int moonOptionsLength = sizeof(moonOptions)/sizeof(char*);

        printf("\nYou have just landed on the Moon. You have limited resources and need to find supplies to survive.\n");
        printf("You can choose from the following options: ");

        do {
            printOptions(moonOptions, moonOptionsLength);
            scanf("%d", &option);
            getchar();

            switch(option) {
                case 1:
                    printf("\nYou found a water source and gained 20 points! Unfortunately, it's not enough to survive. Keep searching!\n");
                    score += 20;
                    break;

                case 2:
                    printf("\nYou found a cave and gained shelter. Good job. You gained 10 points!\n");
                    score += 10;
                    break;

                case 3:
                    printf("\nYou found old rover parts lying around and gained 15 points. Unfortunately, it's not enough for you to build a new one.\n");
                    score += 15;
                    break;

                default:
                    printf("\nOption not recognized. Please choose again.\n");
            }
        } while(option < 1 || option > moonOptionsLength);

        printf("\nYou survived the Moon! Score: %d\n", score);

    }
    // End of The Moon game

    // Start of Mars game
    else if(strcmp(location, "Mars") == 0) {
        int option;
        char* marsOptions[] = {"Go to the nearest crater", "Build a shelter", "Find edible plants"};
        int marsOptionsLength = sizeof(marsOptions)/sizeof(char*);

        printf("\nYou have just landed on Mars. You have limited resources and need to find supplies to survive.\n");
        printf("You can choose from the following options: ");

        do {
            printOptions(marsOptions, marsOptionsLength);
            scanf("%d", &option);   
            getchar();

            switch(option) {
                case 1:
                    printf("\nYou found a crater and gained 15 points! Unfortunately, there was no water source. Keep searching!\n");
                    score += 15;
                    break;

                case 2:
                    printf("\nYou built a shelter and gained safety. Good job. You gained 10 points!\n");
                    score += 10;
                    break;

                case 3:
                    printf("\nYou found edible plants and gained 20 points! Looks like you're going to survive.\n");
                    score += 20;
                    break;

                default:
                    printf("\nOption not recognized. Please choose again.\n");
            }
        } while(option < 1 || option > marsOptionsLength);

        printf("\nYou survived Mars! Score: %d\n", score);
    }
    // End of Mars game

    else {
        printf("\nLocation not recognized. Game over!\n");
    }

    free(name);
    free(gender);
    free(location);

    return 0;
}