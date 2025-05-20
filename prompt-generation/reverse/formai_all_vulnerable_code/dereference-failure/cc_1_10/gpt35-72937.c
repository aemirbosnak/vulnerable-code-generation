//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
/* Welcome to the C User Input Sanitizer program! 
   This program is designed to clean and sanitize user input
   to prevent any malicious or unintended actions. 

   Let's get started! */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of user input

/* Function to sanitize user input */
char *sanitize(char *input) {

  /* Firstly, let's remove any leading or trailing spaces */
  while (isspace(*input)) {
    input++;
  }

  int length = strlen(input);

  while (length > 0 && isspace(input[length - 1])) {
    length--;
  }

  input[length] = '\0';

  /* Now let's remove any undesirable characters */
  char *sanitized_input = malloc(MAX_LENGTH); // Allocate memory for sanitized input
  char *temp = sanitized_input;

  while (*input != '\0') {
    if (isalnum(*input) || *input == ' ' || *input == '_' || *input == '-') {
      *temp++ = *input;
    }
    input++;
  }

  *temp = '\0'; // Add null terminator

  return sanitized_input;
}

int main() {

  /* Let's create a welcoming message */
  printf("Welcome to the C User Input Sanitizer program!\n");
  printf("This program is designed to clean and sanitize user input to prevent any malicious or unintended actions.\n");
  printf("Please enter your desired input:\n");

  char raw_input[MAX_LENGTH]; // User input buffer
  fgets(raw_input, MAX_LENGTH, stdin); // Get user input

  /* Let's sanitize the user input */
  char *sanitized_input = sanitize(raw_input);

  /* Now let's print out the sanitized input */
  printf("Your sanitized input is: %s\n", sanitized_input);

  /* Don't forget to free allocated memory! */
  free(sanitized_input);

  return 0;
}