//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a node at the beginning of the list
void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else if (temp->data == key) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp->next!= NULL) {
            if (temp->next->data == key) {
                temp->next = temp->next->next;
                free(temp->next);
                break;
            }
            temp = temp->next;
        }
    }
}

// Function to search for a node in the list
int search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to reverse the list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Driver code
int main() {
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 10);
    push(&head, 15);
    push(&head, 20);
    printf("Original list: ");
    printList(head);
    printf("\n");

    append(&head, 25);
    append(&head, 30);
    printf("List after append: ");
    printList(head);
    printf("\n");

    deleteNode(&head, 10);
    printf("List after delete: ");
    printList(head);
    printf("\n");

    if (search(head, 15) == 1) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }

    reverse(&head);
    printf("List after reverse: ");
    printList(head);
    printf("\n");

    return 0;
}