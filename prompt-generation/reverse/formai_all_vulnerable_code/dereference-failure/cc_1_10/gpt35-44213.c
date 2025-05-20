//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateGalaxyMap(int rows, int cols, char map[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int val = rand() % 5;
            if(val == 0) {
                map[i][j] = '*';
            } else {
                map[i][j] = '_';
            }
        }
    }
}

void printGalaxyMap(int rows, int cols, char map[rows][cols]) {
    printf("\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int rows = 10;
    int cols = 10;
    char galaxyMap[rows][cols];
    printf("Generating Galaxy Map...\n");
    generateGalaxyMap(rows, cols, galaxyMap);
    printGalaxyMap(rows, cols, galaxyMap);
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of the USS Voyager, on a mission to explore the unknown depths of space.\n");
    printf("Your mission: to navigate through the galaxy, discovering new planets and resources while avoiding dangers along the way.\n");
    printf("Let's get started!\n");
    int currentX = 0;
    int currentY = 0;
    int resources = 0;
    while(resources < 5) {
        char direction;
        printf("Enter your next move (N/S/E/W): ");
        scanf(" %c", &direction);
        switch(direction) {
            case 'N':
                currentY--;
                break;
            case 'S':
                currentY++;
                break;
            case 'E':
                currentX++;
                break;
            case 'W':
                currentX--;
                break;
            default:
                printf("Invalid direction. Please try again.\n");
                continue;
        }
        if(currentX < 0 || currentX >= cols || currentY < 0 || currentY >= rows) {
            printf("You have flown off the map and crashed your ship. Game over.\n");
            return 0;
        }
        if(galaxyMap[currentY][currentX] == '*') {
            printf("You have discovered a new planet!\n");
            resources++;
            galaxyMap[currentY][currentX] = '_';
        } else {
            printf("Nothing of interest here...yet.\n");
        }
        printGalaxyMap(rows, cols, galaxyMap);
    }
    printf("Congratulations! You have gathered enough resources to complete your mission and return home.\n");
    return 0;
}