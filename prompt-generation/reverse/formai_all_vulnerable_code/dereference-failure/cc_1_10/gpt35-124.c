//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subscriber {
    char name[50];
    char email[50];
    struct subscriber *next;
} Subscriber;

Subscriber *head = NULL;

void add_subscriber() {
    Subscriber *newSubscriber = (Subscriber*)malloc(sizeof(Subscriber));
    printf("Enter subscriber name: ");
    scanf("%s",newSubscriber->name);
    printf("Enter subscriber email: ");
    scanf("%s",newSubscriber->email);
    newSubscriber->next = NULL;
    if (head == NULL) {
        head = newSubscriber;
    } else {
        Subscriber *currentSubscriber = head;
        while (currentSubscriber->next != NULL) {
            currentSubscriber = currentSubscriber->next;
        }
        currentSubscriber->next = newSubscriber;
    }
    printf("Subscriber added successfully.\n\n");
}

void delete_subscriber() {
    char email[50];
    printf("Enter subscriber email to delete: ");
    scanf("%s",email);
    Subscriber *currentSubscriber = head;
    Subscriber *previousSubscriber = NULL;
    while (currentSubscriber != NULL) {
        if (strcmp(currentSubscriber->email,email) == 0) {
            if (previousSubscriber == NULL) {
                head = currentSubscriber->next;
            } else {
                previousSubscriber->next = currentSubscriber->next;
            }
            free(currentSubscriber);
            printf("Subscriber deleted successfully.\n\n");
            return;
        }
        previousSubscriber = currentSubscriber;
        currentSubscriber = currentSubscriber->next;
    }
    printf("Subscriber not found in list.\n\n");
}

void display_subscribers() {
    printf("\n================\nSUBSCRIBER LIST\n================\n\n");
    Subscriber *currentSubscriber = head;
    while (currentSubscriber != NULL) {
        printf("Subscriber Name: %s\n",currentSubscriber->name);
        printf("Subscriber Email: %s\n\n",currentSubscriber->email);
        currentSubscriber = currentSubscriber->next;
    }
}

void main() {
    int choice = 0;
    while (choice != 4) {
        printf("Mailing List Manager\n---------------------\n1. Add Subscriber\n2. Delete Subscriber\n3. Display Subscribers\n4. Quit\n\nWhat would you like to do? ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                delete_subscriber();
                break;
            case 3:
                display_subscribers();
                break;
            case 4:
                printf("\nGoodbye.\n");
                break;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }
}