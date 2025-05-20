//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables
char targetString[1001];
char inputString[1001];
int targetStringLength;
int inputStringLength;
int startTime;
int endTime;
int numberOfErrors;

// Function prototypes
void generateTargetString();
void printTargetString();
void getInputString();
void calculateStatistics();
void printStatistics();

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the target string
  generateTargetString();

  // Print the target string
  printTargetString();

  // Get the input string from the user
  getInputString();

  // Calculate the statistics
  calculateStatistics();

  // Print the statistics
  printStatistics();

  return 0;
}

void generateTargetString() {
  // Generate a random number between 10 and 100
  targetStringLength = 10 + rand() % 91;

  // Generate a random string of characters
  for (int i = 0; i < targetStringLength; i++) {
    targetString[i] = 'a' + rand() % 26;
  }
}

void printTargetString() {
  // Print the target string to the console
  printf("Target string: %s\n", targetString);
}

void getInputString() {
  // Get the input string from the user
  printf("Type the target string: ");
  scanf("%s", inputString);

  // Calculate the input string length
  inputStringLength = strlen(inputString);
}

void calculateStatistics() {
  // Start time
  startTime = clock();

  // Compare the target string and the input string
  for (int i = 0; i < targetStringLength; i++) {
    // Increment the number of errors if the characters do not match
    if (targetString[i] != inputString[i]) {
      numberOfErrors++;
    }
  }

  // End time
  endTime = clock();
}

void printStatistics() {
  // Calculate the time taken to type the string
  int timeTaken = (endTime - startTime) / CLOCKS_PER_SEC;

  // Calculate the typing speed
  int typingSpeed = inputStringLength / timeTaken;

  // Print the statistics to the console
  printf("Number of errors: %d\n", numberOfErrors);
  printf("Time taken: %d seconds\n", timeTaken);
  printf("Typing speed: %d characters per second\n", typingSpeed);
}