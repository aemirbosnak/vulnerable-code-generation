//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Doubly linked list
struct Node* head = NULL;
struct Node* tail = NULL;

void insert(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList() {
    struct Node* current = head;
    
    printf("");
    while (current!= NULL) {
        printf(" | ");
        
        if (current->next == NULL) {
            printf(" \n");
            printf("* ");
        } else {
            printf(" ");
        }
        
        printf("* ");
        printf("%d ", current->data);
        
        current = current->next;
    }
    
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    
    printList();
    
    return 0;
}