//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of a given length
char *generate_string(int length) {
  char *string = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    string[i] = (rand() % 26) + 'a';
  }
  string[length] = '\0';
  return string;
}

// Function to test the user's typing speed
void test_typing_speed() {
  // Generate a random string
  char *string = generate_string(100);

  // Print the string to the console
  printf("Type the following string as quickly and accurately as possible:\n\n");
  printf("%s\n\n", string);

  // Start the timer
  clock_t start = clock();

  // Get the user's input
  char input[101];
  scanf("%s", input);

  // Stop the timer
  clock_t end = clock();

  // Calculate the user's typing speed
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  int wpm = (int)(strlen(string) / 5) / time_taken;

  // Print the user's typing speed to the console
  printf("\nYour typing speed is: %d words per minute\n", wpm);

  // Free the memory allocated for the string
  free(string);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Test the user's typing speed
  test_typing_speed();

  return 0;
}