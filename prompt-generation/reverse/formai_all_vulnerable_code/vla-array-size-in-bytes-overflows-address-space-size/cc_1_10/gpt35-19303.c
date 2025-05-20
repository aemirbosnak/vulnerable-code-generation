//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GHOSTS 10 // Defining the number of ghosts

void createHauntedHouse(char houseModel[][50], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 50; j++) {
            houseModel[i][j] = ' ';
        }
    }
}

void printHauntedHouse(char houseModel[][50], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 50; j++) {
            printf("%c", houseModel[i][j]);
        }
        printf("\n");
    }
}

void createGhosts(char houseModel[][50], int size) {
    int i;
    srand(time(NULL));
    for (i = 0; i < GHOSTS; i++) {
        int x = rand() % size;
        int y = rand() % 50;
        houseModel[x][y] = 'G';
    }
}

void simulateHauntedHouse(char houseModel[][50], int size) {
    int playerX = size - 1;
    int playerY = 0;
    int ghostsCollected = 0;
    printHauntedHouse(houseModel, size);
    while (1) {
        int direction;
        printf("Enter 1 to move up, 2 to move right, 3 to move down, 4 to move left: ");
        scanf("%d", &direction);
        if (direction == 1) {
            playerX--;
        }
        else if (direction == 2) {
            playerY++;
        }
        else if (direction == 3) {
            playerX++;
        }
        else if (direction == 4) {
            playerY--;
        }
        else {
            printf("Invalid direction\n");
            continue;
        }
        if (playerX < 0 || playerY < 0 || playerX >= size || playerY >= 50) {
            printf("You collided with a wall and died.\n");
            break;
        }
        if (houseModel[playerX][playerY] == 'G') {
            ghostsCollected++;
            printf("You collected a ghost! Ghosts collected: %d\n", ghostsCollected);
            houseModel[playerX][playerY] = ' ';
        }
        printHauntedHouse(houseModel, size);
        if (ghostsCollected == GHOSTS) {
            printf("Congratulations, you collected all the ghosts and escaped the haunted house!\n");
            break;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the house: ");
    scanf("%d", &size);
    char houseModel[size][50];
    createHauntedHouse(houseModel, size);
    createGhosts(houseModel, size);
    simulateHauntedHouse(houseModel, size);
    return 0;
}