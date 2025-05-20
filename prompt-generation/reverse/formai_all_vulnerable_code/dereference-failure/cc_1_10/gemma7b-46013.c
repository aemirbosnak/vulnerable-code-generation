//Gemma-7B DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Recipients 10

typedef struct Email {
  char sender[50];
  char recipient[MAX_Recipients][50];
  char subject[50];
  char message[1000];
} Email;

Email *createEmail() {
  Email *email = (Email *)malloc(sizeof(Email));
  email->sender[0] = '\0';
  email->recipient[0][0] = '\0';
  email->subject[0] = '\0';
  email->message[0] = '\0';
  return email;
}

void addRecipient(Email *email, char *recipient) {
  int i = 0;
  for (; email->recipient[i][0] != '\0'; i++) {}
  strcpy(email->recipient[i], recipient);
  email->recipient[i+1][0] = '\0';
}

void setSubject(Email *email, char *subject) {
  strcpy(email->subject, subject);
}

void setMessage(Email *email, char *message) {
  strcpy(email->message, message);
}

void sendEmail(Email *email) {
  printf("From: %s\n", email->sender);
  printf("To: ");
  for (int i = 0; email->recipient[i][0] != '\0'; i++) {
    printf("%s, ", email->recipient[i]);
  }
  printf("\nSubject: %s\n", email->subject);
  printf("\nMessage: %s\n", email->message);
  printf("\n");
}

int main() {
  Email *email = createEmail();
  addRecipient(email, "john@example.com");
  addRecipient(email, "jane@example.com");
  setSubject(email, "Hello, world!");
  setMessage(email, "This is a test email.");
  sendEmail(email);

  return 0;
}