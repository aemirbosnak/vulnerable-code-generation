//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 100

struct Email {
  char subject[MAX_SUBJECT_LENGTH];
  char message[MAX_MESSAGE_LENGTH];
  char to[50];
  char from[50];
  int id;
  int isSent;
};

struct Email *emails[MAX_EMAILS];
int email_count = 0;

void send_email() {
  struct Email email;
  printf("Enter recipient's email address: ");
  scanf("%s", email.to);
  printf("Enter subject: ");
  scanf("%s", email.subject);
  printf("Enter message: ");
  scanf("%s", email.message);
  printf("Enter sender's email address: ");
  scanf("%s", email.from);
  email.id = email_count;
  email.isSent = 1;

  emails[email_count] = (struct Email *) malloc(sizeof(struct Email));
  *emails[email_count] = email;
  email_count++;

  printf("\nEmail sent successfully!\n");
}

void view_email() {
  int id;
  printf("Enter email id: ");
  scanf("%d", &id);

  if (id >= email_count || id < 0) {
    printf("Invalid email id!\n");
    return;
  }

  struct Email *email = emails[id];
  printf("\nTo: %s\n", email->to);
  printf("Subject: %s\n", email->subject);
  printf("Message: %s\n", email->message);
  printf("From: %s\n\n", email->from);
}

void list_emails() {
  printf("%-5s%-15s%-30s\n", "ID", "To", "Subject");

  for (int i = 0; i < email_count; i++) {
    struct Email *email = emails[i];
    if (email->isSent) {
      printf("%-5d%-15s%-30s\n", email->id, email->to, email->subject);
    }
  }
}

void delete_email() {
  int id;
  printf("Enter email id: ");
  scanf("%d", &id);

  if (id >= email_count || id < 0) {
    printf("Invalid email id!\n");
    return;
  }

  struct Email *email = emails[id];
  email->isSent = 0;
  printf("Email deleted successfully!\n");
}

int main() {
  int choice;
  do {
    printf("\n");
    printf("1. Send Email\n");
    printf("2. View Email\n");
    printf("3. List Emails\n");
    printf("4. Delete Email\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        send_email();
        break;
      case 2:
        view_email();
        break;
      case 3:
        list_emails();
        break;
      case 4:
        delete_email();
        break;
      case 5:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }

  } while (choice != 5);

  return 0;
}