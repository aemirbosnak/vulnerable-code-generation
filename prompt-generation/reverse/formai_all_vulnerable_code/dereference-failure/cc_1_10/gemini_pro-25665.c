//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A surrealist mailing list manager

// The list of subscribers
struct subscriber {
  char *name;
  char *email;
};

// The list of subscribers
struct mailing_list {
  struct subscriber *subscribers;
  int num_subscribers;
};

// Create a new mailing list
struct mailing_list *create_mailing_list() {
  struct mailing_list *list = malloc(sizeof(struct mailing_list));
  list->subscribers = NULL;
  list->num_subscribers = 0;
  return list;
}

// Add a subscriber to the list
void add_subscriber(struct mailing_list *list, char *name, char *email) {
  struct subscriber *new_subscriber = malloc(sizeof(struct subscriber));
  new_subscriber->name = strdup(name);
  new_subscriber->email = strdup(email);
  list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(struct subscriber));
  list->subscribers[list->num_subscribers++] = *new_subscriber;
}

// Remove a subscriber from the list
void remove_subscriber(struct mailing_list *list, char *name) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      free(list->subscribers[i].name);
      free(list->subscribers[i].email);
      list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
      list->num_subscribers--;
      break;
    }
  }
}

// Send a message to all subscribers
void send_message(struct mailing_list *list, char *message) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    printf("From: Surrealist Mailing List <surrealist@example.com>\n");
    printf("Subject: Surrealist Message\n");
    printf("\n");
    printf("%s\n", message);
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
  }
}

// Free the mailing list
void free_mailing_list(struct mailing_list *list) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    free(list->subscribers[i].name);
    free(list->subscribers[i].email);
  }
  free(list->subscribers);
  free(list);
}

// The main function
int main() {
  // Create a new mailing list
  struct mailing_list *list = create_mailing_list();

  // Add some subscribers to the list
  add_subscriber(list, "Alice", "alice@example.com");
  add_subscriber(list, "Bob", "bob@example.com");
  add_subscriber(list, "Carol", "carol@example.com");

  // Send a message to all subscribers
  send_message(list, "Hello, subscribers!\n\nThis is a surrealist message.\n\nPlease enjoy.");

  // Free the mailing list
  free_mailing_list(list);

  return 0;
}