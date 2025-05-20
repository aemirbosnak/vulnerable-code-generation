//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
} subscriber;

typedef struct {
  subscriber *subscribers;
  int num_subscribers;
} mailing_list;

mailing_list *create_mailing_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->subscribers = NULL;
  list->num_subscribers = 0;
  return list;
}

void add_subscriber(mailing_list *list, char *name, char *email) {
  list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
  list->subscribers[list->num_subscribers].name = strdup(name);
  list->subscribers[list->num_subscribers].email = strdup(email);
  list->num_subscribers++;
}

void remove_subscriber(mailing_list *list, char *name) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      break;
    }
  }

  if (i == list->num_subscribers) {
    return;
  }

  for (i = i + 1; i < list->num_subscribers; i++) {
    list->subscribers[i - 1] = list->subscribers[i];
  }

  list->num_subscribers--;
}

void send_email(mailing_list *list, char *subject, char *body) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
  }
}

void free_mailing_list(mailing_list *list) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    free(list->subscribers[i].name);
    free(list->subscribers[i].email);
  }
  free(list->subscribers);
  free(list);
}

int main() {
  mailing_list *list = create_mailing_list();
  add_subscriber(list, "John Doe", "john.doe@example.com");
  add_subscriber(list, "Jane Doe", "jane.doe@example.com");
  send_email(list, "Hello, world!", "This is a test email.");
  remove_subscriber(list, "John Doe");
  send_email(list, "Goodbye, world!", "This is a test email.");
  free_mailing_list(list);
  return 0;
}