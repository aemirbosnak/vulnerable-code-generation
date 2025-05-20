//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteLinkedList(Node* head) {
    while (head!= NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int size;
    printf("Enter the size of linked list: ");
    scanf("%d", &size);

    Node* linkedList = createLinkedList(size);
    printf("Linked List: ");
    printLinkedList(linkedList);

    deleteLinkedList(linkedList);
    return 0;
}