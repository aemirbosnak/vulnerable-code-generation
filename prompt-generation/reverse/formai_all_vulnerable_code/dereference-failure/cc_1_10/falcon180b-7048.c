//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// define the structure of a linked list
typedef struct linkedlist {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

// initialize an empty linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// add a node to the end of the linked list
void addNode(LinkedList* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// search for a node with a specific data value
Node* searchNode(LinkedList* list, int data) {
    Node* current = list->head;
    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// main function to test the linked list implementation
int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    Node* node = searchNode(list, 2);
    if (node!= NULL) {
        printf("Found node with data value %d\n", node->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}