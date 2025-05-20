//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    return head;
}

Node* delete(Node* head, int data) {
    Node* current = head;
    Node* prev = NULL;
    
    while (current!= NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head = current->next;
                free(current);
                return head;
            } else {
                prev->next = current->next;
                free(current);
                return head;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}

Node* search(Node* head, int data) {
    Node* current = head;
    
    while (current!= NULL) {
        if (current->data == data) {
            return current;
        } else {
            current = current->next;
        }
    }
    
    return NULL;
}

void display(Node* head) {
    Node* current = head;
    
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    
    display(head);
    
    head = delete(head, 3);
    display(head);
    
    Node* searchResult = search(head, 3);
    if (searchResult!= NULL) {
        printf("Element found: %d\n", searchResult->data);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}