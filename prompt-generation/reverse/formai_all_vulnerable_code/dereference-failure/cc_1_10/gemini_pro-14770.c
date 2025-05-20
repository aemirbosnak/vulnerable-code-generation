//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of an email address
#define MAX_EMAIL_LENGTH 100

// Define the maximum length of an email subject
#define MAX_SUBJECT_LENGTH 100

// Define the maximum length of an email body
#define MAX_BODY_LENGTH 1000

// Define the maximum number of recipients
#define MAX_RECIPIENTS 10

// Define the structure of an email
typedef struct email {
  char sender[MAX_EMAIL_LENGTH];
  char recipients[MAX_RECIPIENTS][MAX_EMAIL_LENGTH];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
} email;

// Function to create a new email
email* create_email(char* sender, char** recipients, int num_recipients, char* subject, char* body) {
  email* new_email = malloc(sizeof(email));
  strcpy(new_email->sender, sender);
  for (int i = 0; i < num_recipients; i++) {
    strcpy(new_email->recipients[i], recipients[i]);
  }
  strcpy(new_email->subject, subject);
  strcpy(new_email->body, body);
  return new_email;
}

// Function to send an email
void send_email(email* email) {
  // Imagine that this function actually sends the email using some magical SMTP client
  printf("Sending email from %s to %s with subject %s and body %s\n", email->sender, email->recipients[0], email->subject, email->body);
}

// Function to print an email
void print_email(email* email) {
  printf("From: %s\n", email->sender);
  printf("To: %s\n", email->recipients[0]);
  printf("Subject: %s\n", email->subject);
  printf("Body: %s\n", email->body);
}

// Function to free the memory allocated for an email
void free_email(email* email) {
  free(email);
}

// Main function
int main() {
  // Create a new email
  email* email = create_email("sender@example.com", "recipient1@example.com", 1, "Hello, world!", "This is a test email.");

  // Print the email
  print_email(email);

  // Send the email
  send_email(email);

  // Free the memory allocated for the email
  free_email(email);

  return 0;
}