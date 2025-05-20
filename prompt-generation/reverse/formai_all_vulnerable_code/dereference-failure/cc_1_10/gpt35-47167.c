//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100    /* Maximum emails in list */
#define MAX_LEN 50        /* Maximum length of email */

/**
 * The structure of a node in the linked list
 */
typedef struct emailNode {
    char email[MAX_LEN];
    struct emailNode* next;
} EmailNode;

/**
 * The structure of the mailing list manager
 */
typedef struct {
    EmailNode* head;
    int count;
} MailingList;

/**
 * Create and initialize a new empty mailing list
 */
MailingList* createMailingList() {
    MailingList* list = (MailingList*) malloc(sizeof(MailingList));
    list->head = NULL;
    list->count = 0;
    return list;
}

/**
 * Add an email to the mailing list
 */
void addEmail(MailingList* list, char* email) {
    if (list->count == MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }

    EmailNode* newNode = (EmailNode*) malloc(sizeof(EmailNode));
    strncpy(newNode->email, email, MAX_LEN-1);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        EmailNode* currNode = list->head;
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    list->count++;
}

/**
 * Remove an email from the mailing list
 */
void removeEmail(MailingList* list, char* email) {
    if (list->head == NULL) {
        printf("Mailing list is empty!\n");
        return;
    }

    EmailNode* currNode = list->head;
    EmailNode* prevNode = NULL;
    while (currNode != NULL) {
        if (strcmp(currNode->email, email) == 0) {
            /* Found email, remove from list */
            if (prevNode == NULL) {
                list->head = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            list->count--;
            printf("Removed %s from mailing list.\n", email);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    printf("%s is not in mailing list.\n", email);
}

/**
 * Print the mailing list
 */
void printList(MailingList* list) {
    printf("Mailing List (%d):\n", list->count);
    EmailNode* currNode = list->head;
    while (currNode != NULL) {
        printf("%s\n", currNode->email);
        currNode = currNode->next;
    }
}

/**
 * Main function to test the mailing list manager
 */
int main() {
    MailingList* list = createMailingList();

    /* Add emails to the mailing list */
    addEmail(list, "john.doe@example.com");
    addEmail(list, "jane.doe@example.com");
    addEmail(list, "bob.smith@example.com");
    addEmail(list, "alice.harris@example.com");
    addEmail(list, "richard.brown@example.com");
    addEmail(list, "megan.wilde@example.com");
    addEmail(list, "david.king@example.com");
    addEmail(list, "sara.moore@example.com");

    /* Print the mailing list */
    printf("-------------------------\n");
    printList(list);
    printf("-------------------------\n");

    /* Remove an email from the mailing list */
    removeEmail(list, "richard.brown@example.com");

    /* Print the mailing list again */
    printf("-------------------------\n");
    printList(list);
    printf("-------------------------\n");

    return 0;
}