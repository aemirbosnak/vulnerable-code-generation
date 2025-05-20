//FormAI DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about subscribers
typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber* next;
} Subscriber;

// Function to add a new subscriber to the list
void addSubscriber(Subscriber** head_ref, char name[], char email[]) {
    // Allocate memory for the new subscriber
    Subscriber* new_subscriber = (Subscriber*) malloc(sizeof(Subscriber));

    // Copy the subscriber information
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);

    // Set the next pointer to NULL
    new_subscriber->next = NULL;

    // If the list is empty, set the head to the new subscriber
    if (*head_ref == NULL) {
        *head_ref = new_subscriber;
        return;
    }

    // Otherwise, traverse the list to the end and add the new subscriber
    Subscriber* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_subscriber;
}

// Function to print all the subscribers in the list
void printSubscribers(Subscriber* head) {
    printf("Subscriber List:\n");

    // Traverse the list and print each subscriber
    Subscriber* current = head;
    while (current != NULL) {
        printf("Name: %s\nEmail: %s\n\n", current->name, current->email);
        current = current->next;
    }
}

// Function to remove a subscriber from the list
void removeSubscriber(Subscriber** head_ref, char email[]) {
    // If the list is empty, there is nothing to remove
    if (*head_ref == NULL) {
        return;
    }

    // If the subscriber to remove is at the head of the list, update the head
    if (strcmp((*head_ref)->email, email) == 0) {
        Subscriber* current = *head_ref;
        *head_ref = current->next;
        free(current);
        return;
    }

    // Otherwise, traverse the list to find the subscriber to remove
    Subscriber* current = *head_ref;
    while (current->next != NULL) {
        if (strcmp(current->next->email, email) == 0) {
            Subscriber* to_remove = current->next;
            current->next = to_remove->next;
            free(to_remove);
            return;
        }
        current = current->next;
    }
}

int main() {
    // Initialize the list to be empty
    Subscriber* head = NULL;

    // Add some subscribers to the list
    addSubscriber(&head, "Mary Smith", "marysmith@example.com");
    addSubscriber(&head, "John Doe", "johndoe@example.com");

    // Print the current list of subscribers
    printSubscribers(head);

    // Remove a subscriber from the list
    removeSubscriber(&head, "johndoe@example.com");

    // Print the updated list of subscribers
    printSubscribers(head);

    // Clean up memory by removing remaining subscribers in the list
    while (head != NULL) {
        Subscriber* current = head;
        head = current->next;
        free(current);
    }

    return 0;
}