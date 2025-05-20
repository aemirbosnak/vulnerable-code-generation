//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMANDS 20
#define MAX_LENGTH 20

typedef struct {
    char *command;
    void (*function)(void);
} Command;

void turnOnLight(void);
void turnOffLight(void);
void openDoor(void);
void closeDoor(void);

int main() {
    Command commands[MAX_COMMANDS] = {
        {"turn on light", turnOnLight},
        {"turn off light", turnOffLight},
        {"open door", openDoor},
        {"close door", closeDoor}
    };

    int numCommands = sizeof(commands) / sizeof(Command);
    char input[MAX_LENGTH];

    printf("Enter a command:\n");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    tolower(input);

    for (int i = 0; i < numCommands; i++) {
        if (strcmp(input, commands[i].command) == 0) {
            commands[i].function();
            break;
        }
    }

    return 0;
}

void turnOnLight(void) {
    printf("Turn on light\n");
}

void turnOffLight(void) {
    printf("Turn off light\n");
}

void openDoor(void) {
    printf("Open door\n");
}

void closeDoor(void) {
    printf("Close door\n");
}