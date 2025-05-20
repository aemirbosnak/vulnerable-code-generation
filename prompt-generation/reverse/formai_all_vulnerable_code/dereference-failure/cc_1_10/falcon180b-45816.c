//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_COMMANDS 50
#define MAX_COMMAND_LENGTH 20
#define PI 3.14159265358979323846

char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];
int num_commands;

void add_command(char* command) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        return;
    }

    strcpy(commands[num_commands], command);
    num_commands++;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Drone Remote Control!\n");
    printf("Enter commands (up to %d) followed by 'done':\n", MAX_COMMANDS - 1);

    char input[MAX_COMMAND_LENGTH];
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "done") == 0) {
            break;
        }

        char* command = strtok(input, " ");
        add_command(command);
    }

    num_commands--; // Remove 'done' command

    printf("\nCommands:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%d: %s\n", i + 1, commands[i]);
    }

    int choice;
    printf("\nEnter the number of the command to execute: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_commands) {
        printf("Invalid choice.\n");
        return 1;
    }

    char* command = commands[choice - 1];

    if (strcmp(command, "takeoff") == 0) {
        printf("Taking off...\n");
    } else if (strcmp(command, "land") == 0) {
        printf("Landing...\n");
    } else if (strcmp(command, "forward") == 0) {
        printf("Moving forward...\n");
    } else if (strcmp(command, "backward") == 0) {
        printf("Moving backward...\n");
    } else if (strcmp(command, "left") == 0) {
        printf("Turning left...\n");
    } else if (strcmp(command, "right") == 0) {
        printf("Turning right...\n");
    } else if (strcmp(command, "up") == 0) {
        printf("Moving up...\n");
    } else if (strcmp(command, "down") == 0) {
        printf("Moving down...\n");
    } else if (strcmp(command, "hover") == 0) {
        printf("Hovering...\n");
    } else {
        printf("Unknown command.\n");
    }

    return 0;
}