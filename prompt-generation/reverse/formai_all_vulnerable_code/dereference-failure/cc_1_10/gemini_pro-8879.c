//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAILING_LISTS 100
#define MAX_SUBSCRIBERS 1000

// A mailing list has a name and a list of subscribers
typedef struct mailing_list {
    char name[50];
    int num_subscribers;
    char subscribers[MAX_SUBSCRIBERS][50];
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list(char *name) {
    mailing_list *list = malloc(sizeof(mailing_list));
    strcpy(list->name, name);
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to a mailing list
void add_subscriber(mailing_list *list, char *subscriber) {
    strcpy(list->subscribers[list->num_subscribers], subscriber);
    list->num_subscribers++;
}

// Remove a subscriber from a mailing list
void remove_subscriber(mailing_list *list, char *subscriber) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i], subscriber) == 0) {
            list->num_subscribers--;
            for (; i < list->num_subscribers; i++) {
                strcpy(list->subscribers[i], list->subscribers[i + 1]);
            }
            break;
        }
    }
}

// Print the subscribers of a mailing list
void print_subscribers(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s\n", list->subscribers[i]);
    }
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list("My Mailing List");

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe");
    add_subscriber(list, "Jane Doe");
    add_subscriber(list, "Bill Smith");

    // Print the subscribers of the mailing list
    print_subscribers(list);

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "John Doe");

    // Print the subscribers of the mailing list
    print_subscribers(list);

    return 0;
}