//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

// Struct to hold command and function pointer
typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on lights...\n");
}

void turn_off_lights(void) {
    printf("Turning off lights...\n");
}

void lock_door(void) {
    printf("Locking door...\n");
}

void unlock_door(void) {
    printf("Unlocking door...\n");
}

void open_garage(void) {
    printf("Opening garage...\n");
}

void close_garage(void) {
    printf("Closing garage...\n");
}

int main(int argc, char *argv[]) {
    // Initialize commands
    command_t commands[MAX_COMMANDS] = {{"turn on lights", turn_on_lights},
                                        {"turn off lights", turn_off_lights},
                                        {"lock door", lock_door},
                                        {"unlock door", unlock_door},
                                        {"open garage", open_garage},
                                        {"close garage", close_garage}};

    int num_commands = 0;

    // Read in user commands from file
    FILE *file = fopen("commands.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open commands file.\n");
        return 1;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, MAX_COMMAND_LENGTH, file)!= NULL) {
        if (num_commands >= MAX_COMMANDS) {
            printf("Error: Too many commands.\n");
            return 1;
        }

        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Convert command to uppercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = toupper(line[i]);
        }

        // Find matching command
        command_t *match = NULL;
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(line, commands[i].command) == 0) {
                match = &commands[i];
                break;
            }
        }

        if (match == NULL) {
            printf("Error: Invalid command '%s'.\n", line);
            return 1;
        }

        num_commands++;
    }

    fclose(file);

    // Execute user commands
    for (int i = 0; i < num_commands; i++) {
        commands[i].function();
    }

    return 0;
}