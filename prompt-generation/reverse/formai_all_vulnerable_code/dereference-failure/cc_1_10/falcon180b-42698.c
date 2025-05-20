//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMANDS 20

typedef struct {
    char *command;
    void (*func)(void);
} command_t;

void turn_on_light(void) {
    printf("Turning on the light!\n");
}

void turn_off_light(void) {
    printf("Turning off the light!\n");
}

void lock_door(void) {
    printf("Locking the door!\n");
}

void unlock_door(void) {
    printf("Unlocking the door!\n");
}

void set_temperature(void) {
    printf("Setting the temperature!\n");
}

int main(int argc, char **argv) {
    command_t commands[MAX_COMMANDS] = {
        {"turn_on_light", turn_on_light},
        {"turn_off_light", turn_off_light},
        {"lock_door", lock_door},
        {"unlock_door", unlock_door},
        {"set_temperature", set_temperature}
    };

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char *input;
    while (true) {
        printf("Enter a command: ");
        scanf("%s", input);

        bool found = false;
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].func();
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}