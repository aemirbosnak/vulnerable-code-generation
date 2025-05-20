//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on the lights!\n");
}

void turn_off_lights(void) {
    printf("Turning off the lights!\n");
}

void lock_doors(void) {
    printf("Locking the doors!\n");
}

void unlock_doors(void) {
    printf("Unlocking the doors!\n");
}

int main(int argc, char **argv) {
    command_t commands[MAX_COMMANDS] = {{"turn_on_lights", turn_on_lights},
                                         {"turn_off_lights", turn_off_lights},
                                         {"lock_doors", lock_doors},
                                         {"unlock_doors", unlock_doors}};

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char input[MAX_COMMAND_LENGTH];

    while (true) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(commands[i].command, input) == 0) {
                commands[i].function();
            }
        }
    }

    return 0;
}