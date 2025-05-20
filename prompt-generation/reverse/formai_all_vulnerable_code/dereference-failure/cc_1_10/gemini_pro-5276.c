//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the light states
enum light_state {
  OFF,
  ON,
  DIMMED
};

// Define the light struct
typedef struct {
  char *name;
  enum light_state state;
  int brightness;
} light_t;

// Create an array of lights
light_t lights[MAX_LIGHTS];

// Initialize the lights
void init_lights() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    lights[i].name = NULL;
    lights[i].state = OFF;
    lights[i].brightness = 0;
  }
}

// Add a light to the array
int add_light(char *name) {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    if (lights[i].name == NULL) {
      lights[i].name = strdup(name);
      return i;
    }
  }
  return -1;
}

// Remove a light from the array
void remove_light(int index) {
  if (index >= 0 && index < MAX_LIGHTS) {
    free(lights[index].name);
    lights[index].name = NULL;
    lights[index].state = OFF;
    lights[index].brightness = 0;
  }
}

// Turn a light on
void turn_on(int index) {
  if (index >= 0 && index < MAX_LIGHTS) {
    lights[index].state = ON;
  }
}

// Turn a light off
void turn_off(int index) {
  if (index >= 0 && index < MAX_LIGHTS) {
    lights[index].state = OFF;
  }
}

// Dim a light
void dim(int index, int brightness) {
  if (index >= 0 && index < MAX_LIGHTS) {
    lights[index].state = DIMMED;
    lights[index].brightness = brightness;
  }
}

// Print the state of all lights
void print_lights() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    if (lights[i].name != NULL) {
      printf("%s: ", lights[i].name);
      switch (lights[i].state) {
        case OFF:
          printf("OFF\n");
          break;
        case ON:
          printf("ON\n");
          break;
        case DIMMED:
          printf("DIMMED at %d%%\n", lights[i].brightness);
          break;
      }
    }
  }
}

// Main function
int main() {
  // Initialize the lights
  init_lights();

  // Add some lights
  add_light("Living Room Light");
  add_light("Kitchen Light");
  add_light("Bedroom Light");

  // Turn on the living room light
  turn_on(0);

  // Dim the kitchen light
  dim(1, 50);

  // Turn off the bedroom light
  turn_off(2);

  // Print the state of all lights
  print_lights();

  return 0;
}