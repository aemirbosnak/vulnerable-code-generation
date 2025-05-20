//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // Maximum length of user input string

void sanitizeInput(char *input); // Function declaration for input sanitizer

int main()
{
  char userInput[MAX_LENGTH]; // Declare array for user input

  printf("Enter user input: ");
  fgets(userInput, MAX_LENGTH, stdin); // Get user input

  sanitizeInput(userInput); // Sanitize user input

  printf("Sanitized input: %s\n", userInput); // Print sanitized input

  return 0;
}

void sanitizeInput(char *input)
{
  int i = 0;
  while (input[i] != '\0')
  {
    if (input[i] == '\n') // Remove newline character if present
    {
      input[i] = '\0';
      break;
    }
    else if (!isalnum(input[i])) // Replace non-alphanumeric characters with space
    {
      input[i] = ' ';
    }
    else // Convert uppercase characters to lowercase
    {
      input[i] = tolower(input[i]);
    }
    i++;
  }

  // Remove leading and trailing whitespace
  if (isspace(input[0]) != 0)
  {
    for (int j = 0; j <= strlen(input); j++)
    {
      input[j] = input[j + 1];
    }
  }

  if (isspace(input[strlen(input) - 1]) != 0)
  {
    input[strlen(input) - 1] = '\0';
  }
}