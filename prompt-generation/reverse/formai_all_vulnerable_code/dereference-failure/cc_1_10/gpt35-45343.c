//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[50];
    struct node *next;
} t_node;

void addMailingList(t_node **head, char email[]) {
    t_node *newNode = (t_node*) malloc(sizeof(t_node));

    if (*head == NULL) {
        *head = newNode;
    } else {
        t_node *currentNode = *head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    strcpy(newNode->email, email);

    printf("Element added to the mailing list: %s\n", email);
}

void printMailingList(t_node *head) {
    printf("Mailing list:\n");
    t_node *currentNode = head;
    while (currentNode != NULL) {
        printf("%s\n", currentNode->email);
        currentNode = currentNode->next;
    }
}

void deleteMailingList(t_node **head) {
    t_node *currentNode = *head;
    t_node *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    *head = NULL;

    printf("Mailing list deleted.\n");
}

int main() {
    t_node *head = NULL;
    char email[50];

    printf("Welcome to the mailing list manager. I am your guide, Sherlock Holmes.\n");

    while (1) {
        printf("\nChoose an option: \n1. Add a new email to the mailing list.\n2. Print the mailing list.\n3. Delete the mailing list.\n4. Exit.\nOption: ");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the email to be added: ");
                scanf("%s", email);
                addMailingList(&head, email);
                break;
            case 2:
                printMailingList(head);
                break;
            case 3:
                deleteMailingList(&head);
                break;
            case 4:
                printf("Thank you for using the mailing list manager. Until next time, my dear Watson.\n");
                return 0;
            default:
                printf("Please enter a valid option.");
        }
    }
}