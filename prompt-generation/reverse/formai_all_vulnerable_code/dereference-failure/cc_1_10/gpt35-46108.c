//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MailingList {
    char name[50];
    char email[100];
    struct MailingList *next;
} MailingList;

void printList(MailingList *head) {
    MailingList *current = head;

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s - %s\n", current->name, current->email);
        current = current->next;
    }
}

void addToList(MailingList **head, char *name, char *email) {
    MailingList *newEntry = (MailingList *) malloc(sizeof(MailingList));
    strcpy(newEntry->name, name);
    strcpy(newEntry->email, email);
    newEntry->next = *head;
    *head = newEntry;
}

int removeFromList(MailingList **head, char *email) {
    MailingList *current = *head, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                *head = current->next;
            }

            free(current);
            return 1;
        }

        previous = current;
        current = current->next;
    }

    return 0;
}

int main() {
    MailingList *mailingList = NULL;
    int menuChoice = 0;
    char name[50], email[100];

    do {
        printf("\n1. Print mailing list\n");
        printf("2. Add email to mailing list\n");
        printf("3. Remove email from mailing list\n");
        printf("4. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printList(mailingList);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addToList(&mailingList, name, email);
                break;
            case 3:
                printf("Enter email: ");
                scanf("%s", email);
                if (removeFromList(&mailingList, email)) {
                    printf("\nEmail successfully removed.\n");
                } else {
                    printf("\nEmail not found.\n");
                }
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (menuChoice != 4);

    return 0;
}