//FormAI DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int data;
    struct Node* next;
};

// function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// function to insert a node at the beginning of the linked list
// and return the modified linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* node = newNode(data);
    node->next = head;
    return node;
}

// function to insert a node at the end of the linked list
// and return the modified linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* node = newNode(data);
    if (head == NULL) {
        head = node;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    return head;
}

// function to delete a node from the linked list
// and return the modified linked list
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return head;
    } else if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            struct Node* delNode = temp->next;
            temp->next = delNode->next;
            free(delNode);
        }
    }
    return head;
}

// function to print the linked list
void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// main function
int main() {
    // create an empty linked list
    struct Node* head = NULL;

    // insert some nodes at the beginning of the linked list
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    printList(head);

    // insert some nodes at the end of the linked list
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    printList(head);

    // delete some nodes from the linked list
    head = deleteNode(head, 30);
    head = deleteNode(head, 50);
    printList(head);

    // exit success
    return 0;
}