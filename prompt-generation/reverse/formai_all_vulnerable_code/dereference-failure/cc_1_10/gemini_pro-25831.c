//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the device states
enum device_state { OFF, ON };

// Define the device types
enum device_type { LIGHT, FAN, THERMOSTAT };

// Define the device struct
struct device {
  char *name;
  enum device_type type;
  enum device_state state;
};

// Create a new device
struct device *new_device(char *name, enum device_type type) {
  struct device *dev = malloc(sizeof(struct device));
  dev->name = strdup(name);
  dev->type = type;
  dev->state = OFF;
  return dev;
}

// Set the device state
void set_device_state(struct device *dev, enum device_state state) {
  dev->state = state;
}

// Get the device state
enum device_state get_device_state(struct device *dev) {
  return dev->state;
}

// Print the device state
void print_device_state(struct device *dev) {
  printf("%s is %s.\n", dev->name, dev->state == ON ? "on" : "off");
}

// Create a new smart home
struct smart_home {
  struct device **devices;
  int num_devices;
};

// Create a new smart home
struct smart_home *new_smart_home() {
  struct smart_home *home = malloc(sizeof(struct smart_home));
  home->devices = NULL;
  home->num_devices = 0;
  return home;
}

// Add a device to the smart home
void add_device_to_home(struct smart_home *home, struct device *dev) {
  home->devices = realloc(home->devices, sizeof(struct device *) * (home->num_devices + 1));
  home->devices[home->num_devices++] = dev;
}

// Print the smart home state
void print_smart_home_state(struct smart_home *home) {
  for (int i = 0; i < home->num_devices; i++) {
    print_device_state(home->devices[i]);
  }
}

// Main function
int main() {
  // Create a new smart home
  struct smart_home *home = new_smart_home();

  // Add some devices to the smart home
  struct device *light1 = new_device("Light 1", LIGHT);
  struct device *fan1 = new_device("Fan 1", FAN);
  struct device *thermostat1 = new_device("Thermostat 1", THERMOSTAT);
  add_device_to_home(home, light1);
  add_device_to_home(home, fan1);
  add_device_to_home(home, thermostat1);

  // Set the device states
  set_device_state(light1, ON);
  set_device_state(fan1, ON);
  set_device_state(thermostat1, 72);

  // Print the smart home state
  print_smart_home_state(home);

  // Cleanup
  for (int i = 0; i < home->num_devices; i++) {
    free(home->devices[i]);
  }
  free(home->devices);
  free(home);

  return 0;
}