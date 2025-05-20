//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the light states
#define LIGHT_OFF 0
#define LIGHT_ON 1
#define LIGHT_DIM 2

// Define the light colors
#define LIGHT_COLOR_RED 0
#define LIGHT_COLOR_GREEN 1
#define LIGHT_COLOR_BLUE 2
#define LIGHT_COLOR_WHITE 3

// Define the light commands
#define LIGHT_COMMAND_TURN_ON 0
#define LIGHT_COMMAND_TURN_OFF 1
#define LIGHT_COMMAND_DIM 2
#define LIGHT_COMMAND_SET_COLOR 3

// Define the light struct
typedef struct {
  int state;
  int color;
  int brightness;
} light;

// Create a new light
light* create_light() {
  light* new_light = malloc(sizeof(light));
  new_light->state = LIGHT_OFF;
  new_light->color = LIGHT_COLOR_WHITE;
  new_light->brightness = 100;
  return new_light;
}

// Destroy a light
void destroy_light(light* light) {
  free(light);
}

// Turn on the light
void turn_on_light(light* light) {
  light->state = LIGHT_ON;
}

// Turn off the light
void turn_off_light(light* light) {
  light->state = LIGHT_OFF;
}

// Dim the light
void dim_light(light* light, int brightness) {
  light->brightness = brightness;
}

// Set the light color
void set_light_color(light* light, int color) {
  light->color = color;
}

// Print the light state
void print_light_state(light* light) {
  switch (light->state) {
    case LIGHT_OFF:
      printf("The light is off.\n");
      break;
    case LIGHT_ON:
      printf("The light is on.\n");
      break;
    case LIGHT_DIM:
      printf("The light is dimmed.\n");
      break;
  }
}

// Print the light color
void print_light_color(light* light) {
  switch (light->color) {
    case LIGHT_COLOR_RED:
      printf("The light is red.\n");
      break;
    case LIGHT_COLOR_GREEN:
      printf("The light is green.\n");
      break;
    case LIGHT_COLOR_BLUE:
      printf("The light is blue.\n");
      break;
    case LIGHT_COLOR_WHITE:
      printf("The light is white.\n");
      break;
  }
}

// Print the light brightness
void print_light_brightness(light* light) {
  printf("The light is %d%% bright.\n", light->brightness);
}

// Main function
int main() {
  // Create a new light
  light* light = create_light();

  // Turn on the light
  turn_on_light(light);

  // Set the light color to red
  set_light_color(light, LIGHT_COLOR_RED);

  // Dim the light to 50%
  dim_light(light, 50);

  // Print the light state, color, and brightness
  print_light_state(light);
  print_light_color(light);
  print_light_brightness(light);

  // Destroy the light
  destroy_light(light);

  return 0;
}