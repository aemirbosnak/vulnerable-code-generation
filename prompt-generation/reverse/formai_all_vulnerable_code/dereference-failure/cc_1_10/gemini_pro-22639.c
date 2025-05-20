//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to calculate the typing speed
int calculateTypingSpeed(char *input, int timeTaken) {
  // Calculate the number of words typed
  int numWords = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') {
      numWords++;
    }
  }
  numWords++;

  // Calculate the typing speed in words per minute (WPM)
  int wpm = (numWords * 60) / timeTaken;

  return wpm;
}

// Function to generate a random sentence
char *generateRandomSentence(int length) {
  // Create an array of characters to store the sentence
  char *sentence = malloc(length + 1);

  // Generate a random sentence
  for (int i = 0; i < length; i++) {
    int randomChar = rand() % 26;
    sentence[i] = 'a' + randomChar;
  }

  // Add the null terminator to the end of the sentence
  sentence[length] = '\0';

  return sentence;
}

// Function to run the typing speed test
void runTypingSpeedTest() {
  // Generate a random sentence
  char *sentence = generateRandomSentence(100);

  // Display the sentence to the user
  printf("Type the following sentence as fast as you can:\n");
  printf("%s\n", sentence);

  // Start the timer
  clock_t start = clock();

  // Get the input from the user
  char input[101];
  fgets(input, 101, stdin);

  // Stop the timer
  clock_t end = clock();

  // Calculate the time taken to type the sentence
  int timeTaken = (end - start) / CLOCKS_PER_SEC;

  // Calculate the typing speed
  int wpm = calculateTypingSpeed(input, timeTaken);

  // Display the typing speed to the user
  printf("Your typing speed is %d WPM.\n", wpm);

  // Free the memory allocated for the sentence
  free(sentence);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Run the typing speed test
  runTypingSpeedTest();

  return 0;
}