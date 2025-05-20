//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Constants representing the different traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Function to initialize the traffic light states
void initTrafficLight(int* trafficLightState, int numJunctions) {
  for (int i = 0; i < numJunctions; i++) {
    trafficLightState[i] = RED;
  }
}

// Function to change the traffic light state at a given junction
void changeTrafficLightState(int* trafficLightState, int junctionIndex) {
  trafficLightState[junctionIndex] = (trafficLightState[junctionIndex] + 1) % 3;
}

// Function to simulate the traffic light controller
void simulateTrafficLightController(int* trafficLightState, int numJunctions, int numCycles) {
  for (int i = 0; i < numCycles; i++) {
    // Change the traffic light state at each junction
    for (int j = 0; j < numJunctions; j++) {
      changeTrafficLightState(trafficLightState, j);
    }
    
    // Print the current traffic light states
    printf("Current traffic light states:\n");
    for (int k = 0; k < numJunctions; k++) {
      switch (trafficLightState[k]) {
        case RED:
          printf("Junction %d: RED\n", k);
          break;
        case YELLOW:
          printf("Junction %d: YELLOW\n", k);
          break;
        case GREEN:
          printf("Junction %d: GREEN\n", k);
          break;
      }
    }
    
    // Sleep for 1 second to simulate the passage of time
    sleep(1);
  }
}

// Main function
int main() {
  // Initialize the traffic light states
  int numJunctions = 4;
  int* trafficLightState = malloc(sizeof(int) * numJunctions);
  initTrafficLight(trafficLightState, numJunctions);
  
  // Simulate the traffic light controller
  int numCycles = 10;
  simulateTrafficLightController(trafficLightState, numJunctions, numCycles);
  
  // Free the allocated memory
  free(trafficLightState);
  
  return 0;
}