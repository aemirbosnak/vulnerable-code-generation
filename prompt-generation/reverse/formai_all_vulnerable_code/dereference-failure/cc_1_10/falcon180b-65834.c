//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define NUM_COMMANDS 5

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Drone taking off...\n");
}

void land(void) {
    printf("Drone landing...\n");
}

void forward(int speed) {
    printf("Drone moving forward at %d km/h...\n", speed);
}

void backward(int speed) {
    printf("Drone moving backward at %d km/h...\n", speed);
}

void turn(int direction, int speed) {
    if (direction == 1) {
        printf("Drone turning left at %d degrees/s...\n", speed);
    } else {
        printf("Drone turning right at %d degrees/s...\n", speed);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [parameters]\n", argv[0]);
        return 1;
    }

    command_t commands[NUM_COMMANDS] = {
        {"takeoff", &takeoff},
        {"land", &land},
        {"forward", &forward},
        {"backward", &backward},
        {"turn", &turn}
    };

    char *command = argv[1];
    int i;

    for (i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}