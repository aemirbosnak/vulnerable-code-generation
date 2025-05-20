//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_LIST_SIZE 100

typedef struct subscriber {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
  bool subscribed;
} subscriber;

typedef struct mailing_list {
  subscriber subscribers[MAX_LIST_SIZE];
  int num_subscribers;
} mailing_list;

mailing_list* create_mailing_list() {
  mailing_list* list = malloc(sizeof(mailing_list));
  list->num_subscribers = 0;
  return list;
}

void destroy_mailing_list(mailing_list* list) {
  free(list);
}

bool add_subscriber(mailing_list* list, const char* name, const char* email) {
  if (list->num_subscribers == MAX_LIST_SIZE) {
    return false;
  }

  subscriber* new_sub = &list->subscribers[list->num_subscribers++];
  strcpy(new_sub->name, name);
  strcpy(new_sub->email, email);
  new_sub->subscribed = true;

  return true;
}

bool remove_subscriber(mailing_list* list, const char* name) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
      list->num_subscribers--;
      return true;
    }
  }

  return false;
}

bool send_email(mailing_list* list, const char* subject, const char* body) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (list->subscribers[i].subscribed) {
      printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
      printf("Subject: %s\n", subject);
      printf("Body:\n%s\n", body);
    }
  }

  return true;
}

int main() {
  mailing_list* list = create_mailing_list();

  add_subscriber(list, "John Doe", "john.doe@example.com");
  add_subscriber(list, "Jane Smith", "jane.smith@example.com");

  send_email(list, "Welcome to the List!", "This is a welcome message to the mailing list.");

  remove_subscriber(list, "Jane Smith");

  destroy_mailing_list(list);

  return 0;
}