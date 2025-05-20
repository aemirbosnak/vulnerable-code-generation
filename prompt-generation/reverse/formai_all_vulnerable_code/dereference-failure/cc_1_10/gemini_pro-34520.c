//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a subscriber
typedef struct subscriber {
  char *email;
  struct subscriber *next;
} subscriber_t;

// Structure to represent a mailing list
typedef struct mailing_list {
  char *name;
  subscriber_t *subscribers;
  int subscriber_count;
} mailing_list_t;

// Function to create a new subscriber
subscriber_t *create_subscriber(char *email) {
  subscriber_t *new_subscriber = malloc(sizeof(subscriber_t));
  new_subscriber->email = strdup(email);
  new_subscriber->next = NULL;
  return new_subscriber;
}

// Function to add a subscriber to a mailing list
void add_subscriber(mailing_list_t *list, subscriber_t *subscriber) {
  if (list->subscribers == NULL) {
    list->subscribers = subscriber;
  } else {
    subscriber_t *current_subscriber = list->subscribers;
    while (current_subscriber->next != NULL) {
      current_subscriber = current_subscriber->next;
    }
    current_subscriber->next = subscriber;
  }
  list->subscriber_count++;
}

// Function to remove a subscriber from a mailing list
void remove_subscriber(mailing_list_t *list, subscriber_t *subscriber) {
  if (list->subscribers == subscriber) {
    list->subscribers = subscriber->next;
  } else {
    subscriber_t *current_subscriber = list->subscribers;
    while (current_subscriber->next != subscriber) {
      current_subscriber = current_subscriber->next;
    }
    current_subscriber->next = subscriber->next;
  }
  list->subscriber_count--;
  free(subscriber->email);
  free(subscriber);
}

// Function to send an email to all subscribers on a mailing list
void send_email(mailing_list_t *list, char *subject, char *body) {
  subscriber_t *current_subscriber = list->subscribers;
  while (current_subscriber != NULL) {
    // Send the email to the current subscriber
    printf("Sending email to %s\n", current_subscriber->email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
    printf("-----------------------------------------\n");
    current_subscriber = current_subscriber->next;
  }
}

// Function to print the subscribers on a mailing list
void print_subscribers(mailing_list_t *list) {
  subscriber_t *current_subscriber = list->subscribers;
  while (current_subscriber != NULL) {
    printf("%s\n", current_subscriber->email);
    current_subscriber = current_subscriber->next;
  }
}

// Function to create a new mailing list
mailing_list_t *create_mailing_list(char *name) {
  mailing_list_t *new_mailing_list = malloc(sizeof(mailing_list_t));
  new_mailing_list->name = strdup(name);
  new_mailing_list->subscribers = NULL;
  new_mailing_list->subscriber_count = 0;
  return new_mailing_list;
}

// Function to free the memory allocated for a mailing list
void free_mailing_list(mailing_list_t *list) {
  subscriber_t *current_subscriber = list->subscribers;
  while (current_subscriber != NULL) {
    subscriber_t *next_subscriber = current_subscriber->next;
    free(current_subscriber->email);
    free(current_subscriber);
    current_subscriber = next_subscriber;
  }
  free(list->name);
  free(list);
}

// Main function
int main() {
  // Create a new mailing list
  mailing_list_t *list = create_mailing_list("My Mailing List");

  // Add some subscribers to the mailing list
  add_subscriber(list, create_subscriber("john@example.com"));
  add_subscriber(list, create_subscriber("jane@example.com"));
  add_subscriber(list, create_subscriber("bob@example.com"));

  // Print the subscribers on the mailing list
  printf("Subscribers on the mailing list:\n");
  print_subscribers(list);

  // Send an email to all subscribers on the mailing list
  send_email(list, "Hello from the mailing list!", "This is a test email.");

  // Remove a subscriber from the mailing list
  remove_subscriber(list, create_subscriber("bob@example.com"));

  // Print the subscribers on the mailing list
  printf("Subscribers on the mailing list after removing bob@example.com:\n");
  print_subscribers(list);

  // Free the memory allocated for the mailing list
  free_mailing_list(list);

  return 0;
}