//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random word
char *generate_word() {
  // Array of possible characters
  char *chars = "abcdefghijklmnopqrstuvwxyz";
  // Randomly select a length for the word
  int len = rand() % 10 + 1;
  // Allocate memory for the word
  char *word = malloc(len + 1);
  // Generate the word
  for (int i = 0; i < len; i++) {
    word[i] = chars[rand() % 26];
  }
  // Terminate the word with a null character
  word[len] = '\0';
  // Return the word
  return word;
}

// Get the user's input
char *get_input() {
  // Allocate memory for the input
  char *input = malloc(101);
  // Get the input from the user
  scanf("%s", input);
  // Return the input
  return input;
}

// Compare the user's input to the word
int compare_input(char *word, char *input) {
  // Compare the two strings
  int result = strcmp(word, input);
  // Return the result
  return result;
}

// Print the results of the test
void print_results(int result) {
  // Print the results
  if (result == 0) {
    printf("Correct!\n");
  } else {
    printf("Incorrect!\n");
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a word
  char *word = generate_word();

  // Get the user's input
  char *input = get_input();

  // Compare the user's input to the word
  int result = compare_input(word, input);

  // Print the results of the test
  print_results(result);

  // Free the memory allocated for the word and input
  free(word);
  free(input);

  // Return 0
  return 0;
}