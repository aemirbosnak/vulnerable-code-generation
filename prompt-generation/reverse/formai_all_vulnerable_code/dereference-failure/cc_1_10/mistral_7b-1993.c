//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber *next;
} Subscriber;

Subscriber *head = NULL;
Subscriber *current = NULL;

void addSubscriber(char *name, char *email) {
    Subscriber *newSubscriber = (Subscriber *) malloc(sizeof(Subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    newSubscriber->next = NULL;

    if (head == NULL) {
        head = newSubscriber;
        current = newSubscriber;
    } else {
        current->next = newSubscriber;
        current = newSubscriber;
    }
}

void displayList() {
    Subscriber *temp = head;

    printf("MailBot Mailing List\n");
    printf("----------------------\n");

    while (temp != NULL) {
        printf("%s <%s>\n", temp->name, temp->email);
        temp = temp->next;
    }
}

void removeSubscriber(char *email) {
    Subscriber *prev = NULL;
    Subscriber *current = head;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    int choice, i;
    char name[50], email[100];

    while (1) {
        printf("\nMailBot Mailing List Manager\n");
        printf("-------------------------------\n");
        printf("1. Add Subscriber\n");
        printf("2. Display List\n");
        printf("3. Remove Subscriber\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addSubscriber(name, email);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter email of subscriber to remove: ");
                scanf("%s", email);
                removeSubscriber(email);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}