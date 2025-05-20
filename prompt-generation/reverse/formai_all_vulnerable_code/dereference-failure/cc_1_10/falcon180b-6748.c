//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100

// Struct to hold command and its associated function pointer
typedef struct {
    char* command;
    void (*function)(void);
} command_t;

// Function prototypes
void turn_on_light(void);
void turn_off_light(void);
void set_temperature(void);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char* command = argv[1];
    tolower(command); // Convert command to lowercase for case-insensitive comparison

    // Initialize commands
    command_t commands[] = {
        {"turn_on_light", turn_on_light},
        {"turn_off_light", turn_off_light},
        {"set_temperature", set_temperature}
    };

    int num_commands = sizeof(commands) / sizeof(command_t);

    // Find matching command
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command.\n");
    return 1;
}

// Functions
void turn_on_light(void) {
    printf("Turning on the light.\n");
}

void turn_off_light(void) {
    printf("Turning off the light.\n");
}

void set_temperature(void) {
    printf("Setting temperature.\n");
}