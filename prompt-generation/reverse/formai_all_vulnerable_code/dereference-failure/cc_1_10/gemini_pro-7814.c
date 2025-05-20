//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// A mailing list manager in a mathematical style

// A node in the doubly linked list of subscribers
struct subscriber {
  char *email;
  struct subscriber *next;
  struct subscriber *prev;
};

// The mailing list
struct mailing_list {
  struct subscriber *head;
  struct subscriber *tail;
  int size;
};

// Creates a new mailing list
struct mailing_list *create_mailing_list() {
  struct mailing_list *list = malloc(sizeof(struct mailing_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Adds a subscriber to the mailing list
void add_subscriber(struct mailing_list *list, char *email) {
  struct subscriber *new_subscriber = malloc(sizeof(struct subscriber));
  new_subscriber->email = strdup(email);
  new_subscriber->next = NULL;
  new_subscriber->prev = NULL;

  if (list->size == 0) {
    list->head = new_subscriber;
    list->tail = new_subscriber;
  } else {
    list->tail->next = new_subscriber;
    new_subscriber->prev = list->tail;
    list->tail = new_subscriber;
  }

  list->size++;
}

// Removes a subscriber from the mailing list
void remove_subscriber(struct mailing_list *list, char *email) {
  struct subscriber *current = list->head;

  while (current != NULL) {
    if (strcmp(current->email, email) == 0) {
      if (current == list->head) {
        list->head = current->next;
      } else {
        current->prev->next = current->next;
      }

      if (current == list->tail) {
        list->tail = current->prev;
      } else {
        current->next->prev = current->prev;
      }

      free(current->email);
      free(current);

      list->size--;

      return;
    }

    current = current->next;
  }
}

// Sends an email to all subscribers on the mailing list
void send_email(struct mailing_list *list, char *subject, char *body) {
  struct subscriber *current = list->head;

  while (current != NULL) {
    // Send email to current->email
    printf("Sending email to %s\n", current->email);

    current = current->next;
  }
}

// Prints the mailing list
void print_mailing_list(struct mailing_list *list) {
  struct subscriber *current = list->head;

  printf("Mailing list:\n");

  while (current != NULL) {
    printf("  - %s\n", current->email);
    current = current->next;
  }
}

// Frees the mailing list
void free_mailing_list(struct mailing_list *list) {
  struct subscriber *current = list->head;

  while (current != NULL) {
    struct subscriber *next = current->next;
    free(current->email);
    free(current);
    current = next;
  }

  free(list);
}

int main() {
  // Create a new mailing list
  struct mailing_list *list = create_mailing_list();

  // Add some subscribers to the mailing list
  add_subscriber(list, "alice@example.com");
  add_subscriber(list, "bob@example.com");
  add_subscriber(list, "charlie@example.com");

  // Print the mailing list
  print_mailing_list(list);

  // Send an email to all subscribers on the mailing list
  send_email(list, "Hello", "This is a test email.");

  // Remove a subscriber from the mailing list
  remove_subscriber(list, "bob@example.com");

  // Print the mailing list again
  print_mailing_list(list);

  // Free the mailing list
  free_mailing_list(list);

  return 0;
}