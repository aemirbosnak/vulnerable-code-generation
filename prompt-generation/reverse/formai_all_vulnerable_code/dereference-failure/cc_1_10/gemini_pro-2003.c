//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

// Define the maximum number of lights.
#define MAX_LIGHTS 10

// Define the states of a light.
typedef enum
{
  LIGHT_OFF,
  LIGHT_ON,
  LIGHT_UNKNOWN
} light_state;

// Define the structure of a light.
typedef struct
{
  char name[32];
  light_state state;
} light;

// Define the structure of the smart home.
typedef struct smart_home
{
  light lights[MAX_LIGHTS];
  int num_lights;
} smart_home;

// Create a new smart home.
smart_home *smart_home_new()
{
  smart_home *home = malloc(sizeof(smart_home));
  if (home == NULL)
  {
    return NULL;
  }

  home->num_lights = 0;

  return home;
}

// Add a light to the smart home.
void smart_home_add_light(smart_home *home, char *name)
{
  if (home->num_lights >= MAX_LIGHTS)
  {
    return;
  }

  strcpy(home->lights[home->num_lights].name, name);
  home->lights[home->num_lights].state = LIGHT_OFF;
  home->num_lights++;
}

// Get the state of a light.
light_state smart_home_get_light_state(smart_home *home, char *name)
{
  for (int i = 0; i < home->num_lights; i++)
  {
    if (strcmp(home->lights[i].name, name) == 0)
    {
      return home->lights[i].state;
    }
  }

  return LIGHT_UNKNOWN;
}

// Set the state of a light.
void smart_home_set_light_state(smart_home *home, char *name, light_state state)
{
  for (int i = 0; i < home->num_lights; i++)
  {
    if (strcmp(home->lights[i].name, name) == 0)
    {
      home->lights[i].state = state;
    }
  }
}

// Toggle the state of a light.
void smart_home_toggle_light(smart_home *home, char *name)
{
  light_state state = smart_home_get_light_state(home, name);
  if (state == LIGHT_OFF)
  {
    smart_home_set_light_state(home, name, LIGHT_ON);
  }
  else if (state == LIGHT_ON)
  {
    smart_home_set_light_state(home, name, LIGHT_OFF);
  }
}

// Print the state of all lights in the smart home.
void smart_home_print_lights(smart_home *home)
{
  for (int i = 0; i < home->num_lights; i++)
  {
    printf("%s: ", home->lights[i].name);

    if (home->lights[i].state == LIGHT_OFF)
    {
      printf("off\n");
    }
    else if (home->lights[i].state == LIGHT_ON)
    {
      printf("on\n");
    }
    else
    {
      printf("unknown\n");
    }
  }
}

// Release the memory allocated for the smart home.
void smart_home_free(smart_home *home)
{
  free(home);
}


int main()
{
  smart_home *home = smart_home_new();

  smart_home_add_light(home, "living room");
  smart_home_add_light(home, "kitchen");
  smart_home_add_light(home, "bedroom");

  smart_home_set_light_state(home, "living room", LIGHT_ON);
  smart_home_set_light_state(home, "kitchen", LIGHT_OFF);
  smart_home_set_light_state(home, "bedroom", LIGHT_ON);

  smart_home_print_lights(home);

  smart_home_toggle_light(home, "living room");
  smart_home_toggle_light(home, "kitchen");
  smart_home_toggle_light(home, "bedroom");

  smart_home_print_lights(home);

  smart_home_free(home);

  return 0;
}