//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: minimalist
// Smart Home Automation CLI (Command-Line Interface)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Device commands
#define ON "ON"
#define OFF "OFF"
#define TOGGLE "TOGGLE"
#define STATUS "STATUS"
#define EXIT "EXIT"

// Device types
#define LIGHT "light"
#define FAN "fan"
#define AC "ac"

// Device structure
typedef struct device {
    char *name;
    char *type;
    int status;  // 0 (OFF) or 1 (ON)
} device;

// Create a new device
device *new_device(char *name, char *type) {
    device *d = (device *)malloc(sizeof(device));
    d->name = strdup(name);
    d->type = strdup(type);
    d->status = 0;
    return d;
}

// Parse a command and execute the corresponding action
void parse_command(char *command, device *devices[], int num_devices) {
    char *args[3];  // Max 3 arguments
    int argc = 0;
    char *arg;

    // Tokenize the command
    arg = strtok(command, " ");
    while (arg != NULL) {
        args[argc++] = arg;
        arg = strtok(NULL, " ");
    }

    // Check for valid number of arguments
    if (argc < 2 || argc > 3) {
        printf("Invalid number of arguments\n");
        return;
    }

    // Get the device and command
    char *device_name = args[0];
    char *command_type = args[1];

    // Find the device by name
    int found = 0;
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(device_name, devices[i]->name) == 0) {
            found = 1;
            device *d = devices[i];

            // Execute the command
            if (strcmp(command_type, ON) == 0) {
                d->status = 1;
                printf("%s %s turned ON\n", d->type, d->name);
            } else if (strcmp(command_type, OFF) == 0) {
                d->status = 0;
                printf("%s %s turned OFF\n", d->type, d->name);
            } else if (strcmp(command_type, TOGGLE) == 0) {
                d->status = !d->status;
                printf("%s %s %s\n", d->type, d->name, d->status ? "turned ON" : "turned OFF");
            } else if (strcmp(command_type, STATUS) == 0) {
                printf("%s %s is %s\n", d->type, d->name, d->status ? "ON" : "OFF");
            } else {
                printf("Invalid command\n");
            }

            break;
        }
    }

    // Device not found
    if (!found) {
        printf("Device not found\n");
    }
}

// Main function
int main() {
    // Create an array of devices
    device *devices[] = {
        new_device("living room light", LIGHT),
        new_device("bedroom fan", FAN),
        new_device("master bedroom ac", AC),
    };
    int num_devices = sizeof(devices) / sizeof(devices[0]);

    // Main loop
    while (1) {
        char command[100];
        printf("> ");
        fgets(command, sizeof(command), stdin);

        // Exit the program if the user enters "exit"
        if (strcmp(command, EXIT) == 0) {
            break;
        }

        // Parse the command and execute the corresponding action
        parse_command(command, devices, num_devices);
    }

    // Free the allocated memory
    for (int i = 0; i < num_devices; i++) {
        free(devices[i]->name);
        free(devices[i]->type);
        free(devices[i]);
    }

    return 0;
}