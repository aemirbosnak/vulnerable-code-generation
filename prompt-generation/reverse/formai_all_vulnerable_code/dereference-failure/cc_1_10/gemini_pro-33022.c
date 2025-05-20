//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Ada Lovelace
// Ada Lovelace's Smart Home Light Control Program

// Includes the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the number of rooms and lights in the house
#define NUM_ROOMS 3
#define NUM_LIGHTS 4

// Creates a structure to represent a room
typedef struct {
  char name[20];
  int num_lights;
  int lights[NUM_LIGHTS];
} room;

// Creates an array of rooms
room rooms[NUM_ROOMS] = {
  {"Living Room", 4, {0, 0, 0, 0}},
  {"Kitchen", 3, {0, 0, 0}},
  {"Bedroom", 2, {0, 0}}
};

// Creates a function to turn on a light
void turn_on_light(room *room, int light_num) {
  if (light_num < 0 || light_num >= room->num_lights) {
    printf("Invalid light number\n");
    return;
  }

  room->lights[light_num] = 1;
}

// Creates a function to turn off a light
void turn_off_light(room *room, int light_num) {
  if (light_num < 0 || light_num >= room->num_lights) {
    printf("Invalid light number\n");
    return;
  }

  room->lights[light_num] = 0;
}

// Creates a function to turn on all lights in a room
void turn_on_all_lights(room *room) {
  for (int i = 0; i < room->num_lights; i++) {
    room->lights[i] = 1;
  }
}

// Creates a function to turn off all lights in a room
void turn_off_all_lights(room *room) {
  for (int i = 0; i < room->num_lights; i++) {
    room->lights[i] = 0;
  }
}

// Creates a function to print the status of all lights in a room
void print_room_status(room *room) {
  printf("Room: %s\n", room->name);
  for (int i = 0; i < room->num_lights; i++) {
    printf("Light %d: %s\n", i + 1, room->lights[i] ? "On" : "Off");
  }
}

// Creates a function to print the status of all lights in the house
void print_house_status() {
  for (int i = 0; i < NUM_ROOMS; i++) {
    print_room_status(&rooms[i]);
  }
}

// Creates a function to handle user input
void handle_user_input() {
  char input[256];
  while (1) {
    printf("> ");
    fgets(input, 256, stdin);

    // Parses the user input
    char *command = strtok(input, " ");
    char *room_name = strtok(NULL, " ");
    char *light_num = strtok(NULL, " ");

    // Performs the appropriate action based on the user input
    if (strcmp(command, "on") == 0) {
      if (room_name == NULL || light_num == NULL) {
        printf("Invalid command\n");
        continue;
      }

      int room_index = -1;
      for (int i = 0; i < NUM_ROOMS; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
          room_index = i;
          break;
        }
      }

      if (room_index == -1) {
        printf("Invalid room name\n");
        continue;
      }

      int light_number = atoi(light_num);
      turn_on_light(&rooms[room_index], light_number - 1);
    } else if (strcmp(command, "off") == 0) {
      if (room_name == NULL || light_num == NULL) {
        printf("Invalid command\n");
        continue;
      }

      int room_index = -1;
      for (int i = 0; i < NUM_ROOMS; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
          room_index = i;
          break;
        }
      }

      if (room_index == -1) {
        printf("Invalid room name\n");
        continue;
      }

      int light_number = atoi(light_num);
      turn_off_light(&rooms[room_index], light_number - 1);
    } else if (strcmp(command, "on_all") == 0) {
      if (room_name == NULL) {
        printf("Invalid command\n");
        continue;
      }

      int room_index = -1;
      for (int i = 0; i < NUM_ROOMS; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
          room_index = i;
          break;
        }
      }

      if (room_index == -1) {
        printf("Invalid room name\n");
        continue;
      }

      turn_on_all_lights(&rooms[room_index]);
    } else if (strcmp(command, "off_all") == 0) {
      if (room_name == NULL) {
        printf("Invalid command\n");
        continue;
      }

      int room_index = -1;
      for (int i = 0; i < NUM_ROOMS; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
          room_index = i;
          break;
        }
      }

      if (room_index == -1) {
        printf("Invalid room name\n");
        continue;
      }

      turn_off_all_lights(&rooms[room_index]);
    } else if (strcmp(command, "status") == 0) {
      if (room_name == NULL) {
        print_house_status();
      } else {
        int room_index = -1;
        for (int i = 0; i < NUM_ROOMS; i++) {
          if (strcmp(rooms[i].name, room_name) == 0) {
            room_index = i;
            break;
          }
        }

        if (room_index == -1) {
          printf("Invalid room name\n");
          continue;
        }

        print_room_status(&rooms[room_index]);
      }
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Invalid command\n");
    }
  }
}

// Entry point of the program
int main() {
  printf("Welcome to Ada Lovelace's Smart Home Light Control Program!\n");
  handle_user_input();
  return 0;
}