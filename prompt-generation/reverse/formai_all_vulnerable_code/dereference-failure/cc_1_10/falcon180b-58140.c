//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100

struct command {
    char *name;
    void (*func)(void);
};

void init(void) {
    printf("Initializing system...\n");
}

void boot(void) {
    printf("Booting system...\n");
}

void shutdown(void) {
    printf("Shutting down system...\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [init|boot|shutdown]\n", argv[0]);
        return 1;
    }

    struct command commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands++] = (struct command) {
       .name = "init",
       .func = init,
    };

    commands[num_commands++] = (struct command) {
       .name = "boot",
       .func = boot,
    };

    commands[num_commands++] = (struct command) {
       .name = "shutdown",
       .func = shutdown,
    };

    char *command_name = argv[1];

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            commands[i].func();
            return 0;
        }
    }

    printf("Unknown command: %s\n", command_name);
    return 1;
}