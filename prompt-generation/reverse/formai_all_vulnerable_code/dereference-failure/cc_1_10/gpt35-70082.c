//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

//Structure for node in Linked List
struct Node {
    int value;
    struct Node* next;
};

//Function to add a node at the end of linked list
void addNode(struct Node** head, int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to print linked list
void printList(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

//Function to add a node at the beginning of linked list
void push(struct Node** head, int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = *head;
    *head = newNode;
}

//Function to add a node after a given node in linked list
void addAfter(struct Node* prevNode, int val) {
    if(prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//Function to add a node at a given position in linked list
void addNodeAtPos(struct Node** head, int pos, int val) {
    if(*head == NULL && pos == 1) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->value = val;
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    if(pos == 1) {
        push(head, val);
        return;
    }
    struct Node* temp = *head;
    for(int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position does not exist\n");
        return;
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

//Function to delete a node from linked list
void deleteNode(struct Node** head, int val) {
    struct Node* temp = *head;
    if(temp != NULL && temp->value == val) {
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* prev;
    while(temp != NULL && temp->value != val) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//Main function
int main() {
    struct Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 4);
    printList(head);
    push(&head, 0);
    printList(head);
    addAfter(head->next, 3);
    printList(head);
    addNodeAtPos(&head, 3, 2);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    return 0;
}