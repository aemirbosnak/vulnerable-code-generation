//FormAI DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct email {
    char* address;
    struct email* next;
} Email;

Email* createList() {
    return NULL;
}

void addEmail(Email** head, char* email) {
    Email* newEmail = (Email*)malloc(sizeof(Email));
    newEmail->address = email;
    newEmail->next = *head;
    *head = newEmail;
}

void deleteEmail(Email** head, char* email) {
    Email* currentEmail = *head;
    Email* prevEmail = NULL;

    while(currentEmail != NULL) {
        if(strcmp(currentEmail->address, email) == 0) {
            if(currentEmail == *head) {
                *head = currentEmail->next;
            } else {
                prevEmail->next = currentEmail->next;
            }
            free(currentEmail);
            return;
        }
        prevEmail = currentEmail;
        currentEmail = currentEmail->next;
    }
}

bool isInList(Email* head, char* email) {
    Email* currentEmail = head;

    while(currentEmail != NULL) {
        if(strcmp(currentEmail->address, email) == 0) {
            return true;
        }
        currentEmail = currentEmail->next;
    }
    return false;
}

void displayList(Email* head) {
    Email* currentEmail = head;
    while(currentEmail != NULL) {
        printf("%s ", currentEmail->address);
        currentEmail = currentEmail->next;
    }
    printf("\n");
}

int main() {
    Email* head = createList();
    char* email = (char*)malloc(50*sizeof(char));
    int choice;

    while(1) {
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter email address: ");
                scanf("%s", email);
                if(!isInList(head, email)) {
                    addEmail(&head, email);
                    printf("%s added to the list\n", email);
                } else {
                    printf("%s is already in the list\n", email);
                }
                break;
            case 2:
                printf("Enter email address: ");
                scanf("%s", email);
                if(isInList(head, email)) {
                    deleteEmail(&head, email);
                    printf("%s deleted from the list\n", email);
                } else {
                    printf("%s is not in the list\n", email);
                }
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}