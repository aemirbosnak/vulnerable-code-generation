//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

// Structure to represent a single light
typedef struct {
  int id;
  char *name;
  int brightness;
  int on;
} light;

// Array of lights
light lights[MAX_LIGHTS];

// Function to create a new light
light *create_light(int id, char *name) {
  light *new_light = malloc(sizeof(light));
  new_light->id = id;
  new_light->name = strdup(name);
  new_light->brightness = 0;
  new_light->on = 0;
  return new_light;
}

// Function to turn a light on or off
void set_light_on(light *light, int on) {
  light->on = on;
}

// Function to set the brightness of a light
void set_light_brightness(light *light, int brightness) {
  light->brightness = brightness;
}

// Function to print the status of a light
void print_light_status(light *light) {
  printf("Light %d (%s): ", light->id, light->name);
  if (light->on) {
    printf("ON, Brightness: %d\n", light->brightness);
  } else {
    printf("OFF\n");
  }
}

// Function to print the status of all lights
void print_all_lights_status() {
  for (int i = 0; i < MAX_LIGHTS; i++) {
    if (lights[i].name != NULL) {
      print_light_status(&lights[i]);
    }
  }
}

// Main function
int main() {
  // Create some lights
  light *light1 = create_light(1, "Living Room");
  light *light2 = create_light(2, "Kitchen");
  light *light3 = create_light(3, "Bedroom");

  // Add the lights to the array
  lights[0] = *light1;
  lights[1] = *light2;
  lights[2] = *light3;

  // Turn on the living room light
  set_light_on(light1, 1);

  // Set the kitchen light to 50% brightness
  set_light_brightness(light2, 50);

  // Print the status of all lights
  print_all_lights_status();

  return 0;
}