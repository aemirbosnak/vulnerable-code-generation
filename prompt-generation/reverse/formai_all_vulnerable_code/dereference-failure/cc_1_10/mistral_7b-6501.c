//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100

typedef struct Subscriber {
    char name[50];
    char email[100];
    bool isSubscribed;
    struct Subscriber *next;
} Subscriber;

Subscriber *head = NULL;
Subscriber *current = NULL;

void addSubscriber(char *name, char *email) {
    Subscriber *newSubscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    newSubscriber->isSubscribed = true;
    newSubscriber->next = NULL;

    if (head == NULL) {
        head = newSubscriber;
        current = newSubscriber;
    } else {
        current->next = newSubscriber;
        current = newSubscriber;
    }

    if (MAX_SUBSCRIBERS == head->next - head) {
        printf("Error: Mailing list is full.\n");
        free(newSubscriber);
    }
}

void removeSubscriber(char *email) {
    Subscriber *previous = NULL;
    Subscriber *temp = head;

    while (temp != NULL && strcmp(temp->email, email) != 0) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: Subscriber not found.\n");
        return;
    }

    if (previous == NULL) {
        head = temp->next;
    } else {
        previous->next = temp->next;
    }

    free(temp);
}

void printSubscribers() {
    Subscriber *temp = head;

    printf("\nMailing List:\n");
    while (temp != NULL) {
        printf("%s (%s)\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main() {
    char name[50];
    char email[100];
    char command[20];

    while (1) {
        printf("\nMailBuddies v1.0.0\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Print Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addSubscriber(name, email);
                break;
            case '2':
                printf("Enter email of subscriber to remove: ");
                scanf("%s", email);
                removeSubscriber(email);
                break;
            case '3':
                printSubscribers();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}