//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char *name;
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on the lights!\n");
}

void turn_off_lights(void) {
    printf("Turning off the lights.\n");
}

void lock_doors(void) {
    printf("Locking the doors.\n");
}

void unlock_doors(void) {
    printf("Unlocking the doors.\n");
}

int main(int argc, char **argv) {
    command_t commands[MAX_COMMANDS] = {
        {"turn_on_lights", turn_on_lights},
        {"turn_off_lights", turn_off_lights},
        {"lock_doors", lock_doors},
        {"unlock_doors", unlock_doors}
    };

    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Smart Home Automation System!\n");

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }

        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(token, commands[i].name) == 0) {
                commands[i].function();
                break;
            }
        }
    }

    return 0;
}