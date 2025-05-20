//FormAI DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

struct Node {
    char* data;
    struct Node* next;
};

int menu() {
    int choice;
    printf("\n\n");
    printf("\t\tMailing List Manager\n\n");
    printf("\t1. Add Email Address\n");
    printf("\t2. Display Email Addresses\n");
    printf("\t3. Search Email Addresses\n");
    printf("\t4. Delete Email Address\n");
    printf("\t5. Exit\n");
    printf("\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addEmail(struct Node** head) {
    char email[MAX];
    printf("\n");
    printf("\tEnter the Email Address: ");
    scanf("%s", email);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = strdup(email);
    new_node->next = (*head);
    (*head) = new_node;
    printf("\n");
    printf("\tEmail Address Added Successfully\n");
}

void displayEmails(struct Node* head) {
    struct Node* temp = head;
    printf("\n");
    printf("\tEmail Addresses:\n");
    while (temp != NULL) {
        printf("\t%s\n", temp->data);
        temp = temp->next;
    }
}

void searchEmail(struct Node* head) {
    char email[MAX];
    printf("\n");
    printf("\tEnter the Email Address to search: ");
    scanf("%s", email);
    struct Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->data, email) == 0) {
            printf("\n");
            printf("\t%s Found!\n", email);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found == 0) {
        printf("\n");
        printf("\t%s not found\n", email);
    }
}

void deleteEmail(struct Node** head) {
    char email[MAX];
    printf("\n");
    printf("\tEnter the Email Address to delete: ");
    scanf("%s", email);
    struct Node* temp = *head, *prev;
    int found = 0;
    if (temp != NULL && strcmp(temp->data, email) == 0) {
        *head = temp->next;
        free(temp);
        found = 1;
    }
    if (found == 0) {
        while (temp != NULL && strcmp(temp->data, email) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("\n");
            printf("\t%s not found\n", email);
            return;
        }
        prev->next = temp->next;
        free(temp);
        printf("\n");
        printf("\t%s deleted successfully\n", email);
    }
}

int main() {
    struct Node* head = NULL;
    int choice = 0;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                addEmail(&head);
                break;
            case 2:
                displayEmails(head);
                break;
            case 3:
                searchEmail(head);
                break;
            case 4:
                deleteEmail(&head);
                break;
            case 5:
                printf("\n\n");
                printf("\tExiting...Goodbye!\n");
                exit(0);
                break;
            default:
                printf("\n");
                printf("\tInvalid Choice!\n");
        }
    } while (1);
    return 0;
}