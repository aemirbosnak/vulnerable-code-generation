//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

// Define the maximum number of lights in the house
#define MAX_LIGHTS 10

// Define the possible states of a light
typedef enum {
  LIGHT_OFF,
  LIGHT_ON,
  LIGHT_DIM
} light_state;

// Define the structure of a light
typedef struct {
  char *name;
  light_state state;
  int brightness;
} light;

// Define the structure of a smart home
typedef struct {
  light lights[MAX_LIGHTS];
  int num_lights;
} smart_home;

// Create a new smart home
smart_home *create_smart_home() {
  smart_home *home = malloc(sizeof(smart_home));
  home->num_lights = 0;
  return home;
}

// Destroy a smart home
void destroy_smart_home(smart_home *home) {
  for (int i = 0; i < home->num_lights; i++) {
    free(home->lights[i].name);
  }
  free(home);
}

// Add a light to a smart home
void add_light(smart_home *home, char *name) {
  assert(home->num_lights < MAX_LIGHTS);
  home->lights[home->num_lights].name = strdup(name);
  home->lights[home->num_lights].state = LIGHT_OFF;
  home->lights[home->num_lights].brightness = 0;
  home->num_lights++;
}

// Turn on a light
void turn_on_light(smart_home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    if (strcmp(home->lights[i].name, name) == 0) {
      home->lights[i].state = LIGHT_ON;
      break;
    }
  }
}

// Turn off a light
void turn_off_light(smart_home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    if (strcmp(home->lights[i].name, name) == 0) {
      home->lights[i].state = LIGHT_OFF;
      break;
    }
  }
}

// Dim a light
void dim_light(smart_home *home, char *name, int brightness) {
  for (int i = 0; i < home->num_lights; i++) {
    if (strcmp(home->lights[i].name, name) == 0) {
      home->lights[i].state = LIGHT_DIM;
      home->lights[i].brightness = brightness;
      break;
    }
  }
}

// Print the status of all lights in a smart home
void print_smart_home_status(smart_home *home) {
  for (int i = 0; i < home->num_lights; i++) {
    printf("%s: ", home->lights[i].name);
    switch (home->lights[i].state) {
      case LIGHT_OFF:
        printf("Off\n");
        break;
      case LIGHT_ON:
        printf("On\n");
        break;
      case LIGHT_DIM:
        printf("Dimmed to %d\n", home->lights[i].brightness);
        break;
    }
  }
}

// Main function
int main() {
  // Create a new smart home
  smart_home *home = create_smart_home();

  // Add some lights to the smart home
  add_light(home, "Kitchen Light");
  add_light(home, "Living Room Light");
  add_light(home, "Bedroom Light");

  // Turn on the kitchen light
  turn_on_light(home, "Kitchen Light");

  // Dim the living room light
  dim_light(home, "Living Room Light", 50);

  // Turn off the bedroom light
  turn_off_light(home, "Bedroom Light");

  // Print the status of all lights in the smart home
  print_smart_home_status(home);

  // Destroy the smart home
  destroy_smart_home(home);

  return 0;
}