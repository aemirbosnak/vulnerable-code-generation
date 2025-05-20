//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100

enum command_type {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD,
    STOP
};

struct command {
    enum command_type type;
    float value;
};

void process_command(struct command *cmd) {
    switch (cmd->type) {
        case UP:
            // Move drone up
            break;
        case DOWN:
            // Move drone down
            break;
        case LEFT:
            // Move drone left
            break;
        case RIGHT:
            // Move drone right
            break;
        case FORWARD:
            // Move drone forward
            break;
        case BACKWARD:
            // Move drone backward
            break;
        case STOP:
            // Stop drone
            break;
        default:
            // Invalid command type
            break;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    struct command cmd;

    while (1) {
        printf("Enter command (e.g. up 10): ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Parse command type and value
        char *command_type_str = strtok(input, " ");
        float value = atof(strtok(NULL, " "));

        if (strcmp(command_type_str, "up") == 0) {
            cmd.type = UP;
        } else if (strcmp(command_type_str, "down") == 0) {
            cmd.type = DOWN;
        } else if (strcmp(command_type_str, "left") == 0) {
            cmd.type = LEFT;
        } else if (strcmp(command_type_str, "right") == 0) {
            cmd.type = RIGHT;
        } else if (strcmp(command_type_str, "forward") == 0) {
            cmd.type = FORWARD;
        } else if (strcmp(command_type_str, "backward") == 0) {
            cmd.type = BACKWARD;
        } else if (strcmp(command_type_str, "stop") == 0) {
            cmd.type = STOP;
        } else {
            printf("Invalid command type\n");
            continue;
        }

        // Process command
        process_command(&cmd);
    }

    return 0;
}