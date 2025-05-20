//FormAI DATASET v1.0 Category: Linked list operations ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

Node* createNode(int data){
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addElement(Node *head, int data){
    if(head->next==NULL){
        head->next=createNode(data);
        return;
    }
    addElement(head->next, data);
}

void printList(Node *head){
    printf("%d ", head->data);
    if(head->next!=NULL){
        printList(head->next);
    }
}

Node* deleteNode(Node *head, int key){
    if(head==NULL){
        return NULL;
    }
    if(head->data == key){
        Node *temp = head->next;
        free(head);
        return temp;
    }
    head->next = deleteNode(head->next, key);
    return head;
}

Node* reverseList(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main(){
    Node *head = createNode(1);
    addElement(head, 2);
    addElement(head, 3);
    addElement(head, 4);
    addElement(head, 5);
    printf("Original List: ");
    printList(head);
    printf("\n");
    head = deleteNode(head,3);
    printf("List after deleting element with data=3: ");
    printList(head);
    printf("\n");
    head = reverseList(head);
    printf("List after reversing: ");
    printList(head);
    return 0;
}