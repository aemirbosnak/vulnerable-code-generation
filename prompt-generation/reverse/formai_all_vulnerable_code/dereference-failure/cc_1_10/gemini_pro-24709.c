//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of words to type
#define MAX_WORDS 100

// Define the minimum number of characters per word
#define MIN_CHARS_PER_WORD 3

// Define the maximum number of characters per word
#define MAX_CHARS_PER_WORD 10

// Define the number of seconds to type for
#define TIME_LIMIT 60

// Define the minimum typing speed (words per minute) to pass the test
#define MIN_PASSING_SPEED 50

// Function to generate a random word
char *generate_word() {
  // Allocate memory for the word
  char *word = malloc(MAX_CHARS_PER_WORD + 1);

  // Generate a random length for the word
  int length = rand() % (MAX_CHARS_PER_WORD - MIN_CHARS_PER_WORD + 1) + MIN_CHARS_PER_WORD;

  // Generate the word
  for (int i = 0; i < length; i++) {
    word[i] = 'a' + rand() % 26;
  }

  // Terminate the word with a null character
  word[length] = '\0';

  // Return the word
  return word;
}

// Function to get the user's input
char *get_input() {
  // Allocate memory for the input
  char *input = malloc(MAX_WORDS * MAX_CHARS_PER_WORD + 1);

  // Get the user's input
  printf("Type the following words as quickly as possible:\n");
  for (int i = 0; i < MAX_WORDS; i++) {
    // Generate a random word
    char *word = generate_word();

    // Print the word
    printf("%s ", word);

    // Free the memory allocated for the word
    free(word);
  }

  // Get the user's input
  scanf("%s", input);

  // Return the user's input
  return input;
}

// Function to calculate the typing speed
double calculate_typing_speed(char *input) {
  // Calculate the number of words typed
  int num_words = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') {
      num_words++;
    }
  }

  // Calculate the number of characters typed
  int num_chars = strlen(input);

  // Calculate the typing speed
  double typing_speed = (num_words / TIME_LIMIT) * 60;

  // Return the typing speed
  return typing_speed;
}

// Function to print the results
void print_results(double typing_speed) {
  // Print the typing speed
  printf("Your typing speed is: %.2f words per minute\n", typing_speed);

  // Print the pass/fail status
  if (typing_speed >= MIN_PASSING_SPEED) {
    printf("Congratulations! You passed the test.\n");
  } else {
    printf("Sorry, you did not pass the test.\n");
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the user's input
  char *input = get_input();

  // Calculate the typing speed
  double typing_speed = calculate_typing_speed(input);

  // Print the results
  print_results(typing_speed);

  // Free the memory allocated for the input
  free(input);

  return 0;
}