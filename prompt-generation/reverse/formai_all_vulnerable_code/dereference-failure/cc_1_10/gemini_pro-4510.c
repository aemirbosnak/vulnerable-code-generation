//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to sanitize a string
char* sanitize_string(char* str) {
  int len = strlen(str);
  char* sanitized = malloc(len + 1);
  int i, j;
  for (i = 0, j = 0; i < len; i++) {
    if (is_alphanumeric(str[i])) {
      sanitized[j++] = str[i];
    }
  }
  sanitized[j] = '\0';
  return sanitized;
}

int main() {
  // The great detective Sherlock Holmes is investigating a case involving a mysterious message.
  // The message is believed to contain important clues, but it has been corrupted by an unknown entity.
  // Holmes suspects that the message has been tampered with and contains malicious code.
  // To ensure the safety of himself and his team, Holmes decides to sanitize the message before proceeding with his investigation.

  // Holmes begins by reading the message from a file.
  FILE* fp = fopen("message.txt", "r");
  if (fp == NULL) {
    printf("Error: could not open file.\n");
    return 1;
  }

  // Holmes allocates memory to store the message.
  char* message = malloc(1024);
  if (message == NULL) {
    printf("Error: could not allocate memory.\n");
    return 1;
  }

  // Holmes reads the message from the file into the allocated memory.
  size_t len = fread(message, 1, 1024, fp);
  if (len == 0) {
    printf("Error: could not read message from file.\n");
    return 1;
  }

  // Holmes closes the file.
  fclose(fp);

  // Holmes sanitizes the message to remove any potential malicious code.
  char* sanitized_message = sanitize_string(message);

  // Holmes prints the sanitized message to the console.
  printf("Sanitized message:\n%s\n", sanitized_message);

  // Holmes frees the allocated memory.
  free(message);
  free(sanitized_message);

  // Holmes concludes his investigation, having successfully sanitized the message and ensured the safety of himself and his team.
  printf("Elementary, my dear Watson.\n");

  return 0;
}