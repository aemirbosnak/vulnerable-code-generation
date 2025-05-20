//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 100
#define MAX_DELAY 60

typedef struct {
    char *command;
    int delay;
    int enabled;
} command_t;

command_t commands[MAX_COMMANDS];
int num_commands = 0;

int add_command(char *command, int delay, int enabled) {
    if (num_commands >= MAX_COMMANDS) {
        return -1;
    }
    commands[num_commands].command = strdup(command);
    commands[num_commands].delay = delay;
    commands[num_commands].enabled = enabled;
    num_commands++;
    return 0;
}

int execute_commands() {
    time_t current_time;
    for (int i = 0; i < num_commands; i++) {
        if (!commands[i].enabled) {
            continue;
        }
        time(&current_time);
        if ((current_time - commands[i].delay) % (24 * 60 * 60) == 0) {
            system(commands[i].command);
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command> [delay] [enabled]\n", argv[0]);
        return 1;
    }
    char *command = argv[1];
    int delay = 0;
    int enabled = 1;
    if (argc > 2) {
        delay = atoi(argv[2]);
    }
    if (argc > 3) {
        enabled = atoi(argv[3]);
    }
    if (add_command(command, delay, enabled)!= 0) {
        printf("Error: Too many commands\n");
        return 1;
    }
    printf("Command added: %s\n", command);
    return 0;
}