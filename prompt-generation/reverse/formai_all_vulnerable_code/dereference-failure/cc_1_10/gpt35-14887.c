//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MailingNode {
    char name[50];
    char email[50];
    struct MailingNode *next;
};

typedef struct MailingNode *MailingList;

void addToList(MailingList *head, char name[], char email[]) {
    MailingList new_node = (MailingList) malloc(sizeof(struct MailingNode));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    MailingList ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void removeFromList(MailingList *head, char email[]) {
    if (*head == NULL) {
        return;
    }
    MailingList curr = *head, prev = NULL;
    while (curr != NULL && strcmp(curr->email, email) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        return;
    }
    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

void displayList(MailingList head) {
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }
    MailingList ptr = head;
    printf("\n");
    while (ptr != NULL) {
        printf("Name: %s\n", ptr->name);
        printf("Email: %s\n", ptr->email);
        printf("\n");
        ptr = ptr->next;
    }
}

int main() {
    char name[50], email[50], choice;
    MailingList mailing_list = NULL;
    while (1) {
        printf("Enter your choice:\n");
        printf("(1) Add to mailing list\n");
        printf("(2) Remove from mailing list\n");
        printf("(3) Display mailing list\n");
        printf("(4) Exit program\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addToList(&mailing_list, name, email);
                break;
            case '2':
                printf("Enter email of person to remove: ");
                scanf("%s", email);
                removeFromList(&mailing_list, email);
                break;
            case '3':
                displayList(mailing_list);
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}