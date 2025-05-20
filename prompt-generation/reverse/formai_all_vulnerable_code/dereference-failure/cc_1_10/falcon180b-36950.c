//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* Define the structure of a node */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* Define the structure of a linked list */
typedef struct list {
    Node* head;
    int size;
} List;

/* Function to create a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to append a node to the end of a linked list */
void appendNode(List* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

/* Function to print the linked list */
void printList(List* list) {
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Function to free the memory of a linked list */
void freeList(List* list) {
    Node* current = list->head;
    while (current!= NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}

/* Function to reverse the linked list */
void reverseList(List* list) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

int main() {
    List list;
    list.head = NULL;
    list.size = 0;

    /* Append nodes to the list */
    appendNode(&list, 1);
    appendNode(&list, 2);
    appendNode(&list, 3);
    appendNode(&list, 4);
    appendNode(&list, 5);

    /* Print the list */
    printf("Original list:\n");
    printList(&list);

    /* Reverse the list */
    reverseList(&list);

    /* Print the reversed list */
    printf("Reversed list:\n");
    printList(&list);

    /* Free the memory of the list */
    freeList(&list);

    return 0;
}