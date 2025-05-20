//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Recipients 10

typedef struct EmailRecipient {
  char *name;
  struct EmailRecipient *next;
} EmailRecipient;

typedef struct EmailMessage {
  char *subject;
  char *body;
  EmailRecipient *recipients;
  struct EmailMessage *next;
} EmailMessage;

EmailMessage *createEmailMessage() {
  EmailMessage *message = malloc(sizeof(EmailMessage));
  message->subject = malloc(100);
  message->body = malloc(1000);
  message->recipients = NULL;
  message->next = NULL;
  return message;
}

void addRecipient(EmailMessage *message, char *name) {
  EmailRecipient *recipient = malloc(sizeof(EmailRecipient));
  recipient->name = strdup(name);
  recipient->next = message->recipients;
  message->recipients = recipient;
}

void sendEmail(EmailMessage *message) {
  printf("Sending email to:");
  for (EmailRecipient *recipient = message->recipients; recipient; recipient = recipient->next) {
    printf(" %s", recipient->name);
  }
  printf("\nSubject: %s\n", message->subject);
  printf("Body: %s\n", message->body);
  printf("\n");
}

int main() {
  EmailMessage *message = createEmailMessage();
  addRecipient(message, "donald.knuth@gmail.com");
  addRecipient(message, "john.doe@gmail.com");
  message->subject = "Hello, world!";
  message->body = "This is a message from Don Knuth.";
  sendEmail(message);

  return 0;
}