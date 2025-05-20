//Gemma-7B DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void email_client(char **mailboxes, int index, int num_mailboxes) {
  printf("Mailboxes:");
  for (int i = 0; i < num_mailboxes; i++) {
    printf(" %s", mailboxes[i]);
  }
  printf("\n");

  char **messages = malloc(num_mailboxes * sizeof(char *));
  for (int i = 0; i < num_mailboxes; i++) {
    messages[i] = malloc(1024 * sizeof(char));
  }

  printf("Enter the recipient's mailbox:");
  char recipient_mailbox[256];
  scanf("%s", recipient_mailbox);

  printf("Enter the subject:");
  char subject[256];
  scanf("%s", subject);

  printf("Enter the message:");
  char message[1024];
  scanf("%s", message);

  int flag = 0;
  for (int i = 0; i < num_mailboxes; i++) {
    if (strcmp(recipient_mailbox, mailboxes[i]) == 0) {
      messages[i] = malloc(strlen(message) + 1);
      strcpy(messages[i], message);
      flag = 1;
    }
  }

  if (flag == 0) {
    printf("No recipient found.\n");
  } else {
    printf("Message sent successfully.\n");
  }

  for (int i = 0; i < num_mailboxes; i++) {
    free(messages[i]);
  }
  free(messages);
  email_client(mailboxes, index + 1, num_mailboxes);
}

int main() {
  char **mailboxes = malloc(10 * sizeof(char *));
  mailboxes[0] = "abc@gmail.com";
  mailboxes[1] = "xyz@gmail.com";
  mailboxes[2] = "pqr@gmail.com";

  email_client(mailboxes, 0, 3);

  for (int i = 0; i < 10; i++) {
    free(mailboxes[i]);
  }
  free(mailboxes);

  return 0;
}