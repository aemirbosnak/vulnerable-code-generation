//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 100

// Define the possible states of a light
typedef enum {
  OFF,
  ON
} light_state;

// Define the structure of a light
typedef struct {
  char name[20];
  light_state state;
} light;

// Define the structure of the smart home
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

// Add a new light to the smart home
void add_light(smart_home *home, char *name) {
  if (home->num_lights >= MAX_LIGHTS) {
    printf("Error: Maximum number of lights reached.\n");
    return;
  }
  strcpy(home->lights[home->num_lights].name, name);
  home->lights[home->num_lights].state = OFF;
  home->num_lights++;
}

// Turn on a light
void turn_on_light(smart_home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    if (strcmp(home->lights[i].name, name) == 0) {
      home->lights[i].state = ON;
      return;
    }
  }
  printf("Error: Light not found.\n");
}

// Turn off a light
void turn_off_light(smart_home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    if (strcmp(home->lights[i].name, name) == 0) {
      home->lights[i].state = OFF;
      return;
    }
  }
  printf("Error: Light not found.\n");
}

// Get the state of a light
light_state get_light_state(smart_home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    if (strcmp(home->lights[i].name, name) == 0) {
      return home->lights[i].state;
    }
  }
  printf("Error: Light not found.\n");
  return -1;
}

// Print the state of all lights
void print_lights(smart_home *home) {
  for (int i = 0; i < home->num_lights; i++) {
    printf("%s: %s\n", home->lights[i].name,
           home->lights[i].state == ON ? "ON" : "OFF");
  }
}

// Main program
int main() {
  // Create a new smart home
  smart_home *home = create_smart_home();

  // Add some lights to the smart home
  add_light(home, "Kitchen");
  add_light(home, "Living Room");
  add_light(home, "Bedroom");

  // Turn on the kitchen light
  turn_on_light(home, "Kitchen");

  // Turn off the living room light
  turn_off_light(home, "Living Room");

  // Get the state of the bedroom light
  light_state state = get_light_state(home, "Bedroom");

  // Print the state of all lights
  print_lights(home);

  return 0;
}