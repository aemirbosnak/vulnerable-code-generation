//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/* Constant definitions */

#define MAX_COMMANDS  20
#define MAX_COMMAND_LENGTH  10
#define MAX_PARAMS  3

/* Function prototypes */

void printMenu();
void executeCommand(char* command, char** params, int numParams);
void move(int distance, int direction);
void turn(int angle);

/* Global variables */

int x, y;
int angleFacing;

/* Main function */

int main() {
    x = 0;
    y = 0;
    angleFacing = 0;

    char input[MAX_COMMAND_LENGTH + (MAX_PARAMS * MAX_COMMAND_LENGTH) + 2];
    char* command;
    char* params[MAX_PARAMS];
    int numParams;

    while (true) {
        printMenu();

        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Parse input into command and parameters
        command = strtok(input, " ");
        numParams = 0;
        while ((params[numParams] = strtok(NULL, " ")) != NULL) {
            numParams++;
        }

        // Execute command
        executeCommand(command, params, numParams);
    }

    return 0;
}

/* Function implementations */

void printMenu() {
    printf("Enter a command:\n");
    printf("move [distance] [direction]\n");
    printf("turn [angle]\n");
    printf("exit\n");
    printf("> ");
}

void executeCommand(char* command, char** params, int numParams) {
    if (strcmp(command, "move") == 0) {
        if (numParams != 2) {
            printf("Error: move requires 2 parameters.\n");
            return;
        }

        int distance = atoi(params[0]);
        if (distance == 0) {
            printf("Error: distance must be a non-zero integer.\n");
            return;
        }

        char* direction = params[1];
        if (strcmp(direction, "north") == 0) {
            move(distance, 0);
        } else if (strcmp(direction, "east") == 0) {
            move(distance, 90);
        } else if (strcmp(direction, "south") == 0) {
            move(distance, 180);
        } else if (strcmp(direction, "west") == 0) {
            move(distance, 270);
        } else {
            printf("Error: invalid direction. Valid directions are: north, east, south, west.\n");
            return;
        }
    } else if (strcmp(command, "turn") == 0) {
        if (numParams != 1) {
            printf("Error: turn requires 1 parameter.\n");
            return;
        }

        int angle = atoi(params[0]);
        if (angle % 90 != 0) {
            printf("Error: angle must be a multiple of 90 degrees.\n");
            return;
        }

        turn(angle);
    } else if (strcmp(command, "exit") == 0) {
        exit(0);
    } else {
        printf("Error: invalid command. Valid commands are: move, turn, exit.\n");
    }
}

void move(int distance, int direction) {
    int deltaX = 0;
    int deltaY = 0;

    if (direction == 0) {
        deltaY = distance;
    } else if (direction == 90) {
        deltaX = distance;
    } else if (direction == 180) {
        deltaY = -distance;
    } else if (direction == 270) {
        deltaX = -distance;
    }

    x += deltaX;
    y += deltaY;

    printf("Moved %d units in direction %d. New coordinates: (%d, %d)\n", distance, direction, x, y);
}

void turn(int angle) {
    angleFacing += angle;
    angleFacing %= 360;

    printf("Turned %d degrees. New direction: %d\n", angle, angleFacing);
}