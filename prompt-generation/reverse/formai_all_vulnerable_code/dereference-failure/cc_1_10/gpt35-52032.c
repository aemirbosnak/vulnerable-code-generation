//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node struct for individual email addresses
typedef struct Node {
    char *email;
    struct Node *next;
} Node;

// Mailing list struct holding head of linked list and number of nodes
typedef struct MailingList {
    Node *head;
    int count;
} MailingList;

// Function to create a new node with given email
Node *createNode(char *email) {
    Node *newNode = malloc(sizeof(Node));
    newNode->email = malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

// Function to print all email addresses in mailing list
void printMailingList(MailingList *list) {
    printf("Total number of email addresses: %d\n", list->count);
    Node *currentNode = list->head;
    while (currentNode != NULL) {
        printf("%s\n", currentNode->email);
        currentNode = currentNode->next;
    }
}

// Function to add an email to the mailing list
void addEmail(MailingList *list, char *email) {
    Node *newNode = createNode(email);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *currentNode = list->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    list->count++;
}

// Function to remove an email from the mailing list
void removeEmail(MailingList *list, char *email) {
    Node *currentNode = list->head;
    Node *prevNode = NULL;
    while (currentNode != NULL && strcmp(currentNode->email, email) != 0) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("%s is not in the mailing list\n", email);
        return;
    } else if (prevNode == NULL) {
        list->head = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }
    free(currentNode->email);
    free(currentNode);
    list->count--;
}

int main() {
    // Initialize an empty mailing list
    MailingList list = { .head = NULL, .count = 0 };

    // Add some initial emails to the mailing list
    addEmail(&list, "johndoe@gmail.com");
    addEmail(&list, "janedoe@gmail.com");
    addEmail(&list, "alexsmith@example.com");

    // Print the current mailing list
    printMailingList(&list);

    // Remove an email from the mailing list
    removeEmail(&list, "janedoe@gmail.com");

    // Print the updated mailing list
    printMailingList(&list);

    return 0;
}