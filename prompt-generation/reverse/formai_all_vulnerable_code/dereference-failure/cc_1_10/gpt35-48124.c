//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char email[50];
    struct node *next;
} Node;

Node *head = NULL;

void add_email() {
    Node *temp = (Node*) malloc(sizeof(Node));
    printf("Enter email address: ");
    scanf("%s", temp->email);
    temp->next = NULL;

    if(head == NULL)
        head = temp;
    else {
        Node *curr = head;
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
    }
    printf("Email added successfully!\n");
}

void print_list() {
    if(head == NULL)
        printf("Mailing list empty.\n");
    else {
        Node *curr = head;
        printf("Mailing list:\n");
        while(curr != NULL) {
            printf("%s\n", curr->email);
            curr = curr->next;
        }
    }
}

void delete_email() {
    if(head == NULL)
        printf("Mailing list is empty. Cannot delete email.\n");
    else {
        char email[50];
        printf("Enter email address to delete: ");
        scanf("%s", email);

        if(strcmp(head->email, email) == 0) {
            Node *temp = head;
            head = head->next;
            free(temp);
            printf("Email deleted successfully.\n");
        }
        else {
            Node *curr = head;
            while(curr->next != NULL && strcmp(curr->next->email, email) != 0)
                curr = curr->next;
            
            if(curr->next == NULL)
                printf("Email not found in mailing list.\n");
            else {
                Node *temp = curr->next;
                curr->next = curr->next->next;
                free(temp);
                printf("Email deleted successfully.\n");
            }
        }
    }
}

int main() {
    printf("Welcome to the Mailing List Manager!\n");

    while(1) {
        printf("\n1. Add email address\n");
        printf("2. Print mailing list\n");
        printf("3. Delete email address\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_email();
                break;
            case 2:
                print_list();
                break;
            case 3:
                delete_email();
                break;
            case 4:
                printf("Thank you for using the Mailing List Manager!");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}