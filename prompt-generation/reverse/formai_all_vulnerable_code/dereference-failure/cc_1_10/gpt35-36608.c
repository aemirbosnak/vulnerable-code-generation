//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

Node *createNewNode(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node **head, char data) {
    Node *newNode = createNewNode(data);
    newNode->next = *head;
    *head = newNode;
}

void pop(Node **head) {
    if (*head == NULL) {
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void printList(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("Current list: ");
        while (head != NULL) {
            printf("%c", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    Node *head = NULL;
    char input[100];
    int i;
    printf("Enter a string of characters to recover: ");
    fgets(input, sizeof(input), stdin);
    printf("Original string: %s", input);

    for (i = 0; i < strlen(input); i++) {
        push(&head, input[i]);
    }

    printf("Recovered string: ");
    while (head != NULL) {
        printf("%c", head->data);
        pop(&head);
    }
    printf("\n");

    return 0;
}