//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of the random string.
#define MAX_STRING_LENGTH 100

// Generate a random string of a given length.
char *generate_string(int length) {
  // Allocate memory for the string.
  char *string = malloc(length + 1);

  // Generate a random string.
  for (int i = 0; i < length; i++) {
    string[i] = (char)('a' + rand() % 26);
  }

  // Terminate the string with a null character.
  string[length] = '\0';

  // Return the string.
  return string;
}

// Test the user's typing speed.
void test_typing_speed() {
  // Generate a random string.
  char *string = generate_string(MAX_STRING_LENGTH);

  // Display the string to the user.
  printf("Type the following string as quickly as possible:\n\n%s\n\n", string);

  // Start the timer.
  clock_t start = clock();

  // Wait for the user to finish typing.
  char typed_string[MAX_STRING_LENGTH + 1];
  fgets(typed_string, MAX_STRING_LENGTH + 1, stdin);

  // Stop the timer.
  clock_t end = clock();

  // Calculate the user's typing speed.
  int time_taken = (end - start) / CLOCKS_PER_SEC;
  int typing_speed = MAX_STRING_LENGTH / time_taken;

  // Display the user's typing speed.
  printf("Your typing speed is %d words per minute.\n", typing_speed);

  // Free the memory allocated for the string.
  free(string);
}

// The main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Test the user's typing speed.
  test_typing_speed();

  return 0;
}