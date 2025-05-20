//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 64

struct command {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
};

void fly_forward(void) {
    printf("Drone flying forward...\n");
}

void fly_backward(void) {
    printf("Drone flying backward...\n");
}

void fly_left(void) {
    printf("Drone flying left...\n");
}

void fly_right(void) {
    printf("Drone flying right...\n");
}

void takeoff(void) {
    printf("Drone taking off...\n");
}

void land(void) {
    printf("Drone landing...\n");
}

int main(int argc, char *argv[]) {
    struct command commands[] = {
        {"forward", fly_forward},
        {"backward", fly_backward},
        {"left", fly_left},
        {"right", fly_right},
        {"takeoff", takeoff},
        {"land", land},
        {NULL, NULL}
    };

    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    struct command *c;

    for (c = commands; c->name!= NULL; c++) {
        if (strcmp(command, c->name) == 0) {
            c->function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}