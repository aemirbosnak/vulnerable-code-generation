//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

// structure of node
struct Node{
    int data;
    struct Node* next;
};

// function to create new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to add new node at the end of the list
void addNodeAtEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

// function to reverse the linked list
struct Node* reverse(struct Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while(current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// function to print linked list
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    addNodeAtEnd(&head, 10);
    addNodeAtEnd(&head, 20);
    addNodeAtEnd(&head, 30);
    addNodeAtEnd(&head, 40);
    printList(head);
    head = reverse(head);
    printf("Reversed List: ");
    printList(head);
    return 0;
}