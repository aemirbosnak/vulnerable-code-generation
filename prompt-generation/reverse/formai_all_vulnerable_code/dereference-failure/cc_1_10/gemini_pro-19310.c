//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the light states
enum light_state {
  OFF,
  ON,
  DIMMED
};

// Define the light commands
enum light_command {
  TURN_ON,
  TURN_OFF,
  DIM,
  BRIGHTEN
};

// Define the light structure
struct light {
  char *name;
  enum light_state state;
};

// Create a new light
struct light *create_light(char *name) {
  struct light *light = malloc(sizeof(struct light));
  light->name = strdup(name);
  light->state = OFF;
  return light;
}

// Destroy a light
void destroy_light(struct light *light) {
  free(light->name);
  free(light);
}

// Turn a light on
void turn_on(struct light *light) {
  light->state = ON;
}

// Turn a light off
void turn_off(struct light *light) {
  light->state = OFF;
}

// Dim a light
void dim(struct light *light) {
  if (light->state == ON) {
    light->state = DIMMED;
  }
}

// Brighten a light
void brighten(struct light *light) {
  if (light->state == DIMMED) {
    light->state = ON;
  }
}

// Get the state of a light
enum light_state get_state(struct light *light) {
  return light->state;
}

// Print the state of a light
void print_state(struct light *light) {
  switch (light->state) {
    case OFF:
      printf("%s is off\n", light->name);
      break;
    case ON:
      printf("%s is on\n", light->name);
      break;
    case DIMMED:
      printf("%s is dimmed\n", light->name);
      break;
  }
}

// Main function
int main() {
  // Create a new light
  struct light *light = create_light("Living Room Light");

  // Turn the light on
  turn_on(light);

  // Print the state of the light
  print_state(light);

  // Dim the light
  dim(light);

  // Print the state of the light
  print_state(light);

  // Turn the light off
  turn_off(light);

  // Print the state of the light
  print_state(light);

  // Destroy the light
  destroy_light(light);

  return 0;
}