//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtPosition(int newData, int position) {
    struct Node* temp = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = newData;
    newNode->next = NULL;
    
    if(position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        for(int i=1; i<position-1; i++) {
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNodeAtPosition(int position) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    if(position == 1) {
        head = head->next;
        free(temp);
    } else {
        for(int i=1; i<position-1; i++) {
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = temp->next;
        free(temp);
    }
}

void reverseList() {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    
    while(current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

int findNode(int value) {
    struct Node* current = head;
    
    while(current!= NULL && current->data!= value) {
        current = current->next;
    }
    
    return current!= NULL;
}

int main() {
    insertAtPosition(10, 0);
    insertAtPosition(20, 1);
    insertAtPosition(30, 2);
    insertAtPosition(40, 3);
    
    deleteNodeAtPosition(2);
    reverseList();
    
    if(findNode(10)) {
        printf("Found 10 at position 1");
    } else {
        printf("Not Found");
    }
    
    return 0;
}