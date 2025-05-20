//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 1000
#define EMAIL_SIZE 100

typedef struct Subscriber {
    char name[50];
    char email[EMAIL_SIZE];
    struct Subscriber *next;
} Subscriber;

Subscriber *head = NULL;
Subscriber *current = NULL;

void add_subscriber(char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    if (head == NULL) {
        head = new_subscriber;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_subscriber;
    }
}

void remove_subscriber(char *email) {
    Subscriber *temp = head;
    Subscriber *previous = NULL;

    if (head != NULL && strcmp(head->email, email) == 0) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->email, email) != 0) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Subscriber not found.\n");
        return;
    }

    previous->next = temp->next;
    free(temp);
}

void print_list() {
    Subscriber *temp = head;

    printf("\nMailing List:\n");
    while (temp != NULL) {
        printf("%s (%s)\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main() {
    int choice, i;
    char name[50], email[EMAIL_SIZE];

    while (1) {
        printf("\n1. Add Subscriber\n2. Remove Subscriber\n3. Print List\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;
            case 2:
                printf("Enter Email of the Subscriber to be removed: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;
            case 3:
                print_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}