//FormAI DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for a subscriber's info
typedef struct subscriber {
    char name[50];
    char email[100];
    struct subscriber *next;
} Subscriber;

//Function to add a new subscriber to the list
void addSubscriber(Subscriber **head) {
    Subscriber *newSubscriber = malloc(sizeof(Subscriber));
    printf("\nEnter name: ");
    scanf("%s", newSubscriber->name);
    printf("Enter email: ");
    scanf("%s", newSubscriber->email);
    newSubscriber->next = *head;
    *head = newSubscriber;
    printf("Successfully added new subscriber!");
}

//Function to print the current list of subscribers
void printSubscribers(Subscriber *head) {
    printf("\n---------------SUBSCRIBERS---------------\n");
    while (head != NULL) {
        printf("Name: %s\n", head->name);
        printf("Email: %s\n\n", head->email);
        head = head->next;
    }
}

//Function to search for a subscriber by their email
void searchSubscriber(Subscriber *head) {
    char email[100];
    printf("\nEnter email to search for: ");
    scanf("%s", email);
    while (head != NULL) {
        if (strcmp(head->email, email) == 0) {
            printf("\n---------------SUBSCRIBER FOUND---------------\n");
            printf("Name: %s\n", head->name);
            printf("Email: %s\n\n", head->email);
            return;
        }
        head = head->next;
    }
    printf("\nSubscriber not found!\n");
}

//Function to remove a subscriber from the list
void removeSubscriber(Subscriber **head) {
    char email[100];
    printf("\nEnter email to remove: ");
    scanf("%s", email);
    Subscriber *currentSubscriber = *head;
    Subscriber *previousSubscriber = NULL;
    while (currentSubscriber != NULL) {
        if (strcmp(currentSubscriber->email, email) == 0) {
            if (previousSubscriber == NULL) {
                *head = currentSubscriber->next;
            } else {
                previousSubscriber->next = currentSubscriber->next;
            }
            free(currentSubscriber);
            printf("\nSubscriber successfully removed!\n");
            return;
        }
        previousSubscriber = currentSubscriber;
        currentSubscriber = currentSubscriber->next;
    }
    printf("\nSubscriber not found!\n");
}

int main() {
    Subscriber *head = NULL;
    int choice;
    do {
        printf("\n---------------MAILING LIST MANAGER---------------\n");
        printf("1. Add subscriber\n");
        printf("2. Print subscribers\n");
        printf("3. Search subscriber\n");
        printf("4. Remove subscriber\n");
        printf("0. Exit\n");
        printf("--------------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSubscriber(&head);
                break;
            case 2:
                printSubscribers(head);
                break;
            case 3:
                searchSubscriber(head);
                break;
            case 4:
                removeSubscriber(&head);
                break;
            case 0:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}