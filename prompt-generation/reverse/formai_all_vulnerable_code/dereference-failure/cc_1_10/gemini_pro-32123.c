//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of the input text
#define MAX_TEXT_LENGTH 1000

// Define the number of seconds for the test
#define TEST_DURATION 60

// Define the minimum number of words per minute to pass the test
#define PASSING_WORDS_PER_MINUTE 30

// Create a struct to store the user's input
typedef struct {
  char *text;
  int length;
} Input;

// Create a struct to store the test results
typedef struct {
  int words_per_minute;
  int accuracy;
} Results;

// Function to generate a random string of characters
char *generate_random_string(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + rand() % 26;
  }
  string[length] = '\0';
  return string;
}

// Function to get the user's input
Input get_input() {
  char *text = malloc(MAX_TEXT_LENGTH);
  int length = 0;

  printf("Start typing!\n");
  while (1) {
    char c = getchar();
    if (c == '\n') {
      break;
    }
    text[length++] = c;
  }

  Input input;
  input.text = text;
  input.length = length;
  return input;
}

// Function to calculate the words per minute
int calculate_words_per_minute(Input input) {
  int words = 0;
  for (int i = 0; i < input.length; i++) {
    if (input.text[i] == ' ') {
      words++;
    }
  }

  return words * 60 / TEST_DURATION;
}

// Function to calculate the accuracy
int calculate_accuracy(Input input, char *correct_text) {
  int correct = 0;
  for (int i = 0; i < input.length; i++) {
    if (input.text[i] == correct_text[i]) {
      correct++;
    }
  }

  return correct * 100 / input.length;
}

// Function to print the test results
void print_results(Results results) {
  printf("Your typing speed is %d words per minute.\n", results.words_per_minute);
  printf("Your accuracy is %d%%.\n", results.accuracy);

  if (results.words_per_minute >= PASSING_WORDS_PER_MINUTE) {
    printf("Congratulations! You passed the test.\n");
  } else {
    printf("Sorry, you did not pass the test.\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the correct text
  char *correct_text = generate_random_string(MAX_TEXT_LENGTH);

  // Get the user's input
  Input input = get_input();

  // Calculate the words per minute
  int words_per_minute = calculate_words_per_minute(input);

  // Calculate the accuracy
  int accuracy = calculate_accuracy(input, correct_text);

  // Print the test results
  Results results;
  results.words_per_minute = words_per_minute;
  results.accuracy = accuracy;
  print_results(results);

  return 0;
}