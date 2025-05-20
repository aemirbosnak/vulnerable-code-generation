//Gemma-7B DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
  char *subject;
  char *from;
  char *to;
  char *cc;
  char *bcc;
  char *body;
  int read_status;
} Email;

void print_email(Email *email) {
  printf("Subject: %s\n", email->subject);
  printf("From: %s\n", email->from);
  printf("To: %s\n", email->to);
  printf("CC: %s\n", email->cc);
  printf("BCC: %s\n", email->bcc);
  printf("Body: %s\n", email->body);
  printf("Read Status: %d\n", email->read_status);
  printf("\n");
}

int main() {
  Email email;
  email.subject = malloc(MAX_BUFFER_SIZE);
  email.from = malloc(MAX_BUFFER_SIZE);
  email.to = malloc(MAX_BUFFER_SIZE);
  email.cc = malloc(MAX_BUFFER_SIZE);
  email.bcc = malloc(MAX_BUFFER_SIZE);
  email.body = malloc(MAX_BUFFER_SIZE);

  strcpy(email.subject, "Hello, world!");
  strcpy(email.from, "john.doe@example.com");
  strcpy(email.to, "jane.doe@example.com");
  strcpy(email.cc, "bob.smith@example.com");
  strcpy(email.bcc, "alice.white@example.com");
  strcpy(email.body, "This is an email message.");

  email.read_status = 0;

  print_email(&email);

  free(email.subject);
  free(email.from);
  free(email.to);
  free(email.cc);
  free(email.bcc);
  free(email.body);

  return 0;
}