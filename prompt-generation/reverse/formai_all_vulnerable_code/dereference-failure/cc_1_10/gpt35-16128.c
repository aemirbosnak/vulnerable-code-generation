//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define a linked list struct
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function to create a new Node
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a new Node at the beginning of a linked list
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// function to delete a Node from a linked list
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current = head->next;
    Node* previous = head;
    while (current != NULL) {
        if (current->data == data) {
            previous->next = current->next;
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

// function to search for a Node in a linked list
bool searchNode(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// function to print all the Nodes in a linked list
void printNodes(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    printNodes(head);
    printf("\n");
    head = deleteNode(head, 3);
    printNodes(head);
    printf("\n");
    bool searchResult = searchNode(head, 2);
    if (searchResult) {
        printf("Node found!\n");
    } else {
        printf("Node not found.\n");
    }
    return 0;
}