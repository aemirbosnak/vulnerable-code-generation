//FormAI DATASET v1.0 Category: Smart home light control ; Style: distributed
/* Smart Home Light Control Program */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

// Define the number of rooms and the number of lights per room
#define NUM_ROOMS 2
#define NUM_LIGHTS 3

/* Define a structure to represent a light */
typedef struct light {
  int state;  // 1 means on, 0 means off
  char id[10]; // Identifier for the light, e.g., "K1L1" for Kitchen 1, Light 1
} Light;

/* Define a structure to represent a room */
typedef struct room {
  char name[20]; // Name of the room, e.g., "Kitchen"
  int num_lights; // Number of lights in the room
  Light **lights; // An array of pointers to Light structs representing the room's lights
} Room;

/* Global variables */
Room *rooms[NUM_ROOMS]; // An array of pointers to Room structs representing the house's rooms
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // A mutex to ensure thread safety

/* Define functions to control the lights */

/* Turn a light on */
void turn_on_light(Light *light) {
  sleep(1); // Simulate a delay for turning on the light
  light->state = 1;
  printf("Light %s turned on\n", light->id);
}

/* Turn a light off */
void turn_off_light(Light *light) {
  sleep(1); // Simulate a delay for turning off the light
  light->state = 0;
  printf("Light %s turned off\n", light->id);
}

/* Toggle a light's state (on->off or off->on) */
void toggle_light(Light *light) {
  if (light->state == 1) {
    turn_off_light(light);
  } else {
    turn_on_light(light);
  }
}

/* Define a function to control a room's lights */
void *room_controller(void *arg) {
  Room *room = (Room *)arg;
  while (1) {
    // Wait for a command to be entered
    char command[20];
    printf("Enter command for %s room (on/off/toggle): ", room->name);
    scanf("%s", command);
    // Process the command for all the room's lights
    pthread_mutex_lock(&mutex); // Acquire the mutex before accessing the shared data
    for (int i = 0; i < room->num_lights; i++) {
      if (strcmp(command, "on") == 0) {
        turn_on_light(room->lights[i]);
      } else if (strcmp(command, "off") == 0) {
        turn_off_light(room->lights[i]);
      } else if (strcmp(command, "toggle") == 0) {
        toggle_light(room->lights[i]);
      } else {
        printf("Invalid command: %s\n", command);
      }
    }
    pthread_mutex_unlock(&mutex); // Release the mutex after accessing the shared data
  }
}

/* Define a function to create a new room */
Room *create_room(char *name, int num_lights, char **light_ids) {
  // Allocate memory for the room struct
  Room *room = (Room *)malloc(sizeof(Room));
  // Set the name and number of lights
  strcpy(room->name, name);
  room->num_lights = num_lights;
  // Allocate memory for the array of pointers to Light structs
  room->lights = (Light **)malloc(num_lights * sizeof(Light *));
  // Create a new Light struct for each light and add it to the room's array
  for (int i = 0; i < num_lights; i++) {
    Light *light = (Light *)malloc(sizeof(Light));
    strcpy(light->id, light_ids[i]);
    light->state = 0;
    room->lights[i] = light;
  }
  return room;
}

/* Main Function */
int main() {

  // Create the rooms and their lights
  char *kitchen_lights[] = {"K1L1", "K1L2", "K1L3"};
  rooms[0] = create_room("Kitchen", NUM_LIGHTS, kitchen_lights);
  char *bedroom_lights[] = {"B1L1", "B1L2", "B1L3"};
  rooms[1] = create_room("Bedroom", NUM_LIGHTS, bedroom_lights);

  // Create a thread for each room to control its lights
  pthread_t threads[NUM_ROOMS];
  for (int i = 0; i < NUM_ROOMS; i++) {
    pthread_create(&threads[i], NULL, room_controller, (void *)rooms[i]);
  }

  // Wait for the threads to exit (which will never happen)
  for (int i = 0; i < NUM_ROOMS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Free the memory allocated for the rooms and their lights
  for (int i = 0; i < NUM_ROOMS; i++) {
    for (int j = 0; j < rooms[i]->num_lights; j++) {
      free(rooms[i]->lights[j]);
    }
    free(rooms[i]->lights);
    free(rooms[i]);
  }
  
  return 0;
}