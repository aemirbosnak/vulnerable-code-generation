//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Linked list structure
typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

// Creates a new linked list
LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Inserts a node at the beginning of the linked list
void insertAtBeginning(LinkedList *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    if (list->tail == NULL) {
        list->tail = newNode;
    }
    list->size++;
}

// Inserts a node at the end of the linked list
void insertAtEnd(LinkedList *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Inserts a node at a specific position in the linked list
void insertAtPosition(LinkedList *list, int data, int position) {
    if (position == 0) {
        insertAtBeginning(list, data);
    } else if (position == list->size) {
        insertAtEnd(list, data);
    } else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->size++;
    }
}

// Deletes a node from the beginning of the linked list
void deleteFromBeginning(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

// Deletes a node from the end of the linked list
void deleteFromEnd(LinkedList *list) {
    if (list->size == 0) {
        return;
    }
    Node *current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->tail = current;
    list->size--;
}

// Deletes a node from a specific position in the linked list
void deleteFromPosition(LinkedList *list, int position) {
    if (position == 0) {
        deleteFromBeginning(list);
    } else if (position == list->size - 1) {
        deleteFromEnd(list);
    } else {
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        list->size--;
    }
}

// Reverses the linked list
void reverseLinkedList(LinkedList *list) {
    Node *previous = NULL;
    Node *current = list->head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    list->head = previous;
}

// Finds the middle element of the linked list
Node *findMiddleElement(LinkedList *list) {
    Node *slow = list->head;
    Node *fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Finds the nth element from the end of the linked list
Node *findNthElementFromEnd(LinkedList *list, int n) {
    Node *current = list->head;
    Node *nthElement = list->head;
    for (int i = 0; i < n; i++) {
        current = current->next;
    }
    while (current != NULL) {
        current = current->next;
        nthElement = nthElement->next;
    }
    return nthElement;
}

// Prints the linked list
void printLinkedList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver code
int main() {
    LinkedList *list = createLinkedList();
    insertAtBeginning(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
    insertAtPosition(list, 40, 1);
    printLinkedList(list); // Output: 10 40 20 30
    deleteFromBeginning(list);
    deleteFromEnd(list);
    deleteFromPosition(list, 1);
    printLinkedList(list); // Output: 40
    reverseLinkedList(list);
    printLinkedList(list); // Output: 40
    Node *middleElement = findMiddleElement(list);
    printf("Middle element: %d\n", middleElement->data); // Output: 40
    Node *nthElementFromEnd = findNthElementFromEnd(list, 1);
    printf("Nth element from end: %d\n", nthElementFromEnd->data); // Output: 40
    return 0;
}