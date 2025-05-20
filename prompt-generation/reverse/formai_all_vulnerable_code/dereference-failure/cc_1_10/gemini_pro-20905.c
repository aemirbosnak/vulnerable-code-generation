//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the states of a light
typedef enum {
  LIGHT_OFF,
  LIGHT_ON
} light_state_t;

// Define the structure of a light
typedef struct {
  char *name;
  light_state_t state;
} light_t;

// Define the structure of the smart home
typedef struct {
  light_t lights[MAX_LIGHTS];
  int num_lights;
} smart_home_t;

// Create a new smart home
smart_home_t *smart_home_new() {
  smart_home_t *smart_home = malloc(sizeof(smart_home_t));
  smart_home->num_lights = 0;
  return smart_home;
}

// Add a light to the smart home
void smart_home_add_light(smart_home_t *smart_home, char *name) {
  if (smart_home->num_lights < MAX_LIGHTS) {
    smart_home->lights[smart_home->num_lights].name = strdup(name);
    smart_home->lights[smart_home->num_lights].state = LIGHT_OFF;
    smart_home->num_lights++;
  }
}

// Turn on a light
void smart_home_turn_on_light(smart_home_t *smart_home, char *name) {
  for (int i = 0; i < smart_home->num_lights; i++) {
    if (strcmp(smart_home->lights[i].name, name) == 0) {
      smart_home->lights[i].state = LIGHT_ON;
      break;
    }
  }
}

// Turn off a light
void smart_home_turn_off_light(smart_home_t *smart_home, char *name) {
  for (int i = 0; i < smart_home->num_lights; i++) {
    if (strcmp(smart_home->lights[i].name, name) == 0) {
      smart_home->lights[i].state = LIGHT_OFF;
      break;
    }
  }
}

// Get the state of a light
light_state_t smart_home_get_light_state(smart_home_t *smart_home, char *name) {
  for (int i = 0; i < smart_home->num_lights; i++) {
    if (strcmp(smart_home->lights[i].name, name) == 0) {
      return smart_home->lights[i].state;
    }
  }
  return LIGHT_OFF;
}

// Print the status of all lights
void smart_home_print_status(smart_home_t *smart_home) {
  for (int i = 0; i < smart_home->num_lights; i++) {
    printf("%s: %s\n", smart_home->lights[i].name,
           smart_home->lights[i].state == LIGHT_ON ? "ON" : "OFF");
  }
}

// Free the memory allocated for the smart home
void smart_home_free(smart_home_t *smart_home) {
  for (int i = 0; i < smart_home->num_lights; i++) {
    free(smart_home->lights[i].name);
  }
  free(smart_home);
}

int main() {
  // Create a new smart home
  smart_home_t *smart_home = smart_home_new();

  // Add some lights to the smart home
  smart_home_add_light(smart_home, "Kitchen");
  smart_home_add_light(smart_home, "Living Room");
  smart_home_add_light(smart_home, "Bedroom");

  // Turn on the living room light
  smart_home_turn_on_light(smart_home, "Living Room");

  // Get the state of the kitchen light
  light_state_t kitchen_light_state = smart_home_get_light_state(smart_home, "Kitchen");

  // Print the status of all lights
  smart_home_print_status(smart_home);

  // Free the memory allocated for the smart home
  smart_home_free(smart_home);

  return 0;
}