//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Mailbox {
  char *sender;
  char *recipient;
  char *subject;
  char *message;
  struct Mailbox *next;
} Mailbox;

Mailbox *createMailbox(char *sender, char *recipient, char *subject, char *message) {
  Mailbox *mailbox = malloc(sizeof(Mailbox));

  mailbox->sender = strdup(sender);
  mailbox->recipient = strdup(recipient);
  mailbox->subject = strdup(subject);
  mailbox->message = strdup(message);
  mailbox->next = NULL;

  return mailbox;
}

void addMailbox(Mailbox *mailbox, Mailbox *newMailbox) {
  if (mailbox) {
    mailbox->next = newMailbox;
  } else {
    mailbox = newMailbox;
  }
}

void printMailbox(Mailbox *mailbox) {
  while (mailbox) {
    printf("From: %s\n", mailbox->sender);
    printf("To: %s\n", mailbox->recipient);
    printf("Subject: %s\n", mailbox->subject);
    printf("Message: %s\n", mailbox->message);
    printf("\n");
    mailbox = mailbox->next;
  }
}

int main() {
  Mailbox *inbox = createMailbox("Romeo", "Juliet", "Secret Message", "Meet me at the rose garden.");

  Mailbox *outbox = createMailbox("Juliet", "Romeo", "Secret Message", "I love you, Romeo.");

  addMailbox(inbox, outbox);

  printMailbox(inbox);

  return 0;
}