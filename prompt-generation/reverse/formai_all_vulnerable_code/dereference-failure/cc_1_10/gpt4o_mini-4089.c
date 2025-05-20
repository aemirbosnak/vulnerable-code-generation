//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node to represent each subscriber
typedef struct Subscriber {
    char email[100];
    struct Subscriber *next;
} Subscriber;

// Node to represent the mailing list
typedef struct MailingList {
    Subscriber *head;
    int count;
} MailingList;

// Function prototypes
MailingList* createMailingList();
int addSubscriber(MailingList *list, const char *email);
int removeSubscriber(MailingList *list, const char *email);
void displaySubscribers(const MailingList *list);
void sendMessage(const MailingList *list, const char *message);
void freeMailingList(MailingList *list);

// Main function
int main() {
    MailingList *list = createMailingList();
    int choice;
    char email[100];
    char message[256];
    
    // Futuristic user interface
    printf("Welcome to the Galactic Mailing List Manager!\n");
    
    do {
        printf("\nSelect an option:\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Display subscribers\n");
        printf("4. Send message\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                if (addSubscriber(list, email)) {
                    printf("Subscriber added successfully.\n");
                } else {
                    printf("Failed to add subscriber. Email may already exist.\n");
                }
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                if (removeSubscriber(list, email)) {
                    printf("Subscriber removed successfully.\n");
                } else {
                    printf("Subscriber not found.\n");
                }
                break;
            case 3:
                printf("Current subscribers:\n");
                displaySubscribers(list);
                break;
            case 4:
                printf("Enter your message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                sendMessage(list, message);
                break;
            case 5:
                printf("Exiting the Galactic Mailing List Manager...\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 5);
    
    freeMailingList(list);
    return 0;
}

// Create a new mailing list
MailingList* createMailingList() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->head = NULL;
    list->count = 0;
    return list;
}

// Add subscriber to the list
int addSubscriber(MailingList *list, const char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    // Check for duplicates
    Subscriber *current = list->head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            free(new_subscriber);
            return 0;
        }
        current = current->next;
    }

    // Add new subscriber at the head
    new_subscriber->next = list->head;
    list->head = new_subscriber;
    list->count++;
    return 1;
}

// Remove subscriber from the list
int removeSubscriber(MailingList *list, const char *email) {
    Subscriber *current = list->head;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next; // remove head
            } else {
                previous->next = current->next; // unlink current
            }
            free(current);
            list->count--;
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0; // Not found
}

// Display all subscribers
void displaySubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers.\n");
        return;
    }
    Subscriber *current = list->head;
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

// Send message to all subscribers
void sendMessage(const MailingList *list, const char *message) {
    if (list->count == 0) {
        printf("No subscribers to send the message.\n");
        return;
    }
    printf("Sending message to all subscribers:\n%s\n", message);
    // In real application, you'd send the email here
}

// Free mailing list and subscribers
void freeMailingList(MailingList *list) {
    Subscriber *current = list->head;
    while (current != NULL) {
        Subscriber *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}