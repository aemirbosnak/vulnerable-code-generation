//Gemma-7B DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Mailbox {
  char *subject;
  char *from;
  char *to;
  char *body;
  struct Mailbox *next;
} Mailbox;

Mailbox *createMailbox() {
  Mailbox *mailbox = malloc(sizeof(Mailbox));
  mailbox->subject = NULL;
  mailbox->from = NULL;
  mailbox->to = NULL;
  mailbox->body = NULL;
  mailbox->next = NULL;
  return mailbox;
}

void addMail(Mailbox **mailbox, char *subject, char *from, char *to, char *body) {
  Mailbox *newMailbox = createMailbox();
  newMailbox->subject = strdup(subject);
  newMailbox->from = strdup(from);
  newMailbox->to = strdup(to);
  newMailbox->body = strdup(body);

  if (*mailbox == NULL) {
    *mailbox = newMailbox;
  } else {
    (*mailbox)->next = newMailbox;
    *mailbox = newMailbox;
  }
}

void printMail(Mailbox *mailbox) {
  printf("Subject: %s\n", mailbox->subject);
  printf("From: %s\n", mailbox->from);
  printf("To: %s\n", mailbox->to);
  printf("Body: %s\n", mailbox->body);
  printf("\n");
}

int main() {
  Mailbox *mailbox = NULL;

  addMail(&mailbox, "Hello, world!", "john.doe@gmail.com", "jane.doe@gmail.com", "This is a message.");

  addMail(&mailbox, "Goodbye, world!", "john.doe@gmail.com", "jane.doe@gmail.com", "See you later.");

  printMail(mailbox);

  return 0;
}