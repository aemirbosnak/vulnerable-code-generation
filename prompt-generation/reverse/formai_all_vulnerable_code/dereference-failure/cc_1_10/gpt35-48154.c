//FormAI DATASET v1.0 Category: Smart home light control ; Style: configurable
// C program for smart home light control

#include <stdio.h>
#include <stdlib.h>

// Defining user-defined datatypes for configuring the light control system
typedef enum { OFF, ON } SwitchStatus;
typedef enum { DISABLED, ENABLED } ConfigStatus;

// Defining structures to hold information for a single light bulb and the whole house
typedef struct {
  SwitchStatus status;
  ConfigStatus config;
} LightBulb;

typedef struct {
  LightBulb* bulbs;
  int num_bulbs;
  ConfigStatus config;
} House;

// Function to turn on a light bulb
void turnOn(LightBulb* bulb) {
  bulb->status = ON;
}

// Function to turn off a light bulb
void turnOff(LightBulb* bulb) {
  bulb->status = OFF;
}

// Function to enable configuration of a light bulb or the whole house
void enableConfig(void* entity) {
  if (entity) {
    ((LightBulb*)entity)->config = ENABLED;
  } else {
    ((House*)entity)->config = ENABLED;
  }
}

// Function to disable configuration of a light bulb or the whole house
void disableConfig(void* entity) {
  if (entity) {
    ((LightBulb*)entity)->config = DISABLED;
  } else {
    ((House*)entity)->config = DISABLED;
  }
}

int main() {
  // Initializing a house with 3 light bulbs
  House myHouse = { (LightBulb*)malloc(3*sizeof(LightBulb)), 3, DISABLED };
  for (int i = 0; i < myHouse.num_bulbs; i++) {
    myHouse.bulbs[i].status = OFF;
    myHouse.bulbs[i].config = DISABLED;
  }

  // Turning on the living room light
  turnOn(&myHouse.bulbs[0]);

  // Enabling configuration of the dining room light
  enableConfig(&myHouse.bulbs[1]);

  // Turning off the bedroom light
  turnOff(&myHouse.bulbs[2]);

  // Outputting the status of all lights in the house
  printf("House Light Status:\n");
  for (int i = 0; i < myHouse.num_bulbs; i++) {
    printf("Light %d: %s\n", i+1, (myHouse.bulbs[i].status == ON) ? "On" : "Off");
  }

  // Freeing memory allocated to house bulbs
  free(myHouse.bulbs);
  myHouse.bulbs = NULL;

  return 0;
}