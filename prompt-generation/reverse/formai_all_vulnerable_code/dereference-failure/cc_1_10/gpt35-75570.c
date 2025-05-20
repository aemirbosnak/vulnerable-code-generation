//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
// Code for futuristic C Data Structures Visualization 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {   // creation of a single node
    int data;
    struct node* next;
} node_t;

typedef struct linkedList {   // creation of linked list
    node_t* head;
} linkedList_t;

// function declarations
void insert(linkedList_t* linkedList, int value);
bool delete(linkedList_t* linkedList, int value);
void display(linkedList_t* linkedList);

int main() {
    // creation of the linked list
    linkedList_t* linkedList = (linkedList_t*) malloc(sizeof(linkedList_t));
    linkedList->head = NULL;
    
    insert(linkedList, 2);
    insert(linkedList, 5);
    insert(linkedList, 8);
    insert(linkedList, 12);
    
    display(linkedList);
    
    if(delete(linkedList, 5)) {
        printf("5 has been deleted.\n");
    }
    
    display(linkedList);
    
    free(linkedList);   // deallocation of memory
    
    return 0;
}

void insert(linkedList_t* linkedList, int value) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t));   // creating new node
    newNode->data = value;
    newNode->next = NULL;
    
    if(linkedList->head == NULL) {  // if head is empty
        linkedList->head = newNode;
    } else {
        node_t* temp = linkedList->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool delete(linkedList_t* linkedList, int value) {
    if(linkedList->head == NULL) {
        return false;   // nothing to delete
    }
    
    node_t* temp = linkedList->head;
    if(temp->data == value) {
        linkedList->head = temp->next;   // remove first element
        free(temp);
        return true;
    }
    
    while(temp->next != NULL) {
        if(temp->next->data == value) {
            node_t* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
            return true;
        }
        temp = temp->next;
    }
    return false;   // no node with given value
}

void display(linkedList_t* linkedList) {
    node_t* current = linkedList->head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}