//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30  
#define MAX_EMAIL_LEN 50 
#define MAX_LIST_SIZE 100 

typedef struct {
  char *name;
  char *email;
} subscriber;

typedef struct {
  subscriber *subscribers[MAX_LIST_SIZE];
  int num_subscribers;
} mailing_list;

mailing_list *create_mailing_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->num_subscribers = 0;
  return list;
}

void add_subscriber(mailing_list *list, char *name, char *email) {
  if (list->num_subscribers == MAX_LIST_SIZE) {
    printf("Error: mailing list is full.\n");
    return;
  }

  subscriber *new_subscriber = malloc(sizeof(subscriber));
  new_subscriber->name = malloc(strlen(name) + 1);
  strcpy(new_subscriber->name, name);
  new_subscriber->email = malloc(strlen(email) + 1);
  strcpy(new_subscriber->email, email);

  list->subscribers[list->num_subscribers++] = new_subscriber;
}

void remove_subscriber(mailing_list *list, char *email) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i]->email, email) == 0) {
      break;
    }
  }

  if (i == list->num_subscribers) {
    printf("Error: subscriber not found.\n");
    return;
  }

  free(list->subscribers[i]->name);
  free(list->subscribers[i]->email);

  list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
  list->num_subscribers--;
}

void print_mailing_list(mailing_list *list) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    printf("%s, %s\n", list->subscribers[i]->name, list->subscribers[i]->email);
  }
}

void send_mail(mailing_list *list, char *subject, char *message) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    printf("Sending email to %s at %s\n", list->subscribers[i]->name, list->subscribers[i]->email);
  }
}

void free_mailing_list(mailing_list *list) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    free(list->subscribers[i]->name);
    free(list->subscribers[i]->email);
  }

  free(list);
}

int main() {
  mailing_list *list = create_mailing_list();

  add_subscriber(list, "John Doe", "john.doe@example.com");
  add_subscriber(list, "Jane Smith", "jane.smith@example.com");
  add_subscriber(list, "Bob Jones", "bob.jones@example.com");

  print_mailing_list(list);

  send_mail(list, "Test Email", "This is a test email.");

  remove_subscriber(list, "bob.jones@example.com");

  print_mailing_list(list);

  free_mailing_list(list);

  return 0;
}