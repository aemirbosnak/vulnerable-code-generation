//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

  int temperature = 25; // default temperature setting
  int lights = 0; // lights are off by default
  int doorLocked = 1; // door is locked by default
  int windowsClosed = 1; // windows are closed by default

  srand(time(0)); // seed random number generator

  printf("Welcome to Smart Home Automation!\n");
  printf("You can control your home using the following commands:\n");
  printf("- Set temperature (example: 'set temperature to 22')\n");
  printf("- Turn lights on or off (example: 'turn lights on')\n");
  printf("- Lock or unlock the front door (example: 'lock front door')\n");
  printf("- Open or close the windows (example: 'open windows')\n");

  char input[50];
  while (1) {
    printf("\nEnter command: ");
    fgets(input, 50, stdin); // read user input

    // convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
      input[i] = tolower(input[i]);
    }

    // parse input
    char *command = strtok(input, " \n");
    char *object = strtok(NULL, " \n");

    if (strcmp(command, "set") == 0 && strcmp(object, "temperature") == 0) {
      // user wants to set the temperature
      char *valueString = strtok(NULL, " \n");
      int value = atoi(valueString); // convert value to integer
      if (value >= 10 && value <= 30) {
        temperature = value;
        printf("Temperature set to %d°C\n", temperature);
      } else {
        printf("Invalid temperature setting\n");
      }
    } else if (strcmp(command, "turn") == 0 && strcmp(object, "lights") == 0) {
      // user wants to turn lights on or off
      char *stateString = strtok(NULL, " \n");
      if (strcmp(stateString, "on") == 0) {
        lights = 1;
        printf("Lights turned on\n");
      } else if (strcmp(stateString, "off") == 0) {
        lights = 0;
        printf("Lights turned off\n");
      } else {
        printf("Invalid lights command\n");
      }
    } else if (strcmp(command, "lock") == 0 && strcmp(object, "front") == 0 && strtok(NULL, " \n") == NULL) {
      // user wants to lock or unlock the front door
      if (doorLocked) {
        doorLocked = 0;
        printf("Front door unlocked\n");
      } else {
        doorLocked = 1;
        printf("Front door locked\n");
      }
    } else if (strcmp(command, "open") == 0 && strcmp(object, "windows") == 0 && strtok(NULL, " \n") == NULL) {
      // user wants to open or close the windows
      if (windowsClosed) {
        windowsClosed = 0;
        printf("Windows opened\n");
      } else {
        windowsClosed = 1;
        printf("Windows closed\n");
      }
    } else {
      // invalid command
      printf("Invalid command\n");
    }

    // simulate random event
    if (rand() % 10 == 0) {
      printf("\n[ALERT] Something unexpected happened!\n");
      if (lights) {
        printf("Lights turned off\n");
        lights = 0;
      } else {
        printf("Lights turned on\n");
        lights = 1;
      }
      if (doorLocked) {
        printf("Front door unlocked\n");
        doorLocked = 0;
      } else {
        printf("Front door locked\n");
        doorLocked = 1;
      }
      if (windowsClosed) {
        printf("Windows opened\n");
        windowsClosed = 0;
      } else {
        printf("Windows closed\n");
        windowsClosed = 1;
      }
    }

    // simulate temperature change
    if (rand() % 5 == 0) {
      int change = rand() % 3 - 1; // -1, 0, or 1
      temperature += change;
      if (temperature < 10) {
        temperature = 10;
      } else if (temperature > 30) {
        temperature = 30;
      }
      printf("\n[INFO] Temperature changed to %d°C\n", temperature);
    }

    // simulate motion detection
    if (rand() % 10 == 0) {
      printf("\n[ALERT] Motion detected!\n");
      if (lights) {
        printf("Lights turned off\n");
        lights = 0;
      } else {
        printf("Lights turned on\n");
        lights = 1;
      }
    }
  }

  return 0;
}