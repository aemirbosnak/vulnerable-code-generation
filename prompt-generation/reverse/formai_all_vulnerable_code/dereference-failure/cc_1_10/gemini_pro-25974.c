//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices
#define MAX_DEVICES 10

// Define the device types
typedef enum {
  DEVICE_TYPE_LIGHT,
  DEVICE_TYPE_SWITCH,
  DEVICE_TYPE_THERMOSTAT
} device_type_t;

// Define the device states
typedef enum {
  DEVICE_STATE_ON,
  DEVICE_STATE_OFF
} device_state_t;

// Define the device structure
typedef struct {
  char *name;
  device_type_t type;
  device_state_t state;
} device_t;

// Define the smart home structure
typedef struct {
  device_t devices[MAX_DEVICES];
  int num_devices;
} smart_home_t;

// Create a new smart home
smart_home_t *smart_home_new() {
  smart_home_t *smart_home = malloc(sizeof(smart_home_t));
  if (smart_home == NULL) {
    return NULL;
  }
  smart_home->num_devices = 0;
  return smart_home;
}

// Add a new device to the smart home
int smart_home_add_device(smart_home_t *smart_home, device_t *device) {
  if (smart_home->num_devices >= MAX_DEVICES) {
    return -1;
  }
  smart_home->devices[smart_home->num_devices++] = *device;
  return 0;
}

// Get a device by name
device_t *smart_home_get_device_by_name(smart_home_t *smart_home, char *name) {
  for (int i = 0; i < smart_home->num_devices; i++) {
    if (strcmp(smart_home->devices[i].name, name) == 0) {
      return &smart_home->devices[i];
    }
  }
  return NULL;
}

// Turn a device on
int smart_home_turn_on_device(smart_home_t *smart_home, char *name) {
  device_t *device = smart_home_get_device_by_name(smart_home, name);
  if (device == NULL) {
    return -1;
  }
  device->state = DEVICE_STATE_ON;
  return 0;
}

// Turn a device off
int smart_home_turn_off_device(smart_home_t *smart_home, char *name) {
  device_t *device = smart_home_get_device_by_name(smart_home, name);
  if (device == NULL) {
    return -1;
  }
  device->state = DEVICE_STATE_OFF;
  return 0;
}

// Print the smart home status
void smart_home_print_status(smart_home_t *smart_home) {
  for (int i = 0; i < smart_home->num_devices; i++) {
    printf("%s: ", smart_home->devices[i].name);
    switch (smart_home->devices[i].state) {
      case DEVICE_STATE_ON:
        printf("on\n");
        break;
      case DEVICE_STATE_OFF:
        printf("off\n");
        break;
    }
  }
}

// Free the smart home
void smart_home_free(smart_home_t *smart_home) {
  for (int i = 0; i < smart_home->num_devices; i++) {
    free(smart_home->devices[i].name);
  }
  free(smart_home);
}

// Main function
int main() {
  // Create a new smart home
  smart_home_t *smart_home = smart_home_new();

  // Add some devices to the smart home
  device_t light1 = {
    .name = "light1",
    .type = DEVICE_TYPE_LIGHT,
    .state = DEVICE_STATE_OFF
  };
  smart_home_add_device(smart_home, &light1);

  device_t light2 = {
    .name = "light2",
    .type = DEVICE_TYPE_LIGHT,
    .state = DEVICE_STATE_OFF
  };
  smart_home_add_device(smart_home, &light2);

  device_t switch1 = {
    .name = "switch1",
    .type = DEVICE_TYPE_SWITCH,
    .state = DEVICE_STATE_OFF
  };
  smart_home_add_device(smart_home, &switch1);

  device_t thermostat1 = {
    .name = "thermostat1",
    .type = DEVICE_TYPE_THERMOSTAT,
    .state = DEVICE_STATE_OFF
  };
  smart_home_add_device(smart_home, &thermostat1);

  // Print the smart home status
  smart_home_print_status(smart_home);

  // Turn on light1
  smart_home_turn_on_device(smart_home, "light1");

  // Turn off switch1
  smart_home_turn_off_device(smart_home, "switch1");

  // Print the smart home status
  smart_home_print_status(smart_home);

  // Free the smart home
  smart_home_free(smart_home);

  return 0;
}