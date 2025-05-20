//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* reverseListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        int data = rand() % 10;
        Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    printf("Given linked list: ");
    printList(head);

    Node* reversedList = reverseListRecursive(head);
    printf("Reversed linked list: ");
    printList(reversedList);

    return 0;
}