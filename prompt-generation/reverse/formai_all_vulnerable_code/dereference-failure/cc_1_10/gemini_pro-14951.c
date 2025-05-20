//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Macros to make the code shorter.
#define N 1000 // Number of characters to type.
#define W 10000 // Number of words to type.
#define C 100000 // Number of characters to type in the correct word.
#define I 1000000 // Number of characters to type in the incorrect word.
#define T 10 // Number of seconds to type.

// Function to generate a random string of characters.
char* generate_string(int n) {
  char* str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    str[i] = 'a' + rand() % 26;
  }
  str[n] = '\0';
  return str;
}

// Function to test the typing speed.
void test_typing_speed() {
  // Generate a random string of characters.
  char* str = generate_string(N);

  // Start the timer.
  clock_t start = clock();

  // Prompt the user to start typing.
  printf("Start typing when you're ready:\n");

  // Get the user's input.
  char* input = malloc(N + 1);
  scanf("%s", input);

  // Stop the timer.
  clock_t end = clock();

  // Calculate the typing speed.
  int time = end - start;
  int wpm = (N / 5) * 60 / time;

  // Print the results.
  printf("Your typing speed is %d WPM.\n", wpm);

  // Free the memory allocated for the strings.
  free(str);
  free(input);
}

// Function to main.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Test the typing speed.
  test_typing_speed();

  return 0;
}