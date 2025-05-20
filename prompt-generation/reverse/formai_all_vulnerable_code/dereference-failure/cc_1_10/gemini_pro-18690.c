//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CMD_LEN 128

typedef struct {
    char *name;
    void (*action)(void);
} command;

void forward(void) {
    printf("Moving forward.\n");
}

void reverse(void) {
    printf("Moving backward.\n");
}

void left(void) {
    printf("Turning left.\n");
}

void right(void) {
    printf("Turning right.\n");
}

void stop(void) {
    printf("Stopping.\n");
}

command commands[] = {
    {"forward", forward},
    {"reverse", reverse},
    {"left", left},
    {"right", right},
    {"stop", stop},
    {NULL, NULL}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *cmd = argv[1];

    for (int i = 0; commands[i].name != NULL; i++) {
        if (!strcmp(cmd, commands[i].name)) {
            commands[i].action();
            return 0;
        }
    }

    printf("Invalid command: %s\n", cmd);
    return 1;
}