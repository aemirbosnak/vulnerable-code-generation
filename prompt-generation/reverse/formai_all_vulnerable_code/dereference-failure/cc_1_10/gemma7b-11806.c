//Gemma-7B DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
  char *subject;
  char *from;
  char *to;
  char *body;
  struct Email *next;
} Email;

Email *createEmail(char *subject, char *from, char *to, char *body) {
  Email *email = malloc(sizeof(Email));
  email->subject = strdup(subject);
  email->from = strdup(from);
  email->to = strdup(to);
  email->body = strdup(body);
  email->next = NULL;
  return email;
}

void printEmail(Email *email) {
  printf("Subject: %s\n", email->subject);
  printf("From: %s\n", email->from);
  printf("To: %s\n", email->to);
  printf("Body: %s\n", email->body);
  printf("\n");
}

int main() {
  Email *myEmailList = NULL;

  // Create a few emails
  Email *email1 = createEmail("Hello, world!", "john.doe@example.com", "jane.doe@example.com", "This is the first email.");
  Email *email2 = createEmail("How are you?", "jane.doe@example.com", "john.doe@example.com", "This is the second email.");
  Email *email3 = createEmail("Best regards,", "john.doe@example.com", "jane.doe@example.com", "This is the third email.");

  // Add the emails to the list
  myEmailList = email1;
  email1->next = email2;
  email2->next = email3;

  // Print the emails
  printEmail(myEmailList);

  return 0;
}