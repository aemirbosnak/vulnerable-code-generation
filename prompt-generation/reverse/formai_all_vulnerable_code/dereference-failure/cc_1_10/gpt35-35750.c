//FormAI DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// define the struct node
struct node {
    int data;
    struct node *next;
};

// merge two sorted linked lists
struct node *merge(struct node *a, struct node *b) {
    // create a new node to store the merged linked list
    struct node *mergedList = malloc(sizeof(struct node));
    struct node *curr = mergedList;

    // traverse both linked lists
    while (a != NULL && b != NULL) {
        // if data in a is less than data in b
        if (a->data < b->data) {
            // add node from a to mergedList
            curr->next = a;
            a = a->next;
        }
        // if data in b is less than data in a
        else {
            // add node from b to mergedList
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }

    // add remaining nodes from a or b to mergedList
    if (a == NULL)
        curr->next = b;
    else
        curr->next = a;

    // return the merged linked list
    return mergedList->next;
}

// sort a linked list using merge sort
void mergeSort(struct node **head) {
    // check if the linked list is empty or contains only one node
    if (*head == NULL || (*head)->next == NULL)
        return;

    // find the middle node using slow and fast pointers
    struct node *slow = *head;
    struct node *fast = (*head)->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split the linked list into two halves
    struct node *secondHalf = slow->next;
    slow->next = NULL;

    // recursively sort the two halves
    mergeSort(head);
    mergeSort(&secondHalf);

    // merge the two sorted halves
    *head = merge(*head, secondHalf);
}

// create a new node with the given data
struct node *createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// add a node to the end of the linked list
void addNode(struct node **head, int data) {
    // create a new node with the given data
    struct node *newNode = createNode(data);

    // traverse the linked list to the last node
    struct node *curr = *head;
    if (curr == NULL) {
        *head = newNode;
        return;
    }
    while (curr->next != NULL)
        curr = curr->next;

    // add the new node to the end of the linked list
    curr->next = newNode;
}

int main() {
    // create a linked list of integers
    struct node *head = NULL;
    addNode(&head, 4);
    addNode(&head, 2);
    addNode(&head, 6);
    addNode(&head, 3);
    addNode(&head, 5);
    addNode(&head, 1);

    // print the unsorted linked list
    printf("Unsorted Linked List: ");
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // sort the linked list using merge sort
    mergeSort(&head);

    // print the sorted linked list
    printf("Sorted Linked List:   ");
    curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}