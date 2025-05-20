//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef enum {
  LIGHT_OFF,
  LIGHT_ON
} light_state;

typedef struct {
  char* name;
  light_state state;
  unsigned int brightness;
  bool is_dimmable;
  bool is_smart;
} light;

// Function prototypes
light* create_light(const char* name);
void destroy_light(light* light);
void turn_on_light(light* light);
void turn_off_light(light* light);
void set_light_brightness(light* light, unsigned int brightness);
void toggle_light(light* light);
void print_light_state(light* light);

// Main function
int main() {
  // Create some lights
  light* living_room_light = create_light("Living Room Light");
  light* kitchen_light = create_light("Kitchen Light");
  light* bedroom_light = create_light("Bedroom Light");

  // Turn on the living room light
  turn_on_light(living_room_light);

  // Set the kitchen light to 50% brightness
  set_light_brightness(kitchen_light, 50);

  // Toggle the bedroom light
  toggle_light(bedroom_light);

  // Print the state of each light
  print_light_state(living_room_light);
  print_light_state(kitchen_light);
  print_light_state(bedroom_light);

  // Destroy the lights
  destroy_light(living_room_light);
  destroy_light(kitchen_light);
  destroy_light(bedroom_light);

  return 0;
}

// Function definitions

light* create_light(const char* name) {
  light* light = malloc(sizeof(light));
  if (light == NULL) {
    return NULL;
  }

  light->name = strdup(name);
  light->state = LIGHT_OFF;
  light->brightness = 100;
  light->is_dimmable = true;
  light->is_smart = true;

  return light;
}

void destroy_light(light* light) {
  free(light->name);
  free(light);
}

void turn_on_light(light* light) {
  light->state = LIGHT_ON;
}

void turn_off_light(light* light) {
  light->state = LIGHT_OFF;
}

void set_light_brightness(light* light, unsigned int brightness) {
  if (brightness > 100) {
    brightness = 100;
  }

  light->brightness = brightness;
}

void toggle_light(light* light) {
  if (light->state == LIGHT_ON) {
    turn_off_light(light);
  } else {
    turn_on_light(light);
  }
}

void print_light_state(light* light) {
  printf("Light Name: %s\n", light->name);
  printf("Light State: %s\n", light->state == LIGHT_ON ? "ON" : "OFF");
  printf("Light Brightness: %u\n", light->brightness);
  printf("Light Dimmable: %s\n", light->is_dimmable ? "Yes" : "No");
  printf("Light Smart: %s\n", light->is_smart ? "Yes" : "No");
  printf("\n");
}