//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/* Declare struct for the linked list nodes */
typedef struct Node {
    int value;
    struct Node* next;
} Node;

/* Function to add a new node to the linked list */
void addNode(Node** head, int value) {
    /* Allocate memory for new node */
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    /* If the list is empty, make this the head */
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    /* Traverse the list and add the new node to the end */
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

/* Function to print the linked list */
void printList(Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

/* Function to create an array of random integers */
int* createRandomArray(int size) {
    int* arr = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%100;
    }
    return arr;
}

/* Function to print an array */
void printArray(int* arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    /* Create a linked list */
    Node* head = NULL;
    addNode(&head, 5);
    addNode(&head, 8);
    addNode(&head, 3);
    printList(head);

    /* Create an array */
    int* arr = createRandomArray(6);
    printArray(arr, 6);

    /* Free memory */
    free(arr);
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}