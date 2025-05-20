//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each subscriber
typedef struct Subscriber {
    char email[100];
    struct Subscriber *next;
} Subscriber;

// Define a struct for the mailing list
typedef struct MailingList {
    Subscriber *head;
    int count;
} MailingList;

// Function to create a new mailing list
MailingList* createMailingList() {
    MailingList *list = (MailingList*)malloc(sizeof(MailingList));
    list->head = NULL;
    list->count = 0;
    return list;
}

// Function to create a new subscriber
Subscriber* createSubscriber(const char *email) {
    Subscriber *newSubscriber = (Subscriber*)malloc(sizeof(Subscriber));
    strncpy(newSubscriber->email, email, 99);
    newSubscriber->email[99] = '\0'; // Ensure the string is null-terminated
    newSubscriber->next = NULL;
    return newSubscriber;
}

// Function to add a subscriber to the mailing list
void addSubscriber(MailingList *list, const char *email) {
    Subscriber *newSubscriber = createSubscriber(email);
    newSubscriber->next = list->head;
    list->head = newSubscriber;
    list->count++;
    printf("Added: %s\n", email);
}

// Function to remove a subscriber from the mailing list
void removeSubscriber(MailingList *list, const char *email) {
    Subscriber *current = list->head;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next; // Removing the head
            } else {
                previous->next = current->next; // Bypass current
            }
            free(current);
            list->count--;
            printf("Removed: %s\n", email);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Email not found: %s\n", email);
}

// Function to list all subscribers
void listSubscribers(MailingList *list) {
    Subscriber *current = list->head;
    printf("Current Subscribers:\n");
    
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
    if (list->count == 0) {
        printf("No subscribers in the list.\n");
    }
}

// Function to free the mailing list
void freeMailingList(MailingList *list) {
    Subscriber *current = list->head;
    Subscriber *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Main function for menu interface
int main() {
    MailingList *list = createMailingList();
    char command[10];
    char email[100];

    printf("Welcome to the C Mailing List Manager!\n");

    while (1) {
        printf("\nCommands: add <email>, remove <email>, list, quit\n");
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            addSubscriber(list, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            removeSubscriber(list, email);
        } else if (strcmp(command, "list") == 0) {
            listSubscribers(list);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    freeMailingList(list);
    printf("Exiting the Mailing List Manager. Goodbye!\n");
    
    return 0;
}