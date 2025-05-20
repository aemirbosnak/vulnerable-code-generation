//FormAI DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Structure to hold a single node
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Structure to hold the entire linked list
typedef struct LinkedList {
    int length;
    Node *head;
} LinkedList;

// Function to create a new node with the given value
Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(LinkedList *list, int value) {
    Node *newNode = createNode(value);
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
}

// Function to delete the first node of the list
void deleteAtBeginning(LinkedList *list) {
    if (list->head == NULL)
        return;
    Node *temp = list->head;
    list->head = list->head->next;
    list->length--;
    free(temp);
}

// Function to print the linked list
void printList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Main function to create and manipulate linked list
int main() {
    srand(time(NULL));
    LinkedList list = {0, NULL};
    int i;
    for (i = 0; i < ROWS; i++) {
        insertAtBeginning(&list, rand() % 10);
    }
    for (i = 0; i < COLS; i++) {
        printList(&list);
        deleteAtBeginning(&list);
    }
    return 0;
}