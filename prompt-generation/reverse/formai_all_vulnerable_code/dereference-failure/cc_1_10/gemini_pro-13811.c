//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
} subscriber;

typedef struct {
  subscriber **subscribers;
  int num_subscribers;
} mailing_list;

mailing_list *create_mailing_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->subscribers = NULL;
  list->num_subscribers = 0;
  return list;
}

void free_mailing_list(mailing_list *list) {
  for (int i = 0; i < list->num_subscribers; i++) {
    free(list->subscribers[i]->name);
    free(list->subscribers[i]->email);
    free(list->subscribers[i]);
  }
  free(list->subscribers);
  free(list);
}

int add_subscriber(mailing_list *list, char *name, char *email) {
  subscriber *new_subscriber = malloc(sizeof(subscriber));
  new_subscriber->name = strdup(name);
  new_subscriber->email = strdup(email);

  list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber *));
  list->subscribers[list->num_subscribers++] = new_subscriber;

  return 0;
}

int remove_subscriber(mailing_list *list, char *email) {
  for (int i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i]->email, email) == 0) {
      free(list->subscribers[i]->name);
      free(list->subscribers[i]->email);
      free(list->subscribers[i]);

      list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
      list->num_subscribers--;

      return 0;
    }
  }

  return -1;
}

int send_email(mailing_list *list, char *subject, char *body) {
  for (int i = 0; i < list->num_subscribers; i++) {
    // Send an email to list->subscribers[i]->email with subject and body.
  }

  return 0;
}

int main() {
  mailing_list *list = create_mailing_list();

  add_subscriber(list, "John Doe", "john.doe@example.com");
  add_subscriber(list, "Jane Doe", "jane.doe@example.com");

  send_email(list, "Hello, world!", "This is a test email.");

  remove_subscriber(list, "jane.doe@example.com");

  free_mailing_list(list);

  return 0;
}