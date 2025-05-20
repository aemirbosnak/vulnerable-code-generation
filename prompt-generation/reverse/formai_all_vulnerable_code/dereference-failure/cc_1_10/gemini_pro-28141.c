//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the star-crossed lovers
#define ROMEO  "Romeo"
#define JULIET "Juliet"

// Define the tragic error message
#define TRAGIC_ERROR "Alas, poor Yorick! I knew him, Horatio: a fellow of infinite jest, of most excellent fancy."

// Define the function that will handle the tragic error
void handle_tragic_error(void)
{
  // Print the tragic error message
  printf("%s\n", TRAGIC_ERROR);

  // Exit the program with an error code
  exit(EXIT_FAILURE);
}

// Define the function that will run the Romeo and Juliet program
int main(void)
{
  // Initialize the Romeo and Juliet character pointers
  char *romeo = ROMEO;
  char *juliet = JULIET;

  // Allocate memory for the Romeo and Juliet character strings
  romeo = malloc(strlen(ROMEO) + 1);
  juliet = malloc(strlen(JULIET) + 1);

  // Check if the memory allocation was successful
  if (romeo == NULL || juliet == NULL)
  {
    // Handle the tragic error
    handle_tragic_error();
  }

  // Copy the Romeo and Juliet character strings into the allocated memory
  strcpy(romeo, ROMEO);
  strcpy(juliet, JULIET);

  // Print the Romeo and Juliet character strings
  printf("Romeo: %s\n", romeo);
  printf("Juliet: %s\n", juliet);

  // Free the memory allocated for the Romeo and Juliet character strings
  free(romeo);
  free(juliet);

  // Exit the program without an error
  exit(EXIT_SUCCESS);
}