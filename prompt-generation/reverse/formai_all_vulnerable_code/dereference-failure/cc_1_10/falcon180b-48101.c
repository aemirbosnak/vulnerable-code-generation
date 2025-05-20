//Falcon-180B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_LENGTH 100

// Function to check if a string is empty
int is_empty(char *str) {
  if (strlen(str) == 0) {
    return 1;
  } else {
    return 0;
  }
}

// Function to print an error message and exit the program
void error(char *message) {
  fprintf(stderr, "Error: %s\n", message);
  exit(1);
}

// Function to read a line of text from the user
char *read_line(char *prompt) {
  char *line = NULL;
  printf("%s", prompt);
  fgets(line, MAX_LENGTH, stdin);
  line[strcspn(line, "\n")] = '\0'; // Remove the newline character from the end of the string
  if (is_empty(line)) {
    error("Input cannot be empty");
  }
  return line;
}

// Function to count the number of characters in a string
int count_chars(char *str) {
  int count = 0;
  while (*str!= '\0') {
    count++;
    str++;
  }
  return count;
}

// Function to reverse a string
char *reverse_string(char *str) {
  char *rev_str = malloc(sizeof(char) * strlen(str) + 1);
  int i = strlen(str) - 1;
  int j = 0;
  while (i >= 0) {
    rev_str[j++] = str[i--];
  }
  rev_str[j] = '\0';
  return rev_str;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  char *rev_str = reverse_string(str);
  int result = strcmp(str, rev_str);
  free(rev_str);
  if (result == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char *input_str = NULL;
  printf("Enter a string: ");
  input_str = read_line("");
  if (is_palindrome(input_str)) {
    printf("The string is a palindrome\n");
  } else {
    printf("The string is not a palindrome\n");
  }
  free(input_str);
  return 0;
}