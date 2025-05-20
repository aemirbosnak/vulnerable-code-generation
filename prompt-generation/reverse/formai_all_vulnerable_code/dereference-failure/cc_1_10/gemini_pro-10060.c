//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the light states
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define the light commands
#define LIGHT_COMMAND_TURN_ON "ON"
#define LIGHT_COMMAND_TURN_OFF "OFF"

// Define the maximum length of a light command
#define MAX_LIGHT_COMMAND_LENGTH 10

// Define the number of lights
#define NUM_LIGHTS 5

// Define the light status array
int lightStatus[NUM_LIGHTS];

// Function to turn on a light
void turnOnLight(int lightNumber) {
  if (lightNumber >= 0 && lightNumber < NUM_LIGHTS) {
    lightStatus[lightNumber] = LIGHT_ON;
    printf("Light %d turned on.\n", lightNumber + 1);
  } else {
    printf("Invalid light number.\n");
  }
}

// Function to turn off a light
void turnOffLight(int lightNumber) {
  if (lightNumber >= 0 && lightNumber < NUM_LIGHTS) {
    lightStatus[lightNumber] = LIGHT_OFF;
    printf("Light %d turned off.\n", lightNumber + 1);
  } else {
    printf("Invalid light number.\n");
  }
}

// Function to handle a light command
void handleLightCommand(char *command) {
  char lightNumberString[MAX_LIGHT_COMMAND_LENGTH];
  int lightNumber;

  // Get the light number from the command
  sscanf(command, "%s %s", lightNumberString, command);
  lightNumber = atoi(lightNumberString);

  // Check if the command is valid
  if (strcmp(command, LIGHT_COMMAND_TURN_ON) == 0) {
    turnOnLight(lightNumber - 1);
  } else if (strcmp(command, LIGHT_COMMAND_TURN_OFF) == 0) {
    turnOffLight(lightNumber - 1);
  } else {
    printf("Invalid light command.\n");
  }
}

// Main function
int main() {
  char command[MAX_LIGHT_COMMAND_LENGTH];

  // Initialize the light status array
  for (int i = 0; i < NUM_LIGHTS; i++) {
    lightStatus[i] = LIGHT_OFF;
  }

  // Get the light commands from the user
  while (1) {
    printf("Enter a light command (e.g., 1 ON, 2 OFF): ");
    scanf("%s", command);

    // Handle the light command
    handleLightCommand(command);
  }

  return 0;
}