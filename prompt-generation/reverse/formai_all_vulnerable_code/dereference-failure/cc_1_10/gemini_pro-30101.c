//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define some funny constants
#define LOL "laughing out loud"
#define ROFL "rolling on the floor laughing"
#define LMAO "laughing my a** off"

// Declare a few functions that we'll need
char *replace_substring(char *str, char *substring, char *replacement);
int count_occurrences(char *str, char *substring);
char *random_string(int length);

int main() {
  // Create a string to play with
  char *str = "This is a test string. It contains some funny words like LOL, ROFL, and LMAO.";

  // Replace all occurrences of "LOL" with "ROFL"
  str = replace_substring(str, "LOL", "ROFL");

  // Count the number of occurrences of "ROFL" in the string
  int num_rofl = count_occurrences(str, "ROFL");

  // Print out the modified string
  printf("Modified string: %s\n", str);

  // Print out the number of occurrences of "ROFL"
  printf("Number of occurrences of \"ROFL\": %d\n", num_rofl);

  // Generate a random string
  char *random_str = random_string(10);

  // Print out the random string
  printf("Random string: %s\n", random_str);

  // Free the allocated memory
  free(str);
  free(random_str);

  return 0;
}

// Replace all occurrences of a substring with a replacement string
char *replace_substring(char *str, char *substring, char *replacement) {
  char *result = malloc(strlen(str) + strlen(replacement) - strlen(substring) + 1); // Allocate memory for the result string
  char *p = str;
  char *q = result;

  while (*p != '\0') {
    if (strncmp(p, substring, strlen(substring)) == 0) { // If the current substring matches the search substring
      strcpy(q, replacement); // Copy the replacement string to the result string
      q += strlen(replacement); // Advance the result string pointer
      p += strlen(substring); // Advance the string pointer
    } else {
      *q++ = *p++; // Copy the current character to the result string
    }
  }

  *q = '\0'; // Add the null terminator to the result string
  return result;
}

// Count the number of occurrences of a substring in a string
int count_occurrences(char *str, char *substring) {
  int count = 0;
  char *p = str;

  while (*p != '\0') {
    if (strncmp(p, substring, strlen(substring)) == 0) { // If the current substring matches the search substring
      count++; // Increment the count
      p += strlen(substring); // Advance the string pointer
    } else {
      p++; // Advance the string pointer
    }
  }

  return count;
}

// Generate a random string of a specified length
char *random_string(int length) {
  char *str = malloc(length + 1); // Allocate memory for the string
  int i;

  for (i = 0; i < length; i++) {
    str[i] = (rand() % 26) + 'a'; // Generate a random lowercase letter
  }

  str[length] = '\0'; // Add the null terminator to the string
  return str;
}