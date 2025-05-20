//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

// Struct to hold command and function pointer
typedef struct {
    char* command;
    void (*function)(void);
} command_t;

// Function prototypes
void turn_on_light(void);
void turn_off_light(void);
void set_light_brightness(void);
void get_light_status(void);

int main() {
    // Initialize command list
    command_t commands[MAX_COMMANDS] = {{"turn_on_light", turn_on_light},
                                        {"turn_off_light", turn_off_light},
                                        {"set_light_brightness", set_light_brightness},
                                        {"get_light_status", get_light_status}};

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Convert input to uppercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
        }

        // Search for command in list
        int found = 0;
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                // Call function associated with command
                commands[i].function();
                found = 1;
                break;
            }
        }

        if (!found) {
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

// Function to set light brightness
void set_light_brightness(void) {
    int brightness;
    printf("Enter brightness (0-100): ");
    scanf("%d", &brightness);
    printf("Light brightness set to %d.\n", brightness);
}

// Function to get light status
void get_light_status(void) {
    printf("Light is %s.\n", rand() % 2? "on" : "off");
}