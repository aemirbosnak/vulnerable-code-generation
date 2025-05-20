//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Our beloved Romeo and Juliet
#define ROMEO "Romeo"
#define JULIET "Juliet"

// The forbidden URL
#define FORBIDDEN_URL "https://www.example.com/forbidden"

// Declare our star-crossed lovers
char *romeo, *juliet;

// The Capulet's filter
char *filter = "^https://www\\.example\\.com/[^/]+$";

int main(void)
{
  // Allocate memory for our lovers
  romeo = malloc(strlen(ROMEO) + 1);
  juliet = malloc(strlen(JULIET) + 1);

  // Copy their names to memory
  strcpy(romeo, ROMEO);
  strcpy(juliet, JULIET);

  // Declare our regex
  regex_t regex;

  // Compile the regular expression
  if (regcomp(&regex, filter, 0) != 0) {
    fprintf(stderr, "Failed to compile regular expression.\n");
    return EXIT_FAILURE;
  }

  // Declare our results
  regmatch_t match;

  // Attempt to match the URL
  if (regexec(&regex, FORBIDDEN_URL, 1, &match, 0) != 0) {
    printf("The URL is forbidden.\n");
    return EXIT_SUCCESS;
  }

  // The URL is allowed
  printf("The URL is allowed.\n");

  // Free the memory for our lovers
  free(romeo);
  free(juliet);

  // Free the compiled regex
  regfree(&regex);

  return EXIT_SUCCESS;
}