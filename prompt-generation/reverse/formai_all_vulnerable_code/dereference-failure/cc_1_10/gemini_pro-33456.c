//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 1024

// Define the number of strings to generate
#define NUM_STRINGS 10

// Define the characters to use for generating strings
char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Function to generate a random string
char *generate_random_string(int length) {
  // Allocate memory for the string
  char *string = malloc(length + 1);

  // Generate a random string
  for (int i = 0; i < length; i++) {
    int index = rand() % (sizeof(characters) - 1);
    string[i] = characters[index];
  }

  // Terminate the string with a null character
  string[length] = '\0';

  // Return the string
  return string;
}

// Function to print an array of strings
void print_strings(char **strings, int num_strings) {
  for (int i = 0; i < num_strings; i++) {
    printf("%s\n", strings[i]);
  }
}

// Function to free the memory allocated for an array of strings
void free_strings(char **strings, int num_strings) {
  for (int i = 0; i < num_strings; i++) {
    free(strings[i]);
  }
}

// Main function
int main() {
  // Generate an array of random strings
  char **strings = malloc(sizeof(char *) * NUM_STRINGS);
  for (int i = 0; i < NUM_STRINGS; i++) {
    strings[i] = generate_random_string(rand() % MAX_STRING_LENGTH + 1);
  }

  // Print the array of strings
  print_strings(strings, NUM_STRINGS);

  // Free the memory allocated for the array of strings
  free_strings(strings, NUM_STRINGS);

  return 0;
}