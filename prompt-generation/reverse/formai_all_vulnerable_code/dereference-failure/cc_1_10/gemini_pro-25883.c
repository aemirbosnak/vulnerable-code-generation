//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: medieval
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
      free(list->subscribers[i].name);
      free(list->subscribers[i].email);
      list->num_subscribers--;
      memmove(&list->subscribers[i], &list->subscribers[i + 1], (list->num_subscribers - i) * sizeof(subscriber));
      return;
    }
  }
}

void send_message(mailing_list *list, char *subject, char *body) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
  }
}

int main() {
  mailing_list list;
  list.subscribers = NULL;
  list.num_subscribers = 0;

  add_subscriber(&list, "Sir Robin", "robin@example.com");
  add_subscriber(&list, "Lady Marian", "marian@example.com");
  add_subscriber(&list, "Little John", "john@example.com");

  send_message(&list, "Quest for the Holy Grail", "We need your help to find the Holy Grail!");

  remove_subscriber(&list, "Sir Robin");

  send_message(&list, "Quest for the Holy Grail (minus Sir Robin)", "We need your help to find the Holy Grail (minus Sir Robin)!");

  return 0;
}