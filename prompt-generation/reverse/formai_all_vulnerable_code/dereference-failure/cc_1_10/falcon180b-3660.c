//Falcon-180B DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char data[50];
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(char* str) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->data, str);
    node->next = NULL;
    return node;
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to print a linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%s -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Function to remove duplicates from a linked list
Node* removeDuplicates(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    while (curr!= NULL) {
        Node* next = curr->next;
        if (next!= NULL && strcmp(curr->data, next->data) == 0) {
            free(next);
            curr->next = next->next;
        } else {
            prev = curr;
            curr = next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    char* token = strtok(input, " ");
    while (token!= NULL) {
        Node* node = newNode(token);
        if (head == NULL) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
        token = strtok(NULL, " ");
    }
    printf("Original list:\n");
    printList(head);
    head = removeDuplicates(head);
    printf("List after removing duplicates:\n");
    printList(head);
    head = reverseList(head);
    printf("List after reversing:\n");
    printList(head);
    return 0;
}