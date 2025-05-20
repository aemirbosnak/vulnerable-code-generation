//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the commands that the smart home can understand
#define COMMAND_TURN_ON "turn on"
#define COMMAND_TURN_OFF "turn off"
#define COMMAND_SET_TEMPERATURE "set temperature"
#define COMMAND_SET_BRIGHTNESS "set brightness"

// Define the devices that the smart home can control
#define DEVICE_LIGHT "light"
#define DEVICE_HEATER "heater"
#define DEVICE_FAN "fan"

// Define the states that the devices can be in
#define STATE_ON "on"
#define STATE_OFF "off"

// Define the data structure for a device
typedef struct {
  char *name;
  char *type;
  char *state;
  int value; // For temperature and brightness
} device;

// Create an array of devices
device devices[] = {
  { "Living Room Light", DEVICE_LIGHT, STATE_OFF, 0 },
  { "Bedroom Heater", DEVICE_HEATER, STATE_OFF, 0 },
  { "Kitchen Fan", DEVICE_FAN, STATE_OFF, 0 },
};

// Get a device by name
device *get_device(char *name) {
  for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
    if (strcmp(devices[i].name, name) == 0) {
      return &devices[i];
    }
  }
  return NULL;
}

// Turn a device on or off
void turn_device(device *device, char *state) {
  if (strcmp(state, STATE_ON) == 0) {
    device->state = STATE_ON;
  } else if (strcmp(state, STATE_OFF) == 0) {
    device->state = STATE_OFF;
  }
}

// Set the temperature of a heater
void set_temperature(device *device, int temperature) {
  device->value = temperature;
}

// Set the brightness of a light
void set_brightness(device *device, int brightness) {
  device->value = brightness;
}

// Parse a command and execute it
void parse_command(char *command) {
  // Split the command into words
  char *words[4];
  int num_words = 0;
  char *word = strtok(command, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Get the device and the command
  device *device = get_device(words[1]);
  char *command_type = words[2];

  // Execute the command
  if (strcmp(command_type, COMMAND_TURN_ON) == 0) {
    turn_device(device, STATE_ON);
  } else if (strcmp(command_type, COMMAND_TURN_OFF) == 0) {
    turn_device(device, STATE_OFF);
  } else if (strcmp(command_type, COMMAND_SET_TEMPERATURE) == 0) {
    set_temperature(device, atoi(words[3]));
  } else if (strcmp(command_type, COMMAND_SET_BRIGHTNESS) == 0) {
    set_brightness(device, atoi(words[3]));
  }
}

// Main function
int main() {
  // Get the user's input
  char command[100];
  printf("Enter a command: ");
  fgets(command, sizeof(command), stdin);

  // Parse the command and execute it
  parse_command(command);

  // Print the current state of the devices
  for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
    printf("%s: %s\n", devices[i].name, devices[i].state);
  }

  return 0;
}