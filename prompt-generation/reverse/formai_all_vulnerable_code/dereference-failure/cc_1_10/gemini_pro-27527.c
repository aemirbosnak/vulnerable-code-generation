//GEMINI-pro DATASET v1.0 Category: Educational ; Style: all-encompassing
// Avast (Ye) C Program: The Pirate's Treasure Hunt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the grid size and the number of treasures
#define GRID_SIZE 10
#define TREASURES 10

// Define the player's initial position
#define START_ROW 0
#define START_COL 0

// Define the directions the player can move
#define UP    'w'
#define DOWN  's'
#define LEFT  'a'
#define RIGHT 'd'

// Define the symbols used in the grid
#define PLAYER  '@'
#define TREASURE '$'
#define WATER   '~'
#define LAND    '.'

// Function to create the grid
char** create_grid() {
    // Allocate memory for the grid
    char** grid = (char**)malloc(GRID_SIZE * sizeof(char*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (char*)malloc(GRID_SIZE * sizeof(char));
    }

    // Fill the grid with water
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = WATER;
        }
    }

    // Place the player at the starting position
    grid[START_ROW][START_COL] = PLAYER;

    // Place the treasures randomly
    srand(time(NULL));
    for (int i = 0; i < TREASURES; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (grid[row][col] == WATER) {
            grid[row][col] = TREASURE;
        }
    }

    return grid;
}

// Function to print the grid
void print_grid(char** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player in a given direction
void move_player(char** grid, char direction) {
    int row = START_ROW;
    int col = START_COL;

    // Get the player's current position
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == PLAYER) {
                row = i;
                col = j;
                break;
            }
        }
    }

    // Move the player in the given direction
    switch (direction) {
        case UP:
            if (row > 0 && grid[row - 1][col] != WATER) {
                grid[row - 1][col] = PLAYER;
                grid[row][col] = LAND;
            }
            break;
        case DOWN:
            if (row < GRID_SIZE - 1 && grid[row + 1][col] != WATER) {
                grid[row + 1][col] = PLAYER;
                grid[row][col] = LAND;
            }
            break;
        case LEFT:
            if (col > 0 && grid[row][col - 1] != WATER) {
                grid[row][col - 1] = PLAYER;
                grid[row][col] = LAND;
            }
            break;
        case RIGHT:
            if (col < GRID_SIZE - 1 && grid[row][col + 1] != WATER) {
                grid[row][col + 1] = PLAYER;
                grid[row][col] = LAND;
            }
            break;
    }
}

// Function to check if the player has won
int has_won(char** grid) {
    // Check if all the treasures have been collected
    int treasures_collected = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == TREASURE) {
                treasures_collected++;
            }
        }
    }

    return treasures_collected == TREASURES;
}

int main() {
    // Create the grid
    char** grid = create_grid();

    // Print the grid
    print_grid(grid);

    // Get the player's input
    char input;
    printf("Enter a direction (w, s, a, d): ");
    scanf("%c", &input);

    // Move the player in the given direction
    move_player(grid, input);

    // Print the grid
    print_grid(grid);

    // Check if the player has won
    if (has_won(grid)) {
        printf("Congratulations! You have found all the treasures.\n");
    } else {
        printf("Sorry, you have not found all the treasures.\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}