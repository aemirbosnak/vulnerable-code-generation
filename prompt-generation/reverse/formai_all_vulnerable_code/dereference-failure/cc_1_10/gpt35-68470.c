//FormAI DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

//custom structure declaration
struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

//function to create a new Node
Node* createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to display the data structures
void displayLinkedList(Node *head)
{
    printf("\nLinked List: ");
    Node *current = head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}

int main(){

    Node *head = NULL;

    //create nodes and link them
    Node *node1 = createNode(2);
    Node *node2 = createNode(4);
    Node *node3 = createNode(6);
    Node *node4 = createNode(8);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    head = node1;

    //display the linked list
    displayLinkedList(head);

    //insert a node at the beginning
    Node *newNode = createNode(0);
    newNode->next = head;
    head = newNode;

    //display the linked list
    displayLinkedList(head);

    //insert a node at the end
    Node *lastNode = createNode(10);
    Node *current = head;
    while(current->next!=NULL){
        current = current->next;      
    }
    current->next = lastNode;

    //display the linked list
    displayLinkedList(head);

    //insert a node at a given position
    Node* prevNode = head->next;
    Node* givenNode = createNode(3);
    givenNode->next = prevNode->next;
    prevNode->next = givenNode;

    //display the linked list
    displayLinkedList(head);
    

    return 0;
}