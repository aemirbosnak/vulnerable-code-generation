//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to initialize a linked list
Node* createList(int value) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = value;
    head->next = NULL;
    return head;
}

// Function to insert a node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = head;
    return temp;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createList(value);
    Node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node from the linked list
Node* deleteNode(Node* head, int value) {
    Node* current = head;
    while (current!= NULL && current->data!= value) {
        current = current->next;
    }
    if (current == NULL) {
        return head;
    }
    if (current->next == NULL) {
        free(current);
        return NULL;
    }
    Node* temp = current->next;
    free(current);
    current->next = temp;
    return head;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to find the length of the linked list
int listLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current!= NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast!= NULL && fast->next!= NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to search for a node in the linked list
Node* searchNode(Node* head, int value) {
    Node* current = head;
    while (current!= NULL && current->data!= value) {
        current = current->next;
    }
    return current;
}

// Main function
int main() {
    Node* head = createList(1);
    head = insertAtBeginning(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtBeginning(head, 4);
    head = insertAtEnd(head, 5);
    head = deleteNode(head, 2);
    head = reverseList(head);
    printList(head);
    printf("Length of the linked list: %d\n", listLength(head));
    Node* middle = findMiddle(head);
    printf("Middle node: %d\n", middle->data);
    Node* searchResult = searchNode(head, 4);
    if (searchResult!= NULL) {
        printf("Node found: %d\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}