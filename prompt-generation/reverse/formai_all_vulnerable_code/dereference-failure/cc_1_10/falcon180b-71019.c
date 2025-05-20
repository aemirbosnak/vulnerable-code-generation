//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LEN 50

// Command structure
typedef struct {
    char *command;
    void (*func)(char *);
} Command;

// Function prototypes
void turnOnLight(char *);
void turnOffLight(char *);
void setBrightness(char *);
void getStatus(char *);

// Initialize commands
Command commands[MAX_COMMANDS] = {
    {"turnOn", turnOnLight},
    {"turnOff", turnOffLight},
    {"setBrightness", setBrightness},
    {"getStatus", getStatus}
};

int main() {
    char input[MAX_COMMAND_LEN];
    int i, j;

    // Print welcome message
    printf("Welcome to the Smart Home Light Control System!\n");

    // Main loop
    while (1) {
        // Get user input
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LEN, stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Convert to lowercase
        for (i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Find matching command
        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                // Execute command
                commands[i].func(input);
                break;
            }
        }

        // Command not found
        if (i == MAX_COMMANDS) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

// Turn on light
void turnOnLight(char *input) {
    printf("Turning on light...\n");
}

// Turn off light
void turnOffLight(char *input) {
    printf("Turning off light...\n");
}

// Set brightness
void setBrightness(char *input) {
    printf("Setting brightness...\n");
}

// Get status
void getStatus(char *input) {
    printf("Getting status...\n");
}