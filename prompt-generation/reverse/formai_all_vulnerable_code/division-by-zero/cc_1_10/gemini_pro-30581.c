//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generateString(int n) {
  char *str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    str[i] = 'a' + rand() % 26;
  }
  str[n] = '\0';
  return str;
}

// Function to calculate the typing speed
int calculateSpeed(char *str, int time) {
  int n = strlen(str);
  return (n / time) * 60;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the string to be typed
  int n;
  printf("Enter the length of the string to be typed: ");
  scanf("%d", &n);

  // Generate a random string of length n
  char *str = generateString(n);

  // Print the string to be typed
  printf("Type the following string: %s\n", str);

  // Start the timer
  time_t start = time(NULL);

  // Wait for the user to finish typing
  char input[n + 1];
   scanf("%s", input);

  // Stop the timer
  time_t end = time(NULL);

  // Calculate the typing speed
  int speed = calculateSpeed(str, end - start);

  // Print the typing speed
  printf("Your typing speed is %d words per minute.\n", speed);

  return 0;
}