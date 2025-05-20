//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of lights in the home.
#define MAX_LIGHTS 10

// Define the different light states.
enum light_state {
  OFF,
  ON,
  DIM
};

// Define the structure of a light.
struct light {
  char *name;
  enum light_state state;
};

// Define the structure of a home.
struct home {
  struct light lights[MAX_LIGHTS];
  int num_lights;
};

// Create a new home.
struct home *create_home(void) {
  struct home *home = malloc(sizeof(struct home));
  if (home == NULL) {
    return NULL;
  }

  home->num_lights = 0;

  return home;
}

// Add a new light to the home.
void add_light(struct home *home, char *name) {
  if (home->num_lights >= MAX_LIGHTS) {
    return;
  }

  struct light *light = &home->lights[home->num_lights];
  light->name = strdup(name);
  light->state = OFF;

  home->num_lights++;
}

// Turn on a light.
void turn_on_light(struct home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    struct light *light = &home->lights[i];
    if (strcmp(light->name, name) == 0) {
      light->state = ON;
      break;
    }
  }
}

// Turn off a light.
void turn_off_light(struct home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    struct light *light = &home->lights[i];
    if (strcmp(light->name, name) == 0) {
      light->state = OFF;
      break;
    }
  }
}

// Dim a light.
void dim_light(struct home *home, char *name) {
  for (int i = 0; i < home->num_lights; i++) {
    struct light *light = &home->lights[i];
    if (strcmp(light->name, name) == 0) {
      light->state = DIM;
      break;
    }
  }
}

// Print the state of the lights in the home.
void print_lights(struct home *home) {
  for (int i = 0; i < home->num_lights; i++) {
    struct light *light = &home->lights[i];
    printf("%s: ", light->name);
    switch (light->state) {
      case OFF:
        printf("Off\n");
        break;
      case ON:
        printf("On\n");
        break;
      case DIM:
        printf("Dim\n");
        break;
    }
  }
}

// Free the memory allocated for the home.
void free_home(struct home *home) {
  for (int i = 0; i < home->num_lights; i++) {
    free(home->lights[i].name);
  }

  free(home);
}

// Main function.
int main(void) {
  // Create a new home.
  struct home *home = create_home();

  // Add some lights to the home.
  add_light(home, "Living Room");
  add_light(home, "Kitchen");
  add_light(home, "Bedroom");

  // Turn on the living room light.
  turn_on_light(home, "Living Room");

  // Dim the kitchen light.
  dim_light(home, "Kitchen");

  // Turn off the bedroom light.
  turn_off_light(home, "Bedroom");

  // Print the state of the lights in the home.
  print_lights(home);

  // Free the memory allocated for the home.
  free_home(home);

  return 0;
}