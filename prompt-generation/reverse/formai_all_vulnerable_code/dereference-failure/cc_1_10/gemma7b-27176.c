//Gemma-7B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Recipients 5

typedef struct Email {
  char *from;
  char *to[MAX_Recipients];
  char *subject;
  char *message;
} Email;

Email *createEmail() {
  Email *email = malloc(sizeof(Email));
  email->from = malloc(20);
  email->to[0] = malloc(20);
  email->subject = malloc(20);
  email->message = malloc(100);
  return email;
}

void sendEmail(Email *email) {
  printf("From: %s\n", email->from);
  printf("To: ");
  for (int i = 0; email->to[i] != NULL; i++) {
    printf("%s, ", email->to[i]);
  }
  printf("\nSubject: %s\n", email->subject);
  printf("Message: %s\n", email->message);
  printf("\n");
}

int main() {
  Email *email = createEmail();
  email->from = "john.doe@example.com";
  email->to[0] = "jane.doe@example.com";
  email->subject = "Hello, Jane!";
  email->message = "This is a test email.";

  sendEmail(email);

  free(email->from);
  free(email->to[0]);
  free(email->subject);
  free(email->message);
  free(email);

  return 0;
}