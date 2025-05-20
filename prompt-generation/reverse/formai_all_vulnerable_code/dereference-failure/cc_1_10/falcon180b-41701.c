//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

enum command_type {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD,
    STOP,
    UNKNOWN
};

struct command {
    enum command_type type;
    char *parameters;
};

enum command_type get_command_type(char *command) {
    if (strcmp(command, "up") == 0) {
        return UP;
    } else if (strcmp(command, "down") == 0) {
        return DOWN;
    } else if (strcmp(command, "left") == 0) {
        return LEFT;
    } else if (strcmp(command, "right") == 0) {
        return RIGHT;
    } else if (strcmp(command, "forward") == 0) {
        return FORWARD;
    } else if (strcmp(command, "backward") == 0) {
        return BACKWARD;
    } else if (strcmp(command, "stop") == 0) {
        return STOP;
    } else {
        return UNKNOWN;
    }
}

struct command parse_command(char *input) {
    char *command = strtok(input, " ");
    char *parameters = strtok(NULL, " ");

    struct command result;
    result.type = get_command_type(command);
    result.parameters = parameters!= NULL? strdup(parameters) : NULL;

    return result;
}

void execute_command(struct command command) {
    switch (command.type) {
        case UP:
            printf("Drone flying up...\n");
            break;
        case DOWN:
            printf("Drone flying down...\n");
            break;
        case LEFT:
            printf("Drone flying left...\n");
            break;
        case RIGHT:
            printf("Drone flying right...\n");
            break;
        case FORWARD:
            printf("Drone flying forward...\n");
            break;
        case BACKWARD:
            printf("Drone flying backward...\n");
            break;
        case STOP:
            printf("Drone stopped...\n");
            break;
        default:
            printf("Unknown command: %s\n", command.parameters);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    char input[MAX_COMMAND_LENGTH];
    strcpy(input, argv[1]);

    struct command command = parse_command(input);
    execute_command(command);

    if (command.parameters!= NULL) {
        free(command.parameters);
    }

    return 0;
}