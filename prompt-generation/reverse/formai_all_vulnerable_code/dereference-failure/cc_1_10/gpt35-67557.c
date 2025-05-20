//FormAI DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAIL_LENGTH 100

typedef struct Email {
  char sender[MAX_EMAIL_LENGTH];
  char recipient[MAX_EMAIL_LENGTH];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
} Email;

Email *emails[MAX_EMAILS];
int num_emails = 0;

void send_email(char *recipient, char *subject, char *body) {
  Email *new_email = malloc(sizeof(Email));

  // Set sender (this program is the sender)
  strcpy(new_email->sender, "myemailclient@example.com");

  // Set recipient
  strcpy(new_email->recipient, recipient);

  // Set subject
  strncpy(new_email->subject, subject, MAX_SUBJECT_LENGTH-1);
  new_email->subject[MAX_SUBJECT_LENGTH-1] = '\0';

  // Set body
  strncpy(new_email->body, body, MAX_BODY_LENGTH-1);
  new_email->body[MAX_BODY_LENGTH-1] = '\0';

  // Add email to list of emails
  emails[num_emails++] = new_email;
}

void list_emails() {
  printf("Num\tSender\tRecipient\tSubject\n");
  for (int i = 0; i < num_emails; i++) {
    printf("%d\t%s\t%s\t%s\n",
      i+1,
      emails[i]->sender,
      emails[i]->recipient,
      emails[i]->subject
    );
  }
}

int main() {
  char recipient[MAX_EMAIL_LENGTH];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
  int choice;
  while (1) {
    printf("\n1. Send email\n");
    printf("2. List emails\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("Enter recipient: ");
        scanf("%s", recipient);
        printf("Enter subject: ");
        scanf("%s", subject);
        printf("Enter body: ");
        getchar(); // consume newline character left in the buffer
        fgets(body, MAX_BODY_LENGTH, stdin);
        send_email(recipient, subject, body);
        printf("Email sent!\n");
        break;
      case 2:
        list_emails();
        break;
      case 3:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}