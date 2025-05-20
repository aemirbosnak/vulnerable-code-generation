//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string
char *generateString(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + rand() % 26;
  }
  string[length] = '\0';
  return string;
}

// Function to get the user's input
char *getUserInput(int length) {
  char *input = malloc(length + 1);
  printf("Type the following string: %s\n", input);
  scanf("%s", input);
  return input;
}

// Function to compare the user's input to the original string
int compareStrings(char *string, char *input) {
  int errors = 0;
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] != input[i]) {
      errors++;
    }
  }
  return errors;
}

// Function to calculate the user's typing speed
int calculateTypingSpeed(int length, int errors, int time) {
  int wordsPerMinute = (length / 5) * (60 / time);
  int accuracy = (1 - (errors / length)) * 100;
  printf("Your typing speed is %d words per minute with %d%% accuracy.\n", wordsPerMinute, accuracy);
  return wordsPerMinute;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random string
  int length = 100;
  char *string = generateString(length);

  // Get the user's input
  char *input = getUserInput(length);

  // Compare the user's input to the original string
  int errors = compareStrings(string, input);

  // Calculate the time taken to type the string
  clock_t start = clock();
  clock_t end = clock();
  int time = (end - start) / CLOCKS_PER_SEC;

  // Calculate the user's typing speed
  int wordsPerMinute = calculateTypingSpeed(length, errors, time);

  // Free the allocated memory
  free(string);
  free(input);

  return 0;
}