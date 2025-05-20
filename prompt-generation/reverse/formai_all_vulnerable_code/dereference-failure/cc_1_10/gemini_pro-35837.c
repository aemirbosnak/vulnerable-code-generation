//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum size of the input string
#define MAX_STRING_SIZE 1024

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
  // Get the length of the string
  int len = strlen(str);

  // Check if the string is empty or has only one character
  if (len <= 1) {
    return 1;
  }

  // Compare the first and last characters of the string
  if (str[0] != str[len - 1]) {
    return 0;
  }

  // Recursively check the remaining characters of the string
  return is_palindrome(str + 1) && is_palindrome(str + len - 2);
}

// Main function
int main(int argc, char** argv) {
  // Check if the user provided an input string
  if (argc < 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  // Get the input string
  char* str = argv[1];

  // Check if the string is a palindrome
  int is_palindrome_result = is_palindrome(str);

  // Print the result
  if (is_palindrome_result) {
    printf("%s is a palindrome\n", str);
  } else {
    printf("%s is not a palindrome\n", str);
  }

  return 0;
}