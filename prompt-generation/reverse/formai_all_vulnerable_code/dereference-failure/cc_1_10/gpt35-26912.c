//FormAI DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char email[100];
    struct node *next;
} Node;

// Function to add a new email to the mailing list
void add_email(Node **head, char email[]) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = *head;
    *head = new_node;
}

// Function to remove an email from the mailing list
void remove_email(Node **head, char email[]) {
    Node *curr = *head;
    Node *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->email, email) == 0) {
            if (prev == NULL) {
                *head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            printf("%s successfully removed from the mailing list.\n", email);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("%s is not in the mailing list.\n", email);
}

// Function to print all the emails in the mailing list
void display_list(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%s\n", curr->email);
        curr = curr->next;
    }
}

int main() {
    Node *head = NULL;
    int choice;
    char email[100];
    do {
        printf("\nMain Menu---\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                add_email(&head, email);
                printf("%s successfully added to the mailing list.\n", email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_email(&head, email);
                break;
            case 3:
                printf("\nMailing List---\n");
                display_list(head);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}