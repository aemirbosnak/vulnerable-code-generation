//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: relaxed
// C Smart Home Automation Example Program
//
// This program simulates a smart home automation system that controls lighting, temperature, and security.
// The system is controlled by a user interface that allows the user to set preferences and control devices.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of devices that the system can control.
#define MAX_DEVICES 10

// Define the types of devices that the system can control.
typedef enum {
  DEVICE_TYPE_LIGHT,
  DEVICE_TYPE_TEMPERATURE,
  DEVICE_TYPE_SECURITY
} device_type_t;

// Define the structure of a device.
typedef struct {
  device_type_t type;
  char *name;
  int state;
} device_t;

// Define the structure of the smart home automation system.
typedef struct {
  device_t devices[MAX_DEVICES];
  int num_devices;
} smart_home_system_t;

// Create a new smart home automation system.
smart_home_system_t *smart_home_system_new() {
  smart_home_system_t *system = malloc(sizeof(smart_home_system_t));
  system->num_devices = 0;
  return system;
}

// Add a new device to the smart home automation system.
void smart_home_system_add_device(smart_home_system_t *system, device_t *device) {
  if (system->num_devices < MAX_DEVICES) {
    system->devices[system->num_devices++] = *device;
  }
}

// Set the state of a device in the smart home automation system.
void smart_home_system_set_device_state(smart_home_system_t *system, char *name, int state) {
  for (int i = 0; i < system->num_devices; i++) {
    if (strcmp(system->devices[i].name, name) == 0) {
      system->devices[i].state = state;
    }
  }
}

// Get the state of a device in the smart home automation system.
int smart_home_system_get_device_state(smart_home_system_t *system, char *name) {
  for (int i = 0; i < system->num_devices; i++) {
    if (strcmp(system->devices[i].name, name) == 0) {
      return system->devices[i].state;
    }
  }
  return -1;
}

// Print the status of the smart home automation system.
void smart_home_system_print_status(smart_home_system_t *system) {
  printf("Smart Home Automation System Status:\n");
  for (int i = 0; i < system->num_devices; i++) {
    printf("  %s: ", system->devices[i].name);
    switch (system->devices[i].type) {
      case DEVICE_TYPE_LIGHT:
        printf("light");
        break;
      case DEVICE_TYPE_TEMPERATURE:
        printf("temperature");
        break;
      case DEVICE_TYPE_SECURITY:
        printf("security");
        break;
      default:
        printf("unknown");
        break;
    }
    printf(" (%s)\n", system->devices[i].state ? "on" : "off");
  }
}

// Main function.
int main() {
  // Create a new smart home automation system.
  smart_home_system_t *system = smart_home_system_new();

  // Add some devices to the system.
  device_t light1 = {
    .type = DEVICE_TYPE_LIGHT,
    .name = "kitchen light",
    .state = 0
  };
  smart_home_system_add_device(system, &light1);

  device_t light2 = {
    .type = DEVICE_TYPE_LIGHT,
    .name = "living room light",
    .state = 0
  };
  smart_home_system_add_device(system, &light2);

  device_t thermostat = {
    .type = DEVICE_TYPE_TEMPERATURE,
    .name = "thermostat",
    .state = 70
  };
  smart_home_system_add_device(system, &thermostat);

  device_t security_system = {
    .type = DEVICE_TYPE_SECURITY,
    .name = "security system",
    .state = 0
  };
  smart_home_system_add_device(system, &security_system);

  // Print the initial status of the system.
  smart_home_system_print_status(system);

  // Simulate some user input.
  int choice;
  char *name;
  int state;
  while (1) {
    printf("Enter a command (1 to turn on a device, 2 to turn off a device, 3 to print the status of the system, or 4 to quit): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the name of the device to turn on: ");
        scanf("%s", name);
        smart_home_system_set_device_state(system, name, 1);
        break;
      case 2:
        printf("Enter the name of the device to turn off: ");
        scanf("%s", name);
        smart_home_system_set_device_state(system, name, 0);
        break;
      case 3:
        smart_home_system_print_status(system);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid command. Please enter a number between 1 and 4.\n");
        break;
    }
  }

  return 0;
}