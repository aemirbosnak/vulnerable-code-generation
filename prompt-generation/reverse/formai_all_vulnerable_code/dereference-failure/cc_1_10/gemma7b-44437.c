//Gemma-7B DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <string.h>

#define MAX_Recipients 10
#define MAX_SUBJECT_LENGTH 255

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
  message->subject = malloc(MAX_SUBJECT_LENGTH);
  message->body = malloc(MAX_SUBJECT_LENGTH);
  message->recipients = NULL;
  return message;
}

void addRecipient(EmailMessage *message, char *name) {
  EmailRecipient *recipient = malloc(sizeof(EmailRecipient));
  recipient->name = malloc(MAX_SUBJECT_LENGTH);
  recipient->name = name;
  recipient->next = NULL;

  if (message->recipients == NULL) {
    message->recipients = recipient;
  } else {
    message->recipients->next = recipient;
  }
}

void sendEmail(EmailMessage *message) {
  printf("To: ");
  EmailRecipient *recipient = message->recipients;
  while (recipient) {
    printf("%s, ", recipient->name);
    recipient = recipient->next;
  }

  printf("\nSubject: %s\n", message->subject);
  printf("Body: %s\n", message->body);

  printf("Sent!\n");
}

int main() {
  EmailMessage *message = createEmailMessage();
  addRecipient(message, "Salvador Dali");
  addRecipient(message, "Pablo Picasso");
  addRecipient(message, "Vincent van Gogh");

  message->subject = "The Persistence of Memory";
  message->body = "My dear friends, I am writing to you with a tale of the most extraordinary nature.";

  sendEmail(message);

  return 0;
}