//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *buffer = NULL;
  long int size = 0L;

  buffer = malloc(size);
  if (buffer == NULL)
  {
    printf("Error allocating memory!\n");
    exit(1);
  }

  // The paranoid user input validation loop
  while (1)
  {
    printf("Please enter a string: ");
    buffer = realloc(buffer, size + 1);
    size++;
    getline(stdin, buffer, size);

    // Check for the dreaded 'S' key
    if (strchr(buffer, 'S') != NULL)
    {
      printf("WARNING: The letter 'S' has been detected! You are being monitored!\n");
      free(buffer);
      exit(1);
    }

    // Check for suspicious characters
    for (int i = 0; i < strlen(buffer); i++)
    {
      if (!isalnum(buffer[i]))
      {
        printf("Error: Invalid characters detected. Please use only alphanumeric characters.\n");
        free(buffer);
        exit(1);
      }
    }

    // Check for overlong strings
    if (strlen(buffer) > 1024)
    {
      printf("Error: String length exceeds limit. Please keep your strings within 1024 characters.\n");
      free(buffer);
      exit(1);
    }

    // All checks complete, proceed to process the user input
    printf("Your input: %s\n", buffer);
    free(buffer);
  }

  return 0;
}