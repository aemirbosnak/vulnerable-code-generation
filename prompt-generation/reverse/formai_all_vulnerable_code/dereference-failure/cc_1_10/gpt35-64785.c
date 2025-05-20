//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

void add_email(Node** head, char* email) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    Node* curr = head;
    while (curr != NULL) {
        printf("%s\n", curr->email);
        curr = curr->next;
    }
}

void delete_email(Node** head, char* email) {
    Node* curr = *head;
    Node* prev = NULL;

    while (curr != NULL && strcmp(curr->email, email) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("The email %s does not exist in the list!\n", email);
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
}

int main() {
    Node* head = NULL;
    int choice;
    char email[50];

    do {
        printf("Menu:\n");
        printf("1 - Add email to list\n");
        printf("2 - Print list\n");
        printf("3 - Delete email from list\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the email to add: ");
                scanf("%s", email);
                add_email(&head, email);
                break;
            case 2:
                printf("The email list is:\n");
                print_list(head);
                break;
            case 3:
                printf("Enter the email to delete: ");
                scanf("%s", email);
                delete_email(&head, email);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}