//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of a given length.
char *generate_random_string(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + rand() % 26;
  }
  string[length] = '\0';
  return string;
}

// Function to test the user's typing speed.
void test_typing_speed() {
  // Generate a random string of 100 characters.
  char *string = generate_random_string(100);

  // Get the current time.
  time_t start_time = time(NULL);

  // Prompt the user to start typing.
  printf("Start typing!\n");

  // Get the user's input.
  char *user_input = malloc(101);  // Allocate space for the user's input, plus the null-terminator.
  fgets(user_input, 101, stdin);

  // Get the current time.
  time_t end_time = time(NULL);

  // Calculate the duration of the test.
  int duration = end_time - start_time;

  // Calculate the user's typing speed.
  int speed = (int)((strlen(string) / 5.0) / duration);

  // Print the user's typing speed.
  printf("Your typing speed is %d words per minute.\n", speed);

  // Free the allocated memory.
  free(string);
  free(user_input);
}

// Main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Test the user's typing speed.
  test_typing_speed();

  return 0;
}