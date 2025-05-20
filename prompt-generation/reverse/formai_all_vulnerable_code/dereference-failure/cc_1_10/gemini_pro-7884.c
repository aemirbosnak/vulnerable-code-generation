//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of a given length
char *generate_string(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = (char)('a' + rand() % 26);
  }
  string[length] = '\0';
  return string;
}

// Function to calculate the typing speed in words per minute
double calculate_speed(int keystrokes, int seconds) {
  double words = (double)keystrokes / 5;
  double minutes = (double)seconds / 60;
  double wpm = words / minutes;
  return wpm;
}

int main() {
  // Set up the random seed
  srand(time(NULL));

  // Generate a random string of 250 characters
  char *string = generate_string(250);

  // Get the current time
  time_t start_time = time(NULL);

  // Prompt the user to start typing
  printf("Start typing!\n");

  // Wait for the user to finish typing
  char input[251];
  scanf("%s", input);

  // Get the current time
  time_t end_time = time(NULL);

  // Calculate the time taken in seconds
  int seconds = (int)(end_time - start_time);

  // Calculate the number of keystrokes
  int keystrokes = strlen(input);

  // Calculate the typing speed in words per minute
  double wpm = calculate_speed(keystrokes, seconds);

  // Print the results
  printf("Your typing speed is: %.2f words per minute\n", wpm);

  // Free the allocated memory
  free(string);

  return 0;
}