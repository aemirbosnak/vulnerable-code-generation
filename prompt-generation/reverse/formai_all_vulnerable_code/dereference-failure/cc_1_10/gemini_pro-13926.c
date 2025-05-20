//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: surprised
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
char *getInput(int length) {
  char *input = malloc(length + 1);
  scanf("%s", input);
  return input;
}

// Function to compare the user's input to the generated string
int compareStrings(char *string1, char *string2) {
  int length = strlen(string1);
  for (int i = 0; i < length; i++) {
    if (string1[i] != string2[i]) {
      return 0;
    }
  }
  return 1;
}

// Function to calculate the user's typing speed
int calculateTypingSpeed(int length, double time) {
  return (int)((length / 5) / time * 60);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random string
  int length = 100;
  char *string = generateString(length);

  // Get the user's input
  char *input = getInput(length);

  // Compare the user's input to the generated string
  int correct = compareStrings(string, input);

  // Calculate the user's typing speed
  double time = clock() / (double)CLOCKS_PER_SEC;
  int speed = calculateTypingSpeed(length, time);

  // Print the results
  if (correct) {
    printf("Congratulations! You typed the string correctly.\n");
  } else {
    printf("Sorry, you made a mistake.\n");
  }
  printf("Your typing speed is %d words per minute.\n", speed);

  // Free the allocated memory
  free(string);
  free(input);

  return 0;
}