//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum speed of the vehicle
#define MAX_SPEED 100

// Define the maximum fuel capacity of the vehicle
#define MAX_FUEL_CAPACITY 50

// Define the maximum distance the vehicle can travel on full fuel
#define MAX_DISTANCE 500

// Define the cost of fuel in dollars per unit
#define FUEL_COST 2.5

int main() {
  int fuel = MAX_FUEL_CAPACITY;  // Initialize fuel to maximum capacity
  int distance = 0;              // Initialize distance travelled to zero
  int speed = 0;                 // Initialize the speed of the vehicle to zero
  int choice;                    // User choice input variable

  srand(time(0));                // Seed the random number generator
  
  printf("Welcome to the Remote Control Vehicle Simulator\n\n");

  while (fuel > 0 && distance < MAX_DISTANCE) {
    printf("Current Fuel: %d | Distance Travelled: %d | Speed: %d\n", fuel, distance, speed);

    // Get user choice of speed
    printf("Enter the speed (0 - %d): ", MAX_SPEED);
    scanf("%d", &speed);

    // Validate user input for speed
    if (speed < 0) {
      printf("Invalid speed entered. Speed set to zero.\n");
      speed = 0;
    } else if (speed > MAX_SPEED) {
      printf("Maximum speed exceeded. Speed set to %d.\n", MAX_SPEED);
      speed = MAX_SPEED;
    }

    // Calculate distance travelled
    distance += speed;

    // Calculate fuel used based on speed
    fuel -= rand() % speed + 1;

    // Validate fuel level
    if (fuel <= 0) {
      printf("Vehicle has run out of fuel. Game over!\n");
      break;
    }

    // Display fuel usage
    printf("Fuel used: %d\n", rand() % speed + 1);

    // Calculate cost of fuel usage and display
    printf("Cost of fuel used: $%.2f\n", FUEL_COST * (rand() % speed + 1));
    
    // Prompt user for next action
    printf("Press any key to continue or 0 to exit: ");
    scanf("%d", &choice);

    // Display final message if user chooses to exit
    if (choice == 0) {
      printf("Thanks for playing! Your total distance travelled is %d km.\n", distance);
      break;
    }
  }

  return 0;
}