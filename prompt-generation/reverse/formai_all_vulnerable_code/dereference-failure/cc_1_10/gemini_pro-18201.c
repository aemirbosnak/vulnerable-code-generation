//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the states of the smart home
typedef enum {
  STATE_OFF,
  STATE_ON,
  STATE_DIMMED
} state_t;

// Define the types of devices
typedef enum {
  DEVICE_TYPE_LIGHT,
  DEVICE_TYPE_FAN,
  DEVICE_TYPE_THERMOSTAT
} device_type_t;

// Define the structure of a device
typedef struct {
  device_type_t type;
  char *name;
  state_t state;
} device_t;

// Define the list of devices
device_t devices[] = {
  { DEVICE_TYPE_LIGHT, "Living Room Light", STATE_OFF },
  { DEVICE_TYPE_FAN, "Bedroom Fan", STATE_OFF },
  { DEVICE_TYPE_THERMOSTAT, "Kitchen Thermostat", STATE_OFF }
};

// Define the number of devices
#define NUM_DEVICES (sizeof(devices) / sizeof(devices[0]))

// Function to turn a device on
void turn_on(device_t *device) {
  device->state = STATE_ON;
  printf("%s is now on.\n", device->name);
}

// Function to turn a device off
void turn_off(device_t *device) {
  device->state = STATE_OFF;
  printf("%s is now off.\n", device->name);
}

// Function to dim a light
void dim_light(device_t *device) {
  if (device->type != DEVICE_TYPE_LIGHT) {
    printf("Error: %s is not a light.\n", device->name);
    return;
  }

  device->state = STATE_DIMMED;
  printf("%s is now dimmed.\n", device->name);
}

// Function to set the temperature of a thermostat
void set_temperature(device_t *device, int temperature) {
  if (device->type != DEVICE_TYPE_THERMOSTAT) {
    printf("Error: %s is not a thermostat.\n", device->name);
    return;
  }

  device->state = STATE_ON;
  printf("%s is now set to %d degrees.\n", device->name, temperature);
}

// Function to print the status of a device
void print_status(device_t *device) {
  switch (device->state) {
    case STATE_OFF:
      printf("%s is off.\n", device->name);
      break;
    case STATE_ON:
      printf("%s is on.\n", device->name);
      break;
    case STATE_DIMMED:
      printf("%s is dimmed.\n", device->name);
      break;
  }
}

// Function to handle user input
void handle_input() {
  char input[100];

  while (1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Parse the input
    char *command = strtok(input, " ");
    char *args = strtok(NULL, "\n");

    // Execute the command
    if (strcmp(command, "on") == 0) {
      for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(devices[i].name, args) == 0) {
          turn_on(&devices[i]);
          break;
        }
      }
    } else if (strcmp(command, "off") == 0) {
      for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(devices[i].name, args) == 0) {
          turn_off(&devices[i]);
          break;
        }
      }
    } else if (strcmp(command, "dim") == 0) {
      for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(devices[i].name, args) == 0) {
          dim_light(&devices[i]);
          break;
        }
      }
    } else if (strcmp(command, "set_temperature") == 0) {
      char *temperature_str = strtok(args, " ");
      int temperature = atoi(temperature_str);

      for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(devices[i].name, args) == 0) {
          set_temperature(&devices[i], temperature);
          break;
        }
      }
    } else if (strcmp(command, "status") == 0) {
      for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(devices[i].name, args) == 0) {
          print_status(&devices[i]);
          break;
        }
      }
    } else if (strcmp(command, "exit") == 0) {
      exit(0);
    } else {
      printf("Error: Unknown command.\n");
    }
  }
}

// Main function
int main() {
  handle_input();

  return 0;
}