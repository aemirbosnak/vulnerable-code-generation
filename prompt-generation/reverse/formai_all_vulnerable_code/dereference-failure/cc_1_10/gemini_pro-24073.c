//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 50

// Define the maximum length of an email address
#define MAX_EMAIL_LENGTH 100

// Define the struct for a subscriber
typedef struct {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} subscriber;

// Define the struct for the mailing list
typedef struct {
  int num_subscribers;
  subscriber subscribers[MAX_SUBSCRIBERS];
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
  mailing_list* list = malloc(sizeof(mailing_list));
  list->num_subscribers = 0;
  return list;
}

// Add a subscriber to the mailing list
void add_subscriber(mailing_list* list, char* name, char* email) {
  if (list->num_subscribers == MAX_SUBSCRIBERS) {
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
    printf("Error: The subscriber '%s' is not on the mailing list.\n", name);
    return;
  }

  for (; i < list->num_subscribers - 1; i++) {
    strcpy(list->subscribers[i].name, list->subscribers[i + 1].name);
    strcpy(list->subscribers[i].email, list->subscribers[i + 1].email);
  }

  list->num_subscribers--;
}

// Send an email to all subscribers on the mailing list
void send_email(mailing_list* list, char* subject, char* body) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    printf("Subject: %s\n", subject);
    printf("%s\n", body);
  }
}

// Print the mailing list
void print_mailing_list(mailing_list* list) {
  int i;

  for (i = 0; i < list->num_subscribers; i++) {
    printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
  }
}

// Free the memory used by the mailing list
void free_mailing_list(mailing_list* list) {
  free(list);
}

// Main function
int main() {
  // Create a new mailing list
  mailing_list* list = create_mailing_list();

  // Add some subscribers to the mailing list
  add_subscriber(list, "John Doe", "johndoe@example.com");
  add_subscriber(list, "Jane Doe", "janedoe@example.com");
  add_subscriber(list, "Bill Smith", "billsmith@example.com");

  // Send an email to all subscribers on the mailing list
  send_email(list, "Hello", "This is a test email.");

  // Print the mailing list
  print_mailing_list(list);

  // Remove a subscriber from the mailing list
  remove_subscriber(list, "Jane Doe");

  // Free the memory used by the mailing list
  free_mailing_list(list);

  return 0;
}