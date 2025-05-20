//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Welcome to the Surreal Smart Home Light Control Program.\n");
  printf("Please enter the number of lights in your home: ");
  int num_lights;
  scanf("%d", &num_lights);
  printf("\n");

  int lights[num_lights];
  for (int i = 0; i < num_lights; i++) {
    lights[i] = 0;
  }

  printf("All lights are currently off.\n\n");

  while (1) {
    char command[20];
    printf("Enter a command (on, off, dim, brighten, disco): ");
    scanf("%s", command);
    printf("\n");

    if (strcmp(command, "on") == 0) {
      printf("Which light would you like to turn on? (Enter a number between 1 and %d): ", num_lights);
      int light_num;
      scanf("%d", &light_num);

      if (light_num > 0 && light_num <= num_lights) {
        lights[light_num - 1] = 1;
        printf("Light %d turned on.\n", light_num);
      } else {
        printf("Invalid light number. Please try again.\n");
      }

    } else if (strcmp(command, "off") == 0) {
      printf("Which light would you like to turn off? (Enter a number between 1 and %d): ", num_lights);
      int light_num;
      scanf("%d", &light_num);

      if (light_num > 0 && light_num <= num_lights) {
        lights[light_num - 1] = 0;
        printf("Light %d turned off.\n", light_num);
      } else {
        printf("Invalid light number. Please try again.\n");
      }

    } else if (strcmp(command, "dim") == 0) {
      printf("Which light would you like to dim? (Enter a number between 1 and %d): ", num_lights);
      int light_num;
      scanf("%d", &light_num);

      if (light_num > 0 && light_num <= num_lights) {
        if (lights[light_num - 1] == 1) {
          printf("Light %d dimmed.\n", light_num);
        } else {
          printf("Light %d is currently off. Cannot dim.\n", light_num);
        }
      } else {
        printf("Invalid light number. Please try again.\n");
      }

    } else if (strcmp(command, "brighten") == 0) {
      printf("Which light would you like to brighten? (Enter a number between 1 and %d): ", num_lights);
      int light_num;
      scanf("%d", &light_num);

      if (light_num > 0 && light_num <= num_lights) {
        if (lights[light_num - 1] == 1) {
          printf("Light %d brightened.\n", light_num);
        } else {
          printf("Light %d is currently off. Cannot brighten.\n", light_num);
        }
      } else {
        printf("Invalid light number. Please try again.\n");
      }

    } else if (strcmp(command, "disco") == 0) {
      printf("Entering disco mode...\n\n");
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < num_lights; j++) {
          if (rand() % 2 == 0) {
            lights[j] = 1;
            printf("Light %d turned on.\n", j + 1);
          } else {
            lights[j] = 0;
            printf("Light %d turned off.\n", j + 1);
          }
        }
        printf("\n");
        sleep(1);
      }
      printf("Disco mode ended.\n\n");

    } else {
      printf("Invalid command. Please try again.\n\n");
    }
  }

  return 0;
}