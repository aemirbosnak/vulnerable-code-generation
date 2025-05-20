//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the light states
#define OFF 0
#define ON 1

// Define the light commands
#define TURN_ON 1
#define TURN_OFF 0

// Define the light structure
typedef struct {
  int state;
  char *name;
} light;

// Create a new light
light *create_light(char *name) {
  light *new_light = malloc(sizeof(light));
  new_light->state = OFF;
  new_light->name = name;
  return new_light;
}

// Turn a light on
void turn_on(light *light) {
  light->state = ON;
  printf("%s is now on.\n", light->name);
}

// Turn a light off
void turn_off(light *light) {
  light->state = OFF;
  printf("%s is now off.\n", light->name);
}

// Toggle a light
void toggle(light *light) {
  light->state = !light->state;
  if (light->state == ON) {
    printf("%s is now on.\n", light->name);
  } else {
    printf("%s is now off.\n", light->name);
  }
}

// Get the state of a light
int get_state(light *light) {
  return light->state;
}

// Print the state of a light
void print_state(light *light) {
  if (light->state == ON) {
    printf("%s is on.\n", light->name);
  } else {
    printf("%s is off.\n", light->name);
  }
}

// Main function
int main() {
  // Create a new light
  light *light1 = create_light("Light 1");

  // Turn the light on
  turn_on(light1);

  // Toggle the light
  toggle(light1);

  // Print the state of the light
  print_state(light1);

  // Turn the light off
  turn_off(light1);

  // Free the light
  free(light1);

  return 0;
}