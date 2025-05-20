//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home devices
typedef enum {
  LIGHT_BULB,
  AC,
  FAN,
  DOOR_LOCK
} device_type;

typedef struct {
  device_type type;
  char *name;
  int state; // 0 for off, 1 for on
} device;

// Create an array of smart home devices
device devices[] = {
  { LIGHT_BULB, "Living Room Light", 0 },
  { AC, "Bedroom AC", 0 },
  { FAN, "Kitchen Fan", 0 },
  { DOOR_LOCK, "Front Door Lock", 0 }
};

// Define the smart home commands
typedef enum {
  TURN_ON,
  TURN_OFF,
  GET_STATUS
} command_type;

typedef struct {
  command_type type;
  char *device_name;
} command;

// Create a function to execute a smart home command
void execute_command(command *cmd) {
  for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
    if (strcmp(cmd->device_name, devices[i].name) == 0) {
      switch (cmd->type) {
        case TURN_ON:
          devices[i].state = 1;
          printf("%s turned on\n", devices[i].name);
          break;
        case TURN_OFF:
          devices[i].state = 0;
          printf("%s turned off\n", devices[i].name);
          break;
        case GET_STATUS:
          printf("%s is %s\n", devices[i].name, devices[i].state ? "on" : "off");
          break;
        default:
          printf("Invalid command\n");
          break;
      }
      break;
    }
  }
}

// Create a function to parse a smart home command from a string
command *parse_command(char *str) {
  command *cmd = malloc(sizeof(command));
  char *token;

  token = strtok(str, " ");
  if (strcmp(token, "turn_on") == 0) {
    cmd->type = TURN_ON;
  } else if (strcmp(token, "turn_off") == 0) {
    cmd->type = TURN_OFF;
  } else if (strcmp(token, "get_status") == 0) {
    cmd->type = GET_STATUS;
  } else {
    printf("Invalid command\n");
    free(cmd);
    return NULL;
  }

  token = strtok(NULL, " ");
  cmd->device_name = malloc(strlen(token) + 1);
  strcpy(cmd->device_name, token);

  return cmd;
}

// Create a function to get a smart home command from the user
char *get_command() {
  char *str = malloc(1024);
  printf("Enter a smart home command: ");
  fgets(str, 1024, stdin);
  return str;
}

// Create a function to print the status of all smart home devices
void print_status() {
  for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
    printf("%s is %s\n", devices[i].name, devices[i].state ? "on" : "off");
  }
}

// Main function
int main() {
  char *command_str;
  command *cmd;

  while (1) {
    command_str = get_command();
    cmd = parse_command(command_str);
    if (cmd) {
      execute_command(cmd);
      free(cmd->device_name);
      free(cmd);
    }
    print_status();
    free(command_str);
  }

  return 0;
}