//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our email struct
typedef struct {
  char *sender;
  char *recipient;
  char *subject;
  char *body;
} email;

// Create a new email
email *new_email(char *sender, char *recipient, char *subject, char *body) {
  email *e = (email *)malloc(sizeof(email));
  e->sender = strdup(sender);
  e->recipient = strdup(recipient);
  e->subject = strdup(subject);
  e->body = strdup(body);
  return e;
}

// Send an email
int send_email(email *e) {
  // Here we would typically use a library to send the email
  printf("Sending email from %s to %s with subject %s\n", e->sender, e->recipient, e->subject);
  printf("Body: %s\n", e->body);
  return 0;
}

// Free an email
void free_email(email *e) {
  free(e->sender);
  free(e->recipient);
  free(e->subject);
  free(e->body);
  free(e);
}

// Bang, here's an example of usage
int main() {
  // Create a new email
  email *e = new_email("John Doe", "Jane Doe", "Hello from C!", "This is an email sent from a C program.");

  // Send the email
  send_email(e);

  // Free the email
  free_email(e);

  return 0;
}