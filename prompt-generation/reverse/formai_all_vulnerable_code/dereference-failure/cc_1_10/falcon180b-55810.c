//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void turnOnLight(void) {
    printf("Turning on light\n");
}

void turnOffLight(void) {
    printf("Turning off light\n");
}

void setLightLevel(int level) {
    printf("Setting light level to %d\n", level);
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS] = {{"on", turnOnLight}, {"off", turnOffLight}, {"level", setLightLevel}};
    int numCommands = sizeof(commands) / sizeof(commands[0]);

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        int i;
        for (i = 0; i < numCommands; i++) {
            if (strcmp(commands[i].command, input) == 0) {
                commands[i].function();
                break;
            }
        }

        if (i == numCommands) {
            printf("Invalid command\n");
        }
    }

    return 0;
}