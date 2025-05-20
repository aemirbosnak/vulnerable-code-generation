//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List data structure
typedef struct email {
  char *sender;
  char *recipient;
  char *subject;
  char *body;
  struct email *next;
} Email;

// Function to create a new email and add it to the linked list
void addEmail(Email **head, char *sender, char *recipient, char *subject, char *body) {
  Email *new_email = (Email*)malloc(sizeof(Email));
  new_email->sender = (char*)malloc(strlen(sender) + 1);
  new_email->recipient = (char*)malloc(strlen(recipient) + 1);
  new_email->subject = (char*)malloc(strlen(subject) + 1);
  new_email->body = (char*)malloc(strlen(body) + 1);
  strcpy(new_email->sender, sender);
  strcpy(new_email->recipient, recipient);
  strcpy(new_email->subject, subject);
  strcpy(new_email->body, body);
  new_email->next = *head;
  *head = new_email;
}

// Function to print all emails in the linked list
void printEmails(Email *head) {
  Email *current = head;
  while (current != NULL) {
    printf("From: %s\nTo: %s\nSubject: %s\n%s\n", current->sender, current->recipient, current->subject, current->body);
    current = current->next;
  }
}

// Function to search for emails by sender or recipient
void searchEmails(Email *head, char *query) {
  Email *current = head;
  while (current != NULL) {
    if (strcmp(current->sender, query) == 0 || strcmp(current->recipient, query) == 0) {
      printf("From: %s\nTo: %s\nSubject: %s\n%s\n", current->sender, current->recipient, current->subject, current->body);
    }
    current = current->next;
  }
}

// Main function
int main() {
  Email *emails = NULL;
  int input = 0;
  char sender[50];
  char recipient[50];
  char subject[50];
  char body[500];

  while (input != 4) {
    printf("1. Compose email\n2. View all emails\n3. Search emails\n4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &input);

    switch(input) {
      case 1:
        printf("Enter sender: ");
        scanf("%s", sender);
        printf("Enter recipient: ");
        scanf("%s", recipient);
        printf("Enter subject: ");
        scanf("%s", subject);
        printf("Enter body: ");
        getchar();
        fgets(body, 500, stdin);
        addEmail(&emails, sender, recipient, subject, body);
        printf("Email sent.\n");
        break;

      case 2:
        if (emails == NULL) {
          printf("No emails to display.\n");
        } else {
          printf("All emails:\n");
          printEmails(emails);
        }
        break;

      case 3:
        printf("Enter query: ");
        scanf("%s", sender);
        searchEmails(emails, sender);
        break;

      case 4:
        printf("Exiting...\n");
        break;

      default:
        printf("Invalid option.\n");
        break;
    }
    printf("\n");
  }
  return 0;
}