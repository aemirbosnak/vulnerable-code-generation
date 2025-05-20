//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct node** head_ref, int data) {
    struct node* newNode = createNode(data);
    struct node* current = *head_ref;
    
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    
    while (current->next!= NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

struct node* searchNode(struct node* head, int data) {
    struct node* current = head;
    
    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        
        current = current->next;
    }
    
    return NULL;
}

void deleteNode(struct node** head_ref, int data) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
    
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    while (current->data!= data) {
        previous = current;
        current = current->next;
    }
    
    if (previous == NULL) {
        *head_ref = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
}

void display(struct node* head) {
    struct node* current = head;
    
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    
    struct node* searchedNode = searchNode(head, 3);
    printf("Node with data 3 found: %p\n", searchedNode);
    
    deleteNode(&head, 3);
    
    display(head);
    
    return 0;
}