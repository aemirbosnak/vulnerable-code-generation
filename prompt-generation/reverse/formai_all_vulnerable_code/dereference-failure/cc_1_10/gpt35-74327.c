//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

Node* createNode(int value){
    Node *newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed.");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node *head, int value){
    Node *newNode = createNode(value);
    if(!head){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* insertAtEnd(Node *head, int value){
    Node *newNode = createNode(value);
    if(!head){
        head = newNode;
    }
    else{
        Node *current = head;
        while(current->next)
            current = current->next;
        current->next = newNode;
    }
    return head;
}

Node* deleteFromBeginning(Node *head){
    if(!head){
        printf("List is empty.");
        return NULL;
    }
    else{
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

Node* deleteFromEnd(Node *head){
    if(!head){
        printf("List is empty.");
        return NULL;
    }
    else if(!head->next){
        free(head);
        head = NULL;
    }
    else{
        Node *current = head;
        while(current->next->next)
            current = current->next;
        free(current->next);
        current->next = NULL;
    }
    return head;
}

void displayList(Node *head){
    if(!head){
        printf("List is empty.");
        return;
    }
    else{
        Node *current = head;
        while(current){
            printf("%d ", current->data);
            current = current->next;
        }
    }
}

void freeMemory(Node *head){
    Node *current = head;
    while(current){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(){
    Node *head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    displayList(head);
    printf("\n");
    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    displayList(head);
    freeMemory(head);
    return 0;
}