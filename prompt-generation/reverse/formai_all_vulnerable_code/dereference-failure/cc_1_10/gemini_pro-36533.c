//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
  char **subscribers;
  int num_subscribers;
};

struct mailing_list *create_mailing_list() {
  struct mailing_list *list = malloc(sizeof(struct mailing_list));
  list->subscribers = NULL;
  list->num_subscribers = 0;
  return list;
}

void add_subscriber(struct mailing_list *list, char *email) {
  list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(char *));
  list->subscribers[list->num_subscribers++] = strdup(email);
}

void remove_subscriber(struct mailing_list *list, char *email) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i], email) == 0) {
      break;
    }
  }
  if (i < list->num_subscribers) {
    free(list->subscribers[i]);
    list->num_subscribers--;
    for (; i < list->num_subscribers; i++) {
      list->subscribers[i] = list->subscribers[i + 1];
    }
    list->subscribers = realloc(list->subscribers, list->num_subscribers * sizeof(char *));
  }
}

void send_email(struct mailing_list *list, char *subject, char *body) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    // Send the email to list->subscribers[i] with subject subject and body body.
  }
}

void free_mailing_list(struct mailing_list *list) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    free(list->subscribers[i]);
  }
  free(list->subscribers);
  free(list);
}

int main() {
  struct mailing_list *list = create_mailing_list();
  add_subscriber(list, "john@example.com");
  add_subscriber(list, "jane@example.com");
  send_email(list, "Hello", "This is a test email.");
  remove_subscriber(list, "jane@example.com");
  free_mailing_list(list);
  return 0;
}