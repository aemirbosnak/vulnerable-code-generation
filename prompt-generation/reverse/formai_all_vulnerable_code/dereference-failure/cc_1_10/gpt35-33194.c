//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

struct node {
    int data;
    struct node* next;
};

typedef struct {
    struct node* head;
    int size;
} LinkedList;

// Creates a new node with given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Adds a new node to the end of the linked list
void append(LinkedList* list, int data) {
    struct node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        struct node* currNode = list->head;
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    list->size++;
}

// Inserts a new node at the given index
void insert(LinkedList* list, int data, int index) {
    if (index < 0 || index > list->size) {
        printf("Invalid index!\n");
        return;
    }
    else if (index == 0) {
        struct node* newNode = createNode(data);
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        struct node* newNode = createNode(data);
        struct node* currNode = list->head;
        for (int i = 0; i < index-1; i++) {
            currNode = currNode->next;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    list->size++;
}

// Removes the node at the given index
void removeNode(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index!\n");
        return;
    }
    else if (index == 0) {
        struct node* tempNode = list->head;
        list->head = list->head->next;
        free(tempNode);
    }
    else {
        struct node* currNode = list->head;
        for (int i = 0; i < index-1; i++) {
            currNode = currNode->next;
        }
        struct node* tempNode = currNode->next;
        currNode->next = tempNode->next;
        free(tempNode);
    }
    list->size--;
}

// Prints out the contents of the linked list
void printList(LinkedList* list) {
    struct node* currNode = list->head;
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    LinkedList myList;
    myList.head = NULL;
    myList.size = 0;

    append(&myList, 1); // 1
    append(&myList, 2); // 1 -> 2
    insert(&myList, 3, 1); // 1 -> 3 -> 2
    removeNode(&myList, 0); // 3 -> 2
    append(&myList, 4); // 3 -> 2 -> 4

    for (int i = 0; i < 3; i++) {
        sleep(1);
        system("clear");
        printf("Data Structure Visualization Example\n\n");
        printf("Linked List:\n");
        printList(&myList);
        printf("\n");
    }

    return 0;
}