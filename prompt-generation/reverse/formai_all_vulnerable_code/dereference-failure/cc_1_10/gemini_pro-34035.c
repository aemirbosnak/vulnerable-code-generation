//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char *email;
  char *name;
  int subscribed;
} subscriber_t;

typedef struct {
  subscriber_t *subscribers;
  int size;
  int capacity;
} mailing_list_t;

mailing_list_t *mailing_list_create() {
  mailing_list_t *list = malloc(sizeof(mailing_list_t));
  if (list == NULL) {
    return NULL;
  }
  list->subscribers = NULL;
  list->size = 0;
  list->capacity = 0;
  return list;
}

void mailing_list_destroy(mailing_list_t *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->subscribers[i].email);
    free(list->subscribers[i].name);
  }
  free(list->subscribers);
  free(list);
}

int mailing_list_add(mailing_list_t *list, const char *email, const char *name) {
  if (email == NULL || name == NULL) {
    return -1;
  }
  if (mailing_list_find(list, email) != -1) {
    return -1;
  }
  if (list->size >= list->capacity) {
    list->capacity *= 2;
    list->subscribers = realloc(list->subscribers, list->capacity * sizeof(subscriber_t));
    if (list->subscribers == NULL) {
      return -1;
    }
  }
  list->subscribers[list->size].email = strdup(email);
  list->subscribers[list->size].name = strdup(name);
  list->subscribers[list->size].subscribed = 1;
  list->size++;
  return 0;
}

int mailing_list_remove(mailing_list_t *list, const char *email) {
  int index = mailing_list_find(list, email);
  if (index == -1) {
    return -1;
  }
  for (int i = index; i < list->size - 1; i++) {
    list->subscribers[i] = list->subscribers[i + 1];
  }
  list->size--;
  return 0;
}

int mailing_list_subscribe(mailing_list_t *list, const char *email) {
  int index = mailing_list_find(list, email);
  if (index == -1) {
    return -1;
  }
  list->subscribers[index].subscribed = 1;
  return 0;
}

int mailing_list_unsubscribe(mailing_list_t *list, const char *email) {
  int index = mailing_list_find(list, email);
  if (index == -1) {
    return -1;
  }
  list->subscribers[index].subscribed = 0;
  return 0;
}

int mailing_list_find(mailing_list_t *list, const char *email) {
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->subscribers[i].email, email) == 0) {
      return i;
    }
  }
  return -1;
}

void mailing_list_print(mailing_list_t *list) {
  printf("Mailing list:\n");
  for (int i = 0; i < list->size; i++) {
    printf("  %s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
  }
}

int main() {
  mailing_list_t *list = mailing_list_create();
  mailing_list_add(list, "john@example.com", "John Doe");
  mailing_list_add(list, "jane@example.com", "Jane Doe");
  mailing_list_add(list, "bob@example.com", "Bob Smith");
  mailing_list_print(list);
  mailing_list_unsubscribe(list, "bob@example.com");
  mailing_list_print(list);
  mailing_list_destroy(list);
  return 0;
}