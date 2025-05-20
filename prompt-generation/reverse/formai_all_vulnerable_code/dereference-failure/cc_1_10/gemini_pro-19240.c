//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the commands that the smart home system understands
#define COMMAND_TURN_ON "turn on"
#define COMMAND_TURN_OFF "turn off"
#define COMMAND_SET_TEMPERATURE "set temperature"
#define COMMAND_SET_LIGHT_LEVEL "set light level"
#define COMMAND_PLAY_MUSIC "play music"
#define COMMAND_STOP_MUSIC "stop music"
#define COMMAND_SET_ALARM "set alarm"
#define COMMAND_CANCEL_ALARM "cancel alarm"

// Define the devices that the smart home system can control
#define DEVICE_LIGHT "light"
#define DEVICE_THERMOSTAT "thermostat"
#define DEVICE_MUSIC_PLAYER "music player"
#define DEVICE_ALARM_CLOCK "alarm clock"

// Define the states that the devices can be in
#define STATE_ON "on"
#define STATE_OFF "off"

// Create a struct to represent a device
typedef struct {
    char *name;
    char *type;
    char *state;
} device;

// Create an array of devices
device devices[] = {
    { "living room light", DEVICE_LIGHT, STATE_OFF },
    { "kitchen light", DEVICE_LIGHT, STATE_OFF },
    { "bedroom light", DEVICE_LIGHT, STATE_OFF },
    { "thermostat", DEVICE_THERMOSTAT, "72" },
    { "music player", DEVICE_MUSIC_PLAYER, STATE_OFF },
    { "alarm clock", DEVICE_ALARM_CLOCK, STATE_OFF }
};

// Create a function to handle a command
void handle_command(char *command) {
    // Parse the command
    char *device_name = strtok(command, " ");
    char *action = strtok(NULL, " ");
    char *value = strtok(NULL, "\n");

    // Find the device that the command is for
    device *device = NULL;
    for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
        if (strcmp(device_name, devices[i].name) == 0) {
            device = &devices[i];
            break;
        }
    }

    // If the device was not found, print an error message
    if (device == NULL) {
        printf("Error: device not found\n");
        return;
    }

    // Handle the action
    if (strcmp(action, COMMAND_TURN_ON) == 0) {
        device->state = STATE_ON;
    } else if (strcmp(action, COMMAND_TURN_OFF) == 0) {
        device->state = STATE_OFF;
    } else if (strcmp(action, COMMAND_SET_TEMPERATURE) == 0) {
        device->state = value;
    } else if (strcmp(action, COMMAND_SET_LIGHT_LEVEL) == 0) {
        device->state = value;
    } else if (strcmp(action, COMMAND_PLAY_MUSIC) == 0) {
        device->state = STATE_ON;
    } else if (strcmp(action, COMMAND_STOP_MUSIC) == 0) {
        device->state = STATE_OFF;
    } else if (strcmp(action, COMMAND_SET_ALARM) == 0) {
        device->state = value;
    } else if (strcmp(action, COMMAND_CANCEL_ALARM) == 0) {
        device->state = STATE_OFF;
    } else {
        printf("Error: invalid action\n");
        return;
    }

    // Print a success message
    printf("Command executed successfully\n");
}

// Get input from the user
char *get_input() {
    char *input = malloc(256);
    printf("> ");
    fgets(input, 256, stdin);
    input[strlen(input) - 1] = '\0';
    return input;
}

// Main function
int main() {
    // Run the smart home system until the user quits
    while (1) {
        // Get input from the user
        char *input = get_input();

        // Handle the command
        handle_command(input);

        // Free the input buffer
        free(input);
    }

    return 0;
}