//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the different types of devices
typedef enum {
  LIGHT,
  FAN,
  THERMOSTAT
} device_type;

// Define the different states of a device
typedef enum {
  ON,
  OFF
} device_state;

// Define the maximum number of devices
#define MAX_DEVICES 10

// Define the structure of a device
typedef struct {
  device_type type;
  char *name;
  device_state state;
} device;

// Define the structure of a smart home
typedef struct {
  device devices[MAX_DEVICES];
  int num_devices;
} smart_home;

// Create a new smart home
smart_home* create_smart_home() {
  smart_home* home = malloc(sizeof(smart_home));
  home->num_devices = 0;
  return home;
}

// Add a device to a smart home
void add_device(smart_home* home, device* device) {
  if (home->num_devices < MAX_DEVICES) {
    home->devices[home->num_devices] = *device;
    home->num_devices++;
  }
}

// Get a device from a smart home by name
device* get_device(smart_home* home, char* name) {
  for (int i = 0; i < home->num_devices; i++) {
    if (strcmp(home->devices[i].name, name) == 0) {
      return &home->devices[i];
    }
  }
  return NULL;
}

// Turn on a device
void turn_on(device* device) {
  device->state = ON;
}

// Turn off a device
void turn_off(device* device) {
  device->state = OFF;
}

// Print the status of a device
void print_device_status(device* device) {
  printf("%s is %s\n", device->name, device->state == ON ? "on" : "off");
}

// Print the status of a smart home
void print_smart_home_status(smart_home* home) {
  for (int i = 0; i < home->num_devices; i++) {
    print_device_status(&home->devices[i]);
  }
}

// Main function
int main() {
  // Create a new smart home
  smart_home* home = create_smart_home();

  // Add some devices to the smart home
  device light = {LIGHT, "Light", OFF};
  add_device(home, &light);

  device fan = {FAN, "Fan", OFF};
  add_device(home, &fan);

  device thermostat = {THERMOSTAT, "Thermostat", OFF};
  add_device(home, &thermostat);

  // Turn on the light
  turn_on(&light);

  // Turn on the fan
  turn_on(&fan);

  // Set the thermostat to 72 degrees
  thermostat.state = 72;

  // Print the status of the smart home
  print_smart_home_status(home);

  return 0;
}