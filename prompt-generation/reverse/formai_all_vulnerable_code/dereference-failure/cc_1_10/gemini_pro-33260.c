//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct drone {
    int x;
    int y;
    int z;
    int yaw;
    int pitch;
    int roll;
} drone_t;

typedef struct command {
    char *cmd;
    int num_args;
    int *args;
} command_t;

typedef struct command_table {
    char *cmd;
    void (*func)(drone_t *, command_t *);
} command_table_t;

void move_forward(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for move_forward command\n");
        return;
    }

    drone->x += cmd->args[0];
}

void move_backward(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for move_backward command\n");
        return;
    }

    drone->x -= cmd->args[0];
}

void move_left(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for move_left command\n");
        return;
    }

    drone->y -= cmd->args[0];
}

void move_right(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for move_right command\n");
        return;
    }

    drone->y += cmd->args[0];
}

void move_up(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for move_up command\n");
        return;
    }

    drone->z += cmd->args[0];
}

void move_down(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for move_down command\n");
        return;
    }

    drone->z -= cmd->args[0];
}

void turn_left(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for turn_left command\n");
        return;
    }

    drone->yaw -= cmd->args[0];
}

void turn_right(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for turn_right command\n");
        return;
    }

    drone->yaw += cmd->args[0];
}

void pitch_up(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for pitch_up command\n");
        return;
    }

    drone->pitch -= cmd->args[0];
}

void pitch_down(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for pitch_down command\n");
        return;
    }

    drone->pitch += cmd->args[0];
}

void roll_left(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for roll_left command\n");
        return;
    }

    drone->roll -= cmd->args[0];
}

void roll_right(drone_t *drone, command_t *cmd) {
    if (cmd->num_args != 1) {
        printf("Invalid number of arguments for roll_right command\n");
        return;
    }

    drone->roll += cmd->args[0];
}

void print_drone_status(drone_t *drone) {
    printf("Drone status:\n");
    printf("  x: %d\n", drone->x);
    printf("  y: %d\n", drone->y);
    printf("  z: %d\n", drone->z);
    printf("  yaw: %d\n", drone->yaw);
    printf("  pitch: %d\n", drone->pitch);
    printf("  roll: %d\n", drone->roll);
}

int main() {
    // Create a drone
    drone_t drone = {0, 0, 0, 0, 0, 0};

    // Create a command table
    command_table_t command_table[] = {
        {"move_forward", move_forward},
        {"move_backward", move_backward},
        {"move_left", move_left},
        {"move_right", move_right},
        {"move_up", move_up},
        {"move_down", move_down},
        {"turn_left", turn_left},
        {"turn_right", turn_right},
        {"pitch_up", pitch_up},
        {"pitch_down", pitch_down},
        {"roll_left", roll_left},
        {"roll_right", roll_right},
        {"print_status", print_drone_status},
        {NULL, NULL}
    };

    // Get a command from the user
    char cmd[MAX_COMMAND_LENGTH];
    printf("Enter a command: ");
    scanf("%s", cmd);

    // Parse the command
    command_t *cmd_parsed = malloc(sizeof(command_t));
    cmd_parsed->cmd = strdup(cmd);
    cmd_parsed->num_args = 0;
    cmd_parsed->args = NULL;

    char *token = strtok(cmd, " ");
    while (token != NULL) {
        cmd_parsed->num_args++;
        cmd_parsed->args = realloc(cmd_parsed->args, cmd_parsed->num_args * sizeof(int));
        cmd_parsed->args[cmd_parsed->num_args - 1] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Find the command in the command table
    int i;
    for (i = 0; command_table[i].cmd != NULL; i++) {
        if (strcmp(cmd_parsed->cmd, command_table[i].cmd) == 0) {
            break;
        }
    }

    // If the command was found, execute it
    if (command_table[i].cmd != NULL) {
        command_table[i].func(&drone, cmd_parsed);
    } else {
        printf("Invalid command\n");
    }

    // Free the memory allocated for the command
    free(cmd_parsed->cmd);
    free(cmd_parsed->args);
    free(cmd_parsed);

    return 0;
}