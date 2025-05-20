//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_EMAIL_LENGTH 256
#define MAX_LIST_SIZE 1024

typedef struct {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} subscriber;

typedef struct {
  subscriber subscribers[MAX_LIST_SIZE];
  int count;
} mailing_list;

// Create a new mailing list.
mailing_list *create_mailing_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->count = 0;
  return list;
}

// Free the memory allocated for a mailing list.
void free_mailing_list(mailing_list *list) {
  free(list);
}

// Add a subscriber to a mailing list.
void add_subscriber(mailing_list *list, const char *name, const char *email) {
  if (list->count >= MAX_LIST_SIZE) {
    printf("Error: Mailing list is full.\n");
    return;
  }

  strcpy(list->subscribers[list->count].name, name);
  strcpy(list->subscribers[list->count].email, email);
  list->count++;
}

// Remove a subscriber from a mailing list.
void remove_subscriber(mailing_list *list, const char *name) {
  int i;

  for (i = 0; i < list->count; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      break;
    }
  }

  if (i == list->count) {
    printf("Error: Subscriber not found.\n");
    return;
  }

  for (; i < list->count - 1; i++) {
    list->subscribers[i] = list->subscribers[i + 1];
  }

  list->count--;
}

// Print the subscribers in a mailing list.
void print_mailing_list(mailing_list *list) {
  int i;

  printf("Mailing List:\n");
  for (i = 0; i < list->count; i++) {
    printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
  }
}

// Send an email to all subscribers in a mailing list.
void send_email(mailing_list *list, const char *subject, const char *body) {
  int i;

  for (i = 0; i < list->count; i++) {
    printf("Sending email to %s (%s):\n", list->subscribers[i].name, list->subscribers[i].email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
  }
}

int main() {
  // Create a new mailing list.
  mailing_list *list = create_mailing_list();

  // Add some subscribers to the mailing list.
  add_subscriber(list, "John Doe", "john.doe@example.com");
  add_subscriber(list, "Jane Doe", "jane.doe@example.com");
  add_subscriber(list, "Peter Parker", "peter.parker@example.com");

  // Print the subscribers in the mailing list.
  print_mailing_list(list);

  // Send an email to all subscribers in the mailing list.
  send_email(list, "Hello world!", "This is a test email.");

  // Free the memory allocated for the mailing list.
  free_mailing_list(list);

  return 0;
}