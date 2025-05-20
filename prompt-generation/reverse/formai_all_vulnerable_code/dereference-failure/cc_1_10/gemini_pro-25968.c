//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the different types of devices that can be controlled
typedef enum {
  LIGHT,
  FAN,
  THERMOSTAT
} device_type;

// Define the different states that a device can be in
typedef enum {
  ON,
  OFF
} device_state;

// Define the structure of a device
typedef struct {
  char *name;
  device_type type;
  device_state state;
} device;

// Create an array of devices
device devices[] = {
  { "Living Room Light", LIGHT, OFF },
  { "Ceiling Fan", FAN, OFF },
  { "Thermostat", THERMOSTAT, 72 }
};

// Print the current state of all the devices
void print_devices() {
  for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
    printf("%s: ", devices[i].name);
    switch (devices[i].type) {
      case LIGHT:
        printf("%s\n", devices[i].state == ON ? "On" : "Off");
        break;
      case FAN:
        printf("%s\n", devices[i].state == ON ? "On" : "Off");
        break;
      case THERMOSTAT:
        printf("%d degrees Fahrenheit\n", devices[i].state);
        break;
    }
  }
}

// Parse a command and execute it
void execute_command(char *command) {
  // Tokenize the command
  char *tokens[3];
  int num_tokens = 0;
  char *token = strtok(command, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Check if the command is valid
  if (num_tokens != 3) {
    printf("Invalid command: %s\n", command);
    return;
  }

  // Find the device
  int device_index = -1;
  for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
    if (strcmp(devices[i].name, tokens[1]) == 0) {
      device_index = i;
      break;
    }
  }

  // Check if the device was found
  if (device_index == -1) {
    printf("Device not found: %s\n", tokens[1]);
    return;
  }

  // Execute the command
  if (strcmp(tokens[0], "on") == 0) {
    devices[device_index].state = ON;
  } else if (strcmp(tokens[0], "off") == 0) {
    devices[device_index].state = OFF;
  } else if (strcmp(tokens[0], "set") == 0 && devices[device_index].type == THERMOSTAT) {
    devices[device_index].state = atoi(tokens[2]);
  } else {
    printf("Invalid command: %s\n", command);
  }
}

// Get a command from the user
char *get_command() {
  char *buffer = NULL;
  size_t size = 0;
  getline(&buffer, &size, stdin);
  return buffer;
}

// Main function
int main() {
  // Print the initial state of the devices
  print_devices();

  // Get commands from the user until they quit
  while (1) {
    printf("> ");
    char *command = get_command();
    if (strcmp(command, "quit\n") == 0) {
      break;
    }
    execute_command(command);
    print_devices();
  }

  return 0;
}