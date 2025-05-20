//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
} subscriber;

typedef struct {
  subscriber *subscribers;
  size_t count;
  size_t capacity;
} mailing_list;

mailing_list *create_mailing_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->subscribers = NULL;
  list->count = 0;
  list->capacity = 0;
  return list;
}

void add_subscriber(mailing_list *list, subscriber *subscriber) {
  if (list->count == list->capacity) {
    size_t new_capacity = list->capacity * 2;
    list->subscribers = realloc(list->subscribers, new_capacity * sizeof(subscriber));
    list->capacity = new_capacity;
  }
  list->subscribers[list->count++] = *subscriber;
}

void remove_subscriber(mailing_list *list, subscriber *subscriber) {
  size_t index = 0;
  while (index < list->count && strcmp(list->subscribers[index].email, subscriber->email) != 0) {
    index++;
  }
  if (index < list->count) {
    list->subscribers[index] = list->subscribers[list->count - 1];
    list->count--;
  }
}

void send_email(mailing_list *list, char *subject, char *body) {
  printf("Sending email to %zu subscribers:\n", list->count);
  printf("Subject: %s\n", subject);
  printf("Body: %s\n", body);
  for (size_t i = 0; i < list->count; i++) {
    printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
  }
  printf("\n");
}

void destroy_mailing_list(mailing_list *list) {
  for (size_t i = 0; i < list->count; i++) {
    free(list->subscribers[i].name);
    free(list->subscribers[i].email);
  }
  free(list->subscribers);
  free(list);
}

int main() {
  mailing_list *list = create_mailing_list();

  subscriber *subscriber1 = malloc(sizeof(subscriber));
  subscriber1->name = "John Smith";
  subscriber1->email = "john.smith@example.com";

  subscriber *subscriber2 = malloc(sizeof(subscriber));
  subscriber2->name = "Jane Doe";
  subscriber2->email = "jane.doe@example.com";

  add_subscriber(list, subscriber1);
  add_subscriber(list, subscriber2);

  send_email(list, "Hello from the mailing list!", "This is a test email.");

  remove_subscriber(list, subscriber2);

  send_email(list, "Goodbye from the mailing list!", "This is the last email you will receive from us.");

  destroy_mailing_list(list);
  free(subscriber1);
  free(subscriber2);

  return 0;
}