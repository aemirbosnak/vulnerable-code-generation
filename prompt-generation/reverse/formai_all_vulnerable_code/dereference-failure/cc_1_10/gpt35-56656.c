//FormAI DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char email[50];
    struct Node* next;
};

struct Node* createNode(char email[]) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

void addSubscriber(struct Node** head, char email[]) {
    struct Node* newNode = createNode(email);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Subscriber added: %s\n", email);
}

void removeSubscriber(struct Node** head, char email[]) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            found = 1;
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Subscriber removed: %s\n", email);
            break;
        }
        prev = current;
        current = current->next;
    }
    if (!found) {
        printf("Subscriber not found: %s\n", email);
    }
}

void printSubscribers(struct Node* head) {
    printf("Mailing list subscribers:\n");
    while (head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    int option;
    char email[50];
    do {
        printf("\nMailing list manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. View subscribers\n");
        printf("4. Exit\n");
        printf("Enter option (1-4): ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                addSubscriber(&head, email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                removeSubscriber(&head, email);
                break;
            case 3:
                printSubscribers(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 4);
    return 0;
}