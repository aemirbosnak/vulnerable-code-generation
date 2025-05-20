//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of lights in the home
#define MAX_LIGHTS 10

// Define the light states
typedef enum {
  LIGHT_OFF,
  LIGHT_ON,
  LIGHT_DIM
} light_state_t;

// Define the light struct
typedef struct {
  char *name;
  light_state_t state;
  int brightness;
} light_t;

// Create an array of lights
light_t lights[MAX_LIGHTS];

// Initialize the lights
void init_lights() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    lights[i].name = NULL;
    lights[i].state = LIGHT_OFF;
    lights[i].brightness = 0;
  }
}

// Create a new light
light_t *create_light(char *name) {
  // Check if there is room for a new light
  for (int i = 0; i < MAX_LIGHTS; i++) {
    if (lights[i].name == NULL) {
      // Allocate memory for the light's name
      lights[i].name = malloc(strlen(name) + 1);
      // Copy the name into the light's name
      strcpy(lights[i].name, name);
      // Set the light's state to off
      lights[i].state = LIGHT_OFF;
      // Set the light's brightness to 0
      lights[i].brightness = 0;
      // Return the light
      return &lights[i];
    }
  }

  // There is no room for a new light
  return NULL;
}

// Delete a light
void delete_light(light_t *light) {
  // Free the memory for the light's name
  free(light->name);
  // Set the light's name to NULL
  light->name = NULL;
  // Set the light's state to off
  light->state = LIGHT_OFF;
  // Set the light's brightness to 0
  light->brightness = 0;
}

// Turn on a light
void turn_on_light(light_t *light) {
  // Set the light's state to on
  light->state = LIGHT_ON;
}

// Turn off a light
void turn_off_light(light_t *light) {
  // Set the light's state to off
  light->state = LIGHT_OFF;
}

// Dim a light
void dim_light(light_t *light, int brightness) {
  // Set the light's state to dim
  light->state = LIGHT_DIM;
  // Set the light's brightness
  light->brightness = brightness;
}

// Print the state of a light
void print_light_state(light_t *light) {
  // Print the light's name
  printf("%s is ", light->name);

  // Print the light's state
  switch (light->state) {
    case LIGHT_OFF:
      printf("off");
      break;
    case LIGHT_ON:
      printf("on");
      break;
    case LIGHT_DIM:
      printf("dimmed to %d%%", light->brightness);
      break;
  }

  // Print a newline
  printf("\n");
}

// Main function
int main() {
  // Initialize the lights
  init_lights();

  // Create a new light
  light_t *light1 = create_light("Living Room Light");

  // Turn on the light
  turn_on_light(light1);

  // Dim the light
  dim_light(light1, 50);

  // Print the state of the light
  print_light_state(light1);

  // Delete the light
  delete_light(light1);

  return 0;
}