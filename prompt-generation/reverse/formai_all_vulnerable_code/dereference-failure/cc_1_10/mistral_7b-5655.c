//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to check if a character is alphabetic or not
int is_alphanumeric(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    return 1;
  else
    return 0;
}

// Function to sanitize user input using funny names
char* sanitize_input(char* input) {
  int i, j;
  char* output = malloc(strlen(input) + 1);
  for (i = 0; input[i] != '\0'; i++) {
    if (is_alphanumeric(input[i])) {
      output[i] = input[i];
    } else if (input[i] == '!' && is_alphanumeric(input[i+1])) {
      i++;
      output[i-1] = '_';
      output[i] = toupper(input[i]);
    } else if (input[i] == '.' && is_alphanumeric(input[i+1])) {
      i++;
      output[i-1] = '_';
      output[i] = toupper(input[i]);
    } else if (input[i] == ' ' && i > 0 && is_alphanumeric(input[i-1])) {
      output[i-1] = '_';
    } else if (input[i] == ':' && i > 0 && is_alphanumeric(input[i-1])) {
      i--;
      output[i] = '_';
    } else {
      i--;
      output[i] = '\0';
      printf("Error: Invalid character '%c' in input.\n", input[i]);
      free(output);
      return NULL;
    }
  }
  output[strlen(input)] = '\0';
  return output;
}

int main() {
  char user_input[100];
  char* sanitized_input;

  printf("Hey there, buddy! Let's sanitize your user input!\n");
  fgets(user_input, sizeof(user_input), stdin);

  sanitized_input = sanitize_input(user_input);

  if (sanitized_input != NULL) {
    printf("Sanitized input: %s\n", sanitized_input);

    int fd = open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, sanitized_input, strlen(sanitized_input));
    close(fd);

    free(sanitized_input);
  }

  return 0;
}