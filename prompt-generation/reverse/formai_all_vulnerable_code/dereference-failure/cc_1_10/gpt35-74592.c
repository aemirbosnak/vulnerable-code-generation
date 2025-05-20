//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} node;

node* head = NULL;

void addSubscriber(char email[]) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("%s added to the mailing list!\n", email);
}

void removeSubscriber(char email[]) {
    if (head == NULL) {
        printf("Mailing list is empty!\n");
        return;
    }

    if (strcmp(head->email, email) == 0) {
        node* temp = head;
        head = head->next;
        free(temp);
        printf("%s removed from the mailing list!\n", email);
        return;
    }

    node* current = head->next;
    node* previous = head;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%s is not a subscriber!\n", email);
    } else {
        previous->next = current->next;
        free(current);
        printf("%s removed from the mailing list!\n", email);
    }
}

void printList() {
    int count = 0;
    node* current = head;

    while (current != NULL) {
        printf("%d. %s\n", ++count, current->email);
        current = current->next;
    }

    if (count == 0) {
        printf("Mailing list is empty!\n");
    } else {
        printf("Total subscribers: %d\n", count);
    }
}

int main() {
    int option;
    char email[50];

    printf("Welcome to the mailing list manager!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. View mailing list\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter email address: ");
                scanf("%s", email);
                addSubscriber(email);
                break;
            case 2:
                printf("Enter email address: ");
                scanf("%s", email);
                removeSubscriber(email);
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Thank you for using the mailing list manager!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 4);

    return 0;
}