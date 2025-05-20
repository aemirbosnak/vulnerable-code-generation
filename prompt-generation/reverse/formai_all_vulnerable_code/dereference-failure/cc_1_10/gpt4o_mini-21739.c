//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EmailNode {
    char email[100];
    struct EmailNode *next;
} EmailNode;

typedef struct MailingList {
    EmailNode *head;
} MailingList;

MailingList* createMailingList() {
    MailingList *list = malloc(sizeof(MailingList));
    list->head = NULL;
    return list;
}

void freeMailingList(MailingList* list) {
    EmailNode *current = list->head;
    EmailNode *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

void addEmail(MailingList *list, const char *email) {
    EmailNode *newNode = malloc(sizeof(EmailNode));
    strncpy(newNode->email, email, 99);
    newNode->email[99] = '\0'; // Ensure null-termination
    newNode->next = list->head; // Insert at the beginning
    list->head = newNode;
    printf("Added: %s\n", email);
}

void deleteEmail(MailingList *list, const char *email) {
    EmailNode *current = list->head;
    EmailNode *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next; // Remove head
            } else {
                previous->next = current->next; // Remove current node
            }
            free(current);
            printf("Deleted: %s\n", email);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Email %s not found.\n", email);
}

void viewEmails(MailingList *list) {
    EmailNode *current = list->head;
    if (current == NULL) {
        printf("No emails in the mailing list.\n");
        return;
    }

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

void searchEmail(MailingList *list, const char *email) {
    EmailNode *current = list->head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            printf("Email %s found in the list.\n", email);
            return;
        }
        current = current->next;
    }
    printf("Email %s not found in the list.\n", email);
}

void displayMenu() {
    printf("Mailing List Manager\n");
    printf("--------------------\n");
    printf("1. Add Email\n");
    printf("2. Delete Email\n");
    printf("3. View Emails\n");
    printf("4. Search Email\n");
    printf("5. Exit\n");
}

int main() {
    MailingList *mailingList = createMailingList();
    int choice;
    char email[100];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after entering choice

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addEmail(mailingList, email);
                break;
            case 2:
                printf("Enter email to delete: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                deleteEmail(mailingList, email);
                break;
            case 3:
                viewEmails(mailingList);
                break;
            case 4:
                printf("Enter email to search: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                searchEmail(mailingList, email);
                break;
            case 5:
                freeMailingList(mailingList);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}