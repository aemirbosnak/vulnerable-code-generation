//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 10

struct command {
    char *name;
    void (*function)(void);
};

void fly(void) {
    printf("The drone is flying!\n");
}

void land(void) {
    printf("The drone is landing!\n");
}

void takeoff(void) {
    printf("The drone is taking off!\n");
}

void turn_left(void) {
    printf("The drone is turning left!\n");
}

void turn_right(void) {
    printf("The drone is turning right!\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    tolower(command);

    struct command *commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands++] = &(struct command) {
       .name = "fly",
       .function = fly
    };

    commands[num_commands++] = &(struct command) {
       .name = "land",
       .function = land
    };

    commands[num_commands++] = &(struct command) {
       .name = "takeoff",
       .function = takeoff
    };

    commands[num_commands++] = &(struct command) {
       .name = "turn_left",
       .function = turn_left
    };

    commands[num_commands++] = &(struct command) {
       .name = "turn_right",
       .function = turn_right
    };

    struct command *command_ptr;
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i]->name) == 0) {
            command_ptr = commands[i];
            break;
        }
    }

    if (command_ptr == NULL) {
        printf("Invalid command: %s\n", command);
        return 1;
    }

    command_ptr->function();

    return 0;
}