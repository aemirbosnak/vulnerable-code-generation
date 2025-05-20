//Falcon2-11B DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to represent a node in a doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to initialize a doubly linked list
void initializeList(struct Node** head) {
    struct Node* temp = *head;
    while (temp!= NULL) {
        *head = temp->next;
        temp = *head;
    }
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    while (temp!= NULL) {
        if (temp->data == data) {
            if (temp->prev!= NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next!= NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

// Function to print the contents of the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverseList(struct Node** head) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (temp!= NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    while (list1!= NULL && list2!= NULL) {
        if (list1->data < list2->data) {
            temp = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            list2 = list2->next;
        }
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }
    while (list1!= NULL) {
        temp = list1;
        list1 = list1->next;
        temp->next = head;
        head = temp;
    }
    while (list2!= NULL) {
        temp = list2;
        list2 = list2->next;
        temp->next = head;
        head = temp;
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    initializeList(&head);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 9);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 8);
    printf("Original list: ");
    printList(head);
    reverseList(&head);
    printf("Reversed list: ");
    printList(head);
    struct Node* list1 = head;
    struct Node* list2 = head->next;
    head->next = NULL;
    head = mergeLists(list1, list2);
    printf("Merged list: ");
    printList(head);
    return 0;
}