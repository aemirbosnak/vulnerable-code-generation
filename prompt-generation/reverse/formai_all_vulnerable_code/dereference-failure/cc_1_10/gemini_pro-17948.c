//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// Define the light structure
typedef struct light {
  char *name;
  bool state;
} light_t;

// Create an array of lights
light_t lights[MAX_LIGHTS];

// Initialize the lights
void init_lights() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    lights[i].name = malloc(10);
    sprintf(lights[i].name, "light%d", i);
    lights[i].state = false;
  }
}

// Print the lights
void print_lights() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("%s: %s\n", lights[i].name, lights[i].state ? "on" : "off");
  }
}

// Turn a light on
void turn_on(char *name) {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    if (strcmp(lights[i].name, name) == 0) {
      lights[i].state = true;
      break;
    }
  }
}

// Turn a light off
void turn_off(char *name) {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    if (strcmp(lights[i].name, name) == 0) {
      lights[i].state = false;
      break;
    }
  }
}

// Toggle a light
void toggle(char *name) {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    if (strcmp(lights[i].name, name) == 0) {
      lights[i].state = !lights[i].state;
      break;
    }
  }
}

// Main function
int main() {
  // Initialize the lights
  init_lights();

  // Print the lights
  print_lights();

  // Turn on light1
  turn_on("light1");

  // Turn off light2
  turn_off("light2");

  // Toggle light3
  toggle("light3");

  // Print the lights
  print_lights();

  return 0;
}