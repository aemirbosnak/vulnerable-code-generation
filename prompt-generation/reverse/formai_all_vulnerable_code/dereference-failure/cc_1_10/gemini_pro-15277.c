//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers and the maximum length of a subscriber's email address
#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100

// Define the structure of a subscriber
typedef struct subscriber {
  char email[MAX_EMAIL_LENGTH];
  int subscribed;
} subscriber;

// Define the structure of the mailing list
typedef struct mailing_list {
  subscriber subscribers[MAX_SUBSCRIBERS];
  int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
  mailing_list* list = malloc(sizeof(mailing_list));
  list->num_subscribers = 0;
  return list;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list* list, char* email) {
  if (list->num_subscribers < MAX_SUBSCRIBERS) {
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = 1;
    list->num_subscribers++;
  } else {
    printf("Error: Maximum number of subscribers reached.\n");
  }
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list* list, char* email) {
  for (int i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].email, email) == 0) {
      list->subscribers[i].subscribed = 0;
      break;
    }
  }
}

// Send a message to all subscribers on the mailing list
void send_message(mailing_list* list, char* message) {
  for (int i = 0; i < list->num_subscribers; i++) {
    if (list->subscribers[i].subscribed) {
      printf("Sending message to %s: %s\n", list->subscribers[i].email, message);
    }
  }
}

// Print the list of subscribers on the mailing list
void print_subscribers(mailing_list* list) {
  for (int i = 0; i < list->num_subscribers; i++) {
    printf("%s\n", list->subscribers[i].email);
  }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list* list) {
  free(list);
}

// Main function
int main() {
  // Create a new mailing list
  mailing_list* list = create_mailing_list();

  // Add some subscribers to the mailing list
  add_subscriber(list, "john@example.com");
  add_subscriber(list, "mary@example.com");
  add_subscriber(list, "bob@example.com");

  // Send a message to all subscribers on the mailing list
  send_message(list, "Hello, subscribers!");

  // Remove a subscriber from the mailing list
  remove_subscriber(list, "bob@example.com");

  // Print the list of subscribers on the mailing list
  print_subscribers(list);

  // Free the memory allocated for the mailing list
  free_mailing_list(list);

  return 0;
}