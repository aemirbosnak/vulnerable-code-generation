//Gemma-7B DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
  char *subject;
  char *from;
  char *to;
  char *cc;
  char *bcc;
  char *body;
} Email;

Email *createEmail() {
  Email *email = malloc(sizeof(Email));
  email->subject = malloc(MAX_BUFFER_SIZE);
  email->from = malloc(MAX_BUFFER_SIZE);
  email->to = malloc(MAX_BUFFER_SIZE);
  email->cc = malloc(MAX_BUFFER_SIZE);
  email->bcc = malloc(MAX_BUFFER_SIZE);
  email->body = malloc(MAX_BUFFER_SIZE);
  return email;
}

void freeEmail(Email *email) {
  free(email->subject);
  free(email->from);
  free(email->to);
  free(email->cc);
  free(email->bcc);
  free(email->body);
  free(email);
}

int main() {
  Email *email = createEmail();

  email->subject = "Test Email";
  email->from = "sender@example.com";
  email->to = "recipient@example.com";
  email->cc = "carbon_copy@example.com";
  email->bcc = "blind_copy@example.com";
  email->body = "This is a test email.";

  freeEmail(email);

  return 0;
}