//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char *data;
    struct node *next;
} Node;

Node *createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, char *data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void search(Node *head, char *searchKey) {
    Node *temp = head;
    char *key = searchKey;
    int flag = 0;
    while (temp!= NULL) {
        if (strcmp(temp->data, key) == 0) {
            printf("Key found in the list!\n");
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0) {
        printf("Key not found in the list!\n");
    }
}

int main() {
    Node *head = NULL;
    int choice, i;
    char searchKey[MAX_SIZE];

    do {
        printf("Enter your choice:\n");
        printf("1. Add node\n");
        printf("2. Search node\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data for the node:\n");
            scanf("%s", searchKey);
            addNode(&head, searchKey);
            break;

        case 2:
            printf("Enter the key to search:\n");
            scanf("%s", searchKey);
            search(head, searchKey);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}