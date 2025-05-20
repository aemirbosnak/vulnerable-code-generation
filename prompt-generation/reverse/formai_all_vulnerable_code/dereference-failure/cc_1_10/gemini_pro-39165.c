//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to send an email
bool send_email(char *to, char *from, char *subject, char *message) {
  // Create an email message
  char *email = malloc(strlen(to) + strlen(from) + strlen(subject) + strlen(message) + 100);
  sprintf(email, "To: %s\nFrom: %s\nSubject: %s\n\n%s", to, from, subject, message);

  // Send the email using the system's default email client
  system(email);

  // Free the allocated memory
  free(email);

  return true;
}

// Function to get the user's input
char *get_input(char *prompt) {
  char *input = malloc(100);
  printf("%s", prompt);
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = '\0';  // Remove the newline character
  return input;
}

int main() {
  // Get the recipient's email address
  char *to = get_input("Enter the recipient's email address: ");

  // Get the sender's email address
  char *from = get_input("Enter your email address: ");

  // Get the subject of the email
  char *subject = get_input("Enter the subject of the email: ");

  // Get the message of the email
  char *message = get_input("Enter the message of the email: ");

  // Send the email
  bool success = send_email(to, from, subject, message);

  // Print a success message
  if (success) {
    printf("Email sent successfully!\n");
  } else {
    printf("Error sending email.\n");
  }

  // Free the allocated memory
  free(to);
  free(from);
  free(subject);
  free(message);

  return 0;
}