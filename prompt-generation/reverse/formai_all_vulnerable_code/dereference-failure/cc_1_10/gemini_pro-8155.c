//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defines the maximum length of a line in the email
#define MAX_LINE_LENGTH 1024

// Function to read a line of text from the user
char *readLine() {
  // Allocate memory for the line
  char *line = malloc(MAX_LINE_LENGTH);

  // Read the line from the user
  fgets(line, MAX_LINE_LENGTH, stdin);

  // Return the line
  return line;
}

// Function to send an email
void sendEmail(char *to, char *from, char *subject, char *body) {
  // Create the email message
  char *message = malloc(MAX_LINE_LENGTH * 4);
  sprintf(message, "To: %s\nFrom: %s\nSubject: %s\nBody: %s\n", to, from, subject, body);

  // Send the email
  system(message);

  // Free the memory allocated for the message
  free(message);
}

// Main function
int main() {
  // Get the recipient's email address
  char *to = readLine();

  // Get the sender's email address
  char *from = readLine();

  // Get the subject of the email
  char *subject = readLine();

  // Get the body of the email
  char *body = readLine();

  // Send the email
  sendEmail(to, from, subject, body);

  // Free the memory allocated for the email addresses, subject, and body
  free(to);
  free(from);
  free(subject);
  free(body);

  return 0;
}