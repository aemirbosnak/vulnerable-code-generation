//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
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

// Define the structure of a mailing list
typedef struct {
    int num_subscribers;
    subscriber subscribers[MAX_SUBSCRIBERS];
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to a mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    if (list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(list->subscribers[list->num_subscribers].name, name);
        strcpy(list->subscribers[list->num_subscribers].email, email);
        list->num_subscribers++;
    } else {
        printf("Error: Mailing list is full.\n");
    }
}

// Remove a subscriber from a mailing list
void remove_subscriber(mailing_list *list, char *name) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            list->num_subscribers--;
            for (int j = i; j < list->num_subscribers; j++) {
                strcpy(list->subscribers[j].name, list->subscribers[j + 1].name);
                strcpy(list->subscribers[j].email, list->subscribers[j + 1].email);
            }
            break;
        }
    }
}

// Send a message to all subscribers on a mailing list
void send_message(mailing_list *list, char *message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("From: Romeo Montague <romeo@montague.com>\n");
        printf("Subject: %s\n\n", message);
        printf("%s\n\n", message);
    }
}

// Print the subscribers on a mailing list
void print_subscribers(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory allocated for a mailing list
void free_mailing_list(mailing_list *list) {
    free(list);
}

int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "Romeo Montague", "romeo@montague.com");
    add_subscriber(list, "Juliet Capulet", "juliet@capulet.com");
    add_subscriber(list, "Tybalt Capulet", "tybalt@capulet.com");
    add_subscriber(list, "Mercutio Montague", "mercutio@montague.com");
    add_subscriber(list, "Benvolio Montague", "benvolio@montague.com");

    // Print the subscribers on the mailing list
    printf("Subscribers:\n");
    print_subscribers(list);

    // Send a message to all subscribers on the mailing list
    printf("\nMessage:\n");
    send_message(list, "My dearest Juliet,");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "Tybalt Capulet");

    // Print the subscribers on the mailing list
    printf("\nSubscribers after removing Tybalt:\n");
    print_subscribers(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}