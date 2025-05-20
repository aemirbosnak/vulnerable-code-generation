//FormAI DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define constants for lightbulb status
enum {OFF, ON};

// Define a struct for a lightbulb
typedef struct {
  int id;
  int status;
} Lightbulb;

// Define global variables
const int NUM_LIGHTBULBS = 3;
Lightbulb* lightbulbs;

// Function prototypes
void displayMenu();
void displayStatus();
void toggleLightbulb(int id);

int main() {
  // Allocate memory for lightbulbs
  lightbulbs = (Lightbulb*) malloc(NUM_LIGHTBULBS * sizeof(Lightbulb));

  // Initialize lightbulb ids and statuses
  lightbulbs[0].id = 1;
  lightbulbs[0].status = OFF;
  lightbulbs[1].id = 2;
  lightbulbs[1].status = ON;
  lightbulbs[2].id = 3;
  lightbulbs[2].status = OFF;

  // Display menu options and loop until user enters 'q' to quit
  char selection;
  do {
    displayStatus();
    displayMenu();
    printf("Enter selection: ");
    scanf(" %c", &selection);

    switch(selection) {
      case '1': toggleLightbulb(1); break;
      case '2': toggleLightbulb(2); break;
      case '3': toggleLightbulb(3); break;
      case 'q': printf("Quitting...\n"); break;
      default: printf("Invalid selection.\n"); break;
    }
    printf("\n");
  } while(selection != 'q');

  // Free up memory and exit program
  free(lightbulbs);
  return 0;
}

// Function to display menu options to user
void displayMenu() {
  printf("Lightbulb Control\n");
  printf("1. Toggle Lightbulb 1\n");
  printf("2. Toggle Lightbulb 2\n");
  printf("3. Toggle Lightbulb 3\n");
  printf("q. Quit\n");
}

// Function to display current lightbulb statuses to user
void displayStatus() {
  printf("Lightbulb Status\n");
  for(int i=0; i<NUM_LIGHTBULBS; i++) {
    printf("Lightbulb %d is %s.\n", lightbulbs[i].id, lightbulbs[i].status == ON ? "ON" : "OFF");
  }
}

// Function to toggle a lightbulb's status
void toggleLightbulb(int id) {
  for(int i=0; i<NUM_LIGHTBULBS; i++) {
    if(lightbulbs[i].id == id) {
      lightbulbs[i].status = lightbulbs[i].status == ON ? OFF : ON;
      printf("Lightbulb %d is now %s.\n", lightbulbs[i].id, lightbulbs[i].status == ON ? "ON" : "OFF");
      return;
    }
  }
}