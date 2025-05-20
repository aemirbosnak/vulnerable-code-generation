//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 20

// Define the maximum length of an email address
#define MAX_EMAIL_LENGTH 50

// Define the structure of a subscriber
typedef struct {
  int id;
  char name[MAX_NAME_LENGTH + 1];
  char email[MAX_EMAIL_LENGTH + 1];
  struct subscriber *next;
} subscriber_t;

// Define the head of the mailing list
subscriber_t *head = NULL;

// Define the tail of the mailing list
subscriber_t *tail = NULL;

// Function to add a subscriber to the mailing list
void add_subscriber(int id, char *name, char *email) {
  // Create a new subscriber
  subscriber_t *new_subscriber = malloc(sizeof(subscriber_t));

  // Set the subscriber's id
  new_subscriber->id = id;

  // Copy the subscriber's name
  strncpy(new_subscriber->name, name, MAX_NAME_LENGTH);

  // Copy the subscriber's email
  strncpy(new_subscriber->email, email, MAX_EMAIL_LENGTH);

  // Add the subscriber to the mailing list
  if (head == NULL) {
    head = new_subscriber;
    tail = new_subscriber;
  } else {
    tail->next = new_subscriber;
    tail = new_subscriber;
  }
}

// Function to remove a subscriber from the mailing list
void remove_subscriber(int id) {
  // Find the subscriber to be removed
  subscriber_t *current = head;
  while (current != NULL && current->id != id) {
    current = current->next;
  }

  // If the subscriber was found, remove it from the mailing list
  if (current != NULL) {
    if (current == head) {
      head = current->next;
    } else if (current == tail) {
      tail = current->next;
    } else {
      subscriber_t *previous = head;
      while (previous->next != current) {
        previous = previous->next;
      }
      previous->next = current->next;
    }

    // Free the subscriber's memory
    free(current);
  }
}

// Function to send a message to all subscribers
void send_message(char *subject, char *body) {
  // Iterate over the subscribers
  subscriber_t *current = head;
  while (current != NULL) {
    // Send the message to the subscriber
    printf("To: %s <%s>\n", current->name, current->email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n\n", body);

    // Advance to the next subscriber
    current = current->next;
  }
}

// Function to print the mailing list
void print_mailing_list() {
  // Iterate over the subscribers
  subscriber_t *current = head;
  while (current != NULL) {
    // Print the subscriber's information
    printf("ID: %d\n", current->id);
    printf("Name: %s\n", current->name);
    printf("Email: %s\n\n", current->email);

    // Advance to the next subscriber
    current = current->next;
  }
}

// Main function
int main() {
  // Add some subscribers to the mailing list
  add_subscriber(1, "John Doe", "john.doe@example.com");
  add_subscriber(2, "Jane Smith", "jane.smith@example.com");
  add_subscriber(3, "Bill Jones", "bill.jones@example.com");

  // Print the mailing list
  print_mailing_list();

  // Send a message to the subscribers
  send_message("Hello, subscribers!", "This is a test message.");

  // Remove a subscriber from the mailing list
  remove_subscriber(2);

  // Print the mailing list
  print_mailing_list();

  return 0;
}