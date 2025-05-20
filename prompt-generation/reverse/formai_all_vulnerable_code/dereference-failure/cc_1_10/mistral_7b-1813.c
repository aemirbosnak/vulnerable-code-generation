//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    char email[100];
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;
Node *newNode = NULL;

void addNode(char name[], char email[]) {
    newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        current->next = newNode;
        current = newNode;
    }
}

void displayList() {
    current = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nMailing List:\n");
    while (current != NULL) {
        printf("%s : %s\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    char name[50], email[100];
    int choice = 1;

    while (choice != 0) {
        printf("\n1. Add Name and Email\n2. Display Mailing List\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name : ");
                scanf("%s", name);
                printf("Enter Email : ");
                scanf("%s", email);
                addNode(name, email);
                break;
            case 2:
                displayList();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}