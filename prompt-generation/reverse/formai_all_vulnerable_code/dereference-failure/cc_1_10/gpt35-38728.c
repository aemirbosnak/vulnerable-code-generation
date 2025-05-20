//FormAI DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *email;
    struct Node *next;
} Node;

Node* create_node(char *email)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->email = (char*) malloc(strlen(email) * sizeof(char));
    strcpy(node->email, email);
    node->next = NULL;
    return node;
}

void add_node(Node **head, char *email)
{
    if (*head == NULL) {
        *head = create_node(email);
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        if (strcmp(temp->email, email) == 0) {
            printf("Error: Email already exists.\n");
            return;
        }
        temp = temp->next;
    }

    if (strcmp(temp->email, email) == 0) {
        printf("Error: Email already exists.\n");
        return;
    }

    temp->next = create_node(email);
}

void print_list(Node *head)
{
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Mailing List:\n");
    while (head != NULL) {
        printf("- %s\n", head->email);
        head = head->next;
    }
}

void delete_node(Node **head, char *email)
{
    if (*head == NULL) {
        printf("Error: Cannot delete from empty list.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: Email does not exist.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp->email);
    free(temp); 
}

int main()
{
    Node *head = NULL;
    int choice = 0;

    while (1) {
        printf("\n1. Add an email to the mailing list.\n");
        printf("2. Remove an email from the mailing list.\n");
        printf("3. Display the mailing list.\n");
        printf("4. Quit.\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email: ");
                char email[100];
                scanf("%s", email);
                add_node(&head, email);
                break;

            case 2:
                printf("Enter email: ");
                char del_email[100];
                scanf("%s", del_email);
                delete_node(&head, del_email);
                break;

            case 3:
                print_list(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}