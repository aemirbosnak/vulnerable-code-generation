//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices that can be controlled
#define MAX_DEVICES 10

// Define the types of devices that can be controlled
typedef enum {
  LIGHT,
  HEATER,
  DOOR,
  WINDOW,
  TV,
  AC,
  FAN,
  BULB,
  CAMERA,
  LOCK
} device_type;

// Define the structure of a device
typedef struct {
  device_type type;       // The type of device
  char *name;             // The name of the device
  int state;              // The state of the device (0 = off, 1 = on)
} device;

// Define the structure of a smart home
typedef struct {
  device devices[MAX_DEVICES];  // The array of devices
  int num_devices;             // The number of devices
} smart_home;

// Create a new smart home
smart_home *create_smart_home() {
  smart_home *home = malloc(sizeof(smart_home));
  home->num_devices = 0;
  return home;
}

// Add a device to a smart home
void add_device(smart_home *home, device_type type, char *name) {
  if (home->num_devices >= MAX_DEVICES) {
    printf("Error: The maximum number of devices has been reached.\n");
    return;
  }

  device *new_device = malloc(sizeof(device));
  new_device->type = type;
  new_device->name = malloc(strlen(name) + 1);
  strcpy(new_device->name, name);
  new_device->state = 0;

  home->devices[home->num_devices++] = *new_device;
}

// Get a device by its name
device *get_device_by_name(smart_home *home, char *name) {
  for (int i = 0; i < home->num_devices; i++) {
    if (strcmp(home->devices[i].name, name) == 0) {
      return &home->devices[i];
    }
  }

  return NULL;
}

// Turn a device on
void turn_on_device(device *device) {
  device->state = 1;
}

// Turn a device off
void turn_off_device(device *device) {
  device->state = 0;
}

// Print the status of all devices in a smart home
void print_smart_home_status(smart_home *home) {
  printf("Smart Home Status:\n");
  for (int i = 0; i < home->num_devices; i++) {
    device *device = &home->devices[i];
    printf("  %s: %s\n", device->name, device->state == 1 ? "On" : "Off");
  }
}

// Main function
int main() {
  // Create a new smart home
  smart_home *home = create_smart_home();

  // Add some devices to the smart home
  add_device(home, LIGHT, "Bedroom Light");
  add_device(home, HEATER, "Living Room Heater");
  add_device(home, DOOR, "Front Door");
  add_device(home, WINDOW, "Kitchen Window");
  add_device(home, TV, "Living Room TV");
  add_device(home, AC, "Bedroom AC");
  add_device(home, FAN, "Bathroom Fan");
  add_device(home, BULB, "Garage Bulb");
  add_device(home, CAMERA, "Front Door Camera");
  add_device(home, LOCK, "Front Door Lock");

  // Print the status of all devices in the smart home
  print_smart_home_status(home);

  // Turn on the bedroom light
  device *bedroom_light = get_device_by_name(home, "Bedroom Light");
  turn_on_device(bedroom_light);

  // Turn off the living room heater
  device *living_room_heater = get_device_by_name(home, "Living Room Heater");
  turn_off_device(living_room_heater);

  // Print the status of all devices in the smart home again
  print_smart_home_status(home);

  return 0;
}