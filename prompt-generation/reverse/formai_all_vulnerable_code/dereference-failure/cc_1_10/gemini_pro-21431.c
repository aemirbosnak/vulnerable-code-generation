//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum input length
#define MAX_INPUT_LENGTH 1024

// Function to check if a string is alphanumeric
int is_alphanumeric(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalnum(str[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string is a valid email address
int is_valid_email(const char *email) {
  int at_count = 0;
  int dot_count = 0;
  int i;

  // Check if the email address is empty
  if (strlen(email) == 0) {
    return 0;
  }

  // Check if the email address contains an "@" symbol
  for (i = 0; email[i] != '\0'; i++) {
    if (email[i] == '@') {
      at_count++;
    }
  }
  if (at_count != 1) {
    return 0;
  }

  // Check if the email address contains a "." symbol
  for (i = 0; email[i] != '\0'; i++) {
    if (email[i] == '.') {
      dot_count++;
    }
  }
  if (dot_count == 0) {
    return 0;
  }

  // Check if the email address contains any invalid characters
  for (i = 0; email[i] != '\0'; i++) {
    if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.' && email[i] != '_') {
      return 0;
    }
  }

  return 1;
}

// Function to check if a string is a valid phone number
int is_valid_phone_number(const char *phone_number) {
  int digit_count = 0;
  int i;

  // Check if the phone number is empty
  if (strlen(phone_number) == 0) {
    return 0;
  }

  // Check if the phone number contains only digits
  for (i = 0; phone_number[i] != '\0'; i++) {
    if (!isdigit(phone_number[i])) {
      return 0;
    }
  }

  // Check if the phone number is the correct length
  if (strlen(phone_number) != 10) {
    return 0;
  }

  return 1;
}

// Function to get a sanitized string from the user
char *get_sanitized_string(const char *prompt, int max_length, int (*validator)(const char *)) {
  char *input = malloc(max_length + 1);
  int valid = 0;

  while (!valid) {
    printf("%s: ", prompt);
    fgets(input, max_length + 1, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Validate the input
    if (validator(input)) {
      valid = 1;
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }

  return input;
}

int main() {
  char *name, *email, *phone_number;

  // Get the user's name
  name = get_sanitized_string("Enter your name", MAX_INPUT_LENGTH, is_alphanumeric);

  // Get the user's email address
  email = get_sanitized_string("Enter your email address", MAX_INPUT_LENGTH, is_valid_email);

  // Get the user's phone number
  phone_number = get_sanitized_string("Enter your phone number", MAX_INPUT_LENGTH, is_valid_phone_number);

  // Print the user's information
  printf("Name: %s\n", name);
  printf("Email: %s\n", email);
  printf("Phone number: %s\n", phone_number);

  // Free the allocated memory
  free(name);
  free(email);
  free(phone_number);

  return 0;
}