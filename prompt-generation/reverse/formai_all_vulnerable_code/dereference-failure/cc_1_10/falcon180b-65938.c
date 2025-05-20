//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100

typedef struct {
    char *name;
    void (*func)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on the lights.\n");
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

int main(int argc, char *argv[]) {
    int num_commands = 0;
    command_t commands[MAX_COMMANDS];

    commands[num_commands++] = (command_t) {"turn_on_lights", turn_on_lights};
    commands[num_commands++] = (command_t) {"turn_off_lights", turn_off_lights};
    commands[num_commands++] = (command_t) {"lock_doors", lock_doors};
    commands[num_commands++] = (command_t) {"unlock_doors", unlock_doors};

    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command_name = argv[1];
    void (*command_func)(void) = NULL;

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].name, command_name) == 0) {
            command_func = commands[i].func;
            break;
        }
    }

    if (command_func == NULL) {
        printf("Invalid command: %s\n", command_name);
        return 1;
    }

    command_func();

    return 0;
}