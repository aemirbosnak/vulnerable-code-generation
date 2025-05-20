//Gemma-7B DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Emails 10

struct Email {
  char *subject;
  char *from;
  char *to;
  char *body;
  struct Email *next;
};

struct Email *createEmail(char *subject, char *from, char *to, char *body) {
  struct Email *newEmail = (struct Email *)malloc(sizeof(struct Email));
  newEmail->subject = strdup(subject);
  newEmail->from = strdup(from);
  newEmail->to = strdup(to);
  newEmail->body = strdup(body);
  newEmail->next = NULL;
  return newEmail;
}

void addEmail(struct Email **emails, char *subject, char *from, char *to, char *body) {
  struct Email *newEmail = createEmail(subject, from, to, body);
  if (*emails == NULL) {
    *emails = newEmail;
  } else {
    (*emails)->next = newEmail;
    *emails = newEmail;
  }
}

void printEmails(struct Email *emails) {
  while (emails) {
    printf("Subject: %s\n", emails->subject);
    printf("From: %s\n", emails->from);
    printf("To: %s\n", emails->to);
    printf("Body: %s\n", emails->body);
    printf("\n");
    emails = emails->next;
  }
}

int main() {
  struct Email *emails = NULL;

  addEmail(&emails, "Hello World!", "john.doe@example.com", "jane.doe@example.com", "This is a test email.");
  addEmail(&emails, "How are you?", "bill.smith@example.com", "jane.doe@example.com", "I'm doing well, thank you.");
  addEmail(&emails, "Best regards,", "john.doe@example.com", "jane.doe@example.com", "Have a nice day.");

  printEmails(emails);

  return 0;
}