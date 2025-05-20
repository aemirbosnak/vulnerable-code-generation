//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void turn_on_light() {
    printf("Turning on the light...\n");
}

void turn_off_light() {
    printf("Turning off the light...\n");
}

void set_brightness(int level) {
    printf("Setting brightness to %d...\n", level);
}

void execute_command(char* input) {
    command_t commands[MAX_COMMANDS] = {{"turn_on_light", turn_on_light},
                                        {"turn_off_light", turn_off_light},
                                        {"set_brightness", set_brightness}};
    int num_commands = sizeof(commands) / sizeof(command_t);
    bool found_command = false;

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, input) == 0) {
            commands[i].function();
            found_command = true;
            break;
        }
    }

    if (!found_command) {
        printf("Invalid command.\n");
    }
}

int main() {
    printf("Smart Home Light Control\n");
    printf("Enter commands:\n");

    char input[MAX_COMMAND_LENGTH];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        execute_command(input);
    }

    return 0;
}