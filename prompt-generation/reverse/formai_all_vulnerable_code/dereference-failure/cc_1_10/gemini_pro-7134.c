//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Define the smart home light control commands
#define CMD_ON "on"
#define CMD_OFF "off"
#define CMD_TOGGLE "toggle"
#define CMD_STATUS "status"

// Define the smart home light control states
#define STATE_ON "on"
#define STATE_OFF "off"

// Define the smart home light control error codes
#define ERR_INVALID_CMD "Invalid command"
#define ERR_INVALID_STATE "Invalid state"

// Define the smart home light control data structure
typedef struct {
  char *name;
  char *state;
  pthread_mutex_t lock;
} light_t;

// Create a new smart home light control object
light_t *light_new(char *name) {
  light_t *light = malloc(sizeof(light_t));
  light->name = strdup(name);
  light->state = strdup(STATE_OFF);
  pthread_mutex_init(&light->lock, NULL);
  return light;
}

// Destroy a smart home light control object
void light_destroy(light_t *light) {
  pthread_mutex_destroy(&light->lock);
  free(light->name);
  free(light->state);
  free(light);
}

// Turn on a smart home light control object
int light_on(light_t *light) {
  pthread_mutex_lock(&light->lock);
  if (strcmp(light->state, STATE_OFF) == 0) {
    light->state = strdup(STATE_ON);
    pthread_mutex_unlock(&light->lock);
    return 0;
  }
  pthread_mutex_unlock(&light->lock);
  return -1;
}

// Turn off a smart home light control object
int light_off(light_t *light) {
  pthread_mutex_lock(&light->lock);
  if (strcmp(light->state, STATE_ON) == 0) {
    light->state = strdup(STATE_OFF);
    pthread_mutex_unlock(&light->lock);
    return 0;
  }
  pthread_mutex_unlock(&light->lock);
  return -1;
}

// Toggle a smart home light control object
int light_toggle(light_t *light) {
  pthread_mutex_lock(&light->lock);
  if (strcmp(light->state, STATE_OFF) == 0) {
    light->state = strdup(STATE_ON);
  } else if (strcmp(light->state, STATE_ON) == 0) {
    light->state = strdup(STATE_OFF);
  } else {
    pthread_mutex_unlock(&light->lock);
    return -1;
  }
  pthread_mutex_unlock(&light->lock);
  return 0;
}

// Get the state of a smart home light control object
char *light_get_state(light_t *light) {
  pthread_mutex_lock(&light->lock);
  char *state = strdup(light->state);
  pthread_mutex_unlock(&light->lock);
  return state;
}

// Parse a smart home light control command
int light_parse_cmd(char *cmd, char **name, char **state) {
  char *ptr;

  // Parse the command name
  *name = strtok(cmd, " ");
  if (*name == NULL) {
    return -1;
  }

  // Parse the command state
  *state = strtok(NULL, " ");
  if (*state == NULL) {
    return -1;
  }

  return 0;
}

// Execute a smart home light control command
int light_execute_cmd(light_t *light, char *cmd) {
  char *name, *state;

  // Parse the command
  if (light_parse_cmd(cmd, &name, &state) != 0) {
    return -1;
  }

  // Execute the command
  if (strcmp(name, CMD_ON) == 0) {
    return light_on(light);
  } else if (strcmp(name, CMD_OFF) == 0) {
    return light_off(light);
  } else if (strcmp(name, CMD_TOGGLE) == 0) {
    return light_toggle(light);
  } else if (strcmp(name, CMD_STATUS) == 0) {
    printf("%s: %s\n", light->name, light_get_state(light));
    return 0;
  } else {
    return -1;
  }
}

// Main function
int main(int argc, char *argv[]) {
  light_t *light = light_new("Bedroom Light");

  // Parse the command line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <command>\n", argv[0]);
    return -1;
  }

  // Execute the command
  if (light_execute_cmd(light, argv[1]) != 0) {
    fprintf(stderr, "Error: %s\n", ERR_INVALID_CMD);
    return -1;
  }

  // Destroy the light object
  light_destroy(light);

  return 0;
}