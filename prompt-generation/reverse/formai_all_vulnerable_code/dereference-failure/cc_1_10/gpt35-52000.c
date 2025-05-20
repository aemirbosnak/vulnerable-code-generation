//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char email[50];
    struct node* next;
};

typedef struct node NODE;

NODE* head = NULL;

void insert(char email[]) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    strcpy(temp->email, email);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        NODE* curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void delete(char email[]) {
    NODE *temp = head, *prev = NULL;
    if (temp != NULL && strcmp(temp->email, email) == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList() {
    NODE* curr = head;
    if (curr == NULL) {
        printf("Mailing list is empty!\n");
        return;
    }
    while(curr != NULL) {
        printf("%s\n", curr->email);
        curr = curr->next;
    }
}

int main() {
    printf("Welcome to the mailing list manager!\n");
    printf("Enter 'q' to quit the program.\n");
    while(1) {
        printf("Enter 'a' to add an email or 'r' to remove an email from the list: ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'q') {
            printf("Goodbye!\n");
            break;
        }
        if (choice == 'a') {
            printf("Enter email: ");
            char email[50];
            scanf("%s", email);
            insert(email);
            printf("%s added to the mailing list.\n", email);
        }
        else if (choice == 'r') {
            printf("Enter email to remove: ");
            char email[50];
            scanf("%s", email);
            delete(email);
            printf("%s removed from the mailing list.\n", email);
        }
        printList();
        getchar();
    }
    return 0;
}