//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

// Constants representing traffic light colors
#define RED 0
#define YELLOW 1
#define GREEN 2

// Constants representing road directions
#define NORTH_SOUTH 0
#define EAST_WEST 1

// Function prototypes
void setupTrafficLight(int[], int);
void runTrafficLight(int[], int, int, bool);
void displayTrafficLight(int[], int);
void delay(int);

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Setup traffic lights (north-south and east-west)
  int trafficLightNS[3];
  int trafficLightEW[3];
  setupTrafficLight(trafficLightNS, NORTH_SOUTH);
  setupTrafficLight(trafficLightEW, EAST_WEST);

  // Run traffic light simulation
  bool isNSGreen = true;
  for (int i = 0; i < 10; i++) {
    // Display traffic lights
    printf("\n\n====================");
    printf("\n North-South: ");
    displayTrafficLight(trafficLightNS, trafficLightNS[GREEN]);
    printf("\n East-West: ");
    displayTrafficLight(trafficLightEW, trafficLightEW[GREEN]);

    // Run north-south traffic light
    runTrafficLight(trafficLightNS, trafficLightNS[GREEN], YELLOW, isNSGreen);
    
    // Run east-west traffic light
    runTrafficLight(trafficLightEW, trafficLightEW[GREEN], YELLOW, !isNSGreen);

    // Switch direction of green light
    isNSGreen = !isNSGreen;
  }

  return 0;
}

// Sets up traffic light with initial colors and direction
void setupTrafficLight(int trafficLight[], int direction) {
  switch (direction) {
    case NORTH_SOUTH:
      trafficLight[RED] = 5;
      trafficLight[YELLOW] = 2;
      trafficLight[GREEN] = 0;
      break;
    case EAST_WEST:
      trafficLight[RED] = 3;
      trafficLight[YELLOW] = 1;
      trafficLight[GREEN] = 2;
      break;
  }
}

// Runs the traffic light for one cycle (green, yellow, red)
void runTrafficLight(int trafficLight[], int greenColor, int yellowColor, bool isGreen) {
  int redColor = (greenColor + 2) % 3;
  
  if (isGreen) {
    // Green light
    trafficLight[greenColor] = rand() % 6 + 5; // Random time between 5-10 seconds
    trafficLight[yellowColor] = 2;
    trafficLight[redColor] = 0;
  } else {
    // Yellow light
    trafficLight[yellowColor] = 3;
    trafficLight[greenColor] = 0;
    trafficLight[redColor] = rand() % 6 + 5; // Random time between 5-10 seconds
  }

  // Wait for current light to finish
  delay(trafficLight[greenColor] + trafficLight[yellowColor] + trafficLight[redColor]);
}

// Displays the traffic light colors
void displayTrafficLight(int trafficLight[], int greenColor) {
  printf("Red: ");
  if (greenColor == RED) printf("[X]");
  else printf("[ ]");
  
  printf(" Yellow: ");
  if (greenColor == YELLOW) printf("[X]");
  else printf("[ ]");
  
  printf(" Green: ");
  if (greenColor == GREEN) printf("[X]");
  else printf("[ ]");
}

// Delays the program for given number of seconds
void delay(int seconds) {
  sleep(seconds);
}