//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LEN 50

typedef struct {
    char* command;
    char* light_name;
} LightCommand;

void parse_command(LightCommand* command, char* input_command) {
    char* tokens[MAX_COMMAND_LEN];
    char* token;
    char* c;

    token = strtok_r(input_command, " ", &c);
    command->command = strdup(token);

    token = strtok_r(NULL, " ", &c);
    command->light_name = strdup(token);
}

void print_usage() {
    printf("Usage: light_control [command] [light_name]\n");
    printf("Valid commands:\n");
    printf("  on - turns on the specified light\n");
    printf("  off - turns off the specified light\n");
    printf("  status - displays the status of the specified light\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    LightCommand command;
    parse_command(&command, argv[1]);

    char* light_name = command.light_name;

    if (strcmp(command.command, "on") == 0) {
        printf("Turning on light %s...\n", light_name);
        // Implement the logic to turn on the specified light
    } else if (strcmp(command.command, "off") == 0) {
        printf("Turning off light %s...\n", light_name);
        // Implement the logic to turn off the specified light
    } else if (strcmp(command.command, "status") == 0) {
        printf("Status of light %s:\n", light_name);
        // Implement the logic to display the status of the specified light
    } else {
        printf("Invalid command %s\n", command.command);
    }

    return 0;
}