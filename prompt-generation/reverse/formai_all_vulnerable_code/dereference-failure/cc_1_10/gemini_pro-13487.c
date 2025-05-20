//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10

typedef struct {
    char *name;
    int type; // 0: light, 1: outlet, 2: thermostat
    int state; // 0: off, 1: on
} device;

device devices[MAX_DEVICES];

int main() {
    // Initialize devices
    devices[0].name = "Living Room Light";
    devices[0].type = 0;
    devices[0].state = 0;

    devices[1].name = "Kitchen Outlet";
    devices[1].type = 1;
    devices[1].state = 1;

    devices[2].name = "Upstairs Thermostat";
    devices[2].type = 2;
    devices[2].state = 72;

    // Main loop
    while (1) {
        // Get user input
        char input[100];
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Tokenize input
        char *tokens[3];
        int num_tokens = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            tokens[num_tokens++] = token;
            token = strtok(NULL, " ");
        }

        // Parse command
        if (strcmp(tokens[0], "on") == 0) {
            // Turn on device
            int device_index = atoi(tokens[1]);
            devices[device_index].state = 1;
            printf("%s turned on.\n", devices[device_index].name);
        } else if (strcmp(tokens[0], "off") == 0) {
            // Turn off device
            int device_index = atoi(tokens[1]);
            devices[device_index].state = 0;
            printf("%s turned off.\n", devices[device_index].name);
        } else if (strcmp(tokens[0], "status") == 0) {
            // Get device status
            int device_index = atoi(tokens[1]);
            if (devices[device_index].state == 0) {
                printf("%s is off.\n", devices[device_index].name);
            } else {
                printf("%s is on.\n", devices[device_index].name);
            }
        } else if (strcmp(tokens[0], "exit") == 0) {
            // Exit program
            break;
        } else {
            // Unknown command
            printf("Unknown command.\n");
        }
    }

    return 0;
}