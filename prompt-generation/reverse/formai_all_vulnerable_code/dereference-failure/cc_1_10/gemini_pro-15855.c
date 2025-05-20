//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the light states
enum light_state {
  LIGHT_OFF,
  LIGHT_ON
};

// Define the commands
enum command {
  CMD_HELP,
  CMD_TOGGLE,
  CMD_QUIT
};

// Define the device
struct device {
  char *name;
  enum light_state state;
};

// Create a new device
struct device *create_device(char *name) {
  struct device *device = malloc(sizeof(struct device));
  device->name = name;
  device->state = LIGHT_OFF;
  return device;
}

// Free a device
void free_device(struct device *device) {
  free(device->name);
  free(device);
}

// Toggle a device
void toggle_device(struct device *device) {
  device->state = (device->state == LIGHT_OFF) ? LIGHT_ON : LIGHT_OFF;
}

// Print help
void print_help() {
  printf("Commands:\n");
  printf("  help - Print this help message\n");
  printf("  toggle <device> - Toggle the state of a device\n");
  printf("  quit - Quit the program\n");
}

// Parse a command
enum command parse_command(char *input) {
  if (strcmp(input, "help") == 0) {
    return CMD_HELP;
  } else if (strcmp(input, "toggle") == 0) {
    return CMD_TOGGLE;
  } else if (strcmp(input, "quit") == 0) {
    return CMD_QUIT;
  } else {
    return -1;
  }
}

// Main function
int main() {
  // Create a device
  struct device *device = create_device("Lantern");

  // Main loop
  while (1) {
    // Get input
    char input[256];
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Parse the input
    enum command command = parse_command(input);

    // Handle the command
    switch (command) {
      case CMD_HELP:
        print_help();
        break;
      case CMD_TOGGLE:
        toggle_device(device);
        break;
      case CMD_QUIT:
        free_device(device);
        return 0;
      default:
        printf("Invalid command\n");
        break;
    }
  }

  return 0;
}