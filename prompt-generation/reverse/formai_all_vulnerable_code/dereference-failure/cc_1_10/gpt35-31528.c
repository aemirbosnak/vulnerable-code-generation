//FormAI DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for storing data 
struct Node {
    int value;
    struct Node *next;
};

// Function to insert a new node in linked list
void insertNode(struct Node **headRef, int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to print linked list elements
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d->", node->value);
        node = node->next;
    }
    printf("NULL");
}

// Function that returns the length of list
int length(struct Node *node) {
    int len = 0;
    while (node != NULL) {
        len++;
        node = node->next;
    }
    return len;
}

// Function that splits the list into two halves
void splitList(struct Node *list, struct Node **list1, struct Node **list2) {

    // Find the middle element using two pointers technique
    struct Node *slowPtr = list;
    struct Node *fastPtr = list->next;

    while (fastPtr != NULL) {
        fastPtr = fastPtr->next;
        if (fastPtr != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    // Split the list and assign the halves to list1 and list2
    *list1 = list;
    *list2 = slowPtr->next;
    slowPtr->next = NULL;
}

// Function that merges two sorted lists
struct Node* merge(struct Node *list1, struct Node *list2) {

    // Create a dummy node which will be used to add new nodes
    struct Node *dummy = (struct Node*) malloc(sizeof(struct Node));
    
    // Create a tail node which will point to the last element of the new list
    struct Node *tail = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->value < list2->value) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Add remaining nodes to the new list
    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    return dummy->next;
}

// Function that performs merge sort on the linked list
void mergeSort(struct Node **headRef) {

    struct Node *head = *headRef;
    struct Node *list1, *list2;

    // Base case
    if (head == NULL || head->next == NULL)
        return;

    // Split the list into two halves
    splitList(head, &list1, &list2);

    // Recursively sort the two halves
    mergeSort(&list1);
    mergeSort(&list2);

    // Merge the two sorted lists
    *headRef = merge(list1, list2);
}

// Driver program
int main() {
    struct Node *head = NULL;

    // Insert some random values in the linked list
    insertNode(&head, 7);
    insertNode(&head, 3);
    insertNode(&head, 9);
    insertNode(&head, 5);
    insertNode(&head, 1);
    
    printf("Original list: ");
    printList(head);

    // Perform merge sort on the linked list
    mergeSort(&head);

    printf("\nSorted list  : ");
    printList(head);

    return 0;
}