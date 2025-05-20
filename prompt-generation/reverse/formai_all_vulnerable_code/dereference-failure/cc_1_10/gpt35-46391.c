//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insertAtEnd(Node* head, int data)
{
    Node* new_node = createNode(data);
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

Node* deleteLastNode(Node* head)
{
    if (head == NULL) {
        printf("Linked list is empty.");
        return head;
    }
    Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return head;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

void displayLinkedList(Node* head)
{
    if (head == NULL) {
        printf("Linked list is empty.");
    }
    else {
        Node* current = head;
        printf("Linked list: ");
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL");
    }
}

int main()
{
    Node* head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = deleteLastNode(head);
    displayLinkedList(head);
    return 0;
}