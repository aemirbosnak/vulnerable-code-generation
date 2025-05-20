//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the linked list head
struct Node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to display the linked list
void display() {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to search for a node with a given value in the linked list
struct Node* search(int value) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(int value) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current!= NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

// Function to reverse the linked list
void reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Function to check if the linked list is empty
int isEmpty() {
    return head == NULL;
}

// Function to calculate the length of the linked list
int length() {
    int count = 0;
    struct Node* current = head;
    while (current!= NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // Create a linked list
    push(1);
    push(2);
    push(3);
    push(4);

    // Display the linked list
    display();

    // Search for a node with a given value
    printf("Node with value 5: %s\n", (search(5)!= NULL? "Found" : "Not Found"));

    // Delete a node with a given value
    printf("After deleting node with value 2: ");
    display();

    // Reverse the linked list
    reverse();

    // Display the reversed linked list
    printf("Reversed linked list: ");
    display();

    return 0;
}