//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define some constants and variables
#define MAX_LENGTH 100
#define SPACE_CHAR ' '
#define PUNCTUATION_CHARS "!@#$%^&*()_-+\|[]\";'<,>?"

// Function to check if the input string is a palindrome
int is_palindrome(char *str) {
  int i, j;
  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return 0;
    }
  }
  return 1;
}

// Function to reverse a string
char *reverse_string(char *str) {
  int i, j;
  char temp;
  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
  return str;
}

// Function to remove punctuations from a string
char *remove_punctuations(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (strchr(PUNCTUATION_CHARS, str[i])) {
      str[i] = ' ';
    }
  }
  return str;
}

// Function to convert string to title case
char *to_title_case(char *str) {
  int i, j;
  for (i = 0, j = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ' || str[i] == '\t') {
      continue;
    }
    str[j] = toupper(str[i]);
    j++;
  }
  return str;
}

// Main function
int main() {
  char input[MAX_LENGTH];
  printf("Enter a string: ");
  fgets(input, MAX_LENGTH, stdin);

  // Check if the input string is a palindrome
  if (is_palindrome(input)) {
    printf("Yes, the string is a palindrome!\n");
  } else {
    printf("No, the string is not a palindrome.\n");
  }

  // Reverse the input string
  char *reversed_str = reverse_string(input);
  printf("The reversed string is: %s\n", reversed_str);

  // Remove punctuations from the input string
  char *punctuation_free_str = remove_punctuations(input);
  printf("The punctuation-free string is: %s\n", punctuation_free_str);

  // Convert the input string to title case
  char *title_case_str = to_title_case(input);
  printf("The title case string is: %s\n", title_case_str);

  free(reversed_str);
  free(punctuation_free_str);
  free(title_case_str);

  return 0;
}