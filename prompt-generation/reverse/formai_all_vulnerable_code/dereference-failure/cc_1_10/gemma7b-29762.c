//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 20

// Define the structure of a subscriber
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    struct subscriber* next;
} subscriber;

// Function to add a subscriber to the list
subscriber* addSubscriber(subscriber* head, char* name) {
    // Allocate memory for the new subscriber
    subscriber* newSubscriber = malloc(sizeof(subscriber));

    // Copy the subscriber's name into the new subscriber
    strcpy(newSubscriber->name, name);

    // Set the new subscriber's next pointer to NULL
    newSubscriber->next = NULL;

    // If the list is empty, make the new subscriber the head of the list
    if (head == NULL) {
        head = newSubscriber;
    } else {
        // Traverse the list until the last subscriber is reached
        subscriber* currentSubscriber = head;
        while (currentSubscriber->next != NULL) {
            currentSubscriber = currentSubscriber->next;
        }

        // Add the new subscriber to the end of the list
        currentSubscriber->next = newSubscriber;
    }

    // Return the head of the list
    return head;
}

// Function to remove a subscriber from the list
subscriber* removeSubscriber(subscriber* head, char* name) {
    // Traverse the list to find the subscriber to remove
    subscriber* previousSubscriber = NULL;
    subscriber* currentSubscriber = head;
    while (currentSubscriber && strstr(currentSubscriber->name, name) != NULL) {
        previousSubscriber = currentSubscriber;
        currentSubscriber = currentSubscriber->next;
    }

    // If the subscriber is found, remove the subscriber from the list
    if (previousSubscriber) {
        previousSubscriber->next = currentSubscriber->next;
        free(currentSubscriber);
    }

    // Return the head of the list
    return head;
}

// Function to print the list of subscribers
void printSubscribers(subscriber* head) {
    // Traverse the list of subscribers
    subscriber* currentSubscriber = head;
    while (currentSubscriber) {
        printf("%s\n", currentSubscriber->name);
        currentSubscriber = currentSubscriber->next;
    }
}

int main() {
    // Create a list of subscribers
    subscriber* head = NULL;

    // Add some subscribers to the list
    addSubscriber(head, "Romeo");
    addSubscriber(head, "Juliet");
    addSubscriber(head, "Mercutio");
    addSubscriber(head, "Benvolio");

    // Print the list of subscribers
    printSubscribers(head);

    // Remove some subscribers from the list
    removeSubscriber(head, "Mercutio");
    removeSubscriber(head, "Benvolio");

    // Print the list of subscribers after removing subscribers
    printSubscribers(head);

    return 0;
}