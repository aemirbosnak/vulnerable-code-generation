//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct {
    char name[50];
    char email[50];
} subscriber;

// Define the structure of the mailing list
typedef struct {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list *new_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list *list, char *name) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
            list->num_subscribers--;
            return;
        }
    }
    printf("Error: Subscriber not found.\n");
}

// Send an email to all subscribers on the mailing list
void send_email(mailing_list *list, char *subject, char *body) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);
    }
}

// Print the mailing list
void print_mailing_list(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list *list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = new_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "johndoe@example.com");
    add_subscriber(list, "Jane Smith", "janesmith@example.com");
    add_subscriber(list, "Bob Jones", "bobjones@example.com");

    // Print the mailing list
    printf("Mailing List:\n");
    print_mailing_list(list);

    // Send an email to all subscribers on the mailing list
    send_email(list, "Hello from the mailing list!", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "Bob Jones");

    // Print the mailing list again
    printf("\nMailing List (after removing Bob Jones):\n");
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}