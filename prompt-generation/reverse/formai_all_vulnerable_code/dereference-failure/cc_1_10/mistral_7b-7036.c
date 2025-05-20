//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, char* str) {
    Node* newNode = createNode(str);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int length(Node* node) {
    int count = 0;
    while (node != NULL) {
        node = node->next;
        count++;
    }
    return count;
}

void reverse(Node** head) {
    Node *prev = NULL, *current = *head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    push(&head, "Apple");
    push(&head, "Banana");
    push(&head, "Cherry");
    push(&head, "Durian");
    push(&head, "Elderberry");

    printf("Original List:\n");
    printList(head);

    printf("Length of List: %d\n", length(head));

    printf("List in Reverse Order:\n");
    reverse(&head);
    printList(head);

    printf("Freeing Memory\n");
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}