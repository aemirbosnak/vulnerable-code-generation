//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a name
#define MAX_NAME 30

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
  char name[MAX_NAME];
  char email[MAX_NAME];
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
void add_subscriber(mailing_list* list, char* name, char* email) {
  if (list->num_subscribers >= MAX_SUBSCRIBERS) {
    printf("Error: The mailing list is full.\n");
    return;
  }

  strcpy(list->subscribers[list->num_subscribers].name, name);
  strcpy(list->subscribers[list->num_subscribers].email, email);
  list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list* list, char* name) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      break;
    }
  }

  if (i == list->num_subscribers) {
    printf("Error: The subscriber '%s' was not found.\n", name);
    return;
  }

  // Shift the subscribers down to fill the gap
  for (i++; i < list->num_subscribers; i++) {
    strcpy(list->subscribers[i - 1].name, list->subscribers[i].name);
    strcpy(list->subscribers[i - 1].email, list->subscribers[i].email);
  }

  list->num_subscribers--;
}

// Send a message to all subscribers
void send_message(mailing_list* list, char* message) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    printf("From: The Mailing List <mailing-list@example.com>\n");
    printf("Subject: %s\n\n", message);
  }
}

// Print the mailing list
void print_mailing_list(mailing_list* list) {
  int i;

  printf("Mailing List:\n");
  for (i = 0; i < list->num_subscribers; i++) {
    printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
  }
}

// Main function
int main() {
  // Create a new mailing list
  mailing_list* list = create_mailing_list();

  // Add some subscribers to the mailing list
  add_subscriber(list, "John Doe", "johndoe@example.com");
  add_subscriber(list, "Jane Doe", "janedoe@example.com");
  add_subscriber(list, "John Smith", "johnsmith@example.com");

  // Print the mailing list
  print_mailing_list(list);

  // Send a message to all subscribers
  send_message(list, "Greetings, fair subscribers!");

  // Remove a subscriber from the mailing list
  remove_subscriber(list, "John Smith");

  // Print the mailing list again
  print_mailing_list(list);

  return 0;
}