//FormAI DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct node {
    char email[MAX_LENGTH];
    struct node *next;
} Node;

void addEmail(Node **head, char email[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *currentNode = *head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

void displayEmails(Node *head) {
    if (head == NULL) {
        printf("Email list is empty.\n");
        return;
    }

    printf("\nEmail List:\n");
    while (head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}

int main() {
    Node *emailList = NULL;
    char email[MAX_LENGTH];

    printf("Welcome to the Mailing List Manager\n");

    while (1) {
        printf("\nEnter email (type 'exit' to quit): ");
        scanf("%s", email);

        if (strcmp(email, "exit") == 0) {
            break;
        }

        addEmail(&emailList, email);
        displayEmails(emailList);
    }

    printf("\nThank You for using Mailing List Manager\n");

    return 0;
}