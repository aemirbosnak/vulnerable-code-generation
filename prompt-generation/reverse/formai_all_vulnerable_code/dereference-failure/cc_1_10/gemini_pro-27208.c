//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum size of the input string.
#define MAX_INPUT_SIZE 1024

// Define the maximum number of words in the input string.
#define MAX_WORDS 100

// Define the maximum length of a word.
#define MAX_WORD_LENGTH 32

// Define the number of iterations for the performance test.
#define ITERATIONS 1000000

// Define the function to generate a random string.
char *generate_random_string(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + rand() % 26;
  }
  string[length] = '\0';
  return string;
}

// Define the function to count the number of words in a string.
int count_words(char *string) {
  int count = 0;
  int in_word = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] != ' ' && !in_word) {
      count++;
      in_word = 1;
    } else if (string[i] == ' ') {
      in_word = 0;
    }
  }
  return count;
}

// Define the main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Generate a random string.
  char *string = generate_random_string(MAX_INPUT_SIZE);

  // Count the number of words in the string.
  int count = count_words(string);

  // Print the number of words in the string.
  printf("The string contains %d words.\n", count);

  // Free the memory allocated for the string.
  free(string);

  return 0;
}