//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of characters
char *generate_string(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + rand() % 26;
  }
  string[length] = '\0';
  return string;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculate_wpm(int characters_typed, int time_taken) {
  float wpm = (characters_typed / 5) / (time_taken / 60);
  return (int)wpm;
}

int main() {
  srand(time(NULL));

  // Generate a random string of characters
  char *string = generate_string(100);

  // Print the string to the console
  printf("Your challenge is to type the following string as quickly as possible:\n\n");
  printf("%s\n\n", string);

  // Start the timer
  clock_t start = clock();

  // Prompt the user to type the string
  char typed_string[101];
  printf("Type the string: ");
  scanf("%s", typed_string);

  // Stop the timer
  clock_t end = clock();

  // Calculate the time taken to type the string
  int time_taken = (end - start) / CLOCKS_PER_SEC;

  // Calculate the number of characters typed
  int characters_typed = strlen(typed_string);

  // Calculate the typing speed in WPM
  int wpm = calculate_wpm(characters_typed, time_taken);

  // Print the results to the console
  printf("\nYour typing speed is %d WPM.\n", wpm);

  // Free the allocated memory
  free(string);

  return 0;
}