//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LEN 256
#define MAX_EMAIL_LEN 256
#define MAX_LIST_SIZE 100

typedef struct {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
} subscriber;

typedef struct {
  subscriber subscribers[MAX_LIST_SIZE];
  int num_subscribers;
} mailing_list;

mailing_list *create_mailing_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->num_subscribers = 0;
  return list;
}

void free_mailing_list(mailing_list *list) {
  free(list);
}

int add_subscriber(mailing_list *list, char *name, char *email) {
  if (list->num_subscribers >= MAX_LIST_SIZE) {
    return -1;
  }

  strcpy(list->subscribers[list->num_subscribers].name, name);
  strcpy(list->subscribers[list->num_subscribers].email, email);

  list->num_subscribers++;

  return 0;
}

int remove_subscriber(mailing_list *list, char *name) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      break;
    }
  }

  if (i == list->num_subscribers) {
    return -1;
  }

  list->num_subscribers--;

  for (; i < list->num_subscribers; i++) {
    list->subscribers[i] = list->subscribers[i + 1];
  }

  return 0;
}

void print_mailing_list(mailing_list *list) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
  }
}

int main() {
  mailing_list *list = create_mailing_list();

  add_subscriber(list, "Alice", "alice@example.com");
  add_subscriber(list, "Bob", "bob@example.com");
  add_subscriber(list, "Carol", "carol@example.com");

  print_mailing_list(list);

  remove_subscriber(list, "Bob");

  print_mailing_list(list);

  free_mailing_list(list);

  return 0;
}