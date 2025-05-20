//FormAI DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// define struct for node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// define struct for linked list
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// function prototypes
void insertNode(LinkedList* list, int data);
void traverseList(LinkedList* list);
void deleteList(LinkedList* list);

int main() {
    LinkedList list;
    list.head = NULL;
    list.size = 0;

    // insert nodes into linked list
    insertNode(&list, 5);
    insertNode(&list, 10);
    insertNode(&list, 15);
    insertNode(&list, 20);

    // print linked list
    traverseList(&list);

    // free memory
    deleteList(&list);

    return 0;
}

// function to insert a node into linked list
void insertNode(LinkedList* list, int data) {
    // create new node
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // if list is empty, set head to new node
    if (list->head == NULL) {
        list->head = newNode;
    }
    // otherwise, insert new node at end of list
    else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
}

// function to traverse a linked list and print each node's data
void traverseList(LinkedList* list) {
    printf("Linked List: ");
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// function to delete a linked list and free all memory
void deleteList(LinkedList* list) {
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->size = 0;
}