//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 100

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
  // Get the length of the string
  int length = strlen(str);

  // Iterate over the string from the beginning and the end
  for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
    // If the characters at the current positions are not equal, the string is not a palindrome
    if (str[i] != str[j]) {
      return false;
    }
  }

  // If the loop finishes without returning false, the string is a palindrome
  return true;
}

// Function to get a string from the user
char* get_string() {
  // Allocate memory for the string
  char* str = malloc(MAX_STRING_LENGTH * sizeof(char));

  // Get the string from the user
  printf("Enter a string: ");
  scanf("%s", str);

  // Return the string
  return str;
}

// Main function
int main() {
  // Get a string from the user
  char* str = get_string();

  // Check if the string is a palindrome
  bool is_palindrome_result = is_palindrome(str);

  // Print the result
  if (is_palindrome_result) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  // Free the memory allocated for the string
  free(str);

  return 0;
}