//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

struct command {
    char *name;
    void (*function)(void);
};

void fly_forward(void) {
    printf("Drone is flying forward.\n");
}

void fly_backward(void) {
    printf("Drone is flying backward.\n");
}

void fly_left(void) {
    printf("Drone is flying left.\n");
}

void fly_right(void) {
    printf("Drone is flying right.\n");
}

void take_off(void) {
    printf("Drone is taking off.\n");
}

void land(void) {
    printf("Drone is landing.\n");
}

int main(int argc, char **argv) {
    struct command commands[] = {
        {"forward", fly_forward},
        {"backward", fly_backward},
        {"left", fly_left},
        {"right", fly_right},
        {"takeoff", take_off},
        {"land", land},
        {NULL, NULL}
    };

    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    int i;

    for (i = 0; commands[i].name!= NULL; i++) {
        if (strcmp(command, commands[i].name) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}