//Gemma-7B DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
  char *subject;
  char *sender;
  char *recipient;
  char *body;
  struct Email *next;
} Email;

Email *insertEmail(Email *head, char *subject, char *sender, char *recipient, char *body) {
  Email *newEmail = malloc(sizeof(Email));
  newEmail->subject = strdup(subject);
  newEmail->sender = strdup(sender);
  newEmail->recipient = strdup(recipient);
  newEmail->body = strdup(body);
  newEmail->next = NULL;

  if (head == NULL) {
    head = newEmail;
  } else {
    head->next = newEmail;
  }

  return head;
}

int main() {
  Email *head = NULL;

  insertEmail(head, "Subject: Hello, world!", "sender@example.com", "recipient@example.com", "This is a message.");

  insertEmail(head, "Subject: Another email", "another@example.com", "recipient@example.com", "Another message.");

  insertEmail(head, "Subject: Third email", "third@example.com", "recipient@example.com", "The third message.");

  Email *currentEmail = head;

  while (currentEmail) {
    printf("Subject: %s\n", currentEmail->subject);
    printf("Sender: %s\n", currentEmail->sender);
    printf("Recipient: %s\n", currentEmail->recipient);
    printf("Body: %s\n", currentEmail->body);
    printf("\n");

    currentEmail = currentEmail->next;
  }

  return 0;
}