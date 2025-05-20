//FormAI DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

struct node {
    char email[50];
    struct node* next;
};

struct node* createNode(char email[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct node** head, char email[]) {
    struct node* newNode = createNode(email);
    if(*head == NULL) {
        *head = newNode;
    } else {
        struct node* curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void displayList(struct node* head) {
    struct node* curr = head;
    while(curr != NULL) {
        printf("%s\t", curr->email);
        curr = curr->next;
    }
}

struct node* searchNode(struct node* head, char email[]) {
    struct node* curr = head;
    while(curr != NULL) {
        if(strcmp(curr->email, email) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void deleteNode(struct node** head, char email[]) {
    struct node* curr = *head;
    struct node* prev = NULL;
    while(curr != NULL && strcmp(curr->email, email) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL) {
        printf("Email not found!\n");
    } else {
        if(prev == NULL) {
            *head = curr->next;
        } else {
            prev->next = curr->next;
        }
        printf("%s has been removed from the list.\n", curr->email);
        free(curr);
    }
}

int main() {
    struct node* head = NULL; // Initialize empty linked list
    int choice;
    char email[50];
    struct node* result;
    while(1) {
        printf("\nMenu:\n");
        printf("1. Add email to mailing list\n");
        printf("2. View mailing list\n");
        printf("3. Search for an email\n");
        printf("4. Remove an email\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter email to add: ");
                    scanf("%s", email);
                    appendNode(&head, email);
                    printf("%s has been added to the mailing list.\n", email);
                    break;
            case 2: printf("\n-------------------\n");
                    printf("Current mailing list:\n");
                    displayList(head);
                    printf("\n-------------------\n");
                    break;
            case 3: printf("Enter email to search: ");
                    scanf("%s", email);
                    result = searchNode(head, email);
                    if(result == NULL) {
                        printf("Email not found!\n");
                    } else {
                        printf("%s is present in the mailing list.\n", email);
                    }
                    break;
            case 4: printf("Enter email to remove: ");
                    scanf("%s", email);
                    deleteNode(&head, email);
                    break;
            case 5: printf("Exiting program...\n");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}