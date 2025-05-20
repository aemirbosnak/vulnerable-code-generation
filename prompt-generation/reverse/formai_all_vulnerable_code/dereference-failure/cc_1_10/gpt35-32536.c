//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for possible room types
#define EMPTY 0
#define GHOST 1
#define TREASURE 2

// function declarations
void generateRooms(int**, int, int);
void printRooms(int**, int, int);
void simulateGame(int**, int, int);

int main() {

    // seed random number generator
    srand(time(NULL));

    // define dimensions of house
    int rows = 5;
    int cols = 5;

    // dynamically allocate memory for 2D array to represent the house
    int** house = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        house[i] = (int*)malloc(cols * sizeof(int));
    }

    // generate rooms randomly
    generateRooms(house, rows, cols);

    // print out the house map
    printRooms(house, rows, cols);

    // simulate the game
    simulateGame(house, rows, cols);

    // free allocated memory
    for(int i = 0; i < rows; i++) {
        free(house[i]);
    }
    free(house);

    return 0;
}

// function to randomly generate the rooms in the house
void generateRooms(int** house, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // randomly assign room type
            house[i][j] = rand() % 3;
        }
    }
}

// function to print out the house map
void printRooms(int** house, int rows, int cols) {
    printf("\nHouse Map:");
    for(int i = 0; i < rows; i++) {
        printf("\n");
        for(int j = 0; j < cols; j++) {
            switch(house[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case GHOST:
                    printf("G");
                    break;
                case TREASURE:
                    printf("T");
                    break;
            }
        }
    }
    printf("\n");
}

// function to simulate the game
void simulateGame(int** house, int rows, int cols) {
    printf("\n\nWelcome to the Haunted House Simulator!\n");
    int playerRow = 0;
    int playerCol = 0;

    while(1) {
        printf("\n\nYou are now in room (%d,%d).", playerRow+1, playerCol+1);
        switch(house[playerRow][playerCol]) {
            case EMPTY:
                printf("\nThis room is empty.");
                break;
            case GHOST:
                printf("\nA ghost has appeared!");
                printf("\nUnfortunately, you have been haunted to death.");
                return;
            case TREASURE:
                printf("\nYou found the treasure!");
                printf("\nCongratulations, you have won the game.");
                return;
        }

        // prompt user to move to another room
        char direction;
        printf("\n\nWhich direction would you like to move? (N/S/E/W): ");
        scanf(" %c", &direction);

        if(direction == 'N' && playerRow > 0) {
            playerRow--;
        }
        else if(direction == 'S' && playerRow < rows-1) {
            playerRow++;
        }
        else if(direction == 'E' && playerCol < cols-1) {
            playerCol++;
        }
        else if(direction == 'W' && playerCol > 0) {
            playerCol--;
        }
        else {
            printf("\nInvalid move.\n");
        }
    }
}