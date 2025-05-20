//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the device states
enum device_state {
    OFF,
    ON,
    DIMMED
};

// Define the device types
enum device_type {
    LIGHT,
    FAN,
    THERMOSTAT
};

// Define the device structure
struct device {
    char name[32];
    enum device_type type;
    enum device_state state;
};

// Create an array of devices
struct device devices[] = {
    {"Living Room Light", LIGHT, OFF},
    {"Ceiling Fan", FAN, OFF},
    {"Thermostat", THERMOSTAT, OFF}
};

// Define the command types
enum command_type {
    TURN_ON,
    TURN_OFF,
    DIM,
    SET_TEMPERATURE
};

// Define the command structure
struct command {
    enum command_type type;
    char device_name[32];
    int value;
};

// Parse the command line arguments
int parse_command(int argc, char *argv[], struct command *command) {
    // Check if the number of arguments is valid
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command> <device_name> [value]\n", argv[0]);
        return 1;
    }

    // Parse the command type
    if (strcmp(argv[1], "on") == 0) {
        command->type = TURN_ON;
    } else if (strcmp(argv[1], "off") == 0) {
        command->type = TURN_OFF;
    } else if (strcmp(argv[1], "dim") == 0) {
        command->type = DIM;
    } else if (strcmp(argv[1], "set_temperature") == 0) {
        command->type = SET_TEMPERATURE;
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[1]);
        return 1;
    }

    // Parse the device name
    strcpy(command->device_name, argv[2]);

    // Parse the value (if any)
    if (command->type == DIM || command->type == SET_TEMPERATURE) {
        command->value = atoi(argv[3]);
    }

    return 0;
}

// Execute the command
int execute_command(struct command *command) {
    // Find the device with the specified name
    struct device *device = NULL;
    for (int i = 0; i < sizeof(devices) / sizeof(struct device); i++) {
        if (strcmp(devices[i].name, command->device_name) == 0) {
            device = &devices[i];
            break;
        }
    }

    // Check if the device was found
    if (device == NULL) {
        fprintf(stderr, "Device not found: %s\n", command->device_name);
        return 1;
    }

    // Execute the command
    switch (command->type) {
    case TURN_ON:
        device->state = ON;
        printf("Turning %s on\n", device->name);
        break;
    case TURN_OFF:
        device->state = OFF;
        printf("Turning %s off\n", device->name);
        break;
    case DIM:
        device->state = DIMMED;
        printf("Dimming %s to %d\n", device->name, command->value);
        break;
    case SET_TEMPERATURE:
        device->state = ON;
        printf("Setting %s to %d degrees\n", device->name, command->value);
        break;
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Parse the command line arguments
    struct command command;
    if (parse_command(argc, argv, &command) != 0) {
        return 1;
    }

    // Execute the command
    if (execute_command(&command) != 0) {
        return 1;
    }

    return 0;
}