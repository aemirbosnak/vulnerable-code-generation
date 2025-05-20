//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// The mailing list
typedef struct {
  char *name;
  char *email;
} subscriber;

// The mailing list manager
typedef struct {
  subscriber subscribers[MAX_SUBSCRIBERS];
  int num_subscribers;
  pthread_mutex_t lock;
} mailing_list_manager;

// Create a new mailing list manager
mailing_list_manager *create_mailing_list_manager() {
  mailing_list_manager *manager = malloc(sizeof(mailing_list_manager));
  manager->num_subscribers = 0;
  pthread_mutex_init(&manager->lock, NULL);
  return manager;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list_manager *manager, char *name, char *email) {
  pthread_mutex_lock(&manager->lock);
  if (manager->num_subscribers < MAX_SUBSCRIBERS) {
    manager->subscribers[manager->num_subscribers].name = malloc(strlen(name) + 1);
    strcpy(manager->subscribers[manager->num_subscribers].name, name);
    manager->subscribers[manager->num_subscribers].email = malloc(strlen(email) + 1);
    strcpy(manager->subscribers[manager->num_subscribers].email, email);
    manager->num_subscribers++;
  }
  pthread_mutex_unlock(&manager->lock);
}

// Send an email to all subscribers
void send_email(mailing_list_manager *manager, char *subject, char *body) {
  pthread_mutex_lock(&manager->lock);
  for (int i = 0; i < manager->num_subscribers; i++) {
    // Send the email to the subscriber
    printf("Sending email to %s <%s>\n",
           manager->subscribers[i].name, manager->subscribers[i].email);
  }
  pthread_mutex_unlock(&manager->lock);
}

// Free the memory allocated for the mailing list manager
void free_mailing_list_manager(mailing_list_manager *manager) {
  pthread_mutex_destroy(&manager->lock);
  for (int i = 0; i < manager->num_subscribers; i++) {
    free(manager->subscribers[i].name);
    free(manager->subscribers[i].email);
  }
  free(manager);
}

// Main function
int main() {
  // Create a new mailing list manager
  mailing_list_manager *manager = create_mailing_list_manager();

  // Add some subscribers to the mailing list
  add_subscriber(manager, "John Doe", "john.doe@example.com");
  add_subscriber(manager, "Jane Doe", "jane.doe@example.com");

  // Send an email to all subscribers
  send_email(manager, "Hello", "This is a test email.");

  // Free the memory allocated for the mailing list manager
  free_mailing_list_manager(manager);

  return 0;
}