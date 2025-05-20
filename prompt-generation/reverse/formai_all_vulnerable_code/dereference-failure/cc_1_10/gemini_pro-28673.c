//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list of subscribers
typedef struct subscriber {
  char *email;
  struct subscriber *next;
} subscriber_t;

// The mailing list
typedef struct mailing_list {
  subscriber_t *head;
  int size;
} mailing_list_t;

// Create a new mailing list
mailing_list_t *mailing_list_new() {
  mailing_list_t *list = malloc(sizeof(mailing_list_t));
  list->head = NULL;
  list->size = 0;
  return list;
}

// Free the memory used by a mailing list
void mailing_list_free(mailing_list_t *list) {
  subscriber_t *current = list->head;
  while (current != NULL) {
    subscriber_t *next = current->next;
    free(current->email);
    free(current);
    current = next;
  }
  free(list);
}

// Add a new subscriber to a mailing list
void mailing_list_add(mailing_list_t *list, char *email) {
  subscriber_t *new_subscriber = malloc(sizeof(subscriber_t));
  new_subscriber->email = strdup(email);
  new_subscriber->next = list->head;
  list->head = new_subscriber;
  list->size++;
}

// Remove a subscriber from a mailing list
void mailing_list_remove(mailing_list_t *list, char *email) {
  subscriber_t *current = list->head;
  subscriber_t *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->email, email) == 0) {
      if (previous == NULL) {
        list->head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->email);
      free(current);
      list->size--;
      return;
    }
    previous = current;
    current = current->next;
  }
}

// Send an email to all subscribers on a mailing list
void mailing_list_send_email(mailing_list_t *list, char *subject, char *body) {
  subscriber_t *current = list->head;
  while (current != NULL) {
    // Send the email to the current subscriber
    printf("Sending email to %s\n", current->email);
    current = current->next;
  }
}

// Print the subscribers on a mailing list
void mailing_list_print(mailing_list_t *list) {
  subscriber_t *current = list->head;
  while (current != NULL) {
    printf("%s\n", current->email);
    current = current->next;
  }
}

int main() {
  // Create a new mailing list
  mailing_list_t *list = mailing_list_new();

  // Add some subscribers to the mailing list
  mailing_list_add(list, "alice@example.com");
  mailing_list_add(list, "bob@example.com");
  mailing_list_add(list, "charlie@example.com");

  // Send an email to all subscribers on the mailing list
  mailing_list_send_email(list, "Hello", "This is an email from the mailing list.");

  // Print the subscribers on the mailing list
  printf("Subscribers:\n");
  mailing_list_print(list);

  // Remove a subscriber from the mailing list
  mailing_list_remove(list, "bob@example.com");

  // Print the subscribers on the mailing list
  printf("Subscribers:\n");
  mailing_list_print(list);

  // Free the memory used by the mailing list
  mailing_list_free(list);

  return 0;
}