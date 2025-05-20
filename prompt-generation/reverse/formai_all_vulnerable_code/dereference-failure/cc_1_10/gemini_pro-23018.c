//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

// Function to initialize the traffic light
void initTrafficLight(int *light) {
  *light = RED;
}

// Function to change the traffic light
void changeTrafficLight(int *light) {
  *light++;
  if (*light > GREEN) {
    *light = RED;
  }
}

// Function to simulate the traffic light
void simulateTrafficLight(int *light) {
  while (1) {
    // Display the current state of the traffic light
    printf("The traffic light is currently %s.\n", *light == RED ? "RED"
                                                  : *light ==
                                                            YELLOW
                                                        ? "YELLOW"
                                                        : "GREEN");

    // Wait for a random amount of time
    sleep(rand() % 10);

    // Change the traffic light
    changeTrafficLight(light);
  }
}

int main() {
    // Define a variable to represent the state of the traffic light
    int light;

    // Initialize the traffic light
    initTrafficLight(&light);

    // Simulate the traffic light
    simulateTrafficLight(&light);

    return 0;
}