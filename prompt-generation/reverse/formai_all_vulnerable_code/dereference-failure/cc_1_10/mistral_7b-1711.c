//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct Node {
    char data[MAX_LEN];
    int len;
    struct Node *next;
} Node;

Node* createNode(char* str) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->len = strlen(str);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    char str1[MAX_LEN] = "Apple";
    char str2[MAX_LEN] = "Banana";
    char str3[MAX_LEN] = "Cherry";

    Node* newNode1 = createNode(str1);
    Node* newNode2 = createNode(str2);
    Node* newNode3 = createNode(str3);

    insertNode(&head, newNode1);
    insertNode(&head, newNode2);
    insertNode(&head, newNode3);

    printList(head);

    return 0;
}