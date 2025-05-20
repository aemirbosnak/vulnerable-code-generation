//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms and devices in the smart home
#define NUM_ROOMS 3
#define NUM_DEVICES 5

// Define the types of devices
typedef enum {
  LIGHT,
  THERMOSTAT,
  FAN,
  DOOR,
  WINDOW
} device_type;

// Define the states of devices
typedef enum {
  ON,
  OFF
} device_state;

// Define the room struct
typedef struct {
  char *name;
  device_state devices[NUM_DEVICES];
} room;

// Define the smart home struct
typedef struct {
  room rooms[NUM_ROOMS];
} smart_home;

// Create a new smart home
smart_home *create_smart_home() {
  smart_home *home = malloc(sizeof(smart_home));
  if (home == NULL) {
    return NULL;
  }

  // Initialize the rooms
  for (int i = 0; i < NUM_ROOMS; i++) {
    home->rooms[i].name = NULL;
    for (int j = 0; j < NUM_DEVICES; j++) {
      home->rooms[i].devices[j] = OFF;
    }
  }

  return home;
}

// Destroy a smart home
void destroy_smart_home(smart_home *home) {
  if (home == NULL) {
    return;
  }

  // Free the room names
  for (int i = 0; i < NUM_ROOMS; i++) {
    free(home->rooms[i].name);
  }

  // Free the smart home
  free(home);
}

// Get the state of a device
device_state get_device_state(smart_home *home, int room_index, int device_index) {
  if (home == NULL || room_index < 0 || room_index >= NUM_ROOMS || device_index < 0 || device_index >= NUM_DEVICES) {
    return -1;
  }

  return home->rooms[room_index].devices[device_index];
}

// Set the state of a device
int set_device_state(smart_home *home, int room_index, int device_index, device_state state) {
  if (home == NULL || room_index < 0 || room_index >= NUM_ROOMS || device_index < 0 || device_index >= NUM_DEVICES) {
    return -1;
  }

  home->rooms[room_index].devices[device_index] = state;

  return 0;
}

// Print the state of a smart home
void print_smart_home(smart_home *home) {
  if (home == NULL) {
    return;
  }

  // Print the room names
  for (int i = 0; i < NUM_ROOMS; i++) {
    printf("Room %d: %s\n", i + 1, home->rooms[i].name);
  }

  // Print the device states
  for (int i = 0; i < NUM_ROOMS; i++) {
    for (int j = 0; j < NUM_DEVICES; j++) {
      printf("  Device %d: %s\n", j + 1, home->rooms[i].devices[j] == ON ? "ON" : "OFF");
    }
  }
}

// Main function
int main() {
  // Create a new smart home
  smart_home *home = create_smart_home();

  // Set the room names
  home->rooms[0].name = "Living Room";
  home->rooms[1].name = "Kitchen";
  home->rooms[2].name = "Bedroom";

  // Set the device states
  set_device_state(home, 0, 0, ON); // Living Room light
  set_device_state(home, 0, 1, OFF); // Living Room thermostat
  set_device_state(home, 0, 2, ON); // Living Room fan
  set_device_state(home, 0, 3, OFF); // Living Room door
  set_device_state(home, 0, 4, OFF); // Living Room window

  set_device_state(home, 1, 0, ON); // Kitchen light
  set_device_state(home, 1, 1, OFF); // Kitchen thermostat
  set_device_state(home, 1, 2, OFF); // Kitchen fan
  set_device_state(home, 1, 3, OFF); // Kitchen door
  set_device_state(home, 1, 4, OFF); // Kitchen window

  set_device_state(home, 2, 0, ON); // Bedroom light
  set_device_state(home, 2, 1, OFF); // Bedroom thermostat
  set_device_state(home, 2, 2, ON); // Bedroom fan
  set_device_state(home, 2, 3, OFF); // Bedroom door
  set_device_state(home, 2, 4, OFF); // Bedroom window

  // Print the state of the smart home
  print_smart_home(home);

  // Destroy the smart home
  destroy_smart_home(home);

  return 0;
}