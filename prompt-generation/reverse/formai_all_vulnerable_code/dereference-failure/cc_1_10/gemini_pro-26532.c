//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subscriber {
  char *email;
  struct subscriber *next;
} subscriber_t;

typedef struct mailing_list {
  char *name;
  subscriber_t *subscribers;
} mailing_list_t;

mailing_list_t *create_mailing_list(char *name) {
  mailing_list_t *list = malloc(sizeof(mailing_list_t));
  list->name = strdup(name);
  list->subscribers = NULL;
  return list;
}

void add_subscriber(mailing_list_t *list, char *email) {
  subscriber_t *new_subscriber = malloc(sizeof(subscriber_t));
  new_subscriber->email = strdup(email);
  new_subscriber->next = list->subscribers;
  list->subscribers = new_subscriber;
}

void send_email(mailing_list_t *list, char *subject, char *body) {
  subscriber_t *current = list->subscribers;
  while (current != NULL) {
    printf("Sending email to %s:\n", current->email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
    current = current->next;
  }
}

void free_mailing_list(mailing_list_t *list) {
  subscriber_t *current = list->subscribers;
  while (current != NULL) {
    subscriber_t *next = current->next;
    free(current->email);
    free(current);
    current = next;
  }
  free(list->name);
  free(list);
}

int main() {
  mailing_list_t *list = create_mailing_list("My Mailing List");
  add_subscriber(list, "alice@example.com");
  add_subscriber(list, "bob@example.com");
  add_subscriber(list, "carol@example.com");
  send_email(list, "Hello!", "This is a test email.");
  free_mailing_list(list);
  return 0;
}