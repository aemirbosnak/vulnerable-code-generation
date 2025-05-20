//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 50
#define SUBSCRIBER_EMAIL_LENGTH 100

typedef struct Subscriber {
    char name[SUBSCRIBER_NAME_LENGTH];
    char email[SUBSCRIBER_EMAIL_LENGTH];
    struct Subscriber *next;
} Subscriber;

Subscriber *subscribers = NULL;
Subscriber *current = NULL;
Subscriber *new_subscriber = NULL;

void add_subscriber() {
    new_subscriber = (Subscriber*)malloc(sizeof(Subscriber));
    printf("Enter name: ");
    scanf("%s", new_subscriber->name);
    printf("Enter email: ");
    scanf("%s", new_subscriber->email);

    new_subscriber->next = NULL;

    if (subscribers == NULL) {
        subscribers = new_subscriber;
        current = subscribers;
    } else {
        current->next = new_subscriber;
        current = new_subscriber;
    }

    printf("Subscriber added successfully.\n");
}

void remove_subscriber() {
    char name[SUBSCRIBER_NAME_LENGTH];
    bool found = false;

    if (subscribers == NULL) {
        printf("No subscribers to remove.\n");
        return;
    }

    printf("Enter name of subscriber to remove: ");
    scanf("%s", name);

    current = subscribers;

    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Subscriber not found.\n");
        return;
    }

    if (current == subscribers) {
        subscribers = subscribers->next;
    } else {
        Subscriber *previous = subscribers;

        while (previous->next != current) {
            previous = previous->next;
        }

        previous->next = current->next;
    }

    free(current);
    printf("Subscriber removed successfully.\n");
}

void display_subscribers() {
    if (subscribers == NULL) {
        printf("No subscribers.\n");
        return;
    }

    current = subscribers;

    printf("\nSubscribers:\n");

    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    int choice;

    while (true) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Display subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                remove_subscriber();
                break;
            case 3:
                display_subscribers();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}