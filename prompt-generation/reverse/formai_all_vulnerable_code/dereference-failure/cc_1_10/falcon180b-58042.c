//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *name;
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Drone takes off\n");
}

void land(void) {
    printf("Drone lands\n");
}

void forward(int speed) {
    printf("Drone moves forward at %d m/s\n", speed);
}

void backward(int speed) {
    printf("Drone moves backward at %d m/s\n", speed);
}

void left(int speed) {
    printf("Drone turns left at %d rad/s\n", speed);
}

void right(int speed) {
    printf("Drone turns right at %d rad/s\n", speed);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [parameters]\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {
        {"takeoff", &takeoff},
        {"land", &land},
        {"forward", &forward},
        {"backward", &backward},
        {"left", &left},
        {"right", &right},
    };

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commands[i].name, argv[1]) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Unknown command: %s\n", argv[1]);
    return 1;
}