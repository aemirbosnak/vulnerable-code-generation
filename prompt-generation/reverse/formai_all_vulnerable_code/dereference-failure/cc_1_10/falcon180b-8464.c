//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_COMMANDS 10

// Struct to hold command and its corresponding function pointer
typedef struct {
    char *command;
    void (*function)(void);
} command_t;

// Function prototypes
void turn_on_light(void);
void turn_off_light(void);
void set_light_brightness(void);

int main(void) {
    // Initialize command list
    command_t commands[MAX_COMMANDS] = {{"turn_on_light", turn_on_light},
                                        {"turn_off_light", turn_off_light},
                                        {"set_light_brightness", set_light_brightness}};

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char input_buffer[256];
    while (true) {
        printf("Enter command: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        // Remove newline character from input buffer
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Convert input to lowercase
        for (int i = 0; input_buffer[i]!= '\0'; i++) {
            input_buffer[i] = tolower(input_buffer[i]);
        }

        bool command_found = false;
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input_buffer, commands[i].command) == 0) {
                commands[i].function();
                command_found = true;
                break;
            }
        }

        if (!command_found) {
            printf("Invalid command\n");
        }
    }

    return 0;
}

// Function to turn on light
void turn_on_light(void) {
    printf("Light turned on\n");
}

// Function to turn off light
void turn_off_light(void) {
    printf("Light turned off\n");
}

// Function to set light brightness
void set_light_brightness(void) {
    int brightness;
    printf("Enter brightness (0-100): ");
    scanf("%d", &brightness);

    if (brightness >= 0 && brightness <= 100) {
        printf("Light brightness set to %d\n", brightness);
    } else {
        printf("Invalid brightness\n");
    }
}