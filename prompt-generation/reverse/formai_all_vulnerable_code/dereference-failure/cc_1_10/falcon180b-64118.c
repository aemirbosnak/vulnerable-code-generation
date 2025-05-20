//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insertNode(Node* head, int data) {
    Node* new_node = createNode(data);
    if (head == NULL) {
        new_node->next = NULL;
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
    return head;
}

void deleteNode(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchList(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
}

void reverseList(Node* head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = head;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void concatenateLists(Node* list1, Node* list2) {
    if (list1 == NULL) {
        list1 = list2;
        return;
    }
    Node* temp = list1;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = list2;
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    displayList(head);
    reverseList(head);
    displayList(head);
    deleteNode(head, 3);
    displayList(head);
    concatenateLists(head, createNode(6));
    displayList(head);
    return 0;
}