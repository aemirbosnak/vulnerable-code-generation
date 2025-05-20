//Gemma-7B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_Recipients 10

typedef struct Mailbox {
  char **recipients;
  int num_recipients;
  char subject;
  char message[1024];
} Mailbox;

Mailbox mailbox;

void read_mailbox() {
  mailbox.num_recipients = 0;
  mailbox.recipients = NULL;
  mailbox.subject = '\0';
  mailbox.message[0] = '\0';
}

void add_recipient(char *recipient) {
  mailbox.recipients = realloc(mailbox.recipients, (mailbox.num_recipients + 1) * sizeof(char *));
  mailbox.recipients[mailbox.num_recipients++] = recipient;
}

void set_subject(char subject) {
  mailbox.subject = subject;
}

void set_message(char *message) {
  strcpy(mailbox.message, message);
}

void send_mail() {
  printf("To: ");
  for (int i = 0; i < mailbox.num_recipients; i++) {
    printf("%s, ", mailbox.recipients[i]);
  }
  printf("\nSubject: %c\n\nMessage: %s\n", mailbox.subject, mailbox.message);
  printf("Sent!\n");
  read_mailbox();
}

int main() {
  read_mailbox();
  add_recipient("john.doe@example.com");
  add_recipient("jane.doe@example.com");
  set_subject('Important');
  set_message("This is an important message.");
  send_mail();

  return 0;
}