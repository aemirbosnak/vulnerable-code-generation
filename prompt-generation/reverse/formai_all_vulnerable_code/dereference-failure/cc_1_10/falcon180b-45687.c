//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

// Define structure for command and function pointer
typedef struct {
    char *command;
    void (*function)(void);
} command_t;

// Define global array of commands
command_t commands[MAX_COMMANDS];

// Define function prototypes
void turn_on_light(void);
void turn_off_light(void);
void set_temperature(int temperature);
void get_temperature(void);

// Initialize command array
void init_commands(void) {
    int i = 0;

    // Turn on light
    commands[i].command = "turn_on_light";
    commands[i].function = turn_on_light;
    i++;

    // Turn off light
    commands[i].command = "turn_off_light";
    commands[i].function = turn_off_light;
    i++;

    // Set temperature
    commands[i].command = "set_temperature";
    commands[i].function = set_temperature;
    i++;

    // Get temperature
    commands[i].command = "get_temperature";
    commands[i].function = get_temperature;
    i++;
}

// Main function to process user input
int main(int argc, char *argv[]) {
    init_commands();

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Convert input to lowercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Search for command in array
        int index = -1;
        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                index = i;
                break;
            }
        }

        // Execute command if found
        if (index!= -1) {
            commands[index].function();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

// Function to turn on light
void turn_on_light(void) {
    printf("Light turned on.\n");
}

// Function to turn off light
void turn_off_light(void) {
    printf("Light turned off.\n");
}

// Function to set temperature
void set_temperature(int temperature) {
    printf("Temperature set to %d degrees.\n", temperature);
}

// Function to get temperature
void get_temperature(void) {
    printf("Current temperature is 25 degrees.\n");
}