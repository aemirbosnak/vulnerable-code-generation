//Gemma-7B DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

typedef struct Mailbox {
  char **messages;
  int size;
  int capacity;
} Mailbox;

Mailbox *create_mailbox(int capacity) {
  Mailbox *mailbox = malloc(sizeof(Mailbox));
  mailbox->messages = NULL;
  mailbox->size = 0;
  mailbox->capacity = capacity;

  return mailbox;
}

void add_message(Mailbox *mailbox, char *message) {
  mailbox->messages = realloc(mailbox->messages, (mailbox->size + 1) * sizeof(char *));
  mailbox->messages[mailbox->size++] = message;
}

char *get_message(Mailbox *mailbox, int index) {
  return mailbox->messages[index];
}

void delete_message(Mailbox *mailbox, int index) {
  mailbox->messages = realloc(mailbox->messages, (mailbox->size - 1) * sizeof(char *));
  mailbox->messages[index] = NULL;
  mailbox->size--;
}

int main() {
  Mailbox *mailbox = create_mailbox(10);

  add_message(mailbox, "Hello, world!");
  add_message(mailbox, "This is a message.");
  add_message(mailbox, "I am a message.");

  char *message = get_message(mailbox, 1);

  printf("%s\n", message);

  delete_message(mailbox, 1);

  message = get_message(mailbox, 0);

  printf("%s\n", message);

  return 0;
}