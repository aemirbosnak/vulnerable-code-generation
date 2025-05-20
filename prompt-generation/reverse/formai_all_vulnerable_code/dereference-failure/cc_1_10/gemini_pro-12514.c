//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the light states
#define LIGHT_OFF 0
#define LIGHT_ON 1
#define LIGHT_DIM 2

// Define the light colors
#define LIGHT_COLOR_WHITE 0
#define LIGHT_COLOR_RED 1
#define LIGHT_COLOR_GREEN 2
#define LIGHT_COLOR_BLUE 3

// Define the light types
#define LIGHT_TYPE_BULB 0
#define LIGHT_TYPE_STRIP 1
#define LIGHT_TYPE_PANEL 2

// Define the light commands
#define LIGHT_COMMAND_ON 0
#define LIGHT_COMMAND_OFF 1
#define LIGHT_COMMAND_DIM 2
#define LIGHT_COMMAND_COLOR 3
#define LIGHT_COMMAND_TYPE 4

// Define the light struct
typedef struct light {
  int state;
  int color;
  int type;
} light;

// Define the smart home struct
typedef struct smart_home {
  light lights[MAX_LIGHTS];
} smart_home;

// Create a new smart home
smart_home* create_smart_home() {
  smart_home* home = malloc(sizeof(smart_home));
  for (int i = 0; i < MAX_LIGHTS; i++) {
    home->lights[i].state = LIGHT_OFF;
    home->lights[i].color = LIGHT_COLOR_WHITE;
    home->lights[i].type = LIGHT_TYPE_BULB;
  }
  return home;
}

// Destroy a smart home
void destroy_smart_home(smart_home* home) {
  free(home);
}

// Turn a light on
void turn_light_on(smart_home* home, int light_index) {
  home->lights[light_index].state = LIGHT_ON;
}

// Turn a light off
void turn_light_off(smart_home* home, int light_index) {
  home->lights[light_index].state = LIGHT_OFF;
}

// Dim a light
void dim_light(smart_home* home, int light_index, int brightness) {
  home->lights[light_index].state = LIGHT_DIM;
  home->lights[light_index].color = brightness;
}

// Change the color of a light
void change_light_color(smart_home* home, int light_index, int color) {
  home->lights[light_index].color = color;
}

// Change the type of a light
void change_light_type(smart_home* home, int light_index, int type) {
  home->lights[light_index].type = type;
}

// Get the state of a light
int get_light_state(smart_home* home, int light_index) {
  return home->lights[light_index].state;
}

// Get the color of a light
int get_light_color(smart_home* home, int light_index) {
  return home->lights[light_index].color;
}

// Get the type of a light
int get_light_type(smart_home* home, int light_index) {
  return home->lights[light_index].type;
}

// Print the state of all lights
void print_lights(smart_home* home) {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("Light %d: ", i);
    switch (home->lights[i].state) {
      case LIGHT_OFF:
        printf("Off\n");
        break;
      case LIGHT_ON:
        printf("On\n");
        break;
      case LIGHT_DIM:
        printf("Dimmed to %d%%\n", home->lights[i].color);
        break;
    }
  }
}

// Parse a command
int parse_command(char* command) {
  if (strcmp(command, "on") == 0) {
    return LIGHT_COMMAND_ON;
  } else if (strcmp(command, "off") == 0) {
    return LIGHT_COMMAND_OFF;
  } else if (strcmp(command, "dim") == 0) {
    return LIGHT_COMMAND_DIM;
  } else if (strcmp(command, "color") == 0) {
    return LIGHT_COMMAND_COLOR;
  } else if (strcmp(command, "type") == 0) {
    return LIGHT_COMMAND_TYPE;
  } else {
    return -1;
  }
}

// Execute a command
void execute_command(smart_home* home, int command, int light_index, int value) {
  switch (command) {
    case LIGHT_COMMAND_ON:
      turn_light_on(home, light_index);
      break;
    case LIGHT_COMMAND_OFF:
      turn_light_off(home, light_index);
      break;
    case LIGHT_COMMAND_DIM:
      dim_light(home, light_index, value);
      break;
    case LIGHT_COMMAND_COLOR:
      change_light_color(home, light_index, value);
      break;
    case LIGHT_COMMAND_TYPE:
      change_light_type(home, light_index, value);
      break;
  }
}

// Main function
int main() {
  // Create a new smart home
  smart_home* home = create_smart_home();

  // Print the initial state of the lights
  printf("Initial state of the lights:\n");
  print_lights(home);

  // Get a command from the user
  char command[256];
  printf("Enter a command: ");
  scanf("%s", command);

  // Parse the command
  int command_id = parse_command(command);

  // Execute the command
  if (command_id != -1) {
    int light_index;
    int value;
    switch (command_id) {
      case LIGHT_COMMAND_ON:
      case LIGHT_COMMAND_OFF:
        printf("Enter the light index: ");
        scanf("%d", &light_index);
        execute_command(home, command_id, light_index, 0);
        break;
      case LIGHT_COMMAND_DIM:
        printf("Enter the light index and brightness: ");
        scanf("%d %d", &light_index, &value);
        execute_command(home, command_id, light_index, value);
        break;
      case LIGHT_COMMAND_COLOR:
        printf("Enter the light index and color: ");
        scanf("%d %d", &light_index, &value);
        execute_command(home, command_id, light_index, value);
        break;
      case LIGHT_COMMAND_TYPE:
        printf("Enter the light index and type: ");
        scanf("%d %d", &light_index, &value);
        execute_command(home, command_id, light_index, value);
        break;
    }
  } else {
    printf("Invalid command\n");
  }

  // Print the new state of the lights
  printf("New state of the lights:\n");
  print_lights(home);

  // Destroy the smart home
  destroy_smart_home(home);

  return 0;
}