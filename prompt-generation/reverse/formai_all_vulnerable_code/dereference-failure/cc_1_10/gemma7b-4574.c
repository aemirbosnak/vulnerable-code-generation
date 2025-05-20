//Gemma-7B DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_MESSAGES 10
#define MAX_MESSAGE_LENGTH 200

typedef struct Message {
  char *subject;
  char *body;
  struct Message *next;
} Message;

Message *create_message(char *subject, char *body) {
  Message *new_message = malloc(sizeof(Message));
  new_message->subject = strdup(subject);
  new_message->body = strdup(body);
  new_message->next = NULL;
  return new_message;
}

void add_message(Message *messages, char *subject, char *body) {
  Message *new_message = create_message(subject, body);
  if (messages == NULL) {
    messages = new_message;
  } else {
    messages->next = new_message;
  }
  messages = new_message;
}

void print_messages(Message *messages) {
  while (messages) {
    printf("Subject: %s\n", messages->subject);
    printf("Body: %s\n", messages->body);
    printf("\n");
    messages = messages->next;
  }
}

int main() {
  Message *messages = NULL;
  add_message(messages, "How to Make a Million Dollars?", "Just sell drugs.");
  add_message(messages, "The Meaning of Life?", "It's a mystery, my friend.");
  add_message(messages, "Free Puppies!", "Adopt one today!");
  add_message(messages, "The Secret to Happiness?", "Be a cat.");

  print_messages(messages);

  return 0;
}