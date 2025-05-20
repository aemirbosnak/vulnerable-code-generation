//FormAI DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

// function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// function to create a new linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// function to add a new node to the end of the linked list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// function to delete a node from the linked list
bool deleteNode(LinkedList* list, int data) {
    Node* curr = list->head;
    while (curr != NULL) {
        if (curr->data == data) {
            if (curr == list->head) {
                list->head = curr->next;
                if (list->head != NULL) {
                    list->head->prev = NULL;
                }
                free(curr);
            } else if (curr == list->tail) {
                list->tail = curr->prev;
                if (list->tail != NULL) {
                    list->tail->next = NULL;
                }
                free(curr);
            } else {
                Node* prev = curr->prev;
                Node* next = curr->next;
                prev->next = next;
                next->prev = prev;
                free(curr);
            }
            list->size--;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// function to print all the nodes in the linked list
void printList(LinkedList* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// function to free up memory used by the linked list
void freeList(LinkedList* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(list);
}

int main() {
    LinkedList* ebook = createLinkedList();
    addNode(ebook, 1);
    addNode(ebook, 2);
    addNode(ebook, 3);
    addNode(ebook, 4);
    addNode(ebook, 5);
    
    printf("Contents of the Ebook:\n");
    printList(ebook);
    
    printf("Deleting Chapter 3...\n");
    deleteNode(ebook, 3);
    
    printf("New Contents of the Ebook:\n");
    printList(ebook);
    
    freeList(ebook);
    return 0;
}