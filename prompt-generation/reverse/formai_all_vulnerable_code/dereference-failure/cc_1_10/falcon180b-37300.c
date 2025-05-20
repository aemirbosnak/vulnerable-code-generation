//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LEN 100
#define MAX_PARAM_LEN 20
#define MAX_NUM_PARAMS 10

typedef struct {
    char *command;
    char **params;
    int num_params;
} Command;

void parse_command(char *input, Command *command) {
    char *token;
    int num_params = 0;
    command->command = strdup(input);
    token = strtok(input, " ");
    while (token!= NULL && num_params < MAX_NUM_PARAMS) {
        command->params[num_params] = strdup(token);
        num_params++;
        token = strtok(NULL, " ");
    }
    command->num_params = num_params;
}

int execute_command(Command *command) {
    if (strcmp(command->command, "TAKEOFF") == 0) {
        printf("Taking off...\n");
        return 0;
    } else if (strcmp(command->command, "LAND") == 0) {
        printf("Landing...\n");
        return 0;
    } else if (strcmp(command->command, "MOVE") == 0) {
        if (command->num_params >= 3) {
            double x = atof(command->params[0]);
            double y = atof(command->params[1]);
            double z = atof(command->params[2]);
            printf("Moving to (%f, %f, %f)...\n", x, y, z);
        } else {
            printf("Invalid parameters for MOVE command.\n");
        }
        return 0;
    } else {
        printf("Invalid command.\n");
        return -1;
    }
}

int main() {
    char input[MAX_COMMAND_LEN];
    Command command;
    while (1) {
        printf("Enter a command (TAKEOFF, LAND, MOVE <x> <y> <z>): ");
        fgets(input, MAX_COMMAND_LEN, stdin);
        parse_command(input, &command);
        execute_command(&command);
    }
    return 0;
}