//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function prototypes
void printMap(char** map, int rows, int cols);
void generatePlanets(char** map, int rows, int cols, int numPlanets);
int* findPlayer(char** map, int rows, int cols);
bool movePlayer(char** map, int rows, int cols, int* player, char move);
bool isValidMove(char** map, int rows, int cols, int* pos);

int main() {
    int rows = 10;
    int cols = 20;
    int numPlanets = 5;

    // Allocate space for map
    char** map = (char**) malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        map[i] = (char*) malloc(cols * sizeof(char));
    }

    // Generate planets and player
    generatePlanets(map, rows, cols, numPlanets);
    int* player = findPlayer(map, rows, cols);

    // Print initial map
    printMap(map, rows, cols);

    // Movement loop
    char move;
    printf("Use WASD to move. Q to quit.\n");
    while (true) {
        scanf(" %c", &move);
        if (move == 'q' || move == 'Q') {
            break;
        }
        if (movePlayer(map, rows, cols, player, move)) {
            printMap(map, rows, cols);
        } else {
            printf("Invalid move.\n");
        }
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
    free(player);

    return 0;
}

// Prints the current map
void printMap(char** map, int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Generates a specified number of planets randomly on the map
void generatePlanets(char** map, int rows, int cols, int numPlanets) {
    srand(time(NULL));
    for (int i = 0; i < numPlanets; i++) {
        int row = rand() % rows;
        int col = rand() % cols;
        map[row][col] = 'P';
    }
}

// Finds the player starting position on the map
int* findPlayer(char** map, int rows, int cols) {
    int* player = (int*) malloc(2 * sizeof(int));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'S') {
                player[0] = i;
                player[1] = j;
                return player;
            }
        }
    }
    return NULL;
}

// Moves the player position on the map according to input move
bool movePlayer(char** map, int rows, int cols, int* player, char move) {
    int newRow = player[0];
    int newCol = player[1];
    switch (move) {
        case 'w':
        case 'W':
            newRow--;
            break;
        case 'a':
        case 'A':
            newCol--;
            break;
        case 's':
        case 'S':
            newRow++;
            break;
        case 'd':
        case 'D':
            newCol++;
            break;
        default:
            return false;
    }
    int newPos[2] = {newRow, newCol};
    if (isValidMove(map, rows, cols, newPos)) {
        map[player[0]][player[1]] = ' ';
        player[0] = newRow;
        player[1] = newCol;
        if (map[newRow][newCol] == 'P') {
            printf("You have landed on a planet!\n");
        }
        map[newRow][newCol] = 'S';
        return true;
    }
    return false;
}

// Checks if a move is valid (within map bounds and not on a planet)
bool isValidMove(char** map, int rows, int cols, int* pos) {
    if (pos[0] < 0 || pos[0] >= rows || pos[1] < 0 || pos[1] >= cols) {
        return false;
    }
    if (map[pos[0]][pos[1]] == 'P') {
        return false;
    }
    return true;
}